/****************************************************
 *      @file   MemoryStruct.h
 *
 *      @brief  メモリ管理に関する構造体?
 *
 *      @author VXdora
 *
 *      @update mindows01b
 ***************************************************/

#include <types.h>

#ifndef __UEFI_MEMORYSTRUCT__
#define __UEFI_MEMORYSTRUCT__

typedef UINT64 EFI_PHYSICAL_ADDRESS;
typedef UINT64 EFI_VIRTUAL_ADDRESS;


//
//      EFI_MEMORY_TYPE
//      @ref    UEFI.Spec 6-2
//      @update mindows01b [New]
//
typedef enum {
    EfiReservedMemoryType,
    EfiLoaderCode,
    EfiLoaderData,
    EfiBootServicesCode,
    EfiBootServicesData,
    EfiRuntimeServicesCode,
    EfiRuntimeServicesData,
    EfiConventionalMemory,
    EfiUnusableMemory,
    EfiACPIReclaimMemory,
    EfiACPIMemoryNVS,
    EfiMemoryMappedIO,
    EfiMemoryMappedIOPortSpace,
    EfiPalCode,
    EfiPersistentMemory,
    EfiMaxMemoryType
} EFI_MEMORY_TYPE;

//
//      EFI_MEMORY_DESCRIPTOR
//      @ref    UEFI.Spec 6-2
//      @update mindows01b [New]
//
typedef struct EFI_MEMORY_DESCRIPTOR {
    UINT32 Type;
    EFI_PHYSICAL_ADDRESS    PhysicalStart;
    EFI_VIRTUAL_ADDRESS     VirtualStart;
    UINT64 NumOfPages;
    UINT64 Attribute;
} EFI_MEMORY_DESCRIPTOR;




#endif  // __UEFI_MEMORYSTRUCT__

