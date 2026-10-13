#include <stdio.h>
int main() {

    int i, j;
    float x, y;

    i = 10;
    j = 20;
    x = 43.2892f;
    y = 5527.0f;

    printf("i = %d, j = %d, x = %f, y = %f\n", x, y, i, j);

}
/* Wrong format specifiers lead to printf() not printing the values properly.
This causes the output to be garbage values or unexpected results */ 