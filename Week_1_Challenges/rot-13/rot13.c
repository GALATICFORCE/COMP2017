#include <stdio.h>
//fgets
int main(){
    char str[1000];

    while(fgets(str, sizeof(str), stdin) != NULL){
        for (int i = 0; str[i] != '\0'; i++){
            if(str[i] >= 'a' && str[i] <= 'z'){
                str[i] = ((str[i] - 'a' + 13) % 26) + 'a';
            }else if (str[i] >= 'A' && str[i] <= 'Z'){
                str[i] = ((str[i] - 'A' +13) % 26) + 'A';
            }
            
        }

        printf("%s", str);
        
    }
    return 0;
}