/*
 * DrawCircle5.cpp
 *
 * Pass by value: A function receives a copy of an object. Changes do not affect the original.
 * Pass by reference: A function works directly with the original object and can modify it.
 * Pass by constant reference: A function accesses the original object without copying it 
 * or being allowed to modify it.
 * Return an object: A function creates and returns a new object.
 */

#include <iostream>
#include "Circle5.h"
using namespace std;

// EXAMPLE 1: PASS BY VALUE
// The function receives a COPY of the object.
// Changes do NOT affect the original.
void increaseByValue(Circle5 circle) {
    circle.setRadius(circle.getRadius() + 1.0);

    cout << "Inside increaseByValue: "
         << circle.getRadius() << endl;
}

// EXAMPLE 2: PASS BY REFERENCE
// The function receives the ORIGINAL object.
// Changes DO affect the original.
void increaseByReference(Circle5& circle) {
    circle.setRadius(circle.getRadius() + 1.0);

    cout << "Inside increaseByReference: "
         << circle.getRadius() << endl;
}

// EXAMPLE 3: PASS BY CONSTANT REFERENCE
// The function accesses the original object.
// No copy is made, but modification is forbidden.
void displayCircle(const Circle5& circle) {
    cout << "Radius: " << circle.getRadius()
         << ", Area: " << circle.calcArea() << endl;

     //circle.setRadius(10); // COMPILER ERROR!
}

// EXAMPLE 4: RETURN AN OBJECT
// Creates and returns a NEW Circle5 object.
// The original is passed by const reference.
Circle5 makeLargerCircle(const Circle5& original,
                         double extraRadius) {

    return Circle5(original.getRadius() + extraRadius);
}

int main() {

    Circle5 circle(2.5);

    cout << "Original circle:" << endl;
    displayCircle(circle);

    // EXAMPLE 1: PASS BY VALUE
    cout << "\nPass by VALUE:" << endl;
    increaseByValue(circle);

    cout << "Original radius: "
         << circle.getRadius() << endl;

    // EXAMPLE 2: PASS BY REFERENCE
    cout << "\nPass by REFERENCE:" << endl;
    increaseByReference(circle);

    cout << "Original radius: "
         << circle.getRadius() << endl;

    // EXAMPLE 3: PASS BY CONST REFERENCE
    cout << "\nPass by CONST REFERENCE:" << endl;
    displayCircle(circle);

    // EXAMPLE 4: RETURN AN OBJECT
    cout << "\nRETURN an object:" << endl;

    Circle5 biggerCircle =
        makeLargerCircle(circle, 2.0);

    cout << "Original: ";
    displayCircle(circle);

    cout << "New circle: ";
    displayCircle(biggerCircle);

    return 0;
}