/*******************************************************
 *      @file   main.c
 *
 *      @brief  カーネルのメイン処理
 *
 *      @author vxdora
 *
 *      @update mindows03a [Fix]
 ******************************************************/

#include <graphics.h>
#include <memory.h>
#include <util.h>

#include "global.h"

int KernelMain() {
    InitGraphics();
    InitGdt();

    DrawRectangle(0, 0, graphicsInfo->width, graphicsInfo->height, 0x000000);   // 画面を黒で塗りつぶす
    DrawString(5, 5, (unsigned char *)"Hello, World!", 0xFFFFFF);

    while (1);
    return 0;
}
