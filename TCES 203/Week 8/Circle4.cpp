/*
 * Circle4.cpp
 * Destructors and Boolean Functions
 * Destructor: A special function automatically called when an object is destroyed.
 * Boolean method: A function that returns true or false, determining whether a new radius 
 * is larger than every previously accepted radius.
 */

#include "Circle4.h"
#include <iostream>

// Default constructor uses constructor chaining
Circle4::Circle4() : Circle4(1.0) { }

// Parameterized constructor
Circle4::Circle4(double r) {
    radius = (r > 0) ? r : 1.0;

    std::cout << "Circle created with radius "
              << radius << '\n';
}

// Destructor: automatically called when the object
// is destroyed (e.g., when it leaves its scope).
Circle4::~Circle4() {
    std::cout << "Circle destroyed (final radius "
              << radius << ")\n";
}

// Boolean function:
// Returns true if the new radius is larger.
// Returns false otherwise.
bool Circle4::updateIfLargest(double r) {
    if (r > radius) {
        radius = r;
        return true;
    }

    return false;
}

// Returns the current radius
double Circle4::getRadius() const {
    return radius;
}

// Calculates the area
double Circle4::calcArea() const {
    return 3.14 * radius * radius;
}