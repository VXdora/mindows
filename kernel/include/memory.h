/**********************************************
 *      @file   include/memory.h
 *
 *      @brief  メモリ管理機能の関数の定義
 *
 *      @author vxdora
 *
 *      @update mindows03b [Fix]
 *********************************************/

#ifndef __MEMORY__
#define __MEMORY__

typedef unsigned long long SEGMENT_DESCRIPTOR;
typedef struct GATE_DESCRIPTOR {
    unsigned short offset1;
    unsigned short selector;
    unsigned short ist  :3;
    unsigned short buf1 :5;
    unsigned short type :4;
    unsigned short buf2 :1;
    unsigned short dpl  :2;
    unsigned short p    :1;
    unsigned short offset2;
    unsigned int   offset3;
    unsigned int   buf3;
} GATE_DESCRIPTOR;

// gdtidt.c
void InitGdt(void);
void InitIdt(void);
GATE_DESCRIPTOR MakeGateDescriptor(unsigned long long addr);

// asm_gdtidt.S
void LoadGdt(void);
void LoadIdt(void);

// asm_fault.S
void AsmEmptyHandler(void);

// fault.c
void EmptyHandler(void);

#endif  // __MEMORY__


