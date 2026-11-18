/*
 * DrawCircle2.cpp
 *
 * overload constructors
 */

#include <iostream>
#include "Circle2.h"
using namespace std;

int main() {

    // Calls the default constructor
    Circle2 circle1;

    // Calls the parameterized constructor
    Circle2 circle2(2.5);

    cout << "Area of circle1: "
         << circle1.calcArea() << endl;

    cout << "Area of circle2: "
         << circle2.calcArea() << endl;

    return 0;
}