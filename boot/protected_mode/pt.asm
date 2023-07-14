; dealing with page table because apparently you have to have an intermediary step in order to get 64 bit

[bits 32]

init_pt_protected:
    pushad ; fancy pusha for double words aka 32 bit

    mov edi, 0x1000
    mov ecx, 4096

    mov cr3, edi
    xor eax, eax ; set eax 0

    rep stosd

    mov edi, cr3

    mov dword[edi], 0x2003
    add edi, 0x1000

    mov dword[edi], 0x3003
    add edi, 0x1000

    mov dword[edi], 0x4003
    add edi, 0x1000

    mov ebx, 0x00000003
    mov ecx, 512 ; loop operator

    add_page_entry:

        mov dword[edi], ebx
        add ebx, 0x1000
        add edi, 8

        loop add_page_entry

    mov eax, cr4
    or eax, 1 << 5
    mov cr4, eax
    
    popad
    ret