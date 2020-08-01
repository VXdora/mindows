/********************************************************
 *      @file   include/device.h
 *
 *      @brief  デバイス管理機能の関数の定義
 *
 *      @author vxdora
 *
 *      @update mindows04b [New]
 *******************************************************/

#ifndef __DEVICE__
#define __DEVICE__

// port define
#define PIC0_ICW1   0x0020
#define PIC0_OCW2   0x0020
#define PIC0_IMR    0x0021
#define PIC0_ICW2   0x0021
#define PIC0_ICW3   0x0021
#define PIC0_ICW4   0x0021
#define PIC1_ICW1   0x00a0
#define PIC1_OCW2   0x00a0
#define PIC1_IMR    0x00a1
#define PIC1_ICW2   0x00a1
#define PIC1_ICW3   0x00a1
#define PIC1_ICW4   0x00a1

#define PIC_EOI     0x20

#define PIT_CTRL    0x0043
#define PIT_CNT0    0x0040

// handler.S
void AsmTimerHandler(void);

// timer.c
void InitTimer(void);

#endif  // __DEVICE__

