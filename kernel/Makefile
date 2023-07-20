CCFLAGS = -Iinclude -ggdb -c -ffreestanding

kernel.bin: kernel.o entry.o io.o vga.o string.o idt.o idt_flush.o isr.o interrupts.o timer.o
	ld.lld -o ../kernel.bin -Ttext 0xffff entry.o kernel.o io.o vga.o string.o idt.o idt_flush.o isr.o interrupts.o timer.o --oformat binary
	rm *.o

interrupts.o:
	nasm interrupts.asm -f elf64 -o interrupts.o

entry.o:
	nasm entry.asm -f elf64 -o entry.o

idt_flush.o:
	nasm idt_flush.asm -f elf64 -o idt_flush.o

kernel.o:
	gcc kernel.c ${CCFLAGS} -o kernel.o

io.o:
	gcc io.c ${CCFLAGS} -o io.o

vga.o:
	gcc vga.c ${CCFLAGS} -o vga.o

string.o:
	gcc string.c ${CCFLAGS} -o string.o

idt.o:
	gcc idt.c ${CCFLAGS} -o idt.o

isr.o:
	gcc isr.c ${CCFLAGS} -o isr.o

timer.o:
	gcc timer.c ${CCFLAGS} -o timer.o

clean: 
	rm *.o