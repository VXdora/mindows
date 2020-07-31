/********************************************
 *      @file   util/string.c
 *
 *      @brief  文字列操作関連の機能
 *
 *      @author vxdora
 *
 *      @update mindows02d [New]
 *******************************************/

#include <util.h>

//
//      memset
//      @args   :   s  - クリアするメモリの開始地点
//                  c  - クリアする値
//                  n  - クリアする長さ
//      @return :   メモリの開始地点
//      @brief  :   メモリをs番地から
//                  値cでn番目までクリアする
//      @author :   vxdora
//      @update :   mindows02d [New]
//
void *memset(void *s, unsigned char c, unsigned int n) {
    unsigned char *tmp = s;
    unsigned char ch = c;
    unsigned int i;
    for (i = 0; i < n; i++) {
        tmp[i] = ch;
    }
    return s;
}

//
//      strlen
//      @args   :   s   - 対象の文字列
//      @return :   文字列の長さ
//      @brief  :   文字列の長さを返す
//      @author :   vxdora
//      @update :   mindows02d [New]
//
unsigned int strlen(unsigned char *s) {
    unsigned int i = 0;
    while (*s++) i++;
    return i;
}

//
//      strcmp
//      @args   :   s   - 比較対象の文字列
//                  t   - 比較文字列
//      @return :   < 0 - sのほうが先にくる
//                  = 0 - 文字列は同じ
//                  > 0 - sのほうが後にくる
//      @brief  :   文字列を比較する
//      @author :   vxdora
//      @update :   mindows02d [New]
//
int strcmp(unsigned char *s, unsigned char *t) {
    int i = 0;
    int ret = 0;
    for (i = 0; i < strlen(s); i++) {
        if (s[i] != t[i]) {
            ret = s[i] - t[i];
            break;
        }
    }
    return ret;
}

//
//      strcmp
//      @args   :   s   - 比較対象の文字列
//                  t   - 比較文字列
//                  n   - n文字目までを比較
//      @return :   < 0 - sのほうが先にくる
//                  = 0 - 文字列は同じ
//                  > 0 - sのほうが後にくる
//      @brief  :   n文字目までの文字列を比較する
//      @author :   vxdora
//      @update :   mindows02d [New]
//
int strncmp(unsigned char *s, unsigned char *t, unsigned int n) {
    int i, ret = 0;
    for (i = 0; i < n; i++) {
        if (s[i] != t[i]) {
            ret = s[i] - t[i];
            break;
        }
    }
    return ret;
}

//
//      strcpy
//      @args   :   s   - コピー先の文字列
//                  t   - コピー元の文字列
//      @return :   コピーした文字列長
//      @brief  :   文字列tをsへコピーする
//      @author :   vxdora
//      @update :   mindows02d [New]
//
unsigned int strcpy(unsigned char *s, unsigned char *t) {
    unsigned int ret = 0x00;
    while (*t) {
        *s++ = *t++;
        ret++;
    }
    return 0;
}


