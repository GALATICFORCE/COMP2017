#include <stdio.h>

int string_compare(const char* w1, const char* w2, unsigned int len) {  
    int res = 0;
    for(int i = 0;i < len && w1[i] != '\0' && w2[i] != '\0';i++){
            if(w1[i] - w2[i] == 0 ){
                res = 0;
            }else{
                res = w1[i] - w2[i];
                return 1;
            }
        }

    return res;
}

void main(void) {
    int result;
    result = string_compare("Hello", "Hello", 5);
    printf("%d\n", result);
    result = string_compare("Hello", "byebye", 5);
    printf("%d\n", result);
    // TODO: Write more test below

}
