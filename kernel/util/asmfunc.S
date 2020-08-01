; *****************************************************
;           @file   util/asmfunc.S
;
;           @brief  アセンブリでのみ使用できる機能を
;                       C言語でも使えるようにする
;
;           @author vxdora
;
;           @update mindows04a
; ******************************************************

global io_cli

; 割り込み禁止
io_cli:
    cli
    ret

global io_sti
; 割り込み許可
io_sti:
    sti
    ret

global io_hlt
; 割り込みあるまで待機
io_hlt:
    hlt
    ret

global io_in8
; 8bit in命令
io_in8:
    mov     edx, ecx
    xor     eax, eax
    in      al, dx
    ret

global io_in32
; 32bit in命令
io_in32:
    mov     rdx, rcx
    in      eax, dx
    ret

global io_out8
; 8bit out命令
io_out8:
    mov     eax, edx
    mov     edx, ecx
    out     dx, al
    ret

global io_out32
; 32bit out命令
io_out32:
    mov     eax, edx
    mov     edx, ecx
    out     dx, eax
    ret

