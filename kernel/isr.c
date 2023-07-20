#include <isr.h>
#include <vga.h>
#include <io.h>

isr_t interrupt_handlers[256];

void register_interrupt_handler(u8_t n, isr_t handler)
{
  interrupt_handlers[n] = handler;
} 

void isr_handler(registers_t regs) {
   print("recieved interrupt: ");
   print_hex(regs.int_no);
}

void irq_handler(registers_t regs)
{
   if (regs.int_no >= 40)
   {
       // if the interrupt belongs to the slave pic, send interrupt to slave
       port_byte_out(0xA0, 0x20);
   }
   port_byte_out(0x20, 0x20);

   print_hex(regs.int_no);

   if (interrupt_handlers[regs.int_no] != 0) {
      isr_t handler = interrupt_handlers[regs.int_no];
      handler(&regs);
   }
} 