#include <stdio.h>

int main(void){

    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (num < 0)
    {
        printf("Number is negative\n");
    }
    else if (num == 0)
    {
        printf("Number is zero\n");
    }
    else 
    {
        printf("Number is positive\n");
    }
    if (num % 2 == 1)
    {
        printf("Number is odd\n");
    }
    else
    {
        printf("Number is even\n");
    }
}