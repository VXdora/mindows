/************************************************
 *          @file   device/mouse.c
 *
 *          @brief  マウスに関する機能の設定
 *
 *          @author vxdora
 *
 *          @update mindows04d [New]
 ***********************************************/

#include <device.h>
#include <graphics.h>
#include <util.h>

extern GraphicsInfo *graphicsInfo;

static unsigned char step = 0;
static signed char mouseData[3];
static MouseInfo mouseInfo;

//
//      InitMouse
//      @args   :   なし
//      @return :   なし
//      @brief  :   マウスの初期化
//      @author :   vxdora
//      @update :   mindows04d [New]
//
void InitMouse(void) {
    // マウスの初期化
    WaitKeyboardSendReady();
    io_out8(0x64, 0xD4);
    WaitKeyboardSendReady();
    io_out8(0x60, 0xF4);

    // 内部データのクリア
    step = 0;
    mouseData[0] = 0x00;
    mouseData[1] = 0x00;
    mouseData[2] = 0x00;

    mouseInfo.bt = 0;
    mouseInfo.mx = 200;
    mouseInfo.my = 200;

    DrawMouse();
}

//
//      MouseHandler
//      @args   :   なし
//      @return :   なし
//      @brief  :   マウスの割り込みの捕捉
//      @author :   vxdora
//      @update :   mindows04d [New]
//
void MouseHandler(void) {
    unsigned char data;
    data = io_in8(0x60);
    PushMouseData(data);
    io_out8(PIC1_OCW2, 0x64);
    io_out8(PIC0_OCW2, 0x62);       // スレーブPIC完了通知
}

// マウスの形
static unsigned char cursor[18 * 12] = {
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    1, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    1, 2, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0,
    1, 2, 2, 2, 1, 0, 0, 0, 0, 0, 0, 0,
    1, 2, 2, 2, 2, 1, 0, 0, 0, 0, 0, 0,
    1, 2, 2, 2, 2, 2, 1, 0, 0, 0, 0, 0,
    1, 2, 2, 2, 2, 2, 2, 1, 0, 0, 0, 0,
    1, 2, 2, 2, 2, 2, 2, 2, 1, 0, 0, 0,
    1, 2, 2, 2, 2, 2, 2, 2, 2, 1, 0, 0,
    1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 0,
    1, 2, 2, 2, 2, 2, 2, 1, 1, 1, 1, 1,
    1, 2, 2, 2, 1, 2, 2, 1, 0, 0, 0, 0,
    1, 2, 2, 1, 0, 1, 2, 2, 1, 0, 0, 0,
    1, 2, 1, 0, 0, 1, 2, 2, 1, 0, 0, 0,
    1, 1, 0, 0, 0, 0, 1, 2, 2, 1, 0, 0,
    0, 0, 0, 0, 0, 0, 1, 2, 2, 1, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0 };


//
//      PushMouseData
//      @arg    :   data    - 送られてきたデータ
//      @return :   なし
//      @brief  :   何バイト目まで送られてきたかを判定，
//                  必要があれば描画
//      @author :   vxdora
//      @update :   mindows04d [New]
//
void PushMouseData(unsigned char data) {
    mouseData[step] = data;
    if (step == 2) {            // 3バイト目まで来た
        DrawRectangle(mouseInfo.mx, mouseInfo.my, 12, 18, 0x000000);
        DecodeMouse();
        DrawMouse();
        step = 0;
    }
    else {
        step++;
    }
}

//
//      DecodeMouse
//      @arg    :   なし
//      @return :   なし
//      @brief  :   送られてきた情報を基にマウスの座標を更新
//      @author :   vxdora
//      @update :   mindows04d [New]
//
void DecodeMouse(void) {
    if (mouseInfo.mx + mouseData[1] +10 < graphicsInfo->width)
        mouseInfo.mx += mouseData[1];

    if (mouseInfo.my -mouseData[2] +20 < graphicsInfo->height)
        mouseInfo.my -= mouseData[2];
}

//
//      DrawMouse
//      @arg    :   なし
//      @return :   なし
//      @brief  :   マウスを描く
//      @author :   vxdora
//      @update :   mindows04d [New]
//
void DrawMouse(void) {
    unsigned int x, y;
    for (y = 0; y < 18; y++) {
        for (x = 0; x < 12; x++) {
            switch(cursor[y *12 +x]) {
            case 0:
                break;
            case 1:
                DrawPoint(mouseInfo.mx +x, mouseInfo.my +y, 0x000000);
                break;
            case 2:
                DrawPoint(mouseInfo.mx +x, mouseInfo.my +y, 0xFFFFFF);
                break;
            }
        }
    }
}


