copy kernel\kernel.bin image
qemu-system-x86_64 -bios tools\OVMF.fd -drive file=fat:rw:image,format=raw -m 6G
