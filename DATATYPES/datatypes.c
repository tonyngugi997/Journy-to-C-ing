#include <stdio.h>  // header file for printf function

int main() {  // entry point - program starts here

    // Declare a string (char array) to store city name, max 50 chars
    char city[50] = "Nakuru";
    
    // Declare an integer to store population (whole number)
    int population = 2148000;
    
    // Declare a float to store temperature (decimal number)
    float average_temperature = 12.5;

    // Print all variables using format specifiers:
    // %s = string, %d = int, %.1f = float (1 decimal place)
    printf("City name is %s, the population is %d, the temperature is %.1f", 
           city, population, average_temperature);

    return 0;  // Exit program successfully (0 means no error)

};  // End of main function (extra semicolon is optional but harmless)