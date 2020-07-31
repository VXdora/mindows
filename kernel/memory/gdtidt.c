/**********************************************
 *      @file   memory/gdtidt.c
 *
 *      @brief  GDT/IDTに関する設定
 *
 *      @author vxdora
 *
 *      @update mindows03a [New]
 *********************************************/

#include <memory.h>

extern SEGMENT_DESCRIPTOR *GDT;

//
//      InitGdt
//      @arg    :   なし
//      @return :   なし
//      @brief  ;   GDTの初期化
//      @author :   vxdora
//      @update :   mindows03a [New]
//
void InitGdt(void) {
    GDT[0] = 0x0000000000000000;
    GDT[1] = 0x00AF9A000000FFFF;
    GDT[2] = 0x00CF93000000FFFF;
    LoadGdt();
}

