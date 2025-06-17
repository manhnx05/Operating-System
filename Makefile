ASM=nasm
CC=i686-elf-gcc
LD=i686-elf-ld

CFLAGS=-std=gnu99 -ffreestanding -O2 -Wall -Wextra -I.
LDFLAGS=-ffreestanding -nostdlib -lgcc

KERNEL_OBJS=kernel/kernel.o kernel/screen.o kernel/string.o kernel/math.o kernel/keyboard.o quadratic/quadratic.o

all: quadraticos.iso

quadraticos.iso: kernel.bin
	mkdir -p isodir/boot/grub
	cp kernel.bin isodir/boot/kernel.bin
	echo 'menuentry "Quadratic OS" {' > isodir/boot/grub/grub.cfg
	echo '  multiboot /boot/kernel.bin' >> isodir/boot/grub/grub.cfg
	echo '  boot' >> isodir/boot/grub/grub.cfg
	echo '}' >> isodir/boot/grub/grub.cfg
	grub-mkrescue -o quadraticos.iso isodir

kernel.bin: boot/boot.o $(KERNEL_OBJS)
	$(LD) -T boot/linker.ld -o kernel.bin $^ --oformat binary

boot/boot.o: boot/boot.asm
	$(ASM) -f elf32 $< -o $@

%.o: %.c
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	rm -f *.o *.bin *.iso kernel/*.o quadratic/*.o boot/*.o
	rm -rf isodir

run: quadraticos.iso
	qemu-system-i386 -cdrom quadraticos.iso