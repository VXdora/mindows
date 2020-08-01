/*************************************************
 *      @file   device/keyboard.c
 *
 *      @brief  キーボードの機能
 *
 *      @author vxdora
 *
 *      @update mindows04c [New]
 ************************************************/

#include <device.h>
#include <graphics.h>
#include <util.h>

//
//      InitKeyboard
//      @args   :   なし
//      @return :   なし
//      @brief  :   キーボードの初期化
//      @author :   vxdora
//      @update :   mindows04c [New]
//
void InitKeyboard(void) {
    WaitKeyboardSendReady();
    io_out8(0x0064, 0x60);
    WaitKeyboardSendReady();
    io_out8(0x0060, 0x47);
}

//
//      WaitKeyboardSendReady
//      @args   :   なし
//      @return :   なし
//      @brief  :   KBC内に残っているデータがないか確認
//      @author :   vxdora
//      @update :   mindows04c [New]
//
void WaitKeyboardSendReady(void) {
    while (1) {
        if ((io_in8(0x0064) & 0x02) == 0) {
            break;
        }
    }
}

//
//      KeyboardHandler
//      @args   :   なし
//      @return :   なし
//      @brief  :   キーボードの割り込みの捕捉
//      @author :   vxdora
//      @update :   mindows04c [New]
//
void KeyboardHandler(void) {
    unsigned char data;
    unsigned char str[256];
    data = io_in8(0x60);
    io_out8(PIC0_OCW2, 0x61);

    sprintf(str, (unsigned char *)"KeyCode : %x", data);
    DrawRectangle(3, 3, 150, 30, 0x000000);
    DrawString(5, 5, str, 0xFFFFFF);
}
