#include <stdio.h>

int main(void)
{
    int x = 3, y = 7;
    int *p = &x;
    int *q = &y;

    *p = *q;
    q = p;
    *q += 5;

    printf("%d %d\n", x, y);
    return 0;
}