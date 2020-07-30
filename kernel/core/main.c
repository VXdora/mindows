/*******************************************************
 *      @file   main.c
 *
 *      @brief  カーネルのメイン処理
 *
 *      @author vxdora
 *
 *      @update mindows02c [Fix]
 ******************************************************/

#include <graphics.h>

#include "global.h"

int KernelMain() {
    InitGraphics();
    DrawRectangle(0, 0, graphicsInfo->width, graphicsInfo->height, 0x000000);   // 画面を黒で塗りつぶす

    // 描画のテスト
    DrawRectangle(0, 0, 200, 50, 0xFFCC44);
    DrawRectangleVoid(20, 60, 100, 50, 2, 0xCCFF77);
    DrawCircle(100, 100, 30, 0x00FF00);
    DrawLine(100, 50, 50, 100, 1, 0xFFFFFF);
    DrawLine(30, 100, 1, 100, 1, 0xFFFFFF);

    DrawString(5, 170, (unsigned char *)"Hello, World!", 0xFFFFFF);
    // 画面外の挙動
    DrawString(740, 200, (unsigned char *)"Hello World!", 0xFFFFFF);

    while (1);
    return 0;
}
