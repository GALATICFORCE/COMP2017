#include <stdio.h>
#include <ctype.h>

void count(FILE *fp, long *lines, long *words, long *bytes) {
    char buf[4096];
    size_t n;
    int in_word = 0;

    *lines = 0;
    *words = 0;
    *bytes = 0;

    while ((n = fread(buf, 1, sizeof(buf), fp)) > 0) {
        *bytes += n;
        for (size_t i = 0; i < n; i++) {
            if (buf[i] == '\n') {
                (*lines)++;
            }
            if (isspace((unsigned char)buf[i])) {
                in_word = 0;
            } else {
                if (!in_word) {
                    (*words)++;
                    in_word = 1;
                }
            }
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc == 1) {
        long lines, words, bytes;
        count(stdin, &lines, &words, &bytes);
        printf("%ld %ld %ld\n", lines, words, bytes);
        return 0;
    }

    long total_lines = 0, total_words = 0, total_bytes = 0;

    for (int i = 1; i < argc; i++) {
        FILE *fp = fopen(argv[i], "r");
        if (fp == NULL) {
            fprintf(stderr, "wc: %s: No such file or directory\n", argv[i]);
            continue;
        }
        long lines, words, bytes;
        count(fp, &lines, &words, &bytes);
        fclose(fp);

        printf("%ld %ld %ld %s\n", lines, words, bytes, argv[i]);
        total_lines += lines;
        total_words += words;
        total_bytes += bytes;
    }

    if (argc > 2) {
        printf("%ld %ld %ld total\n", total_lines, total_words, total_bytes);
    }

    return 0;
}
