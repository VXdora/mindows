/*******************************************************
 *      @file   main.c
 *
 *      @brief  カーネルのメイン処理
 *
 *      @author vxdora
 *
 *      @update mindows04c [Fix]
 ******************************************************/

#include <device.h>
#include <graphics.h>
#include <memory.h>
#include <util.h>

#include "global.h"

extern unsigned int timerCounter;

int KernelMain() {
    InitGraphics();
    InitGdt();
    InitIdt();
    InitPic();

    InitTimer();
    InitKeyboard();

    // PICの設定
    io_out8(PIC0_IMR, 0xFC);        // タイマー，キーボードを許可
    io_out8(PIC1_IMR, 0xFF);
    io_sti();

    DrawRectangle(0, 0, graphicsInfo->width, graphicsInfo->height, 0x000000);   // 画面を黒で塗りつぶす

    DrawString(5, 30, (unsigned char *)"Hello, World!", 0xFFFFFF);

    while (1) {
        // メインループ
    }
    return 0;
}
