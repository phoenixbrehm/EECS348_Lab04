/*
Phoenix Brehm
EECS 348
Th 11AM
Lab04
Goal: To take in a temperature and convert it between f, c, and k. And then display category of the temperature
*/
#include <stdio.h>


//Function for printing the temp categories
void categorize_temperature(float celsius){
    if(celsius < 0.0){
        printf("\nTemperature Category: Freezing\nWeathor Advisory: Bring a winter coat and wear warm clothes");
    }
    else if (celsius >= 0.0 && celsius < 10.0){
        printf("\nTemperature Category: Cold\nWeathor Advisory: Wear some warm clothes");
    }
    else if(celsius >= 10.0 && celsius < 25.0){
        printf("\nTemperature Category: Comfortable\nWeathor Advisory: None needed");
    }
    else if(celsius >= 25.0 && celsius < 35.0){
        printf("\nTemperature Category: Hot\nWeathor Advisory: Stay hydrated");
    }
    else if(celsius >= 35.0){
        printf("\nTemperature Category: Extreme Heat\nWeathor Advisory: Stay inside and stay hydrated");
    }
    else{
        printf("ERROR ELSE IN CATEGORIZE_TEMPERATURE REACHED"); //error output just in case
    }
}



/*Conversion functions*/
float celsius_to_fahrenheit(float celsius){ //returns fahrenheit
    return ((9.0/5.0)*celsius)+32.0;
}
float fahrenheit_to_celsius(float fahrenheit){ //returns celsius
    return (5.0/9.0)*(fahrenheit-32.0);
}
float celsius_to_kelvin (float celsius){ //returns kelvin
    return celsius + 273.15;
}
float kelvin_to_celsius(float kelvin){ //returns celsius
    return kelvin - 273.15;
}
float fahrenheit_to_kelvin(float fahrenheit){ //returns kelvin
    return celsius_to_kelvin(fahrenheit_to_celsius(fahrenheit)); //take the f, convert to c, convert c to k
}
float kelvin_to_fahrenheit(float kelvin){ //returns fahrenheit
    return celsius_to_fahrenheit(kelvin_to_celsius(kelvin)); //take the k, convert to c, convert c to f
}




//Function used as a one stop for converting any kind of temp to celsius
float convCUniversal(float temp, int tempType){
    if(tempType == 1){
        return temp;
    }
    else if(tempType == 2){
        return fahrenheit_to_celsius(temp);
    }
    else if(tempType == 3){
        return kelvin_to_celsius(temp);
    }
    else{
        printf("ERROR REACHED ELSE IN CONVCUNIVERSAL"); //Error output in case
    }
}


int main(){
    //Variable declaration
    float temperEnter;
    int temperTypeEnter, temperTarget;
    int exit = 0;

    //Loop allows for input to be repeated
    while(!exit){

        //obtains user input
        printf("Enter a temperature: ");
        scanf("%f", &temperEnter);
        printf("\nWhat is this temperature measured in (1) Celsius (2) Fahrenheit or (3) Kelvin: ");
        scanf("%d", &temperTypeEnter);
        printf("\nWhat is the target conversion (1) Celsius (2) Fahrenheit or (3) Kelvin: ");
        scanf("%d", &temperTarget);


        //in the case of negative kelvin error check
        if(temperEnter < 0 && temperTypeEnter == 3){
            printf("\nKelvin Values Cannot be negative try again\n");
        }
        else{
            //disables the while loop
            exit = 1;


            if(temperTarget == 2 && temperTypeEnter == 1){
                printf("%f Celsius converts to %f Fahrenheit", temperEnter, celsius_to_fahrenheit(temperEnter));
            }
            else if(temperTarget == 1 && temperTypeEnter == 2){
                printf("%f Fahrenheit converts to %f Celsius", temperEnter, fahrenheit_to_celsius(temperEnter));
            }
            else if(temperTarget == 3 && temperTypeEnter == 1){
                printf("%f Celsius converts to %f Kelvin", temperEnter, celsius_to_kelvin(temperEnter));
            }
            else if(temperTarget == 1 && temperTypeEnter == 3){
                printf("%f Kelvin converts to %f Celsius", temperEnter, kelvin_to_celsius(temperEnter));
            }
            else if(temperTarget == 3 && temperTypeEnter == 2){
                printf("%f Fahrenheit converts to %f Kelvin", temperEnter, fahrenheit_to_kelvin(temperEnter));
            }
            else if(temperTarget == 2 && temperTypeEnter == 3){
                printf("%f Kelvin converts to %f Fahrenheit", temperEnter, kelvin_to_fahrenheit(temperEnter));
            }
            else{
                //if none of the above conditions are met the user input an incorrect temperature type or target value
                printf("\nTarget and/or Entered Temperature Type is invalid, try again.\n");
                exit = 0; //reenables the while loop
                continue; //skips the categorize section
            }
            categorize_temperature(convCUniversal(temperEnter, temperTypeEnter)); //convert to c then input c into cat_temp


            //allows user to end program and close window when they want
            printf("\nType anything then Press Enter to End Program\n");
            int ender;
            scanf("%d", &ender);
        }
    }

}