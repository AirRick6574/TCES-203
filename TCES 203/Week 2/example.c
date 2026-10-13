#include <stdio.h>

int main() {
    int i, j;
    float x, y;

    i = 10;
    j = 29;
    x = 43.2892f; //f was placed there to avoid compiler issues as the number will be treated as a 64 bit double
    y = 5527.0f; //assigning f will silence the "loss of precision" silencer

    printf("i = %d, j = %d, x = %f, y = %f\n", i, j, x, y);
}