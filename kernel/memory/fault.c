/*********************************************
 *      @file   memory/fault.c
 *
 *      @brief  例外の割り込みの機能
 *
 *      @update vxdora
 *
 *      @update mindows03b [New]
 ********************************************/

#include <memory.h>
#include <graphics.h>

extern GraphicsInfo graphicsInfo;

void EmptyHandler(void) {
    DrawString(5, 5, (unsigned char *)"Empty Handler", 0xFFFFFF);
    while (1);
}
