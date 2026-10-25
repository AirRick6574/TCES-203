// Activity 4 — TODO

#include <stdio.h>
#include <stdbool.h>

typedef double Dollars;

static void flushline(void) {
    int t; while ((t = getchar()) != '\n' && t != EOF) { }
}

int main(void) {
    int current_i = 0;
    double current_d = 0.0;
    char last_ch = '?';
    bool verbose = false;
    char cmd = '\0';

    do {
        printf("\n[i] int  [d] double  [c] char  [u] upper  [p] price  [t] toggle verbose  [q] quit\n> ");
        if (scanf(" %c", &cmd) != 1) return 0;

        switch (cmd) {
            case 'i': {
                printf("Enter int: ");
                if (scanf("%d", &current_i) == 1) { /* TODO: optionally print */ }
                flushline();
                break;
            }
            case 'd': {
                printf("Enter double: ");
                if (scanf("%lf", &current_d) == 1) { /* TODO: optionally print */ }
                flushline();
                break;
            }
            case 'c': {
                char ch;
                printf("Enter char: ");
                if (scanf(" %c", &ch) == 1) { last_ch = ch; /* TODO: optionally print */ }
                flushline();
                break;
            }
            case 'u': {
                char ch;
                printf("Enter letter: ");
                if (scanf(" %c", &ch) == 1) {
                    /* TODO: convert to uppercase and store in last_ch; print result */
                }
                flushline();
                break;
            }
            case 'p': {
                Dollars price;
                printf("Enter price: ");
                /* TODO: read price using %lf and print it using %f */
                scanf("%lf", &price);
                printf("Dollars: %.2f", price);
                flushline();
                break;
            }
            case 't': {
                /* TODO: toggle verbose and print its new state */
                verbose = !verbose; 
                if(verbose){
                    printf("Verbose Status: True\n");
                } else{
                   printf("Verbose Status: False\n"); 
                }
                
                break;
            }
            case 'q':
                printf("Bye.\n");
                break;
            default:
                printf("Unknown command.\n");
        }

        if (verbose && cmd != 'q') {
            /* TODO: include last_ch when you track it */
            printf("[state] int=%d  double=%f  last_ch=%c\n", current_i, current_d, last_ch);
        }
    } while (cmd != 'q');

    return 0;
}
