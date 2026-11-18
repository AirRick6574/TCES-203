/*
 * Circle5.h
 *
 * Pass by value: A function receives a copy of an object. Changes do not affect the original.
 * Pass by reference: A function works directly with the original object and can modify it.
 * Pass by constant reference: A function accesses the original object without copying it 
 * or being allowed to modify it.
 * Return an object: A function creates and returns a new object.
 */

#ifndef CIRCLE5_H
#define CIRCLE5_H

class Circle5 {
private:
    double radius;

public:
    Circle5();              // Default constructor
    Circle5(double r);      // Parameterized constructor

    void setRadius(double r);

    // These methods cannot modify the object
    double getRadius() const;
    double calcArea() const;
};

#endif