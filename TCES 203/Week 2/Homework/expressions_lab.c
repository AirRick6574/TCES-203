#include <stdio.h>

int main(void){

    int x, y, sum, difference, product, div, rem, a, b, c;
    float fl_div;

    //Two Integers
    printf("\nEnter two integers: ");
    scanf("%1d%1d", &x, &y);

    sum = x + y;
    difference = x - y;
    product = x * y;
    div = x / y;
    rem = x % y;
    fl_div = (float) x / y;

    printf("Sum = %d\n", sum);
    printf("Difference = %d\n", difference);
    printf("Product = %d\n", product);
    printf("Integer Division = %d\n", div);
    printf("Remainder = %d\n", rem);
    printf("Floating Division = %f\n\n", fl_div);

    //Three Integers Checkpoint
    printf("Enter three integers: ");
    scanf("%1d%1d%1d", &a, &b, &c);

    printf("a + b * c = %1d\n", a+b*c);
    printf("(a + b) * c = %1d\n", (a+b)*c);
    printf("a - b - c = %1d\n", a-b-c);
    printf("(a - b) - c = %1d\n\n", (a-b)-c);

    //Increment and Decrement
    //The difference between i++ and ++i is when they are incremented.
    //i++ is evaluated to current value of i and then incremented by 1
    //While ++i is incremented by 1 and then the expression is used.

    int i, j, k;
    i = 1; 
    j = 2;
    k = ++i + j++;

    printf("Using ++i and j++:\n");
    printf("i = %d, j = %d, k = %d\n", i, j, k);

    i = 1;
    j = 2;
    k = i++ + j++;

    printf("Using i++ and j++:\n");
    printf("i = %d, j = %d, k = %d\n\n", i, j, k);

    //Compound Assignments
    x = 10;
    printf("x = %d\n", x);
   
    x += 5;
    printf("x += 5 = %d\n", x);
    
    x -= 3;
    printf("x -= 3 = %d\n", x);

    x *= 2;
    printf("x *= 2 = %d\n", x);

    x /= 4;
    printf("x /= 4 = %d\n\n", x);

    //UPC 
    int i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, d1, d2, t;
    printf("Enter 11 UPC digits: ");
    scanf("%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d", 
        &i1, &i2, &i3, &i4, &i5, &i6, &i7, &i8, &i9, &i10, &i11);

    d1 = i1 + i3 + i5 + i7 + i9 + i11;
    d2 = i2 + i4 + i6 + i8 + i10;

    t = 9 - ((((d1 * 3) + d2) - 1) % 10);

    
    // 0 1 3 8 0 0 1 5 1 7 3
    printf("Check digit = %d", t);


}