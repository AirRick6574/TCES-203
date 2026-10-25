#include <stdio.h>

int main(void){
    int n, d;

    printf("enter number: n > 1: ");
    scanf("%d", &n);

    for (d = 2; d <n && n % d != 0; d++)
    ; /*Empty Body*/

    printf("%d", d);
}