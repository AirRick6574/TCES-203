#include <stdio.h>

int main(void){
    float balance = 0.0f, credit, debit;
    int cmd;

    for(;;){
        printf("0 = Clear, 1 = Credit, 2 = Debit, 3 = Balance, 4 = Exit\n");
        scanf("%d", &cmd);
        switch (cmd)
        {
        case 0:
            balance = 0.0f;
            printf("Balance was reset\n");
            break;

        case 1:
            printf("Select amount of credit to add: ");
            scanf("%f", &credit);
            balance += credit;
            break;
        
        case 2:
            printf("Select withdrawal amount: ");
            scanf("%f", &debit);
            balance -= debit;
            break;

        case 3:
            printf("Balance is %.2f\n", balance);
            break;

        case 4: 
            return 0;
        
        default:
            printf("Invalid Command\n");
            break;
        }
    }
}