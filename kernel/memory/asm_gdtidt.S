; ****************************************************
;       @file   memory/asm_gdtidt.S
;
;       @brief  GDT/IDTに関するハードウェアレベルの設定
;
;       @author vxdora
;
;       @update mindows03a [New]
; ****************************************************

%define _GDT    0x0900
%define _GDTR   0x0010

global LoadGdt

;       LoadGdt
;       @arg    :   なし
;       @return :   なし
;       @brief  :   GDTの設定
;       @author :   vxdora
;       @update :   mindows03a [New]
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

    ; パイプラインをフラッシュ
    mov     rcx, rsp
    push    0x00
    push    rcx
    pushfq
    push    1 * 8
    push    main_label
    iretq

main_label:
    sti
    jmp     $+2




