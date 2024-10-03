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
    8pts    2*2*2*2
    7pts
    6pts    2*3
    3pts
    2pts

    8a+7b+6c+3d+2e=score

    */
   //8*count8+7*count7+6*count6+3*count3
   //We want to use above equation to find the score values. Then once we find a valid one, take the biggest factor and -1

    count2 = (score / 2) - count2;
    if(count2 < 0){
        count2 = 0;
    }
    count3 = ((score-(2*count2)) / 3) - count3;
    if(count3 < 0){
        count3 = 0;
    }
    count6 = ((score-(2*count2+3*count3)) / 6) - count6;
    if(count6 < 0){
        count6 = 0;
    }
    count7 = ((score-(2*count2+3*count3+6*count6)) / 7) - count7;
    if(count7 < 0){
        count7 = 0;
    }
    count8 = ((score-(2*count2+3*count3+6*count6+7*count7)) / 8) - count8;
    if(count8 < 0){
        count8 = 0;
    }
    //printf("COUNT 2 = %d\n", count2);
    //Sleep(500);


    if(score-(8*count8+7*count7+6*count6+3*count3+2*count2) == 0){
        printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", count8, count7, count6, count3, count2);

        //int sanity = 8*count8+7*count7+6*count6+3*count3+2*count2;
        //printf("SANITY CHECK: %d\n", sanity);

    }
    else if(count8 == 0 && count7 == 0 && count6 == 0 && count3 == 0 && count2 == 0){       /*Exit Condition*/
        return 1;
    }


    if(count2 != 0){
        scoreFinder(score, count8param, count7param, count6param, count3param, count2param+1);
    }
    else if(count3 != 0){
        scoreFinder(score, count8param, count7param, count6param, count3param+1, 0);
    }
    else if(count6 != 0){
        scoreFinder(score, count8param, count7param, count6param+1, 0, 0);
    }
    else if(count7 != 0){
        scoreFinder(score, count8param, count7param+1, 0, 0, 0); /*Will decrement "b" by 1 while keeping a=0*/
    }
    else if(count8 != 0){
        scoreFinder(score, count8param+1, 0, 0, 0, 0); /*Will input value with "a" in our equation decremented by 1 during the count8=(score/8)-count8 line*/
    }
         

}