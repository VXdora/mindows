; ****************************************************
;       @file   memory/asm_gdtidt.S
;
;       @brief  GDT/IDTに関するハードウェアレベルの設定
;
;       @author vxdora
;
;       @update mindows03b
; ****************************************************

%define _GDT    0x0900
%define _GDTR   0x0010

%define _IDT    0x1000
%define _IDTR   0x0010

global LoadGdt
;       LoadGdt
;       @arg    :   なし
;       @return :   なし
;       @brief  :   GDTの設定
;       @author :   vxdora
;       @update :   mindows03a
;
LoadGdt:
    cli

    ; GDTを_GDTRにセット
    ; LGDT命令は上位2バイトにGDTの大きさ，
    ;     下位4バイトにGDTの番地をセット
    mov     [_GDTR],    word  0x18
    mov     [_GDTR +2], dword _GDT
    lgdt    [_GDTR]

    ; セグメントレジスタのリセット
    ; csレジスタはiretqで変更
    mov     ax, 2*8
    mov     ds, ax
    mov     es, ax
    mov     gs, ax
    mov     fs, ax
    mov     ss, ax

    ; csレジスタを変更
    mov     rcx, rsp
    push    0x00
    push    rcx
    pushfq
    push    1 * 8
    push    main_label
    iretq

    ; パイプラインをフラッシュ
main_label:
    sti
    jmp     $+2


global LoadIdt
;       LoadIdt
;       @arg    :   なし
;       @return :   なし
;       @brief  :   IDTの設定
;       @author :   vxdora
;       @update :   mindows03b
;
LoadIdt:
    cli

    ; IDTをIDTRにセット
    ; 上位2バイトにはIDTの大きさ，
    ;      下位8バイトはIDTのアドレスをセット
    mov     word  [_IDTR],    word 16 *256 -1
    mov     qword [_IDTR +2], qword _IDT
    lidt    [_IDTR]
    sti
    ret


