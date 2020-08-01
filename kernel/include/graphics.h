/**********************************************
 *      @file   include/graphics.h
 *
 *      @brief  graphicsの定義
 *
 *      @author vxdora
 *
 *      @update mindows04d [Fix]
 *********************************************/

#ifndef __GRAPHICS__
#define __GRAPHICS__

#define GRAPHICS_INFO 0x100000

typedef struct GraphicsInfo {
    unsigned long *vram;
    unsigned short int width;
    unsigned short int height;
} GraphicsInfo;

// init.c
void InitGraphics(void);

// simple.c
void DrawPoint(unsigned int px, unsigned int py, unsigned int color);
void DrawLine(
        unsigned int sx, unsigned int sy,
        signed int width, signed int height,
        unsigned int thick, unsigned int color);
void DrawRectangle(
        unsigned int sx, unsigned int sy,
        unsigned int width, unsigned int height,
        unsigned int color);
void DrawRectangleVoid(
        unsigned int sx, unsigned int sy,
        unsigned int width, unsigned int height,
        unsigned int thick, unsigned int color);
void DrawCircle(
        unsigned int cx, unsigned int cy,
        unsigned int r, unsigned int color);

void DrawChar(
        unsigned int sx, unsigned int sy,
        unsigned char ch, unsigned int color);
void DrawString(
        unsigned int sx, unsigned int sy,
        unsigned char *str, unsigned int color);
#endif  // __GRAPHICS__

