/**********************************************
 *      @file   memory/gdtidt.c
 *
 *      @brief  GDT/IDTに関する設定
 *
 *      @author vxdora
 *
 *      @update mindows03a [Fix]
 *********************************************/

#include <memory.h>

extern SEGMENT_DESCRIPTOR   *GDT;
extern GATE_DESCRIPTOR      *IDT;

//
//      InitGdt
//      @arg    :   なし
//      @return :   なし
//      @brief  ;   GDTの初期化
//      @author :   vxdora
//      @update :   mindows03a
//
void InitGdt(void) {
    GDT[0] = 0x0000000000000000;
    GDT[1] = 0x00AF9A000000FFFF;
    GDT[2] = 0x00CF93000000FFFF;
    LoadGdt();
}

//
//      InitIdt
//      @arg    :   なし
//      @return :   なし
//      @brief  ;   IDTの初期化
//      @author :   vxdora
//      @update :   mindows03b [New]
//
void InitIdt(void) {
    unsigned int i;
    for (i = 0; i < 256; i++) {
        IDT[i] = MakeGateDescriptor((unsigned long long)AsmEmptyHandler);
    }
    LoadIdt();
}

//
//      MakeGateDescriptor
//      @arg    :   addr    - Gate Descriptorを作成したいアドレス
//      @return :   アドレスを基に作成されたGate Descriptor
//      @brief  :   Gate Descriptorの作成
//      @author :   vxdora
//      @update :   mindows03b [New]
//
GATE_DESCRIPTOR MakeGateDescriptor(unsigned long long addr) {
    GATE_DESCRIPTOR gateDesc;
    gateDesc.offset1    = (unsigned long long)addr;
    gateDesc.selector   = 0x08;
    gateDesc.type       = 14;
    gateDesc.p          = 1;
    gateDesc.offset2    = (unsigned long long)addr >> 16;
    gateDesc.offset3    = (unsigned long long)addr >> 32;
    return gateDesc;
}

