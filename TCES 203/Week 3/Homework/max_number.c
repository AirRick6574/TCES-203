#include <stdio.h>

int main(void){
    int x, y, z;
    int largest = 0;

    printf("Enter 3 integers (x, y, z): ");
    scanf("%d %d %d", &x, &y, &z);

    //Part A:
    if (largest < x)
    {
        largest = x;
    } 
    if (largest < y)
    {
        largest = y;
    }
    if  (largest < z)
    {
        largest = z;
    }
    printf("%d\n", largest);

    //Part B
    printf("Largest: %d\n", (x > y ? (x > z ? x : z) : (y > z ? y : z)));
}