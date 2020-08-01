/*************************************************
 *      @file   include/util.h
 *
 *      @brief  utilの定義
 *
 *      @author vxdora
 *
 *      @update mindows04a
 ************************************************/

#ifndef __UTIL__
#define __UTIL__

// asmfunc.S
extern void io_cli(void);
extern void io_sti(void);
extern void io_hlt(void);
extern char io_in8(unsigned short int port);
extern int  io_in32(unsigned int port);
extern void io_out8(unsigned short int port, unsigned char data);
extern void io_out32(unsigned short int port, unsigned int data);

// ctype.c
unsigned char isupper(unsigned char ch);
unsigned char islower(unsigned char ch);
unsigned char isalpha(unsigned char ch);
unsigned char isdigit(unsigned char ch);
unsigned char isalnum(unsigned char ch);

// string.c
void *memset(void *s, unsigned char c, unsigned int n);
unsigned int strlen(unsigned char *s);
int strcmp(unsigned char *s, unsigned char *t);
int strncmp(unsigned char *s, unsigned char *t, unsigned int n);
unsigned int strcpy(unsigned char *s, unsigned char *t);

// stdio.h
#define TYPE_UCHAR      1
#define TYPE_UINT       2
#define TYPE_ULLINT     3
#define TYPE_UINTX      4
#define TYPE_ULLINTX    5
#define TYPE_SCHAR      11
#define TYPE_SINT       12
#define TYPE_SLLINT     13
#define TYPE_SINTX      13
#define TYPE_SLLINTX    14

typedef union {
    unsigned char uc;
    unsigned int ud;
    unsigned long long int ulld;
    signed char sc;
    signed int sd;
    signed long long int slld;
} ATYPE;

void value2str(
        ATYPE val,
        unsigned char *buf,
        unsigned char type, unsigned char mf, unsigned char zf, unsigned char dig);
unsigned int sprintf(unsigned char *s, const unsigned char *t, ...);


#endif  // __UTIL__

