#include <stdio.h>
#include "Quiz1.h"

int numerator, denominator;

int main(void){
    //question2();
    //q3();
    //q5();
    //q1();
    q4();
}

void question2()
{
    printf("Enter a fraction: ");
    scanf("%d /%d", &numerator, &denominator);
    printf("Fraction: %d, %d", numerator, denominator);
}


void q3()
{
    int total = 10;
    int multiplier = 3;
    int surcharge = 2;

    //total *= multiplier + surcharge;
    total = total * multiplier + surcharge;
    printf("Total: %d\n", total);

}

void q5(){
    int numbers[5] = {10, 20, 30, 40, 50};
    int sum = 0;
    int i;

    for (i = 0; i < 5; i++){
        sum += numbers[i];
    }

    printf("Sum: %d\n", sum);

}

void q1(){
    int total = 0;
    int additional = 10;

    total = total + additional;

    printf("Total: %d\n", total);
}

void q4(){
    int status = 2;

    switch(status) {
        case 1:
            printf("Pending\n");
        case 2:
            printf("Approved\n");
        case 3:
            printf("Rejected\n");
        default:
            printf("Unknownn\n");
    }
   
}
