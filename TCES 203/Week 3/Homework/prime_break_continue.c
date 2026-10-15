#include <stdio.h>
#include <stdbool.h>

int main(void){
    int n;

    //Ask and check
    while(true){
        printf("Enter an integer > 1: ");
        scanf("%d", &n);
        if (n <= 1)
        {
            printf("Must be > 1\n");
            continue;
        }
        break;
    }

    //Divisor
    for (int d = n - 1; d > 1; d--){
        if (n % d == 0) {
            printf("%d is divisible by %d\n", n, d);
            break;
        }
        continue;
    }


}

