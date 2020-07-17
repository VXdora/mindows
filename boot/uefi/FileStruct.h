/***************************************************************
 *      @file   filestruct.h
 *
 *      @brief  ファイル読み込みに関する構造体の定義
 *
 *      @author VXdora
 *
 *      @update mindows01b
 **************************************************************/

#include <types.h>
#include <MemoryStruct.h>

#ifndef __UEFI_FILESTRUCT__
#define __UEFI_FILESTRUCT__

//
//      EFI_LOADED_IMAGE_PROTOCOL
//
#define EFI_LOADED_IMAGE_PROTOCOL_GUID\
    {0x5B1B31A1,0x9562,0x11d2,\
        {0x8E,0x3F,0x00,0xA0,0xC9,0x69,0x72,0x3B}}

EFI_GUID gEfiLoadedImageProtocolGuid = EFI_LOADED_IMAGE_PROTOCOL_GUID;


typedef struct EFI_DEVICE_PATH_PROTOCOL {
    UINT8 reserved[4];
} EFI_DEVICE_PATH_PROTOCOL;     // 使わない

typedef struct EFI_LOADED_IMAGE_PROTOCOL {
    UINT32              Revision;
    EFI_HANDLE          ParentHandle;
    EFI_SYSTEM_TABLE    *SystemTable;

    // Source location of the image
    EFI_HANDLE          DeviceHandle;
    EFI_DEVICE_PATH_PROTOCOL *FilePath;
    VOID                *Reserved;

    // Image's load options
    UINT32              LoadOptionSize;
    VOID                *LoadOptions;

    // Location where image was loaded
    VOID                *ImageBase;
    UINT64              ImageSize;
    EFI_MEMORY_TYPE     ImageCodeType;
    EFI_MEMORY_TYPE     ImageDataType;
    EFI_STATUS          Unload;
} EFI_LOADED_IMAGE_PROTOCOL;

//
//      EFI_TIME
//      ここしか使わない
//
typedef struct EFI_TIME {
    UINT8 reserved[16];
} EFI_TIME;


//
//      EFI_FILE_INFO
//
#define EFI_FILE_READ_ONLY  0x0000000000000001
#define EFI_FILE_HIDDEN     0x0000000000000002
#define EFI_FILE_SYSTEM     0x0000000000000004
#define EFI_FILE_RESERVED   0x0000000000000008
#define EFI_FILE_DIRECTORY  0x0000000000000010
#define EFI_FILE_ARCHIVE    0x0000000000000020
#define EFI_FILE_VALID_ATTR 0x0000000000000037

#define EFI_FILE_INFO_GUID \
    { 0x09576E92, 0x6D3F, 0x11D2, \
        {0x8E, 0x39, 0x00, 0xA0, 0xC9, 0x69, 0x72, 0x3B }}

GUID gEfiFileInfoGuid = EFI_FILE_INFO_GUID;

typedef struct EFI_FILE_INFO {
    UINT64      Size;
    UINT64      FileSize;
    UINT64      PhysicalSize;
    EFI_TIME    efiTime[3];
    UINT64      Attribute;
    CHAR16      FileName[];
} EFI_FILE_INFO;

//
//      EFI_FILE_PROTOCOL
//

#define EFI_FILE_MODE_READ      0x0000000000000001
#define EFI_FILE_MODE_WRITE     0x0000000000000002
#define EFI_FILE_MODE_CREATE    0x8000000000000000

typedef struct EFI_FILE_PROTOCOL {
    UINT64  Revision;
    EFI_STATUS  (*Open) (
            struct EFI_FILE_PROTOCOL *This,
            struct EFI_FILE_PROTOCOL **NewHandle,
            CHAR16 *FileName,
            UINT64 OpenMode,
            UINT64 Attributes
    );
    EFI_STATUS  (*Close) (
            struct EFI_FILE_PROTOCOL *This
    );
    EFI_STATUS  Delete;
    EFI_STATUS  (*Read) (
            struct EFI_FILE_PROTOCOL *This,
            UINTN *BufferSize,
            VOID  *Buffer
    );
    EFI_STATUS  Write;
    EFI_STATUS  GetPosition;
    EFI_STATUS  (*SetPosition) (
            struct EFI_FILE_PROTOCOL *This,
            UINT64 Position
    );
    EFI_STATUS  (*GetInfo) (
            struct EFI_FILE_PROTOCOL *This,
            EFI_GUID    *InformationType,
            UINTN       *BufferSize,
            VOID        *Buffer
    );
    EFI_STATUS  SetInfo;
    EFI_STATUS  Flush;
    EFI_STATUS  OpenEx;
    EFI_STATUS  ReadEx;
    EFI_STATUS  WriteEx;
    EFI_STATUS  FlushEx;
} EFI_FILE_PROTOCOL;

//
//      EFI_SIMPlE_FILE_SYSTEM_PROTOCOL
//
#define EFI_SIMPLE_FILE_SYSTEM_PROTOCOL_GUID \
    {0x0964e5b22,0x6459,0x11d2,\
        {0x8e,0x39,0x00,0xa0,0xc9,0x69,0x72,0x3b}}

EFI_GUID gEfiSimpleFileSystemProtocolGuid = EFI_SIMPLE_FILE_SYSTEM_PROTOCOL_GUID;

typedef struct EFI_SIMPLE_FILE_SYSTEM_PROTOCOL {
    UINT64  Revision;
    EFI_STATUS (*OpenVolume) (
            struct EFI_SIMPLE_FILE_SYSTEM_PROTOCOL *This,
            struct EFI_FILE_PROTOCOL               **Root
    );
} EFI_SIMPLE_FILE_SYSTEM_PROTOCOL;


#endif  // __UEFI_FILESTRUCT__

