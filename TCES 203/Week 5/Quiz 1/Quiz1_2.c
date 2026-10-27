#include <stdio.h>

int generate_id(void){
    static int id = 100;

    id++;
    return id;
}

int main(void){
    int first = generate_id();
    int second = generate_id();

    printf("%d %d \n", first, second);
    return 0;
}
