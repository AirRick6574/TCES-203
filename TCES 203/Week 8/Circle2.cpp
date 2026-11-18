/*
 * Circle2.cpp
 * overload constructors
 */

#include "Circle2.h"
#include <cmath>

// Default constructor:
// Automatically initializes radius to 1.0
Circle2::Circle2() {
    radius = 1.0;
}

// Parameterized constructor:
// Initializes radius with the value provided
Circle2::Circle2(double r) {
    radius = r;
}

// Sets the radius
void Circle2::setRadius(double r) {
    radius = r;
}

// Calculates the area
double Circle2::calcArea() {
    return 3.14 * pow(radius, 2);
}