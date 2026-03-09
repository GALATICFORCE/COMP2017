// TODO
#include <stdio.h>
#include <string.h>

// 打印一个三角形的某一行
// row: 当前是三角形的第几行 (0开始)
// height: 三角形高度
// offset: 这个三角形在整行中的起始列位置
// buf: 输出缓冲区
void draw_triangle_row(char *buf, int row, int height, int offset) {
    // 每个三角形宽度 = 2 * height
    // 第row行: 前面 (height-1-row) 个空格, 然后 '/', 中间填充, 然后 '\'
    int leading = height - 1 - row;
    int pos = offset + leading;
    buf[pos] = '/';
    if (row == height - 1) {
        // 最后一行，中间填 '_'
        for (int j = 1; j <= 2 * row; j++) {
            buf[pos + j] = '_';
        }
    } else if (row > 0) {
        // 中间行，中间是空格（已经是空格，不用管）
    }
    buf[pos + 2 * row + 1] = '\\';
    // 第0行不需要中间填充（/\ 直接相邻）
}

int main() {
    printf("Enter height: ");

    int height;
    if (scanf("%d", &height) != 1 || height < 2 || height > 20) {
        printf("\n");
        printf("Invalid height.\n");
        return 0;
    }

    // 总宽度 = 4 * height
    int width = 4 * height;
    printf("\n");
    // 上面的三角形 (height 行)
    for (int row = 0; row < height; row++) {
        char buf[width + 1];
        memset(buf, ' ', width);
        buf[width] = '\0';

        // 上三角形的偏移: 居中在上方，起始列 = height
        draw_triangle_row(buf, row, height, height);

        // 去掉行尾空格
  
        int end = width - 1;
        while (end >= 0 && buf[end] == ' ') {
            buf[end] = '\0';
            end--;
        }
        printf("%s\n", buf);
    }

    // 下面两个三角形 (height 行)
    for (int row = 0; row < height; row++) {
        char buf[width + 1];
        memset(buf, ' ', width);
        buf[width] = '\0';

        // 左下三角形，偏移 = 0
        draw_triangle_row(buf, row, height, 0);
        // 右下三角形，偏移 = 2 * height
        draw_triangle_row(buf, row, height, 2 * height);

        // 去掉行尾空格
        int end = width - 1;
        while (end >= 0 && buf[end] == ' ') {
            buf[end] = '\0';
            end--;
        }
        printf("%s\n", buf);
    }

    return 0;
}