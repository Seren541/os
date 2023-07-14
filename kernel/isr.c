#include <isr.h>
#include <vga.h>

// This gets called from our ASM interrupt handler stub.
void isr_handler(registers_t regs) {
   print("recieved interrupt: ");
   print_hex(regs.int_no);
}