/**********************************************
 *      @file   include/memory.h
 *
 *      @brief  メモリ管理機能の関数の定義
 *
 *      @author vxdora
 *
 *      @update mindows03a [New]
 *********************************************/

#ifndef __MEMORY__
#define __MEMORY__

typedef unsigned long long SEGMENT_DESCRIPTOR;

// gdtidt.c
void InitGdt(void);

// asm_gdtidt.S
void LoadGdt(void);

#endif  // __MEMORY__


