/***********************************************
 *      @file   graphics/simple.c
 *
 *      @brief  基本図形の描画
 *
 *      @author vxdora
 *
 *      @update mindows02c
 **********************************************/
#include <graphics.h>

extern GraphicsInfo *graphicsInfo;

//
//      DrawRectangle
//      @args   :   sx      - 開始地点のx座標
//                  sy      - 開始地点のy座標
//                  width   - x方向の大きさ
//                  height  - y方向の大きさ
//                  thick   - 線の太さ(予定)
//                  color   - 描画する図形の色
//      @return :   なし
//      @brief  :   直線の描画(線の太さは1のみ)
//      @author :   vxdora
//      @update :   mindows02b
//
void DrawLine(
        unsigned int sx, unsigned int sy,
        signed int width, signed int height,
        unsigned int thick, unsigned int color) {

    unsigned int x, y;
    unsigned int ex = sx +width, ey = sy +height;       // 終了地点
    unsigned int tmp;

    // 開始地点より終了地点のほうが小さい時は入れ替える
    if (ex < sx) {
        tmp = ex;
        ex = sx;
        sx = tmp;

        tmp = ey;
        ey = sy;
        sy = tmp;
    }

    // width == 0のときは0除算が発生するため，例外
    if (width == 0) {
        x = sx;
        for (y = sy; y < ey; y++) {
            if (x < graphicsInfo->width && y < graphicsInfo->height)    // 画面内なら描画
                graphicsInfo->vram[y * graphicsInfo->width + x] = color;
        }
    }

    // y = (height / width) * (x - sx) + sy
    else {
        unsigned int by = sy;
        for (x = sx; x <= ex; x++) {
            y = (unsigned int)(((float)height / (float)width) * (x - sx) +sy);

            // 隙間を描画
            if (y - by > 0) {
                for (tmp = by +1; tmp < y; tmp++) {
                    if (x < graphicsInfo->width && y < graphicsInfo->height)
                        graphicsInfo->vram[tmp * graphicsInfo->width + x] = color;
                }
            }
            else if ((signed int)(y - by) < 0) {
                for (tmp = y +1; tmp < by; tmp++) {
                    if (x < graphicsInfo->width && y < graphicsInfo->height)
                        graphicsInfo->vram[tmp * graphicsInfo->width + x] = color;
                }
            }

            if (x < graphicsInfo->width && y < graphicsInfo->height)    // 画面内なら描画
                graphicsInfo->vram[y * graphicsInfo->width + x] = color;
            by = y;
        }
    }
}


//
//      DrawRectangle
//      @args   :   sx      - 開始地点のx座標
//                  sy      - 開始地点のy座標
//                  width   - 描画する図形の幅
//                  height  - 描画する図形の高さ
//                  color   - 描画する図形の色
//      @return :   なし
//      @brief  :   中身が塗りつぶしてある四角形の描画
//      @author :   vxdora
//      @update :   mindows02b
//
void DrawRectangle(
        unsigned int sx, unsigned int sy,
        unsigned int width, unsigned int height,
        unsigned int color) {

    unsigned int x, y;
    for (y = sy; y < sy +height; y++) {
        for (x = sx; x < sx +width; x++) {
            if (x < graphicsInfo->width && y < graphicsInfo->height)      // 画面内なら描画
                graphicsInfo->vram[y * graphicsInfo->width + x] = color;
        }
    }
}

