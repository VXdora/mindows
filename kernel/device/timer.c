/***********************************************
 *      @file   device/timer.c
 *
 *      @brief  タイマーに関する機能
 *
 *      @author vxdora
 *
 *      @update mindows04b [New]
 ***********************************************/

#include <device.h>
#include <util.h>


//
//      InitTimer
//      @arg    :   なし
//      @return :   なし
//      @brief  :   タイマの初期化
//      @author :   vxdora
//      @update :   mindows04b [New]
//
void InitTimer(void) {
    io_out8(PIT_CTRL, 0x34);
    io_out8(PIT_CNT0, 0x9C);
    io_out8(PIT_CNT0, 0x2E);        // 信号の割り込み周期を100Hzに設定
}

unsigned int timerCounter = 0;
//
//      TimerHandler
//      @arg    :   なし
//      @return :   なし
//      @brief  :   タイマの割り込みを捕捉
//      @author :   vxdora
//      @update :   mindows04b [New]
//
void TimerHandler(void) {
    timerCounter++;
    io_out8(PIC0_OCW2, 0x60);
}
