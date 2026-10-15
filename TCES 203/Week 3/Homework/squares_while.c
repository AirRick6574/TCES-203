#include <stdio.h>

//Reusing an old function made from previous assignment
long long exponential(int power, int input){
    long long output = 1;
    for (int i = 0; i < power; i++){
        output = output * input;
    }
    return output;
}

int main(void){
    int n, i = 1;

    printf("Enter number of entries in table: ");
    scanf("%d", &n);

    while(i <= n) {
        printf("%10d%10lld\n", i, exponential(2, i));
        i++;
    }
}