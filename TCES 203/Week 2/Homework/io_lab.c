/*
*/

#include <stdio.h>

int main(void)
{
    int x, y;
    float m, z;

    x = 10;
    y = 20;

    m = 43.29f;
    z = 5.527245f;

    printf("Item\tValue\tNotes\n");
    printf("Demo\t \"quotes and a single backslash: \\ \n");

    printf("Ints\t|%5d|%-8.5d|\n", x, y);
    printf("Floats\t|%15.3e|%8.4g|\n\n", m, z);

    int mm, dd, hh, mm_2;
    int a_1, b_1, a_2, b_2;
    int result_num, result_denom;
    
    //Date
    printf("Enter a date (mm/dd): ");
    scanf("%d/%d", &mm, &dd);

    //Time
    printf("Enter a time (hh:mm): ");
    scanf("%d:%d", &hh, &mm_2);

    //First Fractions
    printf("Enter first fraction (a/b): ");
    scanf("%d/%d", &a_1, &b_1);
    
    //Seond Fractions
    printf("Enter second fraction (a/b): ");
    scanf("%d/%d", &a_2, &b_2);


    result_num = a_1 * b_2 + a_2 *b_1;
    result_denom = b_1 * b_2;


    //Outcomes
    printf("Summary for %d/%d at %d:%d\n", mm, dd, hh, mm_2);
    printf("----------------------------\n");
    printf("Entry\tNumer\tDenom\n");
    printf("First\t%d\t%d\n", a_1, b_1);
    printf("Second\t%d\t%d\n", a_2, b_2);
    printf("Sum\t%d\t%d\n", result_num, result_denom);

}