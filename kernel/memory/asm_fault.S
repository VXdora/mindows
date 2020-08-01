; **********************************************************
;       @file   memory/asm_fault.h
;
;       @brief  例外の割り込みの捕捉
;
;       @author vxdora
;
;       @update mindows03c [Fix]
; **********************************************************

; C言語での関数のアドレスを取得
extern EmptyHandler
extern DeHandler
extern DbHandler
extern NmiHandler
extern BpHandler
extern OfHandler
extern BrHandler
extern UdHandler
extern NmHandler
extern DfHandler
extern TsHandler
extern NpHandler
extern SsHandler
extern GpHandler
extern PfHandler
extern MfHandler
extern AcHandler
extern McHandler
extern XmHandler

global AsmEmptyHandler
;
;       AsmEmptyHandler
;       @args   :   なし
;       @return :   なし
;       @brief  :   予期しない例外の捕捉
;       @author :   vxdora
;       @update :   mindows03b
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

global AsmDeHandler
; 除算エラー（0除算）
AsmDeHandler:
    push    rax
    push    rcx
    push    rdx
    push    rbp
    push    rsi
    push    rdi
    call    DeHandler
    pop     rdi
    pop     rsi
    pop     rbp
    pop     rdx
    pop     rcx
    pop     rax
    iretq

global AsmDbHandler
; デバッグエラー
AsmDbHandler:
    push    rax
    push    rcx
    push    rdx
    push    rbp
    push    rsi
    push    rdi
    call    DbHandler
    pop     rdi
    pop     rsi
    pop     rbp
    pop     rdx
    pop     rcx
    pop     rax
    iretq

global AsmNmiHandler
; マスク不可能な外部割込み
AsmNmiHandler:
    push    rax
    push    rcx
    push    rdx
    push    rbp
    push    rsi
    push    rdi
    call    NmiHandler
    pop     rdi
    pop     rsi
    pop     rbp
    pop     rdx
    pop     rcx
    pop     rax
    iretq

global AsmBpHandler
; ブレークポイント
AsmBpHandler:
    push    rax
    push    rcx
    push    rdx
    push    rbp
    push    rsi
    push    rdi
    call    BpHandler
    pop     rdi
    pop     rsi
    pop     rbp
    pop     rdx
    pop     rcx
    pop     rax
    iretq

global AsmOfHandler
; オーバーフロー
AsmOfHandler:
    push    rax
    push    rcx
    push    rdx
    push    rbp
    push    rsi
    push    rdi
    call    OfHandler
    pop     rdi
    pop     rsi
    pop     rbp
    pop     rdx
    pop     rcx
    pop     rax
    iretq

global AsmBrHandler
; BOUND範囲外
AsmBrHandler:
    push    rax
    push    rcx
    push    rdx
    push    rbp
    push    rsi
    push    rdi
    call    BrHandler
    pop     rdi
    pop     rsi
    pop     rbp
    pop     rdx
    pop     rcx
    pop     rax
    iretq

global AsmUdHandler
; 未定義のオペコード
AsmUdHandler:
    push    rax
    push    rcx
    push    rdx
    push    rbp
    push    rsi
    push    rdi
    call    UdHandler
    pop     rdi
    pop     rsi
    pop     rbp
    pop     rdx
    pop     rcx
    pop     rax
    iretq

global AsmNmHandler
; デバイス使用不可（数値演算コプロセッサなし）
AsmNmHandler:
    push    rax
    push    rcx
    push    rdx
    push    rbp
    push    rsi
    push    rdi
    call    NmHandler
    pop     rdi
    pop     rsi
    pop     rbp
    pop     rdx
    pop     rcx
    pop     rax
    iretq

global AsmDfHandler
; ダブルフォルト
AsmDfHandler:
    push    rax
    push    rcx
    push    rdx
    push    rbp
    push    rsi
    push    rdi
    call    DfHandler
    pop     rdi
    pop     rsi
    pop     rbp
    pop     rdx
    pop     rcx
    pop     rax
    iretq

global AsmTsHandler
; 無効なTSS
AsmTsHandler:
    push    rax
    push    rcx
    push    rdx
    push    rbp
    push    rsi
    push    rdi
    call    TsHandler
    pop     rdi
    pop     rsi
    pop     rbp
    pop     rdx
    pop     rcx
    pop     rax
    iretq

global AsmNpHandler
; セグメント不在
AsmNpHandler:
    push    rax
    push    rcx
    push    rdx
    push    rbp
    push    rsi
    push    rdi
    call    NpHandler
    pop     rdi
    pop     rsi
    pop     rbp
    pop     rdx
    pop     rcx
    pop     rax
    iretq

global AsmSsHandler
; スタックセグメントのフォルト
AsmSsHandler:
    push    rax
    push    rcx
    push    rdx
    push    rbp
    push    rsi
    push    rdi
    call    SsHandler
    pop     rdi
    pop     rsi
    pop     rbp
    pop     rdx
    pop     rcx
    pop     rax
    iretq

global AsmGpHandler
; 一般保護
AsmGpHandler:
    push    rax
    push    rcx
    push    rdx
    push    rbp
    push    rsi
    push    rdi
    call    GpHandler
    pop     rdi
    pop     rsi
    pop     rbp
    pop     rdx
    pop     rcx
    pop     rax
    iretq

global AsmPfHandler
; ページフォルト
AsmPfHandler:
    push    rax
    push    rcx
    push    rdx
    push    rbp
    push    rsi
    push    rdi
    call    PfHandler
    pop     rdi
    pop     rsi
    pop     rbp
    pop     rdx
    pop     rcx
    pop     rax
    iretq

global AsmMfHandler
; コプロセッサ・セグメント・オーバーラン
AsmMfHandler:
    push    rax
    push    rcx
    push    rdx
    push    rbp
    push    rsi
    push    rdi
    call    MfHandler
    pop     rdi
    pop     rsi
    pop     rbp
    pop     rdx
    pop     rcx
    pop     rax
    iretq

global AsmAcHandler
; アライメント・チェック
AsmAcHandler:
    push    rax
    push    rcx
    push    rdx
    push    rbp
    push    rsi
    push    rdi
    call    AcHandler
    pop     rdi
    pop     rsi
    pop     rbp
    pop     rdx
    pop     rcx
    pop     rax
    iretq

global AsmMcHandler
; マシンチェック
AsmMcHandler:
    push    rax
    push    rcx
    push    rdx
    push    rbp
    push    rsi
    push    rdi
    call    McHandler
    pop     rdi
    pop     rsi
    pop     rbp
    pop     rdx
    pop     rcx
    pop     rax
    iretq

global AsmXmHandler
; SIMD浮動小数点例外
AsmXmHandler:
    push    rax
    push    rcx
    push    rdx
    push    rbp
    push    rsi
    push    rdi
    call    XmHandler
    pop     rdi
    pop     rsi
    pop     rbp
    pop     rdx
    pop     rcx
    pop     rax
    iretq
