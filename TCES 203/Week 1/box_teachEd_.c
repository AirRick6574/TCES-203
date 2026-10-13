#include <stdio.h> 

int main(void)
{
    int height, length, width, volume, weight;

    height = 8;
    length = 12;
    width = 10;
    volume = height * length * width;
    weight = volume / 166;

    //Placeholder that works only with integer
    printf("Dimensions: %dx%dx%d\n", length, width, height);
    printf("Volume (cubic inches): %d\n", volume);
    printf("Dimensional weight (pounds): %d\n", weight);

    return 0;
}

//Using Floaters
/**
    int main(void)
    {
        float height, length, width, volume, weight;

        height = 8;
        length = 12;
        width = 10;
        volume = height * length * width;
        weight = volume / 166;

        //Placeholder that works only with integer
        printf("Dimensions: %fx%fx%f\n", length, width, height);
        printf("Volume (cubic inches): %f\n", volume);
        printf("Dimensional weight (pounds): %f\n", weight);

        return 0;
    }
 * 
 */