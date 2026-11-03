/*
 * Chapters 10-11 Lab: Program Organization and Pointers
 * Starter code -- complete the TODOs without changing the menu structure.
 */
#include <stdio.h>
#define MAX_N 10
    /* Chapter 10: External (global) variable, with file scope. */
    int total_calls = 0;
/* Clears invalid characters remaining in the input stream. */
void clear_input(void)
{
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF)
    {
    }
}
/* Step 1: automatic local, static local, and external variable. */
void show_counters(void)
{
    int local_calls = 0;         /* Reset on each function call. */
    static int static_calls = 0; /* Retains its value across calls. */

    local_calls++;
    static_calls++;
    total_calls++;
    printf("Local: %d | Static: %d | Global: %d\n", local_calls, static_calls, total_calls);

}
/* Step 3: Use a pointer to modify a caller's variable. */
void add_ten(int *value)
{
    *value += 10;
    
}
/* Step 3: Use a pointer to modify a caller's variable. */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* Step 4: Return two answers through pointer parameters. */
void max_min(int values[], int n, int *maximum, int *minimum)
{
    /* TODO Step 4:
    - Start *maximum and *minimum at values[0].
    - Inspect the remaining elements using a loop.
    - Update *maximum and *minimum as needed.
    - The caller must ensure n >= 1.
    */
    
    *maximum = values[0];
    *minimum = values[0];
    for (int i = 1; i < n; i++) {
        if (values[i] > *maximum) {
            *maximum = values[i];
        }
        if (values[i] < *minimum) {
            *minimum = values[i];
        }
    }   

    return;

}
/* Step 4: Return the address of the larger of two integers. */
int *larger_pointer(int *a, int *b)
{
    /* TODO Step 4: Return a if *a >= *b; otherwise return b.
    Never return the address of a local variable here.
    */
    if (*a >= *b) {
        return a;
    } else {
        return b;
    }
}
int main(void)
{
    int choice = -1;
    int x = 0, y = 0;      /* Used in Steps 2 and 3. */
    int data[MAX_N] = {0}; /* Used in Step 4. */
    int n = 0;
    do
    {
        printf("\n=== Program Organization & Pointers Lab ===\n");
        printf("1) Step 1: Local, static, and global variables\n");
        printf("2) Step 2: Pointer basics and assignment\n");
        printf("3) Step 3: Pointers as function arguments\n");
        printf("4) Step 4: Maximum/minimum and pointer returns\n");
        printf("0) Quit\n");
        printf("Select: ");
        int result = scanf("%d", &choice);
        if (result == EOF)
        {
            printf("\nEnd of input.\n");
            break;
        }
        if (result != 1)
        {
            clear_input();
            printf("Please enter a menu number.\n");
            continue;
        }
        switch (choice)
        {
        case 1:
        {
            /* TODO Step 1:
            - Ask how many times to call show_counters (1..5).
            - Reject values outside this range.
            - Call show_counters that many times in a for loop.
            - Select case 1 again to observe retained counters.
            */
            printf("How many times would like you call show_counters (1..5)? ");
            scanf("%d", &n);
            if (n < 1 || n > 5) {
                clear_input();
                printf("Invalid number of calls.\n");
                break;
            }

            for (int i = 0; i < n; i++) {
                show_counters();
            }

            break;
        }
        case 2:
        {
            /* TODO Step 2:
            - Read x and y (check scanf returned 2).
            - Declare int *p = &x and int *q = &y.
            - Print x and y directly and via *p and *q.
            - Print &x and p with %%p, casting to (void *).
            - Execute *p = *q; print x and y.
            - Execute q = p; then *q += 5; print x and y.
            */
            printf("Declare X and Y\n");
            scanf("%d %d", &x, &y);
            int *p = &x;
            int *q = &y;
            printf("x = %d, y = %d\n", x, y);
            printf("*p = %d, *q = %d\n", *p, *q);
            printf("&x = %p, p = %p\n", (void *)&x, (void *)p);
            printf("&y = %p, q = %p\n", (void *)&y, (void *)q);
            *p = *q;
            printf("After *p = *q: x = %d, y = %d\n", x, y);
            q = p;
            *q += 5;
            printf("After q = p and *q += 5: x = %d, y = %d\n", x, y);
            break;
        }
        case 3:
        {

            printf("Declare X and Y\n");
            scanf("%d %d", &x, &y);

            printf("Before changes: x = %d, y = %d\n", x, y);
            add_ten(&x);
            printf("After add_ten: x = %d, y = %d\n", x, y);
            swap(&x, &y);
            printf("After swap: x = %d, y = %d\n", x, y);

            break;
        }
        case 4:
        {

            printf("How many elements (1..%d)? ", MAX_N);
            if (scanf("%d", &n) != 1) { 
                clear_input(); 
                printf("Input error.\n"); 
                break; }
            if (n < 1 || n > MAX_N) {
                printf("Out of range.\n");
                break;
            }  else{
                    printf("Enter %d integers:\n", n);
                    for (int i = 0; i < n; i++) {
                        if (scanf("%d", &data[i]) != 1) { 
                            clear_input(); 
                            printf("Input error.\n"); 
                            n = 0; 
                            break; 
                        }
                    } if (n == 0){
                            break;
                        }
                }
            int largest, smallest;
            max_min(data, n, &largest, &smallest);
            printf("Largest: %d, Smallest: %d\n", largest, smallest);
            int *larger = larger_pointer(&largest, &smallest);
            *larger += 1;
            printf("After incrementing the larger value:\n");
            printf("Largest: %d, Smallest: %d\n", largest, smallest);
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
    /* Suppress warnings before the students complete each step. */
    (void)x;
    (void)y;
    (void)data;
    (void)n;
    return 0;
}