/************************************************************
 *      @file   iostruct.h
 *
 *      @brief  UEFIの入出力に関する構造体の定義
 *
 *      @author VXdora
 *
 *      @update mindows01a
 ***********************************************************/

#include <types.h>

#ifndef __UEFI_IOSTRUCT__
#define __UEFI_IOSTRUCT__

//
//      EFI_SIMPLE_TEXT_INPUT_PROTOCOL
//      @brief  UEFIの入力に関する構造体の定義
//      @ref    UEFI.Spec 11-3
//      @update mindows01a
//

typedef struct EFI_SIMPLE_TEXT_INPUT_PROTOCOL {
    EFI_STATUS  Reset;
    EFI_STATUS  ReadKeyStroke;
    EFI_EVENT   WaitForKey;
} EFI_SIMPLE_TEXT_INPUT_PROTOCOL;


//
//      EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL
//      @brief  UEFIの画面出力（文字ベース）に関する構造体の定義
//      @ref    UEFI.Spec 11-3
//      @update mindows01a
//

typedef struct EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL {
    EFI_STATUS  Reset;
    EFI_STATUS  (*OutputString) (
            struct EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL  *This,
            CHAR16                                  *String
    );

    EFI_STATUS  TestString;
    EFI_STATUS  QueryMode;
    EFI_STATUS  SetMode;
    EFI_STATUS  SetAttribute;

    EFI_STATUS  (*ClearScreen) (
            struct EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL  *This
    );

    EFI_STATUS  SetCursorPosition;
    EFI_STATUS  EnableCursor;
    struct SIMPLE_TEXT_OUTPUT_MODE {
        INT32   reserve[5];
        BOOLEAN CursorVisible;
    } *Mode;
} EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL;


#endif  // __UEFI_IOSTRUCT__

