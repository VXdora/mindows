extern KernelMain
global KernelStart

section .text.entry

KernelStart:
    DQ      KernelMain

section .text
