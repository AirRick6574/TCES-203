#include <stdio.h>
#include <ctype.h>

#define MAX_N 100
#define ROWS 10
#define COLS 10

void clear_input(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
    }
}

int main(void)
{
    int choice = -1;

    /* Step 1 state (1-D array) */
    int n = 0;
    int a1d[MAX_N] = {0};

    /* Step 3 state (2-D array) */
    int r = 0, c = 0;
    int m2d[ROWS][COLS] = {0};
    int check = 0;

    do
    {
        printf("\n=== Array Lab Menu ===\n");
        printf("1) Step 1: 1-D array basics\n");
        printf("2) Step 2: Use sizeof safely\n");
        printf("3) Step 3: 2-D array operations\n");
        printf("0) Quit\n");
        printf("Select: ");
        if (scanf("%d", &choice) != 1)
        {
            clear_input();
            continue;
        }

        switch (choice)
        {
        case 1:
        {
            char c_choice;
            /* TODO Step 1:
               - Ask for n (1..MAX_N)
               - Read n integers into a 1d[0..n-1]
               - Print them forward and then in reverse
               - Prompt for an index/value to edit and apply it if in range
            */
            printf("How many integers would you like to enter? (1-100): ");
            if (scanf("%d", &n) != 1)
            {
                clear_input();
                printf("Invalid input.\n");
                break;
            }

            if (n < 1 || n > MAX_N)
            {
                printf("Invalid size.\n");
                break;
            }

            // Read integers
            for (int i = 0; i < n; i++)
            {
                printf("Enter integer %d: ", i + 1);
                scanf("%d", &a1d[i]);
            }

            // Print forward
            printf("List of numbers: ");
            for (int i = 0; i < n; i++)
            {
                printf("%d ", a1d[i]);
            }

            // Print in reverse
            printf("\nIn Reverse: ");
            for (int i = n - 1; i >= 0; i--)
            {
                printf("%d ", a1d[i]);
            }
            printf("\n\n");

            //Modify Number
            printf("Would you like to modify a number in range? (Y or N) ");
            scanf(" %c", &c_choice);
            c_choice = toupper(c_choice);


            //(Note to Self) This overall could be simplified by just having one print statement
            //request both index/value at same time :(
            while(c_choice == 'Y'){
                int index, value;
                printf("Where in array would you like to modify? ");
                //Reuse N since at this point, the array will be created
                scanf("%d", &index);
                if (index < 0 || index >= n){
                    printf("INVALID RANGE\n");
                    continue;
                }
                printf("New value to replace: ");
                scanf("%d", &value);
                a1d[index] = value;

                // Print forward
                printf("List of numbers: ");
                for (int i = 0; i < n; i++)
                {
                    printf("%d ", a1d[i]);
                }

                //Run Again?
                printf("\nWould you like to modify a number in range? (Y or N) ");
                scanf(" %c", &c_choice);
                c_choice = toupper(c_choice);
            }   
            break;
        }

        case 2:
        {
            /* TODO Step 2:
               - Compute capacity = sizeof(a1d)/sizeof(a1d[0]) and print it
               - Clear the entire storage of a1d to zero using a capacity-based loop
               - If n>0, refill the first n elements, then compute and print their sum
               - Also print sizeof(a1d[0]) in bytes
            */

            //Compute and print capacity
            int capacity = sizeof(a1d) / sizeof(a1d[0]);
            int total_sum = 0;
            printf("\nCapacity = %d\n", capacity);

            //Clear storage of a1d
            for (int i = 0; i < capacity; i++){
                a1d[i] = 0;
            }
            
            if (n > 0){
                for (int i = 0; i < n; i++){
                    printf("Enter integer %d: ", i + 1);
                    scanf("%d", &a1d[i]);  
                    total_sum += a1d[i];
                }
            }

            printf("Sum of first %d elements = %d\n", n, total_sum);
            printf("Size of a1d[0] in bytes =  %zu\n", sizeof(a1d[0]));
            
            break;
        }
        

        case 3:
        {
            /* TODO Step 3:
               - Ask for r and c within 1..ROWS and 1..COLS
               - Read r*c integers into m2d row-by-row
               - Print the matrix in a grid
               - If square (r==c), transform into the identity matrix and print it
                 otherwise compute and print each row sum
            */
            
            //System does not account for not interger inputs, will bug out if nonint
            while (1){
                printf("Enter Rows (1..ROWS) and Cols (1..Cols): ");
                scanf("%d %d", &r, &c);
                if (r < 1 || r > ROWS || c < 1 || c > COLS){
                    clear_input();
                    printf("Invalid size.\n");
                    continue;
                }
                break;    
            }   
            
            //Read r*c integers into m2d row-by-row
            printf("Enter %d x %d integers (row by row): ", r, c);
            for (int i = 0; i < r; i++){
                for (int j = 0; j < c; j++){
                    if (scanf("%d", &m2d[i][j]) != 1) {
                        clear_input();
                        printf("Input error.\n");
                        break;
                    }    
                }
            }

            printf("Matrix:\n");
            //Print the matrix in a grid
            for (int i = 0; i < r; i++){
                for (int j = 0; j < c; j++){
                    printf("%d ", m2d[i][j]);
                }
                printf("\n");
            }

            //Check if identity matrix 
            if (r == c) {
                for (int i = 0; i < r; i++){
                    for (int j = 0; j < c; j++){
                        if (j == i){
                            m2d[i][j] = 1;
                        } else{
                            m2d[i][j] = 0;
                        }
                    }
                }

                check = 1;

                printf("Matrix:\n");
                //Print the matrix in a grid
                for (int i = 0; i < r; i++){
                    for (int j = 0; j < c; j++){
                        printf("%d ", m2d[i][j]);
                    }
                    printf("\n");
                }
            }

            

            //Calculate Row Sums 
            if (check == 0){
                for (int i = 0; i < r; i++){
                    int row_sum = 0;
                    for (int j = 0; j < c; j++){
                        row_sum += m2d[i][j];
                    }
                    printf("Row %d sum: %d\n", i + 1, row_sum);
                }
            }   else {
                printf("Matrix is square, no row sums calculated.\n");
            }

            check = 0;
            break;
        }

        case 0:
            printf("Goodbye!\n");
            break;
        default:
            printf("Invalid choice.\n");
            break;
        }
    } while (choice != 0);

    return 0;
}