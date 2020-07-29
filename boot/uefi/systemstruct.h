/***************************************************************
 *      @file   systemstruct.h
 *
 *      @brief  ・UEFIの起動時の引数として使用する
 *                  EFI_RUNTIME_SERVICE, EFI_BOOT_SERVICEの
 *                  定義
 *
 *      @author VXdora
 *
 *      @update mindows01b
 **************************************************************/

#include <types.h>
#include <IOStruct.h>
#include <MemoryStruct.h>

#ifndef __UEFI_SYSTEMSTRUCT__
#define __UEFI_SYSTEMSTRUCT__

//
//      Table Header
//      @ref    UEFI.Spec 4-2
//      @update mindows01a
//

typedef struct EFI_TABLE_HEADER{
    UINT32  reserve[6];             // 使わないので省略
} EFI_TABLE_HEADER;


//
//      Runtime Services Table
//      @ref    UEFI.Spec 4-5
//      @update mindows01a
//

typedef struct EFI_RUNTIME_SERVICES {

    //    Time Services
    // @ref    UEFI.Spec 7-3
    // @update mindows01a
    EFI_STATUS  GetTime;
    EFI_STATUS  SetTime;
    EFI_STATUS  GetWakeupTime;
    EFI_STATUS  SetWakeupTime;

    //    Virt Memory Services
    // @ref    UEFI.Spec 7-4
    // @update mindows011a
    EFI_STATUS  SetVirtualAddressMap;
    EFI_STATUS  ConvertPointer;

    //    Variable Services
    // @ref    UEFI.Spec 7-2
    // @update mindows01a
    EFI_STATUS  GetVariable;
    EFI_STATUS  GetNextVariableName;
    EFI_STATUS  SetVariable;

    //    Miscellaneous Services
    // @ref    UEFI.Spec 7-5
    // @update mindows01a
    EFI_STATUS  GetNextHighMonotonicCount;
    VOID        (*ResetSystem) ();

    //    UEFI2.0 Capsule Services
    // @ref    UEFI.Spec 7-5
    // @update mindows01a
    EFI_STATUS  UpdateCapsule;
    EFI_STATUS  QueryCapsuleCapabilities;

    //    Miscellaneous UEFI2.0 Services
    // @ref    UEFI.Spec 7-2
    // @update mindows01a
    EFI_STATUS  QueryVariableInfo;
} EFI_RUNTIME_SERVICES;



//
//      Boot Services
//      @ref    UEFI.Spec 4-4
//      @update mindows01b
//

#define EFI_OPEN_PROTOCOL_BY_HANDLE_PROTOCOL    0x00000001
#define EFI_OPEN_PROTOCOL_GET_PROTOCOL          0x00000002
#define EFI_OPEN_PROTOCOL_TEST_PROTOCOL         0x00000004
#define EFI_OPEN_PROTOCOL_BY_CHILD_CONTROLLER   0x00000008
#define EFI_OPEN_PROTOCOL_BY_DRIVER             0x00000010
#define EFI_OPEN_PROTOCOL_EXCLUSIVE             0x00000020

typedef struct {
    EFI_TABLE_HEADER        Hdr;

    //    TaskPriority Services
    //    @ref    UEFI.Spec 6-1
    //    @update mindows01a
    UINTN       RaiseTPL;           // EFI_TPL -> UINTN
    VOID        (*RestoreTPL) ();

    //    Memory Services
    //    @ref    UEFI.Spec 6-2
    //    @update mindows01b
    EFI_STATUS  AllocatePages;
    EFI_STATUS  FreePages;
    EFI_STATUS  (*GetMemoryMap) (
            UINTN *MemoryMapSize,
            EFI_MEMORY_DESCRIPTOR *MemoryMap,
            UINTN *MapKey,
            UINTN *DescriptorSize,
            UINT32 *DescriptorVersion
    );
    EFI_STATUS  (*AllocatePool) (
            EFI_MEMORY_TYPE PoolType,
            UINTN Size,
            VOID **Buffer
    );
    EFI_STATUS  (*FreePool) (
            VOID *Buffer
    );

    //    Event and Timer Services
    //    @ref    UEFI.Spec 6-1
    //    @update mindows01a
    EFI_STATUS  CreateEvent;
    EFI_STATUS  SetTimer;
    EFI_STATUS  WaitForEvent;
    EFI_STATUS  SignalEvent;
    EFI_STATUS  CloseEvent;
    EFI_STATUS  CheckEvent;

    //    Protocol Handler Services
    //    @ref    UEFI.Spec 6-3
    //    @update mindows01a
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
    //    @update mindows01b
    EFI_STATUS  LoadImage;
    EFI_STATUS  StartImage;
    EFI_STATUS  Exit;
    EFI_STATUS  UnloadImage;
    EFI_STATUS  (*ExitBootServices) (
            EFI_HANDLE  ImageHandle,
            UINTN       MapKey
    );

    //    Miscellaneous Services
    //    @ref    UEFI.Spec 6-5
    //    @update mindows01a
    EFI_STATUS  GetNextMonotonicCount;
    EFI_STATUS  Stall;
    EFI_STATUS  SetWatchdogTimer;

    //    Driver Support Services
    //    @ref    UEFI.Spec 6-3
    //    @update mindows01a
    EFI_STATUS  ConnectController;
    EFI_STATUS  DisConnectController;

    //    Open and Close Protocol Services
    //    @ref    UEFI.Spec 6-3
    //    @update mindows01b
    EFI_STATUS  (*OpenProtocol) (
            EFI_HANDLE  Handle,
            EFI_GUID    *Protocol,
            VOID        **Interface,
            EFI_HANDLE  AgentHandle,
            EFI_HANDLE  ControllerHandle,
            UINT32      Attributes
    );
    EFI_STATUS  CloseProtocol;
    EFI_STATUS  OpenProtocolInformation;

    //    Library Services
    //    @ref    UEFI.Spec 6-3
    //    @update mindows01b
    EFI_STATUS  ProtocolPerHandle;
    EFI_STATUS  LocateHandleBuffer;
    EFI_STATUS  (*LocateProtocol) (
            EFI_GUID    *Protocol,
            VOID        *Registeration,
            VOID        **Interface
    );
    EFI_STATUS  InstallMultipleProtocolInterfaces;
    EFI_STATUS  UninstallMultipleProtocolInterfaces;

    //    32bit CRC Services
    //    @ref    UEFI.Spec 6-3
    //    @update mindows01a
    EFI_STATUS  CalculateCrc32;

    //    Miscellaneous Services
    //    @ref    UEFI.Spec 6-5
    //    @update mindows01a
    VOID        (*CopyMem) ();
    VOID        (*SetMem) ();
    EFI_STATUS  CreateEventEx;
} EFI_BOOT_SERVICES;


//
//      EFI Configuration Table
//      @ref    UEFI.Spec 4-6
//      @update mindows01a
//

typedef struct {
    EFI_GUID    VendorGuid;
    VOID        *VendorTable;
} EFI_CONFIGURATION_TABLE;


//
//      System Table
//      @ref    UEFI.Spec 4-3
//      @update mindows01a
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

