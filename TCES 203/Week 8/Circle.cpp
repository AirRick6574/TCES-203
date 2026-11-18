/*
 * Circle.cpp
 *
 * This file implements the methods declared in Circle.h.
 * It defines HOW the Circle class works.
 *
 * WHY SEPARATE IT?
 * We can modify how the methods work without changing
 * the code that uses the Circle class, as long as
 * the public interface remains unchanged.
 */

#include "Circle.h"
#include <cmath>

// Sets the radius of the circle
void Circle::setRadius(double r) {
    radius = r;
}

// Calculates and returns the area of the circle
double Circle::calcArea() {
    return 3.14 * pow(radius, 2);
}