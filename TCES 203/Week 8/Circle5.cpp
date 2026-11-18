/*
 * Circle5.cpp
 *
 * Pass by value: A function receives a copy of an object. Changes do not affect the original.
 * Pass by reference: A function works directly with the original object and can modify it.
 * Pass by constant reference: A function accesses the original object without copying it 
 * or being allowed to modify it.
 * Return an object: A function creates and returns a new object.
 */

#include "Circle5.h"

// Default constructor uses constructor chaining
Circle5::Circle5() : Circle5(1.0) { }

// Parameterized constructor
Circle5::Circle5(double r) {
    setRadius(r);
}

// Set the radius, accepting only positive values
void Circle5::setRadius(double r) {
    radius = (r > 0) ? r : 1.0;
}

// Return the radius without modifying the object
double Circle5::getRadius() const {
    return radius;
}

// Calculate area without modifying the object
double Circle5::calcArea() const {
    return 3.14 * radius * radius;
}