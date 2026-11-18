/*
 * Circle4.h
 *
 * Destructors and Boolean Functions
 * Destructor: A special function automatically called when an object is destroyed.
 * Boolean method: A function that returns true or false, determining whether a new radius 
 * is larger than every previously accepted radius.
 */

#ifndef CIRCLE4_H
#define CIRCLE4_H

class Circle4 {
private:
    double radius; // Largest radius accepted so far

public:
    Circle4();          // Default constructor
    Circle4(double r);  // Parameterized constructor
    ~Circle4();         // Destructor

    // Returns true if r is a new largest radius
    bool updateIfLargest(double r);

    double getRadius() const;
    double calcArea() const;
};

#endif