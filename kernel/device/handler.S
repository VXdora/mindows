; **************************************************
;       @file   device/handler
;
;       @brief  デバイスの割り込み
;
;       @author vxdora
;
;       @update mindows04b [New]
; **************************************************

extern TimerHandler

global AsmTimerHandler
;
;       AsmTimerHandler
;       @arg    :   なし
;       @return :   なし
;       @brief  :   タイマの割り込みを捕捉
;       @author :   vxdora
;       @update :   mindows04b [New]
;
AsmTimerHandler:
    push    rax
    push    rcx
    push    rdx
    push    rbx
    push    rbp
    push    rsi
    push    rdi
    call    TimerHandler
    pop     rdi
    pop     rsi
    pop     rbp
    pop     rbx
    pop     rdx
    pop     rcx
    pop     rax
    iretq


