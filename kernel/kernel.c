#include <io.h>
#include <vga.h>
#include <string.h>
#include <types.h>
#include <idt.h>

int main() {

    init_idt();

    hide_cursor();
    clear_window();


    print("Hello world  ");
    __asm__ volatile ("int $0x3");

    return 0;
}