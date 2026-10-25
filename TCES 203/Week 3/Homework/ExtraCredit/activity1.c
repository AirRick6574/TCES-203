// Activity 1 — TODO

#include <stdio.h>

static void flushline(void) {
    int t; while ((t = getchar()) != '\n' && t != EOF) { }
}

int main(void) {
    int current_i = 0;
    double current_d = 0.0;
    char cmd = '\0';

    do {
        printf("\n[i] set int  [d] set double  [q] quit\n> ");
        if (scanf(" %c", &cmd) != 1) return 0;

        switch (cmd) {
            case 'i': {
                printf("Enter int: ");
                if (scanf("%d", &current_i) == 1) {
                    /* TODO: print the stored integer value */
                }
                flushline();
                break;
            }
            case 'd': {
                printf("Enter double: ");
                if (scanf("%lf", &current_d) == 1) {
                    /* TODO: print the stored double value using %f */
                }
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
