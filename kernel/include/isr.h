#include <types.h>
typedef struct registers
{
   u64_t rdi, rsi, rbp, rsp, rbx, rdx, rcx, rax; // Pushed by pusha.
   u64_t int_no, err_code;    // Interrupt number and error code (if applicable)
   u64_t eip, cs, eflags, useresp, ss; // Pushed by the processor automatically.
} registers_t; 

#define IRQ0 32
#define IRQ1 33
#define IRQ2 34
#define IRQ3 35
#define IRQ4 36
#define IRQ5 37
#define IRQ6 38
#define IRQ7 39
#define IRQ8 40
#define IRQ9 41
#define IRQ10 42
#define IRQ11 43
#define IRQ12 44
#define IRQ13 45
#define IRQ14 46
#define IRQ15 47

typedef void (*isr_t)(registers_t*);
void register_interrupt_handler(u8_t n, isr_t handler); 