/*******************************************************
 *      @file   main.c
 *
 *      @brief  カーネルのメイン処理
 *
 *      @author vxdora
 *
 *      @update mindows02d [Fix]
 ******************************************************/

#include <graphics.h>
#include <util.h>

#include "global.h"

int KernelMain() {
    unsigned char str[128];

    InitGraphics();
    DrawRectangle(0, 0, graphicsInfo->width, graphicsInfo->height, 0x000000);   // 画面を黒で塗りつぶす

    // 描画のテスト
    DrawRectangle(0, 0, 200, 50, 0xFFCC44);
    DrawRectangleVoid(20, 60, 100, 50, 2, 0xCCFF77);
    DrawCircle(100, 100, 30, 0x00FF00);
    DrawLine(100, 50, 50, 100, 1, 0xFFFFFF);
    DrawLine(30, 100, 1, 100, 1, 0xFFFFFF);

    // sprintfのテスト
    sprintf(str, (unsigned char *)"Hello, World!");
    DrawString(5, 170, str, 0xFFFFFF);

    sprintf(str, (unsigned char *)"%02d", 5);
    DrawString(5, 200, str, 0xFFFFFF);

    sprintf(str, (unsigned char *)"0x%06x", 0x55AA);
    DrawString(5, 230, str, 0xFFFFFF);

    while (1);
    return 0;
}
