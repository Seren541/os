[org 0x7c00]

KERNEL_OFFSET equ 0xffff
mov [BOOT_DRIVE], dl

mov bp, 0x9000 ; set bottom pointer
mov sp, bp ; set stack pointer

mov bx, HELLO_WORLD ; move pointer to message into general register b
call print_string ; bx is in this case your argument

call load_kernel

call switch_to_protected_mode

jmp $

%include "real_mode/print.asm"
%include "real_mode/disk.asm"
%include "real_mode/kernel.asm"

%include "real_mode/pm.asm"
%include "real_mode/gdt.asm"
%include "protected_mode/pt.asm"
%include "protected_mode/gdt.asm"
%include "protected_mode/lm.asm"

[bits 32]

begin_pm:

    call init_pt_protected

    call switch_to_long_mode

[bits 64]

begin_lm:

    call KERNEL_OFFSET
    
    jmp $

HELLO_WORLD db `\r\nBooting into GabrielOS soon\r\n`, 0
BOOT_DRIVE db 0

times 510-($ - $$) db 0
dw 0xaa55