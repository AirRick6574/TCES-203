// Activity 3 — TODO

#include <stdio.h>
#include <limits.h>

static void flushline(void) {
    int t; while ((t = getchar()) != '\n' && t != EOF) { }
}

int main(void) {
    int current_i = 0;
    double current_d = 0.0;
    char cmd = '\0';

    do {
        printf("\n[i] set int  [d] set double  [m] mixed div  [s] short/long  [w] unsigned  [q] quit\n> ");
        if (scanf(" %c", &cmd) != 1) return 0;

        switch (cmd) {
            case 'i': {
                printf("Enter int: ");
                if (scanf("%d", &current_i) == 1) printf("int=%d\n", current_i);
                flushline();
                break;
            }
            case 'd': {
                printf("Enter double: ");
                if (scanf("%lf", &current_d) == 1) printf("double=%f\n", current_d);
                flushline();
                break;
            }
            case 'm': {
                /* TODO: if current_d != 0, compute a double-precision quotient using a cast,
                        and also show an integer-division comparison (with guard for 0 divisor). */

                if(current_i == 0){
                    printf("Set a nonzero integer with [i] first.\n");
                }
                else if (current_d == 0.0) {
                    printf("Set a nonzero double with [d] first.\n");
                } else {
                    double casted = (double)current_i / current_d;
                    printf("Casted division: %f\n", casted);

                    // Convert the double to an integer for comparison
                    int divisor = (int)current_d;

                    if (divisor != 0)
                    {
                        int uncasted = current_i / divisor;
                        printf("Integer division: %d\n", uncasted);
                    }
                    else
                    {
                        printf("Cannot perform integer division (divisor becomes 0).\n");
                    }
                }
                break;
            }
            case 's': {
                short s;
                long l;
                printf("Enter <short> <long>: ");
                scanf("%hd %ld", &s, &l);
                printf("Short = %hd\n", s);
                printf("Long = %ld\n", l);
                /* TODO: read s and l with %hd and %ld; then print them with the same specifiers */
                flushline();
                break;
            }
            case 'w': {
                unsigned int u;
                printf("UINT_MAX = %u\n", UINT_MAX);
                printf("Enter unsigned int: ");
                scanf("%u", &u);
                printf("Scanned unsigned int = %u\n", u);
                printf("(U+1) = %u", (u+1));
                flushline();
                break;
            }
            case 'q':
                printf("Bye.\n");
                break;
            default:
                printf("Unknown command.\n");
        }
    } while (cmd != 'q');

    return 0;
}
