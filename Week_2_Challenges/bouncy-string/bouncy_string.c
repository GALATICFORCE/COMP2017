#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int parse_int(const char *s, int *out) {
    char *end;
    if (s[0] == '\0') return 0;
    long val = strtol(s, &end, 10);
    if (*end != '\0') return 0;
    *out = (int)val;
    return 1;
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Invalid arguments length\n");
        exit(1);
    }

    char *word = argv[1];
    int start, iterations;

    if (!parse_int(argv[2], &start)) {
        printf("Invalid start position\n");
        exit(1);
    }
    if (!parse_int(argv[3], &iterations)) {
        printf("Invalid iteration count\n");
        exit(1);
    }

    int len = strlen(word);

    if (start < 0 || start >= len) {
        printf("Invalid start position\n");
        exit(1);
    }

    if (iterations < 0) {
        printf("Invalid iteration count\n");
        exit(1);
    }

    int total = iterations + 1;
    int pos = start;
    int dir = 1;

    for (int i = 0; i < total; i++) {
        printf("%c", word[pos]);

        if (i < total - 1) {
            if (pos + dir >= len || pos + dir < 0) dir = -dir;
            if (pos + dir >= 0 && pos + dir < len)
                pos += dir;
        }
    }
    printf("\n");

    return 0;
}