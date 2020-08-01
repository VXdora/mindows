; **************************************************
;       @file   device/handler
;
;       @brief  デバイスの割り込み
;
;       @author vxdora
;
;       @update mindows04d [Fix]
; **************************************************

extern TimerHandler
extern KeyboardHandler
extern MouseHandler

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

global AsmKeyboardHandler
;
;       AsmKeyboardHandler
;       @arg    :   なし
;       @return :   なし
;       @brief  :   キーボードの割り込みを捕捉
;       @author :   vxdora
;       @update :   mindows04c
;
AsmKeyboardHandler:
    push    rax
    push    rcx
    push    rdx
    push    rbx
    push    rbp
    push    rsi
    push    rdi
    call    KeyboardHandler
    pop     rdi
    pop     rsi
    pop     rbp
    pop     rbx
    pop     rdx
    pop     rcx
    pop     rax
    iretq

global AsmMouseHandler
;
;       AsmMouseHandler
;       @arg    :   なし
;       @return :   なし
;       @brief  :   マウスの割り込みを捕捉
;       @author :   vxdora
;       @update :   mindows04d [New]
;
AsmMouseHandler:
    push    rax
    push    rcx
    push    rdx
    push    rbx
    push    rbp
    push    rsi
    push    rdi
    call    MouseHandler
    pop     rdi
    pop     rsi
    pop     rbp
    pop     rbx
    pop     rdx
    pop     rcx
    pop     rax
    iretq
