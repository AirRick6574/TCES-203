#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>

int main(void){
    float r = 10.0; 
    float formula = (4.0f / 3.0f) * M_PI * (r * r * r);

    printf("Volume of a Sphere with a 10 meter radius is %.2f\n", formula);
}