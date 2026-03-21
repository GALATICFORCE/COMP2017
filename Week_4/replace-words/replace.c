#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 5) {
        fprintf(stderr, "Usage: %s <input> <output> <old_word> <new_word>\n", argv[0]);
        return 1;
    }

    char *input_file = argv[1];
    char *output_file = argv[2];
    char *old_word = argv[3];
    char *new_word = argv[4];
    size_t old_len = strlen(old_word);
    size_t new_len = strlen(new_word);

    FILE *in = fopen(input_file, "r");
    if (in == NULL) {
        fprintf(stderr, "Cannot open %s\n", input_file);
        return 1;
    }

    FILE *out = fopen(output_file, "w");
    if (out == NULL) {
        fprintf(stderr, "Cannot open %s\n", output_file);
        fclose(in);
        return 1;
    }

    char line[4096];
    while (fgets(line, sizeof(line), in) != NULL) {
        char *pos = line;
        while ((pos = strstr(pos, old_word)) != NULL) {
            // Move the rest of the string to make room
            memmove(pos + new_len, pos + old_len, strlen(pos + old_len) + 1);
            // Copy new word in
            memcpy(pos, new_word, new_len);
            pos += new_len;
        }
        fprintf(out, "%s", line);
    }

    fclose(in);
    fclose(out);
    return 0;
}
