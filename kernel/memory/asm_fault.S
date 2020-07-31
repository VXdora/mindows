; **********************************************************
;       @file   memory/asm_fault.h
;
;       @brief  例外の割り込みの捕捉
;
;       @author vxdora
;
;       @update mindows03b [New]
; **********************************************************

; C言語での関数のアドレスを取得
extern EmptyHandler

global AsmEmptyHandler
;
;       AsmEmptyHandler
;       @args   :   なし
;       @return :   なし
;       @brief  :   予期しない例外の捕捉
;       @author :   vxdora
;       @update :   mindows03b [New]
;       @extra  :   基本的にはレジスタを退避し，C言語の関数を呼び出す
;                   その後，退避したレジスタを復帰し，カーネルに戻す
;
AsmEmptyHandler:
    push    rax
    push    rcx
    push    rdx
    push    rbp
    push    rsi
    push    rdi
    call    EmptyHandler
    pop     rdi
    pop     rsi
    pop     rbp
    pop     rdx
    pop     rcx
    pop     rax
    iretq

