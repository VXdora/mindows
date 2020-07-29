##########################################################
#		@file	Makefile
#
#		@brief	Makefile
#
#		@author	VXdora
#
#		@update mindows02b [Fix]
##########################################################

default:
	make -C boot main.efi
	cp boot/main.efi image/EFI/BOOT/BOOTX64.EFI
	make -C kernel kernel.bin
	cp kernel/kernel.bin image

clean:
	make -C kernel clean


