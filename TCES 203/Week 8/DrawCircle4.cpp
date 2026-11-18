/*
 * DrawCircle4.cpp
 *
 * Destructors and Boolean Functions
 * Destructor: A special function automatically called when an object is destroyed.
 * Boolean method: A function that returns true or false, determining whether a new radius 
 * is larger than every previously accepted radius.
 */

#include <iostream>
#include "Circle4.h"
using namespace std;

int main() {

    // Display bool results as true/false
    cout << boolalpha;

    // Default constructor: radius = 1.0
    Circle4 circle1;

    // Test whether incoming values are new largest radii
    cout << "Is 3.0 a new largest? "
         << circle1.updateIfLargest(3.0) << endl;

    cout << "Is 2.0 a new largest? "
         << circle1.updateIfLargest(2.0) << endl;

    cout << "Is 5.0 a new largest? "
         << circle1.updateIfLargest(5.0) << endl;

    cout << "Is 5.0 a new largest again? "
         << circle1.updateIfLargest(5.0) << endl;

    cout << "Circle1 radius: "
         << circle1.getRadius() << endl;

    cout << "Circle1 area: "
         << circle1.calcArea() << endl;

    cout << "\nEntering inner block...\n";

    {
        // Parameterized constructor
        Circle4 circle2(2.5);

        cout << "Circle2 area: "
             << circle2.calcArea() << endl;

    } // circle2 is destroyed HERE automatically!

    cout << "Back in main (circle1 still exists).\n";

    return 0;

} // circle1 is destroyed HERE automatically!