# *****************************************
# 	kernel - Makefile
# 	Update  develop3.1
# *****************************************
CFLAGS = -Wall -Wextra -O0 -nodefaultlibs -nostdlib -fno-builtin -fno-common -e KernelMain
LDFLAGS = -T kernel.ld

OBJS = 	entry.obj main.obj

kernel.bin: $(OBJS)
	ld -Map kernel.map $(LDFLAGS) -o kernel.bin $+

%.obj: %.c
	x86_64-w64-mingw32-gcc $< $(CFLAGS) -c -o $@

%.obj: %.S
	nasm -felf64 $< -o $@

force:
	make -r clean
	make -r kernel.bin

clean:
	rm kernel.bin
	rm kernel.map
	rm $(OBJS)
