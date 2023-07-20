#include <io.h>
#include <vga.h>
#include <string.h>
#include <types.h>
#include <idt.h>
#include <timer.h>

int main() {

    hide_cursor();
    clear_window();

    init_idt();
    init_timer(50);

    __asm__ volatile ("sti"); //enable interupts

    print("Hello world  ");
    __asm__ volatile ("int $0x2");

    while(1)
        __asm__ volatile("hlt");
}