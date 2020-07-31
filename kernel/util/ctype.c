/*********************************************
 *      @file   util/ctype.c
 *
 *      @brief  文字操作に関する機能
 *
 *      @author vxdora
 *
 *      @update mindows02d
 ********************************************/

#include <util.h>

//
//      isupper
//      @args   :   ch  - 判定したい文字
//      @return :   1   - 大文字
//                  0   - その他
//      @brief  :   文字が大文字かを判定
//      @author :   vxdora
//      @update :   mindows02d
//
unsigned char isupper(unsigned char ch) {
    if ('A' <= ch && ch <= 'Z')
        return 1;
    return 0;
}

//
//      islower
//      @args   :   ch  - 判定したい文字
//      @return :   1   - 小文字
//                  0   - その他
//      @brief  :   文字が小文字かを判定
//      @author :   vxdora
//      @update :   mindows02d
//
unsigned char islower(unsigned char ch) {
    if ('a' <= ch && ch <= 'z')
        return 1;
    return 0;
}

//
//      islower
//      @args   :   ch  - 判定したい文字
//      @return :   1   - 英字
//                  0   - その他
//      @brief  :   文字が英字かを判定
//      @author :   vxdora
//      @update :   mindows02d
//
unsigned char isalpha(unsigned char ch) {
    if (islower(ch) || isupper(ch))
        return 1;
    return 0;
}

//
//      isdigit
//      @args   :   ch  - 判定したい文字
//      @return :   1   - 数字
//                  0   - その他
//      @brief  :   文字が数字かを判定
//      @author :   vxdora
//      @update :   mindows02d
//
unsigned char isdigit(unsigned char ch) {
    if ('0' <= ch && ch <= '9')
        return 1;
    return 0;
}

//
//      islower
//      @args   :   ch  - 判定したい文字
//      @return :   1   - 英数字
//                  0   - その他
//      @brief  :   文字が英数字かを判定
//      @author :   vxdora
//      @update :   mindows02d
//
unsigned char isalnum(unsigned char ch) {
    if (isalpha(ch) || isdigit(ch))
        return 1;
    return 0;
}

