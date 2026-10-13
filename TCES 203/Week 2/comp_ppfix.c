#include <stdio.h>

int main(void)
{
    int x;
    int y;

    printf("Enter an integer value for x: ");
    scanf("%d", &x);

    printf("\nInitial value: x = %d\n", x);

    /* Compound assignment operators */
    x += 5;
    printf("After x += 5:  x = %d\n", x);

    x -= 2;
    printf("After x -= 2:  x = %d\n", x);

    x *= 3;
    printf("After x *= 3:  x = %d\n", x);

    x /= 2;
    printf("After x /= 2:  x = %d\n", x);

    x %= 5;
    printf("After x %%= 5:  x = %d\n", x);

    /* Prefix and postfix increment */
    printf("\nIncrement operators:\n");

    printf("Enter a new integer value for x: ");
    scanf("%d", &x);

    /* Postfix increment:
      y gets the current value of x first,
      then x is increased by 1. */
    y = x++;
    printf("y = x++  -> x = %d, y = %d\n", x, y);

    /* Prefix increment:
      x is increased by 1 first,
      then the new value of x is assigned to y. */
    y = ++x;
    printf("y = ++x  -> x = %d, y = %d\n", x, y);


    /* Prefix and postfix decrement */
    printf("\nDecrement operators:\n");

    /* Postfix decrement:
      y gets the current value of x first,
      then x is decreased by 1. */
    y = x--;
    printf("y = x--  -> x = %d, y = %d\n", x, y);

    /* Prefix decrement:
      x is decreased by 1 first,
      then the new value of x is assigned to y. */
    y = --x;
    printf("y = --x  -> x = %d, y = %d\n", x, y);

    /* Operator precedence */
    printf("\nOperator precedence:\n");

    x = 2 + 3 * 4;
    printf("2 + 3 * 4 = %d\n", x);

    x = (2 + 3) * 4;
    printf("(2 + 3) * 4 = %d\n", x);

    return 0;
}