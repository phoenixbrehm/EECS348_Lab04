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
        printf("\n%d can be achieved by:\n", enter);
        if(enter <= 1){
            exit = 0;
        }
        else{
            scoreFinder(enter);
        }
    }
    printf("Quitting...");
}


int scoreFinder(int score){
    /*
    Types of scoring
    8a+7b+6c+3d+2e=score
    */
   //We want to use above equation to find the score values. Then once we find a valid one, take the biggest factor and -1


   //METHOD Incremental Counting
    for(int a = 0;a <= (score/8)+1;a++){ //we will only iterate as many times as we need to because of score/value+1
        for(int b = 0; b <= (score/7)+1;b++){
            for(int c = 0; c <= (score/6)+1; c++){
                for(int d = 0; d <= (score/3)+1; d++){
                    for(int e = 0; e <= (score/2)+1; e++){
                        if(a*8+b*7+c*6+d*3+e*2 == score){ //If all the added values for our loops equal the intened score, print
                            printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", a, b, c, d, e);
                        }
                    }
                }
            }
        }
    }

}