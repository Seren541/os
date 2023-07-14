make -C boot
make -C kernel
cat bootloader kernel.bin > os.img