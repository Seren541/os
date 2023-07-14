[bits 16]

print_string:
    pusha
    mov ah, 0x0e

print_loop:
    cmp byte[bx], 0
    je print_end

    mov al, byte[bx]
    int 0x10

    inc bx
    jmp print_loop

print_end:
    popa
    ret