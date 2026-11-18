/*
 * DrawCircle3.cpp
 *
 * constructors chaining
 */

#include <iostream>
#include "Circle3.h"
using namespace std;

int main() {

    // Calls default constructor
    // which delegates to Circle3(1.0)
    Circle3 circle1;

    // Calls parameterized constructor
    Circle3 circle2(2.5);

    // Invalid radius: constructor uses 1.0
    Circle3 circle3(-5);

    cout << "Area of circle1: "
         << circle1.calcArea() << endl;

    cout << "Area of circle2: "
         << circle2.calcArea() << endl;

    cout << "Area of circle3: "
         << circle3.calcArea() << endl;

    return 0;
}