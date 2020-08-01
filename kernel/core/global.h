/********************************************
 *      @file   global.h
 *
 *      @brief  グローバル変数
 *
 *      @author vxdora
 *
 *      @update mindows03b
 *******************************************/

// graphics
GraphicsInfo *graphicsInfo;

// memory
SEGMENT_DESCRIPTOR  *GDT = (SEGMENT_DESCRIPTOR *)0x900;
GATE_DESCRIPTOR     *IDT = (GATE_DESCRIPTOR *)0x1000;

