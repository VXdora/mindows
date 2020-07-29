/***************************************************
 *      @file   graphicstruct.h
 *
 *      @brief  UEFIの画面情報に関するプロトコル
 *
 *      @author VXdora
 *
 *      @update mindows01b
 **************************************************/

#include <types.h>

#ifndef __UEFI_GRAPHICSTRUCT__
#define __UEFI_GRAPHICSTRUCT__

//
//      EFI_GRAPHICS_OUTPUT_PROTOCOL
//      @brief  画面情報に関する構造体の定義
//      @ref    UEFI.Spec 11-9
//      @update mindows01b
//

typedef enum {
    rgb8bit,
    bgr8bit,
    bitmask,
    bltonly,
    formatmax
} EFI_GRAPHICS_PIXEL_FORMAT;

typedef struct EFI_PIXEL_BITMASK {
    UINT32 reserved[4];
} EFI_PIXEL_BITMASK;

//
//      EFI_GRAPHICS_OUTPUT_MODE_INFORMATION
//
typedef struct EFI_GRAPHICS_OUTPUT_MODE_INFORMATION {
    UINT32 Version;
    UINT32 HorizontalResolution;
    UINT32 VerticalResolution;
    EFI_GRAPHICS_PIXEL_FORMAT PixelFormat;
    EFI_PIXEL_BITMASK         PixelInformation;
    UINT32 PixelsPerScanLine;
} EFI_GRAPHICS_OUTPUT_MODE_INFORMATION;


//
//      EFI_GRAPHICS_OUTPUT_PROTOCOL_MODE
//
typedef struct EFI_GRAPHICS_OUTPUT_PROTOCOL_MODE {
    UINT32  MaxMode;
    UINT32  Mode;
    EFI_GRAPHICS_OUTPUT_MODE_INFORMATION *Info;
    UINTN   SizeOfInfo;
    EFI_PHYSICAL_ADDRESS    FrameBufferBase;
    UINTN   FrameBufferSize;
} EFI_GRAPHICS_OUTPUT_PROTOCOL_MODE;


//
//      EFI_GRAPHICS_OUTPUT_PROTOCOL
//
#define EFI_GRAPHICS_OUTPUT_PROTOCOL_GUID \
        { 0x9042A9DE, 0x23DC, 0x4A38, \
                    { 0x96, 0xFB, 0x7A, 0xDE, 0xD0, 0x80, 0x51, 0x6A }}

EFI_GUID gEfiGraphicsOutputProtocolGuid = EFI_GRAPHICS_OUTPUT_PROTOCOL_GUID;

typedef struct EFI_GRAPHICS_OUTPUT_PROTOCOL {
    EFI_STATUS QueryMode;
    EFI_STATUS SetMode;
    EFI_STATUS Blt;
    EFI_GRAPHICS_OUTPUT_PROTOCOL_MODE       *Mode;
} EFI_GRAPHICS_OUTPUT_PROTOCOL;



#endif  // __UEFI_GRAPHICSTRUCT__

