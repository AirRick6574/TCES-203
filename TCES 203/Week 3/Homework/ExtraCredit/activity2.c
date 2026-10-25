// Activity 2 - TODO

#include <stdio.h>
#include <ctype.h>

static void flushline(void) {
    int t; while ((t = getchar()) != '\n' && t != EOF) { }
}

int main(void) {
    int current_i = 0;
    double current_d = 0.0;
    char last_ch = '?';
    char cmd = '\0';

    do {
        printf("\n[i] set int  [d] set double  [c] char info  [u] uppercase  [q] quit\n> ");
        if (scanf(" %c", &cmd) != 1) return 0;

        switch (cmd) {
            case 'i': {
                printf("Enter int: ");
                if (scanf("%d", &current_i) == 1) {
                    printf("Stored int = %d\n", current_i);
                }
                flushline();
                break;
            }
            case 'd': {
                printf("Enter double: ");
                if (scanf("%lf", &current_d) == 1) {
                    printf("Stored double = %f\n", current_d);
                }
                flushline();
                break;
            }
            case 'c': {
                char ch;
                printf("Enter a non-space char: ");
                if (scanf(" %c", &ch) == 1) {
                    /* TODO: print ch's integer code and the “next” character (ch + 1) */

                    printf("Stored char = %c\n", ch);
                    printf("ASCII equilavent = %d\n", ch);
                    last_ch = ch;
                    char next_ch = (ch + 1);
                    printf("Next Char = %c\n", next_ch);
                    printf("Next Char in ASCII = %d\n", next_ch);
                }
                flushline();
                break;
            }
            case 'u': {
                char ch;
                printf("Enter a letter: ");
                if (scanf(" %c", &ch) == 1) {
                    /* TODO: convert to uppercase with toupper and print it; update last_ch */
                    char upper = toupper(ch);
                    printf("Uppercase = %c", upper);
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
