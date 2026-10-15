#include <stdio.h>

int main(void){
    int n, i = 1, square = 1, odd = 3;

    printf("Enter number of entries in table: ");
    scanf("%d", &n);
    
    for (; i <= n; i++, square += odd, odd += 2)
    printf("%10d%10d\n", i, square);
}