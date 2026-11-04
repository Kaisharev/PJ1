#pragma once
#include <iostream>

class Complex {
    private:
        double real, imaginary;

    public:
        Complex () : real (0), imaginary (0) {};
        Complex (double re, double im) : real (re), imaginary (im) {};
        double getRe () const {
            return this->real;
        }
        double getIm () const {
            return this->imaginary;
        }

        Complex operator+ (const Complex& other) {
            return Complex ((this->real + other.real), (this->imaginary + other.imaginary));
        }

        friend std::ostream& operator<< (std::ostream& os, const Complex& c) {
            return os << c.real << "+ i" << c.imaginary;
        }
};