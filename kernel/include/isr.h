#include <types.h>
typedef struct registers
{
   u64_t rdi, rsi, rbp, rsp, rbx, rdx, rcx, rax; // Pushed by pusha.
   u64_t int_no, err_code;    // Interrupt number and error code (if applicable)
   u64_t eip, cs, eflags, useresp, ss; // Pushed by the processor automatically.
} registers_t; 
