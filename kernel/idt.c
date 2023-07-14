#include <types.h>
#include <idt.h>
#include <string.h>

// Lets us access our ASM functions from our C code.
extern void idt_flush(u64_t);

// Internal function prototypes.
void idt_set_gate(u8_t, u64_t handler_address, u16_t, u8_t);

idt_entry_t idt_entries[256];
idt_ptr_t   idt_ptr;

void init_idt() {

    idt_ptr.limit = sizeof(idt_entry_t) * 256 -1;
    idt_ptr.base  = (u64_t)&idt_entries;

    memset(&idt_entries, 0, sizeof(idt_entry_t)*256);

	idt_set_gate( 0,  (u64_t)isr0, 0x08, 0x8E);
	idt_set_gate( 1,  (u64_t)isr1, 0x08, 0x8E);
	idt_set_gate( 2,  (u64_t)isr2, 0x08, 0x8E);
	idt_set_gate( 3,  (u64_t)isr3, 0x08, 0x8E);
	idt_set_gate( 4,  (u64_t)isr4, 0x08, 0x8E);
	idt_set_gate( 5,  (u64_t)isr5, 0x08, 0x8E);
	idt_set_gate( 6,  (u64_t)isr6, 0x08, 0x8E);
	idt_set_gate( 7,  (u64_t)isr7, 0x08, 0x8E);
	idt_set_gate( 8,  (u64_t)isr8, 0x08, 0x8E);
	idt_set_gate( 9,  (u64_t)isr9, 0x08, 0x8E);
	idt_set_gate(10, (u64_t)isr10, 0x08, 0x8E);
	idt_set_gate(11, (u64_t)isr11, 0x08, 0x8E);
	idt_set_gate(12, (u64_t)isr12, 0x08, 0x8E);
	idt_set_gate(13, (u64_t)isr13, 0x08, 0x8E);
	idt_set_gate(14, (u64_t)isr14, 0x08, 0x8E);
	idt_set_gate(15, (u64_t)isr15, 0x08, 0x8E);
	idt_set_gate(16, (u64_t)isr16, 0x08, 0x8E);
	idt_set_gate(17, (u64_t)isr17, 0x08, 0x8E);
	idt_set_gate(18, (u64_t)isr18, 0x08, 0x8E);
	idt_set_gate(19, (u64_t)isr19, 0x08, 0x8E);
	idt_set_gate(20, (u64_t)isr20, 0x08, 0x8E);
	idt_set_gate(21, (u64_t)isr21, 0x08, 0x8E);
	idt_set_gate(22, (u64_t)isr22, 0x08, 0x8E);
	idt_set_gate(23, (u64_t)isr23, 0x08, 0x8E);
	idt_set_gate(24, (u64_t)isr24, 0x08, 0x8E);
	idt_set_gate(25, (u64_t)isr25, 0x08, 0x8E);
	idt_set_gate(26, (u64_t)isr26, 0x08, 0x8E);
	idt_set_gate(27, (u64_t)isr27, 0x08, 0x8E);
	idt_set_gate(28, (u64_t)isr28, 0x08, 0x8E);
	idt_set_gate(29, (u64_t)isr29, 0x08, 0x8E);
	idt_set_gate(30, (u64_t)isr30, 0x08, 0x8E);
	idt_set_gate(31, (u64_t)isr31, 0x08, 0x8E);

    __asm__ volatile ("lidt (%0)" : : "r" (&idt_ptr));
}

void idt_set_gate(u8_t num, u64_t handler_address, u16_t sel, u8_t flags) {
   idt_entries[num].base_low = (u16_t) (handler_address & 0xFFFF);
   idt_entries[num].base_middle = (u16_t) ((handler_address >> 16) & 0xFFFF);
   idt_entries[num].base_high = (u32_t) ((handler_address >> 32) & 0xFFFFFFFF);

   idt_entries[num].cs_selector = sel;
   idt_entries[num].zero = 0;
   // We must uncomment the OR below when we get to using user-mode.
   // It sets the interrupt gate's privilege level to 3.
   idt_entries[num].attributes   = flags /* | 0x60 */;

   idt_entries[num].reserved = 0;
} 