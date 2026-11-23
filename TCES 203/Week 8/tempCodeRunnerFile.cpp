/*
 * DrawCircle.cpp
 *
 * This file contains the main() function.
 * It creates Circle objects and uses their methods.
 *
 * WHY SEPARATE IT?
 * The main program focuses on USING the Circle class,
 * rather than implementing its internal functionality.
 *
 * This allows us to reuse the same Circle class
 * in many different programs without duplicating code.
 */

#include <iostream>
#include "Circle.h"
using namespace std;

int main() {

    // Create two Circle objects
    Circle circle1, circle2;

    // Set their radii
    circle1.setRadius(1);
    circle2.setRadius(2.5);

    // Display their areas
    cout << "The area of circle1 is "
         << circle1.calcArea() << endl;

    cout << "The area of circle2 is "
         << circle2.calcArea() << endl;

    return 0;
}