/**********************************************
 *      @file   memory/gdtidt.c
 *
 *      @brief  GDT/IDTに関する設定
 *
 *      @author vxdora
 *
 *      @update mindows04d [Fix]
 *********************************************/

#include <memory.h>
#include <device.h>
#include <util.h>

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
//      @update :   mindows04d [Fix]
//
void InitIdt(void) {
    unsigned int i;
    for (i = 0; i < 256; i++) {
        IDT[i] = MakeGateDescriptor((unsigned long long)AsmEmptyHandler);
    }
	IDT[0x00] = MakeGateDescriptor((unsigned long long)AsmDeHandler);
    IDT[0x01] = MakeGateDescriptor((unsigned long long)AsmDbHandler);
    IDT[0x02] = MakeGateDescriptor((unsigned long long)AsmNmiHandler);
    IDT[0x03] = MakeGateDescriptor((unsigned long long)AsmBpHandler);
    IDT[0x04] = MakeGateDescriptor((unsigned long long)AsmOfHandler);
    IDT[0x05] = MakeGateDescriptor((unsigned long long)AsmBrHandler);
    IDT[0x06] = MakeGateDescriptor((unsigned long long)AsmUdHandler);
    IDT[0x07] = MakeGateDescriptor((unsigned long long)AsmNmHandler);
    IDT[0x08] = MakeGateDescriptor((unsigned long long)AsmDfHandler);
    IDT[0x0A] = MakeGateDescriptor((unsigned long long)AsmTsHandler);
    IDT[0x0B] = MakeGateDescriptor((unsigned long long)AsmNpHandler);
    IDT[0x0C] = MakeGateDescriptor((unsigned long long)AsmSsHandler);
    IDT[0x0D] = MakeGateDescriptor((unsigned long long)AsmGpHandler);
    IDT[0x0E] = MakeGateDescriptor((unsigned long long)AsmPfHandler);
    IDT[0x10] = MakeGateDescriptor((unsigned long long)AsmMfHandler);
    IDT[0x11] = MakeGateDescriptor((unsigned long long)AsmAcHandler);
    IDT[0x12] = MakeGateDescriptor((unsigned long long)AsmMcHandler);
    IDT[0x13] = MakeGateDescriptor((unsigned long long)AsmXmHandler);

    IDT[0x20] = MakeGateDescriptor((unsigned long long)AsmTimerHandler);
    IDT[0x21] = MakeGateDescriptor((unsigned long long)AsmKeyboardHandler);
    IDT[0x2C] = MakeGateDescriptor((unsigned long long)AsmMouseHandler);

    LoadIdt();
}

//
//      MakeGateDescriptor
//      @arg    :   addr    - Gate Descriptorを作成したいアドレス
//      @return :   アドレスを基に作成されたGate Descriptor
//      @brief  :   Gate Descriptorの作成
//      @author :   vxdora
//      @update :   mindows03b
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

//
//      InitPic
//      @arg    :   なし
//      @return :   なし
//      @brief  :   PICの初期化
//      @author :   vxdora
//      @update :   mindows04b [New]
//
void InitPic(void) {
    io_out8(PIC0_IMR, 0xFF);
    io_out8(PIC1_IMR, 0xFF);        // すべての割り込みを不許可

    io_out8(PIC0_ICW1, 0x11);
    io_out8(PIC0_ICW2, 0x20);
    io_out8(PIC0_ICW3, 1 << 2);
    io_out8(PIC0_ICW4, 0x01);       // マスターPICの設定

    io_out8(PIC1_ICW1, 0x11);
    io_out8(PIC1_ICW2, 0x28);
    io_out8(PIC1_ICW3, 2);
    io_out8(PIC1_ICW4, 0x01);       // スレーブPICの設定
}
