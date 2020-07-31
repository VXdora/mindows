/*************************************************
 *      @file   util/stdio.h
 *
 *      @brief  入出力関連の機能
 *
 *      @author vxdora
 *
 *      @update mindows02d [New]
 ************************************************/

#include <stdarg.h>

#include <util.h>

//
//      value2str
//      @args   :   val     - 変換したい数字
//                  buf     - 変換した数値の出力先
//                  type    - 数値の型
//                  mf      - 左詰めor右詰め
//                  zf      - 隙間を0で埋める
//                  dig     - 隙間の数
//      @return :   なし
//      @brief  :   数値を文字列に変換する
//                  ex  % - 0 8 d
//                        m z d type
//                        f f i
//                            g
//      @author :   vxdora
//      @update :   mindows02d [New]
//
void value2str(
        ATYPE val,
        unsigned char *buf,
        unsigned char type, unsigned char mf, unsigned char zf, unsigned char dig) {
    const char sx[] = {                             // 16進数用の文字
        '0', '1', '2', '3', '4', '5', '6', '7',
        '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };
    unsigned int len = 0;                           // 文字の長さ
    unsigned char tmp[128];                         // 保存用文字列
    unsigned char minus = 0;                        // 負の数か

    // 一の位から確認していき，tmpに0番目から入れていく
    // その後，tmpを逆から捜査していき，，bufに格納
    switch(type) {
        case TYPE_UINT:
            do {
                tmp[len++] = (val.ud %10) +'0';
                if (dig > 0) dig--;
            } while (val.ud /= 10);
            break;
        case TYPE_ULLINT:
            do {
                tmp[len++] = (val.ulld %10) +'0';
                if (dig > 0) dig--;
            } while (val.ulld /= 10);
            break;
        case TYPE_SINT:
            if (val.sd < 0) {
                val.sd = -val.sd;
                minus = 1;
            }
            do {
                tmp[len++] = (val.sd %10) +'0';
                if (dig > 0) dig--;
            } while (val.sd /= 10);
            break;
        case TYPE_SLLINT:
            if (val.slld < 0) {
                val.slld = -val.slld;
                minus = 1;
            }
            do {
                tmp[len++] = (val.slld %10) +'0';
                if (dig > 0) dig--;
            } while (val.sd /= 10);
            break;
        case TYPE_UINTX:
            do {
                tmp[len++] = sx[val.ud %16];
                if (dig > 0) dig--;
            } while (val.ud /= 16);
            break;
        case TYPE_ULLINTX:
            do {
                tmp[len++] = sx[val.ulld %16];
                if (dig > 0) dig--;
            } while (val.ulld /= 16);
            break;
    }

    // 左詰めの確認
    if (!mf) {
        if (zf) {
            // dig > 0 の確認は必要?? (要検証)
            while(dig--) tmp[len++] = '0';
        }
        else {
            while(dig--) tmp[len++] = ' ';
        }
    }

    // 負の数の時は「-」をつける
    if (minus) {
        tmp[len++] = '-';
    }

    if (mf == 1 && len < dig)
        dig -= len;

    // bufに格納
    while (len--)
        *buf++ = tmp[len];

    if (mf) {
        while (dig--) {
            *buf++ = ' ';
        }
    }
    *buf = '\0';
}

//
//      sprintf
//      @args   :   s   - 出力先文字列
//                  t   - 変換する文字列
//                  以降，出力したい変数が続く...
//      @return :   変換した変数の個数（の予定）
//      @brief  :   文字列sに出力するタイプのprintf
//                  使える変換記号は
//                      s - 文字列
//                      u - 数値（10進数，正の数）
//                      d - 数値（10進数）
//                      x - 数値（16進数）
//                      c - 文字
//                                  etc...
//      @author :   vxdora
//      @update :   mindows02d [New]
//
unsigned int sprintf(unsigned char *s, const unsigned char *t, ...) {
    unsigned char len = 0, ret = 0;
    unsigned char buf[128];
    char *c;

    unsigned char mf = 0;       // minus flag
    unsigned char zf = 0;       // 0 fill
    unsigned char dig = 0;      // 0 fill digit
    unsigned char lf  = 0;      // long
    unsigned char llf = 0;      // long long

    // convert param
    ATYPE val;

    va_list ap;

    va_start(ap, t);
    do {
        if (*t == '%') {
            t++;
            // check flag
            if (*t == '-') {
                mf = 1; t++;
            }
            if (*t == '0') {
                zf = 1; t++;
            }
            if ('1' <= *t && *t <= '9') {
                dig = *t -'0'; t++;
            }
            if (*t == 'l') {
                t++;
                if (*t == 'l')  { llf = 1; t++; }
                else            {  lf = 1;      }
            }

            // convert
            if (*t == 'u') {
                if (llf) {
                    val.ulld = va_arg(ap, unsigned long long int);
                    value2str(val, buf, TYPE_ULLINT, mf, zf, dig);
                }
                else {
                    val.ud = va_arg(ap, unsigned int);
                    value2str(val, buf, TYPE_UINT, mf, zf, dig);
                }
                for (len = 0; buf[len]; len++)
                    *s++ = buf[len];
            }
            else if (*t == 'd') {
                if (llf) {
                    val.slld = va_arg(ap, signed long long int);
                    value2str(val, buf, TYPE_SLLINT, mf, zf, dig);
                }
                else {
                    val.sd = va_arg(ap, signed int);
                    value2str(val, buf, TYPE_SINT, mf, zf, dig);
                }
                for (len = 0; buf[len]; len++)
                    *s++ = buf[len];
            }
            else if (*t == 'x' || *t == 'X') {
                if (llf) {
                    val.ulld = va_arg(ap, unsigned long long int);
                    value2str(val, buf, TYPE_ULLINTX, mf, zf, dig);
                }
                else {
                    val.ud = va_arg(ap, unsigned int);
                    value2str(val, buf, TYPE_UINTX, mf, zf, dig);
                }
                for (len = 0; buf[len]; len++)
                    *s++ = buf[len];
            }
            else if (*t == 's') {
                c = va_arg(ap, char*);
                if (mf) {
                    while (dig--)
                        *s++ = ' ';
                }
                do {
                    *s++ = *c++;
                } while (*c);
                while (dig) {
                    *s++ = ' ';
                }
            }
        }
        else {
            *s++ = *t;
        }
        mf = zf = dig = lf = llf = 0;
    } while(*t++);
    *s = '\0';

    va_end(ap);
    return ret;
}

