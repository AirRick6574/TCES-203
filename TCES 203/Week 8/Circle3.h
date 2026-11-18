/*
 * Circle3.h
 *
 * constructors chaining
 */

#ifndef CIRCLE3_H
#define CIRCLE3_H

class Circle3 {
private:
    double radius;

public:
    // Default constructor
    Circle3();

    // Parameterized constructor
    Circle3(double r);

    void setRadius(double r);
    double calcArea();
};

#endif