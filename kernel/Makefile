# *****************************************
#  		@file	Makefile
#
# 		@brief	kernelのMakefile
#
# 		@author	vxdora
#
#  		@update mindows04c [Fix]
# *****************************************
CFLAGS = -Wall -Wextra -O0 -I include -nodefaultlibs -nostdlib -fno-builtin -fno-common -e KernelMain
LDFLAGS = -T scripts/kernel.ld

OBJS = 	core/entry.obj core/main.obj \
		device/handler.obj device/timer.obj device/keyboard.obj device/mouse.obj \
		graphics/init.obj graphics/simple.obj \
		memory/gdtidt.obj memory/asm_gdtidt.obj memory/asm_fault.obj memory/fault.obj \
		util/asmfunc.obj util/ctype.obj util/string.obj util/stdio.obj

kernel.bin: $(OBJS) scripts/kernel.ld
	ld -Map kernel.map $(LDFLAGS) -o kernel.bin $+

%.obj: %.c
	x86_64-w64-mingw32-gcc $< $(CFLAGS) -c -o $@

%.obj: %.S
	nasm -felf64 $< -o $@

force:
	make -r clean
	make -r kernel.bin

clean:
	rm $(OBJS)
	rm kernel.map
	rm kernel.bin
