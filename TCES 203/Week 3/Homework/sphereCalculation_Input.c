#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>

int main(void){
    float r; 

    //Prompt user for radius
    printf("Please enter the radius of the sphere: ");
    scanf("%f", &r);

    //Calculate volume
    float formula = (4.0f / 3.0f) * M_PI * (r * r * r);

    //Output Volume
    printf("Volume of a Sphere with a %.2f meter radius is %.2f\n", r, formula);
}