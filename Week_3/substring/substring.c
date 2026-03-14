#include <string.h>
#include <stdio.h>

int substring(const char* line, const char* substr) {
    //TODO
    for (int i = 0;i < strlen(line);i++){
        for (int j = 0; j< strlen(substr); j++){
            if(line[i+j] != substr[j]){
                break;//i+j是为了把指针指在最早匹配上的位置
            }else if (j == strlen(substr) - 1){
                return i;
            }    
        }
    }
    return -1;
}

int main() {
    printf("%d\n", substring("racecar", "car")); //4
    printf("%d\n", substring("telephone", "one")); //6
    printf("%d\n", substring("monkey", "cat")); //-1
    return 0;
}

