#include <stdio.h>
#include <string.h>

typedef struct {
    char symbol;
    int count;
}Tuple;

int encode_run(const char* input, int input_len, char* output,int output_len) {
    //TODO, Modify your existing run
    int pos = 0;
    int i = 0;

    while (i < input_len && input[i] != '\0')
    {
        Tuple t;
        t.symbol = input[i];
        t.count = 1;

        while (i + t.count < input_len && input[i + t.count] == t.symbol) {
            t.count++;
        }

        pos += snprintf(output + pos, output_len - pos, "(%c,%d) ", t.symbol, t.count);
        i += t.count;    
    }

    if (pos > 0) output[pos - 1] = '\0';
    
    return pos;
}

int decode_run(const char* input, char* output, int output_len) {
    int pos = 0;

    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] == '(') {
            Tuple t;
            t.symbol = input[i + 1];
            t.count = 0;
            int j = i + 3;
            while (input[j] != ')') {
                t.count = t.count * 10 + (input[j] - '0');
                j++;
            }
            for (int k = 0; k < t.count && pos < output_len - 1; k++) {
                output[pos++] = t.symbol;
            }
            i = j;
        }
    }

    output[pos] = '\0';
    return pos;
}

int main() {
    char encoded_run[128];
    const char* line_run = "1122333334423";

    encode_run(line_run, 14, encoded_run, 128);
    // (1,2) (2,2) (3,5) (4,2) (2,1) (3,1)
    printf("%s\n", encoded_run);

    char decoded[128];
    decode_run(encoded_run, decoded, 128);
    printf("%s\n", decoded);
}
