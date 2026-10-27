#include <stdio.h>

int main(void) {
    int value = 10;
    int *p;

    p = &value;

    *p = 25;

    printf("Value: %d\n", value);

    return 0;
}