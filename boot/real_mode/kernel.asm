[bits 16]

load_kernel:
    mov bx, KERNEL_OFFSET
    mov dh, 9
    mov dl, [BOOT_DRIVE]

    call disk_load
    ret