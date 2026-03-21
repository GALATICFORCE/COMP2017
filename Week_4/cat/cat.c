#include <stdio.h>
#include <stdlib.h>

void output(FILE *fp) {
    char buf[4096];
    size_t n;
    while ((n = fread(buf, 1, sizeof(buf), fp)) > 0) {
        fwrite(buf, 1, n, stdout);
    }
}

int main(int argc, char *argv[]) {
    if (argc == 1) {
        output(stdin);
        return 0;
    }

    for (int i = 1; i < argc; i++) {
        FILE *fp = fopen(argv[i], "r");
        if (fp == NULL) {
            fprintf(stderr, "cat: %s: No such file or directory\n", argv[i]);
            continue;
        }
        output(fp);
        fclose(fp);
    }

    return 0;
}
