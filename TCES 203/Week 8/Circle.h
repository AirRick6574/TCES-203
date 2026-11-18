/*
 * Circle.h
 *
 * This header file declares the Circle class.
 * It tells other files WHAT the Circle class can do,
 * without explaining HOW its methods work.
 *
 * WHY SEPARATE IT?
 * Other programs can reuse Circle simply by including
 * this header, without knowing its implementation.
 */

#ifndef CIRCLE_H  // Checks whether CIRCLE_H has already been defined to prevent 
//including the header's contents multiple times.

#define CIRCLE_H  // Defines CIRCLE_H so that subsequent inclusions of this 
//header will be skipped.

class Circle {
private:
    double radius;

public:
    void setRadius(double r);
    double calcArea();
};

#endif