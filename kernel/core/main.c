/*******************************************************
 *      @file   main.c
 *
 *      @brief  カーネルのメイン処理
 *
 *      @author vxdora
 *
 *      @update mindows03c
 ******************************************************/

#include <graphics.h>
#include <memory.h>
#include <util.h>

#include "global.h"

int KernelMain() {
    InitGraphics();
    InitGdt();
    InitIdt();
    DrawRectangle(0, 0, graphicsInfo->width, graphicsInfo->height, 0x000000);   // 画面を黒で塗りつぶす

    // 0除算を発生させて割り込みを確認
    // DE Handlerの表示が出たらOK
    int x = 3 / 0;

    DrawString(5, 30, (unsigned char *)"Hello, World!", 0xFFFFFF);

    while (1);
    return 0;
}
