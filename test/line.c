#include <stdio.h>

void DrawLine(
        unsigned int sx, unsigned int sy,
        signed int width, signed int height,
        unsigned int thick, unsigned int color) {

    unsigned int x, y;
    unsigned int ex = sx +width, ey = sy +height;       // 終了地点
    unsigned int tmp;

    // 開始地点より終了地点のほうが小さい時は入れ替える
    printf("(%d, %d) -> (%d, %d)\n", sx, sy, ex, ey);
    if (ex < sx) {
        tmp = ex;
        ex = sx;
        sx = tmp;

        tmp = ey;
        ey = sy;
        sy = tmp;
    }

    printf("(%d, %d) -> (%d, %d)\n", sx, sy, ex, ey);


    // width == 0のときは0除算が発生するため，例外
    if (width == 0) {

    }

    // y = (height / width) * (x - sx) + sy
    else {
        // float M = (float)(height / width);
        for (x = sx; x < ex; x++) {
            printf("(%d, %f)\n", x, ((float)height / (float)width) * (x - sx) + sy);
        }
    }
}

int main(int argc, char *argv[]) {
    DrawLine(30, 20, 30, 20, 3, 0xFF0000);
    DrawLine(30, 20, -30, 20, 3, 0xFF0000);
    DrawLine(30, 20, 30, -20, 3, 0xFF0000);
    DrawLine(30, 20, -30, -20, 3, 0xFF0000);
    return 0;
}

