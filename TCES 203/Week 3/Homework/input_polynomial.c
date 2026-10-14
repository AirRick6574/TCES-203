#include <stdio.h>

//Using long long in case of large numbers
long long exponential(int power, int input){
    long long output = 1;
    for (int i = 0; i < power; i++){
        output = output * input;
    }
    return output;
}

int main(void){
    int input;
    long long polynomial;

    printf("Please input a whole number for the polynomial: ");
    scanf("%d", &input);

    polynomial = ((3 * exponential(5, input)) + (2 * exponential(4, input)) + (5 * exponential(3, input)) + (exponential(2, input)) + (7 * input) - 6);

    printf("Polynomial is: %lld\n", polynomial);
}