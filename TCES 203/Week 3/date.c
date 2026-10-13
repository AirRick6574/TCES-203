/* Prints a date in legal form */

#include <stdio.h> // This is not a statement; it's a preprocessor directive.

int main(void) // This is not a statement; it's a function declaration.
{
  int month, day, year; // This is a statement (declaration statement).

  printf("Enter date (mm/dd/yy): "); // This is a statement (expression statement).
  scanf("%d /%d /%d", &month, &day, &year); // This is a statement (expression statement).

  printf("Dated this %d", day); // This is a statement (expression statement).
  switch (day) { // This is a statement (control flow statement).
    case 1: case 21: case 31:
      printf("st"); break; // Two statements here: one expression (printf) and one control (break).
    case 2: case 22:
      printf("nd"); break; // Two statements here: one expression (printf) and one control (break).
    case 3: case 23:
      printf("rd"); break; // Two statements here: one expression (printf) and one control (break).
    default: printf("th"); break; // Two statements here: one expression (printf) and one control (break).
  } // End of switch block.

  printf(" day of "); // This is a statement (expression statement).

  switch (month) { // This is a statement (control flow statement).
    case 1:  printf("January");   break; // Two statements: one expression (printf) and one control (break).
    case 2:  printf("February");  break; // Two statements: one expression (printf) and one control (break).
    case 3:  printf("March");     break; // Two statements: one expression (printf) and one control (break).
    case 4:  printf("April");     break; // Two statements: one expression (printf) and one control (break).
    case 5:  printf("May");       break; // Two statements: one expression (printf) and one control (break).
    case 6:  printf("June");      break; // Two statements: one expression (printf) and one control (break).
    case 7:  printf("July");      break; // Two statements: one expression (printf) and one control (break).
    case 8:  printf("August");    break; // Two statements: one expression (printf) and one control (break).
    case 9:  printf("September"); break; // Two statements: one expression (printf) and one control (break).
    case 10: printf("October");   break; // Two statements: one expression (printf) and one control (break).
    case 11: printf("November");  break; // Two statements: one expression (printf) and one control (break).
    case 12: printf("December");  break; // Two statements: one expression (printf) and one control (break).
  } // End of switch block.

  printf(", 20%.2d.\n", year); // This is a statement (expression statement).
  return 0; // This is a statement (return statement).
}

// The total number of statements in this program is 30.

/*
 A statement in C is an instruction that the compiler can execute. 
 It performs some action or operation and ends with a semicolon (;), 
 except for control flow blocks which may not always have a semicolon 
 but still contain statements inside them. 
 Common types of statements include:
 - Declaration statements (e.g., int x;)
 - Expression statements (e.g., x = 5;)
 - Control flow statements (e.g., if, switch, for, while)
 Each complete instruction that the program executes is considered a statement.
*/
