
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10
#define LIMIT 0

int main(void){
    //Create array
    int direction, x = LIMIT, y = LIMIT; 
    char array[SIZE][SIZE];
    for (int i = LIMIT; i < SIZE; i++){
        for (int j = LIMIT; j < SIZE; j++){
            array[i][j] = '.';
        }
    }

    srand(time(NULL));
    array[x][y] = 'A';
    //Create path
    for (char letter = 'B'; letter <= 'Z';){

    if ((x == LIMIT || array[x - 1][y] != '.') &&
        (x == SIZE - 1 || array[x + 1][y] != '.') &&
        (y == LIMIT || array[x][y - 1] != '.') &&
        (y == SIZE - 1 || array[x][y + 1] != '.')) {
        break;
    }
        direction = rand() % 4; // 0 = up, 1 = down, 2 = left, 3 = right
        switch (direction){
            case 0: // up
               if (x > LIMIT && array[x - 1][y] == '.'){
                    array[--x][y] = letter;
                    letter++;  
               }
               break;
            case 1: // down
                if (x < SIZE - 1 && array[x + 1][y] == '.'){
                    array[++x][y] = letter;
                    letter++;   
               }
               break;
            case 2: // left
                if (y > LIMIT && array[x][y - 1] == '.'){
                    array[x][--y] = letter;
                    letter++;
               }
               break;
            case 3: // right
                if (y < SIZE - 1 && array[x][y + 1] == '.'){
                    array[x][++y] = letter;
                    letter++;
               }
               break;
        }
    }

    //Display
    for (int i = LIMIT; i < SIZE; i++){
        for (int j = LIMIT; j < SIZE; j++){
            printf("%c ", array[i][j]);
        }
        printf("\n");
    }
    
    return 0;

}