//
//      DrawRectangleVoid
//      @args   :   sx      - 開始地点のx座標
//                  sy      - 開始地点のy座標
//                  width   - 描画する図形の幅
//                  height  - 描画する図形の高さ
//                  thick   - 線の太さ
//                  color   - 描画する図形の色
//      @return :   なし
//      @brief  :   中身が塗りつぶしてない四角形の描画
//      @author :   vxdora
//      @update :   mindows02b
//
void DrawRectangleVoid(
        unsigned int sx, unsigned int sy,
        unsigned int width, unsigned int height,
        unsigned int thick, unsigned int color) {

    unsigned int x, y;
    // 上側を描画
    for (y = sy; y < sy +thick; y++) {
        for (x = sx; x < sx +width; x++) {
            if (x < graphicsInfo->width && y < graphicsInfo->height)      // 画面内なら描画
                graphicsInfo->vram[y * graphicsInfo->width + x] = color;
        }
    }
    // 下側を描画
    for (y = sy +height -thick; y < sy +height; y++) {
        for (x = sx; x < sx +width; x++) {
            if (x < graphicsInfo->width && y < graphicsInfo->height)      // 画面内なら描画
                graphicsInfo->vram[y * graphicsInfo->width + x] = color;
        }
    }
    // 左側を描画
    for (y = sy; y < sy +height; y++) {
        for (x = sx; x < sx +thick; x++) {
            if (x < graphicsInfo->width && y < graphicsInfo->height)      // 画面内なら描画
                graphicsInfo->vram[y * graphicsInfo->width + x] = color;
        }
    }
    // 右側を描画
    for (y = sy; y < sy +height; y++) {
        for (x = sx +width -thick; x < sx +width; x++) {
            if (x < graphicsInfo->width && y < graphicsInfo->height)      // 画面内なら描画
                graphicsInfo->vram[y * graphicsInfo->width + x] = color;
        }
    }
}

//
//      DrawCircle
//      @args   :   cx      - 描画する円の中心x座標
//                  cy      - 描画する円の中心y座標
//                  r       - 描画する円の半径
//                  color   - 描画する図形の色
//      @return :   なし
//      @brief  :   中身の塗りつぶされた円の描画
//      @author :   vxdora
//      @update :   mindows02b
//
void DrawCircle(unsigned int cx, unsigned int cy, unsigned int r, unsigned int color) {
    unsigned int x, y;
    for (y = cy -r; y < cy +r; y++) {
        for (x = cx -r; x < cx +r; x++) {
            if (x < graphicsInfo->width && y < graphicsInfo->height     // 画面内なら描画
                    && (cx -x)*(cx -x) + (cy -y)*(cy -y) < r*r )        // x*x + y*y <= r*r
                graphicsInfo->vram[y * graphicsInfo->width +x] = color;
        }
    }
}

// フォントの読み込み
#include "font.h"

//
//      DrawCharacter
//      @args   :   sx      - 描画する文字のx座標
//                  sy      - 描画する文字のy座標
//                  ch      - 描画する文字
//                  color   - 描画する文字の色
//      @return :   なし
//      @brief  :   (sx, sy)から文字を描画する（英数字のみ）
//      @author :   vxdora
//      @update :   mindows02c
//
void DrawChar(unsigned int sx, unsigned int sy, unsigned char ch, unsigned int color) {
    unsigned int x, y, idx, flag;

    for (y = 0; y < 16; y++) {
        idx = _fonts[ch - 0x20][y];         // y行目を取得
        flag = 0x80;

        for (x = 0; x < 8; x++) {
            if ((sx + x) < graphicsInfo->width && (sy + y) < graphicsInfo->height      // 画面内
                    && (idx & flag)) {                                                  // 1ならば
                graphicsInfo->vram[(sy + y) * graphicsInfo->width + (sx + x)] = color;
            }
            flag = flag >> 1;
        }
    }
}

//
//      DrawString
//      @args   :   sx      - 描画する文字のx座標
//                  sy      - 描画する文字のy座標
//                  str     - 描画する文字列
//                  color   - 描画する文字の色
//      @return :   なし
//      @brief  :   (sx, sy)から文字列を描画（英数字のみ）
//      @author :   vxdora
//      @update :   mindows02c
//
void DrawString(unsigned int sx, unsigned int sy, unsigned char *str, unsigned int color) {
    unsigned int i = 0;
    do {
        DrawChar(sx + i*9, sy, *str, color);
        i++;
        str++;
    } while(*str);
}
