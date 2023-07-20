%macro PUSHALL 0
    push rax
    push rbx
    push rcx
    push rdx
    push rsp
    push rbp
    push rsi
    push rdi
%endmacro

%macro POPALL 0
    pop rdi
    pop rsi
    pop rbp
    pop rsp
    pop rdx
    pop rcx
    pop rbx
    pop rax
%endmacro

%macro ISR_NOERRCODE 1  ; define a macro, taking one parameter
    [GLOBAL isr%1]        ; %1 accesses the first parameter.
    isr%1:
        push byte 0
        push byte %1
        jmp isr_common_stub
%endmacro

%macro ISR_ERRCODE 1
    [GLOBAL isr%1]
    isr%1:
        push byte %1
        jmp isr_common_stub
%endmacro

%macro IRQ 2
  [GLOBAL irq%1]
  irq%1:
    push byte 0
    push byte %2
    jmp irq_common_stub
%endmacro

ISR_NOERRCODE  0
ISR_NOERRCODE  1
ISR_NOERRCODE  2
ISR_NOERRCODE  3
ISR_NOERRCODE  4
ISR_NOERRCODE  5
ISR_NOERRCODE  6
ISR_NOERRCODE  7
ISR_ERRCODE    8
ISR_NOERRCODE  9
ISR_ERRCODE   10
ISR_ERRCODE   11
ISR_ERRCODE   12
ISR_ERRCODE   13
ISR_ERRCODE   14
ISR_NOERRCODE 15
ISR_NOERRCODE 16
ISR_NOERRCODE 17
ISR_NOERRCODE 18
ISR_NOERRCODE 19
ISR_NOERRCODE 20
ISR_NOERRCODE 21
ISR_NOERRCODE 22
ISR_NOERRCODE 23
ISR_NOERRCODE 24
ISR_NOERRCODE 25
ISR_NOERRCODE 26
ISR_NOERRCODE 27
ISR_NOERRCODE 28
ISR_NOERRCODE 29
ISR_NOERRCODE 30
ISR_NOERRCODE 31

IRQ   0,    32
IRQ   1,    33
IRQ   2,    34
IRQ   3,    35
IRQ   4,    36
IRQ   5,    37
IRQ   6,    38
IRQ   7,    39
IRQ   8,    40
IRQ   9,    41
IRQ  10,    42
IRQ  11,    43
IRQ  12,    44
IRQ  13,    45
IRQ  14,    46
IRQ  15,    47


[EXTERN isr_handler]
isr_common_stub:
    PUSHALL

    call isr_handler

    POPALL

    add rsp, 16
    iretq           ; pops 5 things at once: CS, EIP, EFLAGS, SS, and ESP

[EXTERN irq_handler]

irq_common_stub:
   PUSHALL

   call irq_handler

   POPALL
   add rsp, 16
   iretq           ; pops 5 things at once: CS, EIP, EFLAGS, SS, and ESP