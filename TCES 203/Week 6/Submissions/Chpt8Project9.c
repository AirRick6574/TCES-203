#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10
#define LIMIT 0

//Create 10 x 10 array that will start with every text being "."
//Have the program randomly walk from element to element, going up, down, left, or right, by one element. 
//The walk will change each elemenmt to letters from A to Z, starting with A and ending with Z.
//Use rand or srand to generate random numbers and divide by 4, the 0, 1, 2, 3 will repesent the direction to go. 
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
