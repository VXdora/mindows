/****************************************************
 *      @file   main.c
 *
 *      @brief  UEFIによるカーネルまでのブート
 *
 *      @author VXdora
 *
 *      @update mindows02a [Fix]
 ***************************************************/

#include <types.h>

#include <SystemStruct.h>
#include <FileStruct.h>
#include <GraphicStruct.h>
#include <IOStruct.h>
#include <MemoryStruct.h>

#define GRAPHIC_INFO    0x100000
#define KERNEL_ENTRY    0x110000

// structure
typedef struct GraphicInfo {
    unsigned int    *vram;
    unsigned short int  width;
    unsigned short int  height;
} GraphicInfo;                  // 画面描画に関する構造体

// 文字列表示を関数化
EFI_SYSTEM_TABLE *gST = NULL;
void print(CHAR16 *s);
void perror(EFI_STATUS stat, CHAR16 *s);

//
//      EfiMain
//      @arg    EFI_HANDLE          ImageHandle
//              EFI_SYSTEM_TABLE    *systemTable
//      @ret    EFI_STATUS      0...Success
//      @brief  UEFIで起動し，文字列を表示
//      @update mindows01b [Fix]
//

EFI_STATUS EfiMain(EFI_HANDLE imageHandle, EFI_SYSTEM_TABLE *systemTable) {
    gST = systemTable;
    EFI_BOOT_SERVICES *gBS = systemTable->BootServices;

    EFI_STATUS status;
    status = systemTable->ConOut->ClearScreen(systemTable->ConOut);
    print(L"Hello, mindows!\r\n");

    //
    // 画面情報を取得
    //
    EFI_GRAPHICS_OUTPUT_PROTOCOL *graphic = NULL;
    GraphicInfo *graphicInfo = (GraphicInfo *)GRAPHIC_INFO;
    status = gBS->LocateProtocol(&gEfiGraphicsOutputProtocolGuid, NULL, (void**)&graphic);
    perror(status, L"[Fatal] GUI Locate Error\r\n");

    graphicInfo->vram    = (unsigned int *)graphic->Mode->FrameBufferBase;
    graphicInfo->width   = (unsigned short int)graphic->Mode->Info->HorizontalResolution;
    graphicInfo->height  = (unsigned short int)graphic->Mode->Info->VerticalResolution;

    print(L"[Success] Get Graphic Info\r\n");


    //
    // ドライブを開く
    //
    EFI_FILE_PROTOCOL *root = NULL;
    EFI_SIMPLE_FILE_SYSTEM_PROTOCOL *simpleFileSystem;
    EFI_LOADED_IMAGE_PROTOCOL       *loadedImage;

    status = gBS->OpenProtocol(
            imageHandle, &gEfiLoadedImageProtocolGuid,
            (void**)&loadedImage, imageHandle, NULL, EFI_OPEN_PROTOCOL_GET_PROTOCOL);
    perror(status, L"[Fatal] Open Protocol (Loaded Image) Error\r\n");

    status = gBS->OpenProtocol(
            loadedImage->DeviceHandle, &gEfiSimpleFileSystemProtocolGuid, (void**)&simpleFileSystem,
            imageHandle, NULL, EFI_OPEN_PROTOCOL_GET_PROTOCOL);
    perror(status, L"[Fatal] Open Protocol (Simple File System) Error\r\n");

    status = simpleFileSystem->OpenVolume(simpleFileSystem, &root);
    perror(status, L"[Fatal] Open Volume Error\r\n");

    print(L"[Success] Open Volume\r\n");


    //
    // カーネルを開く
    //
    EFI_FILE_PROTOCOL *kernel;
    CHAR16 *filePath = L"\\kernel.bin";

    status = root->Open(root, &kernel, filePath, EFI_FILE_MODE_READ, 0);
    perror(status, L"[Fatal] Kernel Open Error\r\n");

    UINTN fileInfoBufSize = sizeof(EFI_FILE_INFO) +sizeof(CHAR16) *11 +2;   // 11はファイルパスの文字数 +予備
    UINT8 fileInfoBuf[fileInfoBufSize];
    status = kernel->GetInfo(kernel, &gEfiFileInfoGuid, &fileInfoBufSize, fileInfoBuf);
    perror(status, L"[Fatal] Get Kernel Info Error\r\n");

    print(L"[Success] Open Kernel File\r\n");

    EFI_FILE_INFO *fileInfo = (EFI_FILE_INFO *)fileInfoBuf;
    UINTN kernelFileSize = fileInfo->FileSize - KERNEL_ENTRY;

    status = kernel->SetPosition(kernel, KERNEL_ENTRY);
    perror(status, L"[Fatal] Kernel Set Position\r\n");

    status = kernel->Read(kernel, &kernelFileSize, (VOID*)KERNEL_ENTRY);
    perror(status, L"[Fatal] Kernel Read\r\n");

    status = kernel->Close(kernel);
    perror(status, L"[Fatal] Kernel Close\r\n");

    print(L"[Success] Kernel Read\r\n");

    //
    // メモリマップの取得
    // UEFIを終了
    //
    UINTN i;
    UINTN   mapSize = 0;
    UINTN   mapKey  = 0;
    UINTN   descSize;
    UINT32  descVersion;
    EFI_MEMORY_DESCRIPTOR *memoryMap = NULL;
    for (i = 0; i < 5; i++) {
        status = gBS->GetMemoryMap(&mapSize, memoryMap, &mapKey, &descSize, &descVersion);
        while ((status & 0xFF) == EFI_BUFFER_TOO_SMALL) {
            if (memoryMap)
                status = gBS->FreePool(memoryMap);
            mapSize += 0x1000;
            status = gBS->AllocatePool(EfiLoaderData, mapSize, (void**)&memoryMap);
            status = gBS->GetMemoryMap(&mapSize, memoryMap, &mapKey, &descSize, &descVersion);
        }

        if (status == EFI_SUCCESS)
            break;
    }

    print(L"[Success] Kernel Entry\r\n");
    status = gBS->ExitBootServices(imageHandle, mapKey);
    __asm__("jmp    *0x00110000\n");


    while (1) ;
    return EFI_SUCCESS;
}

//
//      print
//      @arg    : CHAR16 *s    表示したい文字列
//      @ret    : none
//      @desc   : 文字列を表示する関数
//      @update : mindows01b [New]
//
void print(CHAR16 *s) {
    gST->ConOut->OutputString(gST->ConOut, s);
}

//
//      print
//      @arg    : EFI_STATUS stat   エラー値を取得
//                CHAR16 *s         表示したいエラーメッセージ
//      @ret    : none
//      @desc   : 処理が成功した場合は，プログラムを続行し，
//                  それ以外はエラーメッセージを表示し，中断
//      @update : mindows01b [New]
//
void perror(EFI_STATUS stat, CHAR16 *s) {
    if (stat == EFI_SUCCESS)    return;     // success
    print(s);
    while (1);
}
