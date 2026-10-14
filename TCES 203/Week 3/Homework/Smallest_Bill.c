#include <stdio.h>

int main(void){
    int dollar_input;

    printf("Enter a dollar amount: ");
    scanf("%d", &dollar_input);

    printf("$20 bills: %d\n", dollar_input/20);
    printf("$10 bills: %d\n", (dollar_input % 20) / 10); 
    printf("$5 bills: %d\n", (dollar_input % 10) / 5); 
    printf("$1 bills: %d\n", dollar_input % 5); 

}