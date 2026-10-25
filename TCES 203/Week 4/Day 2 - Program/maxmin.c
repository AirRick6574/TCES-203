
/* Finds the largest and smallest elements in an array using pointers */

#include <stdio.h>

#define N 10

// max and min are pointers to integers
void max_min(int a[], int n, int *max, int *min);

int main(void)
{
    int b[N], i, big, small;

    printf("Enter %d numbers: ", N);

    for (i = 0; i < N; i++)
        scanf("%d", &b[i]);

    // & passes the memory addresses of big and small
    max_min(b, N, &big, &small);

    // big and small have been updated through pointers
    printf("Largest: %d\n", big);
    printf("Smallest: %d\n", small);

    return 0;
}

void max_min(int a[], int n, int *max, int *min)
{
    int i;

    // * dereferences the pointers to modify the original variables
    *max = *min = a[0];

    for (i = 1; i < n; i++) {
        if (a[i] > *max)
            *max = a[i];  // Updates big in main()
        else if (a[i] < *min)
            *min = a[i];  // Updates small in main()
    }
}