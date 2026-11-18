
#include <iostream>
#include <cmath>
using namespace std;

/*
 * PROCEDURAL PROGRAMMING
 *
 * MAIN GOAL:
 * Organize a program into functions (procedures) that
 * perform specific tasks.
 *
 * MAIN CHARACTERISTICS:
 * 1. Data and functions are separate.
 * 2. Functions receive data through parameters.
 * 3. The program focuses on the sequence of operations.
 * 4. Functions can be reused with different data.
 *
 * In this example, the radii are stored in variables,
 * and a separate function calculates the circle's area.
 */

// This function does NOT belong to any object.
// It receives the radius as a parameter.
double calcArea(double radius)
{
    return 3.14 * pow(radius, 2);
}

int main()
{
    // STEP 1: Create two separate variables.
    // Each variable represents the radius of a circle.
    double radius1 = 1.0;
    double radius2 = 2.5;

    // STEP 2: Pass the data to a standalone function.
    // The function does not know which circle it is
    // working with. It only knows the value it receives.
    double area1 = calcArea(radius1);
    double area2 = calcArea(radius2);

    // STEP 3: Display the results.
    cout << "The area of circle1 is "
         << area1 << endl;

    cout << "The area of circle2 is "
         << area2 << endl;

    /*
     * IMPORTANT:
     *
     * The radius variables and the calcArea() function
     * exist independently of one another.
     *
     * ADVANTAGES OF PROCEDURAL PROGRAMMING:
     * - Simple and easy to understand for small programs.
     * - Functions promote code reuse.
     * - Good for tasks with a clear sequence of steps.
     *
     * LIMITATIONS:
     * - Related data and functions are not grouped together.
     * - Managing many related variables can become complex.
     * - Protecting data requires additional design choices.
     */

    return 0;
}
