int encode_run(const char* sequence, unsigned len, char* buf, unsigned int buf_len) {
    //TODO
}

int main() {
    char encoded_run[128];
    const char* line_run = "1122333334423";

    encode_run(line_run, 14, encoded_run, 128);
    printf("%s\n", encoded_run); // 225211
}
