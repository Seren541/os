#include <timer.h>
#include <isr.h>
#include <types.h>
#include <io.h>
#include <vga.h>

u32_t tick = 0;

void timer_callback(registers_t * regs)
{
    tick++;
    print("Tick: ");
}

void init_timer(u32_t frequency)
{
    register_interrupt_handler(IRQ0, &timer_callback);

    u32_t divisor = 1193180 / frequency;
    port_byte_out(0x43, 0x36);

    // split divisor into two bytes
    u8_t l = (u8_t)(divisor & 0xFF); // & operator clears all but last byte
    u8_t h = (u8_t)( (divisor>>8) & 0xFF );

    port_byte_out(0x40, l);
    port_byte_out(0x40, h);
} 