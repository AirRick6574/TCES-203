
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100  // Preprocessor macro, NOT a variable

/* ==========================================
   EXTERNAL (GLOBAL) VARIABLES
   ========================================== */

// These variables are declared outside all functions.
// They can be accessed by all functions in this file.
// They retain their values throughout program execution.

int contents[STACK_SIZE];
int top = 0;


/* ==========================================
   STACK FUNCTIONS (LIFO)
   ========================================== */

void make_empty(void)// i.e., expecting no parameters
{
    top = 0;  // Modifies the external variable
}

bool is_empty(void)
{
    return top == 0;
}

bool is_full(void)
{
    return top == STACK_SIZE;
}

void stack_overflow(void)
{
    printf("Error: Stack overflow!\n");
    exit(EXIT_FAILURE);
}

void stack_underflow(void)
{
    printf("Error: Stack underflow!\n");
    exit(EXIT_FAILURE);
}


/* ==========================================
   PUSH FUNCTION
   Demonstrates LOCAL and STATIC variables
   ========================================== */

void push(int i)
{
    // LOCAL VARIABLE
    // Initialized to 0 every time push() is called.
    int local_counter = 0;

    // STATIC LOCAL VARIABLE
    // Initialized only once.
    // Retains its value between calls to push().
    static int static_counter = 0;

    local_counter++;
    static_counter++;

    if (is_full()) {
        stack_overflow();
    } else {
        contents[top++] = i;
    }

    printf("\nPushed: %d\n", i);
    printf("Local counter:  %d\n", local_counter);
    printf("Static counter: %d\n", static_counter);
    printf("External top:   %d\n", top);
}


/* ==========================================
   POP FUNCTION
   Demonstrates access to external variables
   ========================================== */

int pop(void)
{
    if (is_empty()) {
        stack_underflow();
    }

    // Uses the same external variables as push()
    return contents[--top];
}


/* ==========================================
   MAIN FUNCTION
   ========================================== */

int main(void)
{
    printf("=== STACK VARIABLE DEMONSTRATION ===\n");

    printf("\nInitial top: %d\n", top);

    // Each call creates a new local_counter.
    // The static_counter retains its value.
    // The external top tracks the stack size.

    push(10);
    push(20);
    push(30);

    printf("\n=== POP OPERATION ===\n");

    printf("Popped: %d\n", pop());
    printf("External top after pop: %d\n", top);

    printf("\n=== EMPTYING STACK ===\n");

    make_empty();

    printf("External top after make_empty: %d\n", top);

    printf("\n=== PUSH AGAIN ===\n");

    // Observe what happens to the counters.
    push(40);

    return 0;
}

