// Computes Dimensional weight from input

#include <stdio.h>

int main(void)
{
    /*
    *   Placeholder for interger: %d
    *   Placeholder for Float: %f
    */
    int height, length, width, volume;

    printf("Enter height of box: ");
    scanf("%d", &height);
    printf("Enter length of box: ");
    scanf("%d", &length);
    printf("Enter width of box: ");
    scanf("%d", &width);

    volume = height * length * width;

    #define INCHES_PER_POUND 166
    int weight = (volume + INCHES_PER_POUND - 1) / INCHES_PER_POUND;

    printf("Weight: %d", weight);

    return 0;
}