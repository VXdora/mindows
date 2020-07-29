/*************************************************
 *      @file   graphics/init.c
 *
 *      @brief  グラフィックの初期化関連
 *
 *      @author vxdora
 *
 *      @update mindows02b [New]
 ************************************************/
#include <graphics.h>

extern GraphicsInfo *graphicsInfo;

//
//      DrawRectangle
//      @args   :   なし
//      @return :   なし
//      @brief  :   画面情報の取得
//      @author :   vxdora
//      @update :   mindows02b [New]
//
void InitGraphics(void) {
    graphicsInfo = (GraphicsInfo *)GRAPHICS_INFO;
}

