/*
 * Circle2.cpp
 * constructors
 */

#include "Circle3.h"
#include <cmath>

// Default constructor:
// Delegates initialization to Circle3(double r)
// passing 1.0 as the default radius.
Circle3::Circle3() : Circle3(1.0) {
}

// Parameterized constructor:
// Centralizes initialization and validation.
Circle3::Circle3(double r) {
    radius = (r > 0) ? r : 1.0;
}

// Sets the radius
void Circle3::setRadius(double r) {
    radius = (r > 0) ? r : 1.0;
}

// Calculates the area
double Circle3::calcArea() {
    return 3.14 * pow(radius, 2);
}