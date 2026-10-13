/* Calculates a broker's commission*/

#include <stdio.h>

int main(void){

    float commission, value;

    printf("Enter value of trade: ");
    scanf("%f", &value);

    switch (value < 2500.00f ? 1 :
        value < 6250.00f ? 2:
        value < 20000.00f ? 3:
        value < 50000.00f ? 4:
        value < 500000.00f ? 5: 6)
        {
            case 1:
            commission = 30.00f + .017f * value;
            break;

            case 2:
            commission = 76.00f + .0034f * value;
            break;

            case 3:
            commission =  76.00f + .0034f * value;
            break;

           case 4:
           commission = 100.00f + .0022f * value;
           break;

           case 5:
           commission = 155.00f + 0.11f * value;
           break;

           case 6:
           commission = 255.00f + .0009f * value;
           break;

           default: commission = 39.00f;
        }

        printf("Commission: $%.2f\n", commission);

        

}