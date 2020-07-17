/*******************************************************
 *      @file   kernel.ld
 *
 *      @brief  カーネルのリンク規則
 *
 *      @author VXdora
 *
 *      @update mindows02a [New]
*******************************************************/
OUTPUT_FORMAT(elf64-x86-64);
OUTPUT_ARCH(i386:x86-64);
ENTRY(KernelMain);

MEMORY
{
    HEAD(rwx) : ORIGIN = 0x000000, LENGTH = 0x1FFFFF
    BODY(rwx) : ORIGIN = 0x110000, LENGTH = 128m
}

SECTIONS
{
    .body : {
        *(.text.entry )
        *(.text* )

        *(.rodata* )

        *(.data* )

        *(.rdata* )

        _bss_start = . ;
        *(.bss)
        _bss_end = .;

    } > BODY

    /DISCARD/ : {*(.eh_frame )}
}
