/***************************************************************
 *      @file   systemstruct.h
 *
 *      @brief  ・UEFIの起動時の引数として使用する
 *                  EFI_RUNTIME_SERVICE, EFI_BOOT_SERVICEの
 *                  定義
 *
 *      @author VXdora
 *
 *      @update mindows01a [New]
 **************************************************************/

#include <types.h>
#include <iostruct.h>

#ifndef __UEFI_SYSTEMSTRUCT__
#define __UEFI_SYSTEMSTRUCT__

//
//      Table Header
//      @ref    UEFI.Spec 4-2
//      @update mindows01a [New]
//

typedef struct EFI_TABLE_HEADER{
    UINT32  reserve[6];             // 使わないので省略
} EFI_TABLE_HEADER;


//
//      Runtime Services Table
//      @brief  EFI_RUNTIME_SERVICESの定義
//      @ref    UEFI.Spec 4-5
//      @update mindows01a [New]
//

typedef struct EFI_RUNTIME_SERVICES {

    //    Time Services
    // @ref    UEFI.Spec 7-3
    // @update mindows01a [New]
    EFI_STATUS  GetTime;
    EFI_STATUS  SetTime;
    EFI_STATUS  GetWakeupTime;
    EFI_STATUS  SetWakeupTime;

    //    Virt Memory Services
    // @ref    UEFI.Spec 7-4
    // @update mindows011a [New]
    EFI_STATUS  SetVirtualAddressMap;
    EFI_STATUS  ConvertPointer;

    //    Variable Services
    // @ref    UEFI.Spec 7-2
    // @update mindows01a [New]
    EFI_STATUS  GetVariable;
    EFI_STATUS  GetNextVariableName;
    EFI_STATUS  SetVariable;

    //    Miscellaneous Services
    // @ref    UEFI.Spec 7-5
    // @update mindows01a [New]
    EFI_STATUS  GetNextHighMonotonicCount;
    VOID        (*ResetSystem) ();

    //    UEFI2.0 Capsule Services
    // @ref    UEFI.Spec 7-5
    // @update mindows01a [New]
    EFI_STATUS  UpdateCapsule;
    EFI_STATUS  QueryCapsuleCapabilities;

    //    Miscellaneous UEFI2.0 Services
    // @ref    UEFI.Spec 7-2
    // @update mindows01a [New]
    EFI_STATUS  QueryVariableInfo;
} EFI_RUNTIME_SERVICES;



//
//      Boot Services
//      @brief  EFI_BOOT_SERVICESの定義
//      @ref    UEFI.Spec 4-4
//      @update mindows01a [New]
//

typedef struct {
    EFI_TABLE_HEADER        Hdr;

    //    TaskPriority Services
    //    @ref    UEFI.Spec 6-1
    //    @update mindows01a [New]
    UINTN       RaiseTPL;           // EFI_TPL -> UINTN
    VOID        (*RestoreTPL) ();

    //    Memory Services
    //    @ref    UEFI.Spec 6-2
    //    @update mindows01a [New]
    EFI_STATUS  AllocatePages;
    EFI_STATUS  FreePages;
    EFI_STATUS  GetMemoryMap;
    EFI_STATUS  AllocatePool;
    EFI_STATUS  FreePool;

    //    Event and Timer Services
    //    @ref    UEFI.Spec 6-1
    //    @update mindows01a [New]
    EFI_STATUS  CreateEvent;
    EFI_STATUS  SetTimer;
    EFI_STATUS  WaitForEvent;
    EFI_STATUS  SignalEvent;
    EFI_STATUS  CloseEvent;
    EFI_STATUS  CheckEvent;

    //    Protocol Handler Services
    //    @ref    UEFI.Spec 6-3
    //    @update mindows01a [New]
    EFI_STATUS  InstallProtocolInterface;
    EFI_STATUS  ReinstallProtocolInterface;
    EFI_STATUS  UninstallProtocolInterface;
    EFI_STATUS  HandleProtocol;
    VOID        *Reserved;
    EFI_STATUS  RegisterProtocolNotify;
    EFI_STATUS  LocateHandle;
    EFI_STATUS  LocateDevicePath;
    EFI_STATUS  InstallConfigurationTable;

    //    Image Services
    //    @ref    UEFI.Spec 6-4
    //    @update mindows01a [New]
    EFI_STATUS  LoadImage;
    EFI_STATUS  StartImage;
    EFI_STATUS  Exit;
    EFI_STATUS  UnloadImage;
    EFI_STATUS  ExitBootServices;

    //    Miscellaneous Services
    //    @ref    UEFI.Spec 6-5
    //    @update mindows01a [New]
    EFI_STATUS  GetNextMonotonicCount;
    EFI_STATUS  Stall;
    EFI_STATUS  SetWatchdogTimer;

    //    Driver Support Services
    //    @ref    UEFI.Spec 6-3
    //    @update mindows01a [New]
    EFI_STATUS  ConnectController;
    EFI_STATUS  DisConnectController;

    //    Open and Close Protocol Services
    //    @ref    UEFI.Spec 6-3
    //    @update mindows01a [New]
    EFI_STATUS  OpenProtocol;
    EFI_STATUS  CloseProtocol;
    EFI_STATUS  OpenProtocolInformation;

    //    Library Services
    //    @ref    UEFI.Spec 6-3
    //    @update mindows01a [New]
    EFI_STATUS  ProtocolPerHandle;
    EFI_STATUS  LocateHandleBuffer;
    EFI_STATUS  LocateProtocol;
    EFI_STATUS  InstallMultipleProtocolInterfaces;
    EFI_STATUS  UninstallMultipleProtocolInterfaces;

    //    32bit CRC Services
    //    @ref    UEFI.Spec 6-3
    //    @update mindows01a [New]
    EFI_STATUS  CalculateCrc32;

    //    Miscellaneous Services
    //    @ref    UEFI.Spec 6-5
    //    @update mindows01a [New]
    VOID        (*CopyMem) ();
    VOID        (*SetMem) ();
    EFI_STATUS  CreateEventEx;
} EFI_BOOT_SERVICES;


//
//      EFI Configuration Table
//      @breif  EFI_CONFIGURATION_TABLE構造体の定義
//      @ref    UEFI.Spec 4-6
//      @update mindows01a [New]
//

typedef struct {
    EFI_GUID    VendorGuid;
    VOID        *VendorTable;
} EFI_CONFIGURATION_TABLE;


//
//      System Table
//      @brief  EFI_SYSTEM_TABLEの定義
//      @ref    UEFI.Spec 4-3
//      @update mindows01a [New]
//

typedef struct EFI_SYSTEM_TABLE {
    EFI_TABLE_HEADER                Hdr;
    CHAR16                          *FirmwareVendor;
    UINT32                          FirmwareRevision;
    EFI_HANDLE                      ConsoleInHandle;
    EFI_SIMPLE_TEXT_INPUT_PROTOCOL  *ConIn;
    EFI_HANDLE                      ConsoleOutHandle;
    EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *ConOut;
    EFI_HANDLE                      StandardErrorHandle;
    EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *StdErr;
    EFI_RUNTIME_SERVICES            *RuntimeServices;
    EFI_BOOT_SERVICES               *BootServices;
    UINTN                           NumberOfTableEntries;
    EFI_CONFIGURATION_TABLE         *ConfigurationTable;
} EFI_SYSTEM_TABLE;


#endif  // __UEFI_SYSTEMSTRUCT__

