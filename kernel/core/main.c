/*******************************************************
 *      @file   main.c
 *
 *      @brief  カーネルのメイン処理
 *
 *      @author vxdora
 *
 *      @update mindows04b [Fix]
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

    // PICの設定
    io_out8(PIC0_IMR, 0xFE);        // タイマーのみ許可
    io_out8(PIC1_IMR, 0xFF);
    io_sti();

    DrawRectangle(0, 0, graphicsInfo->width, graphicsInfo->height, 0x000000);   // 画面を黒で塗りつぶす

    DrawString(5, 30, (unsigned char *)"Hello, World!", 0xFFFFFF);

    unsigned char str[256];
    while (1) {
        sprintf(str, (unsigned char *)"TIMER : %d", timerCounter);
        DrawRectangle(3, 3, 200, 30, 0x000000);
        DrawString(5, 5, str, 0xFFFFFF);            // チラつく！

    }
    return 0;
}
