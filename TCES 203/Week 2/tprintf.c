/* Prints int and float values in various formats*/

#include <stdio.h>

int main(void)
{
    int i;
    float x;

    i = 40;
    x = 839.21f;

    //These are format adjusters which will adjust the position of the text, f and d are also the value that is expected
    //With f being float value expected and d being integer
    
    //%d means normal. %5d means include 5 spaces, %-5d means remove 5, %5.3d means minimum width of 5 spaces and 3 digits
    printf("|%d|%5d|%-5d|%5.3d|\n", i,i,i,i); 
    
    //e is a scientific notation while g is a intelligent that will try to trim down the number
    printf("|%10.3g|%10.3e|%-10g|\n", x,x,x);

    return 0;
}