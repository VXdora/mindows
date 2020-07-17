##########################################################
#		@file	Makefile
#
#		@brief	Makefile
#
#		@author	VXdora
#
#		@update mindows01b [Fix]
##########################################################

default:
	make -C boot main.efi
	cp boot/main.efi image/EFI/BOOT/BOOTX64.EFI


