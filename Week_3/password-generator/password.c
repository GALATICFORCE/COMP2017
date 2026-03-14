#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc,char * argv[]){
    int length = atoi(argv[1]);

    srand(time(NULL));

    for (int i = 0;i < length;i++){
        char c = (rand() % 94) + 33;
        printf("%c",c);
    }

    printf("\n");

    return 0;
}