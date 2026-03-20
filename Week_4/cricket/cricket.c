#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* first_name;
    char* last_name;
    int score;
}cricketer;

int main(void){
    cricketer team[11];
    char first[101], last[101];
    int cnt = 0;

    for (int i = 0; i < 11; i++)
    {
        printf("Enter Name and Score for batter %d: ", i + 1);
        scanf("%100s %100s %d",first,last,&team[i].score);

        //molloc 动态分配内存（不需要再限定struct长度需求）
        team[i].first_name = malloc(strlen(first));
        team[i].last_name = malloc(strlen(last));
        strcpy(team[i].first_name, first);
        strcpy(team[i].last_name, last);

        cnt += team[i].score;
    }

    printf("\n");
        for (int i = 0; i < 11; i++) {
                printf("%d. %c. %s: ", i + 1, team[i].first_name[0], team[i].last_name);
                if (team[i].score == 0) {
                    printf("Duck\n");
                } else {
                    printf("%d\n", team[i].score);
                }

                free(team[i].first_name);
                free(team[i].last_name);
            }

    printf("Total: %d\n", cnt);
    return 0;
    





}