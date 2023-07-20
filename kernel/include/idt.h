// A struct describing an interrupt gate.
struct idt_entry_struct {
   u16_t base_low;             // Low 16 bits of the address to jump to
   u16_t cs_selector;          // Code segment selector
   u8_t  zero;                 // Must always be 0
   u8_t  attributes;           // Flag bytes
                              //      - Bit 7:     Interrupt is present
                              //      - Bits 6-5:  Privelege level of caller (0=kernel..3=user)
                              //      - Bit 4:     Set to 0 for interrupt gates
                              //      - Bits 3-0:  Always 1110 for 32 bit interrupt gate
   u16_t base_middle;          // Middle 16 bits of the address to jump to
   u32_t base_high;            // High 16 bits of the address to jump to
   u32_t reserved;             // Must always be 0
} __attribute__((packed));
typedef struct idt_entry_struct idt_entry_t;

struct idt_ptr_struct {
   u16_t limit;
   u64_t base;
} __attribute__((packed));
typedef struct idt_ptr_struct idt_ptr_t;

void init_idt();

extern void  isr0(void);
extern void  isr1(void);
extern void  isr2(void);
extern void  isr3(void);
extern void  isr4(void);
extern void  isr5(void);
extern void  isr6(void);
extern void  isr7(void);
extern void  isr8(void);
extern void  isr9(void);
extern void isr10(void);
extern void isr11(void);
extern void isr12(void);
extern void isr13(void);
extern void isr14(void);
extern void isr15(void);
extern void isr16(void);
extern void isr17(void);
extern void isr18(void);
extern void isr19(void);
extern void isr20(void);
extern void isr21(void);
extern void isr22(void);
extern void isr23(void);
extern void isr24(void);
extern void isr25(void);
extern void isr26(void);
extern void isr27(void);
extern void isr28(void);
extern void isr29(void);
extern void isr30(void);
extern void isr31(void);
extern void  irq0(void);
extern void  irq1(void);
extern void  irq2(void);
extern void  irq3(void);
extern void  irq4(void);
extern void  irq5(void);
extern void  irq6(void);
extern void  irq7(void);
extern void  irq8(void);
extern void  irq9(void);
extern void irq10(void);
extern void irq11(void);
extern void irq12(void);
extern void irq13(void);
extern void irq14(void);
extern void irq15(void);