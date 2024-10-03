/*
Phoenix Brehm
EECS 348
Th 11AM
Lab04
Goal: To take in a NFL score, and output all possible combinations for a given score
*/
#include <stdio.h>
#include <windows.h>
int main(){
    int enter;
    int exit = 1;
    while(exit){
        printf("Enter a number less than or equal to 1 to quit\n");
        printf("What score do you wish to enter: ");
        scanf("%d", &enter);
        if(enter <= 1){
            exit = 0;
        }
        else{
            scoreFinder(enter, 0, 0, 0, 0, 0);
        }
    }
    printf("Quitting...");
}


int scoreFinder(int score, int count8param, int count7param, int count6param, int count3param, int count2param){
    int count8 = count8param;
    int count7 = count7param;
    int count6 = count6param;
    int count3 = count3param;
    int count2 = count2param;
    /*
    Types of scoring
    8a+7b+6c+3d+2e=score
    */
   //We want to use above equation to find the score values. Then once we find a valid one, take the biggest factor and -1


   //METHOD Incremental Counting
    for(int i = 0;i <= (score/8)+1;i++){
        for(int j = 0; j <= (score/7)+1;j++){
            for(int k = 0; k <= (score/6)+1; k++){
                for(int l = 0; l <= (score/3)+1; l++){
                    for(int m = 0; m <= (score/2)+1; m++){
                        if(8*i+7*j+k*6+l*3+m*2 == score){
                            printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", i, j, k, l, m);
                        }
                    }
                }
            }
        }
    }

}