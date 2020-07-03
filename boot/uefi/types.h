/****************************************************
 *      @file   types.h
 *
 *      @brief  ・UEFIによって定義づけられた型を作成
 *
 *      @author VXdora
 *
 *      @update  mindows01a [New]
 ***************************************************/

#ifndef __UEFI_TYPES__
#define __UEFI_TYPES__

//
// @brief   UEFIで共通の型
// @ref     UEFI.Spec p23 [2.3.1]
// @update  mindows01a [New]
//

typedef char            BOOLEAN;
#define FALSE           0
#define TRUE            1

typedef signed long long int    INTN;
typedef unsigned long long int  UINTN;

typedef signed char             INT8;
typedef unsigned char           UINT8;

typedef signed short int        INT16;
typedef unsigned short int      UINT16;

typedef signed int              INT32;
typedef unsigned int            UINT32;

typedef signed long long int    INT64;
typedef unsigned long long int  UINT64;

typedef unsigned char           CHAR8;
typedef unsigned short int      CHAR16;

typedef void                    VOID;

typedef struct {
    UINT32  Data1;
    UINT16  Data2;
    UINT16  Data3;
    UINT8   Data4[8];
} GUID;

typedef GUID EFI_GUID;

typedef unsigned long long  EFI_STATUS;
typedef VOID*               EFI_HANDLE;
typedef VOID*               EFI_EVENT;

#define NULL                0


//
// @brief   UEFIのエラー状態を定義
// @ref     UEFI.Spec p2347 [Appendix D]
// @update  mindows01a [New]
//

#define EFI_SUCCESS             0

#define EFI_LOAD_ERROR          1
#define EFI_INVALID_PARAMATER   2
#define EFI_UNSUPPORTED         3
#define EFI_BAD_BUFFER_SIZE     4
#define EFI_BUFFER_TOO_SMALL    5
#define EFI_NOT_READY           6
#define EFI_DEVICE_ERROR        7
#define EFI_WRITE_PROTECTED     8
#define EFI_OUT_OF_RESOURCES    9
#define EFI_VOLUME_CORRUPTED    10
#define EFI_VOLUME_FULL         11
#define EFI_NO_MEDIA            12
#define EFI_MEDIA_CHANGED       13
#define EFI_NOT_FOUND           14
#define EFI_ACCESS_DENIED       15
#define EFI_NO_RESPONSE         16
#define EFI_NO_MAPPING          17
#define EFI_TIMEOUT             18
#define EFI_NOT_STARTED         19
#define EFI_ALREADY_STARTED     20
#define EFI_ABORTED             21
#define EFI_ICMP_ERROR          22
#define EFI_TFTP_ERROR          23
#define EFI_PROTOCOL_ERROR      24
#define EFI_INCOMPATIBLE_VERSION 25
#define EFI_SECURITY_VIOLATION  26
#define EFI_CRC_ERROR           27
#define EFI_END_OF_MEDIA        28
#define EFI_END_OF_FILE         31
#define EFI_INVALID_LANGUAGE    32
#define EFI_COMPROMISED_DATA    33
#define EFI_IP_ADDRESS_CONFLICT 34
#define EFI_HTTP_ERROR          35

#endif  // __UEFI_TYPES__

