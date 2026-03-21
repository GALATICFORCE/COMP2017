#include <stdio.h>

struct batsman {
    char first_name[20];   
    char last_name[20];
    int score;
};

int output_scores(struct batsman* batter, int no_batsmen, const char* filename){
    FILE *fp = fopen(filename, "w");
    if (fp == NULL){
        return -1;
    }

    for (int i = 0; i < no_batsmen; i++)
    {
        if(batter[i].score == 0){
            fprintf(fp,"%s,%s,Duck\n",batter[i].first_name,batter[i].last_name);
        }else{
            fprintf(fp,"%s,%s,%d\n",batter[i].first_name,batter[i].last_name,batter[i].score);
        }
    }
    
    fclose(fp);
    return 0;
}


int main(void){
    // Test 1: 题目给的例子
    struct batsman team1[] = {
        {"Cameron", "Bancroft", 40},
        {"Mitchell", "Marsh", 67},
        {"David", "Warner", 59},
        {"Ben", "McDermott", 0},
        {"Cameron", "White", 78},
        {"Usman", "Khawja", 54}
    };
    output_scores(team1, 6, "test1.csv");

    // Test 2: 全是Duck (score都为0)
    struct batsman team2[] = {
        {"John", "Smith", 0},
        {"Jane", "Doe", 0}
    };
    output_scores(team2, 2, "test2.csv");

    // Test 3: 只有一个人
    struct batsman team3[] = {
        {"Steve", "Smith", 100}
    };
    output_scores(team3, 1, "test3.csv");

    // Test 4: 空数组
    output_scores(NULL, 0, "test4.csv");

    printf("All tests done. Check test1~4.csv\n");
    return 0;






}