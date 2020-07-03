/****************************************************
 *      @file   main.c
 *
 *      @brief  UEFIによるカーネルまでのブート
 *
 *      @author VXdora
 *
 *      @update mindows01a [New]
 ***************************************************/

#include <types.h>
#include <systemstruct.h>
#include <iostruct.h>

//
//      EfiMain
//      @arg    EFI_HANDLE          ImageHandle
//              EFI_SYSTEM_TABLE    *SystemTable
//      @ret    EFI_STATUS      0...Success
//      @brief  UEFIで起動し，文字列を表示
//      @update mindows01a [New]
//

EFI_STATUS EfiMain(EFI_HANDLE ImageHandle, EFI_SYSTEM_TABLE *SystemTable) {
    EFI_STATUS Status;

    Status = SystemTable->ConOut->ClearScreen(SystemTable->ConOut);
    Status = SystemTable->ConOut->OutputString(SystemTable->ConOut, L"Hello, World!\r\n");

    while (1) ;
    return EFI_SUCCESS;
}
