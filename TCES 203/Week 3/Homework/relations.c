#include <stdio.h>

int main(void){

    int a, b, c;

    printf("Enter 3 Integers: ");
    scanf("%1d %1d %1d", &a, &b, &c);

    printf("a < b: %d\n", a < b);
    printf("b <= c: %d\n", b <= c);
    printf("a == c: %d\n", a == c);
    printf("a < b && b < c: %d\n", a < b && b < c);
    printf("a < b || b > c: %d\n", a < b || b > c); //OR statement
    printf("!(a == b): %d\n", !(a == b)); 

    return 0;

}