#include <stdio.h>
//self_func
int my_strlen(const char *s){
    int count = 0;
    while (s[count] != '\0')
    {
        count++;
    }
    return count;
    
}

int main(){
    printf("%d\n", my_strlen("")); // should output 0
    printf("%d\n", my_strlen("123")); // should output 3
    printf("%d\n", my_strlen("abc\n")); // should output 4
    printf("%d\n", my_strlen("lorem\0ipsum\n")); // should output 5
    printf("%d\n", my_strlen("lorem ipsum\n")); // should output 12

    return 0;
}