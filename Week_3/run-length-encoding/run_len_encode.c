#include <stdio.h>
//遍历字符串，统计每组连续相同字符的个数，把个数写入 buf，最后加 '\0' 终止
int encode_run(const char* sequence, unsigned len, char* buf, unsigned int buf_len) {
    unsigned int bi = 0;
    unsigned int i = 0;

    while (i < len && sequence[i] != '\0') {
        unsigned int count = 1;
        while (i + count < len && sequence[i + count] == sequence[i]) {
            count++;
        }
        if (bi < buf_len - 1) {
            //buf是char类型，所以输出形式要是字符型
            buf[bi++] = '0' + count;
        }
        i += count;
    }
    buf[bi] = '\0';
    return bi;
}

int main() {
    //用于存储最后的输出结果
    char encoded_run[128];
    const char* line_run = "1122333334423";

    encode_run(line_run, 14, encoded_run, 128);
    printf("%s\n", encoded_run); // 225211
}
