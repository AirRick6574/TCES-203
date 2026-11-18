/*
 * Circle2.h
 *
 * overload constructors
 */

#ifndef CIRCLE2_H
#define CIRCLE2_H

class Circle2 {
private:
    double radius;

public:
    // Default constructor (no parameters)
    Circle2();

    // Parameterized constructor
    Circle2(double r);

    void setRadius(double r);
    double calcArea();
};

#endif