#include <stdio.h>

int main(void){
    int month, grade;

    printf("Please input a month (1-12): ");
    scanf("%d", &month);

    switch (month)
    {
    case 1:
    {
        printf("January\n");
        break;
    }
    case 2:
    {
        printf("February\n");
        break;
    }
    case 3:
    {
        printf("March\n");
        break;
    }
    case 4:
    {
        printf("April\n");
        break;
    }
    case 5:
    {
        printf("May\n");
        break;
    }
    case 6:
    {
        printf("June\n");
        break;
    }
    case 7:
    {
        printf("July\n");
        break;
    }
    case 8:
    {
        printf("August\n");
        break;
    }
    case 9:
    {
        printf("September\n");
        break;
    }
    case 10:
    {
        printf("October\n");
        break;
    }
    case 11:
    {
        printf("November\n");
        break;
    }
    case 12:
    {
        printf("December\n");
        break;
    }
    default:
        printf("Invalid Match");
        break;
    }

    printf("Please input a grade (0-4): ");
    scanf("%d", &grade);

    switch (grade)
    {
    case 1:
    {
        printf("Bad");
        break;
    }
    case 2:
    {
        printf("Okay");
        break;
    }
    case 3:
    {
        printf("Good");
        break;
    }
    case 4:
    {
        printf("Excellent");
        break;
    }

    default:
    {   
        printf("Invalid Match");
        break;
    }
    }

}