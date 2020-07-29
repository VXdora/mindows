;###################################################
;       @file   entry.S
;
;       @brief  カーネルの番地を取得，メモリに書き込み
;
;       @author VXdora
;
;       @update mindows02a
;###################################################
extern KernelMain
global KernelStart

section .text.entry

KernelStart:
    DQ      KernelMain

section .text
