#pragma once

class Complex {
    private:
        double real;
        double imaginary;

    public:
        Complex () {
            this->real = 0;
            this->imaginary = 0;
        }

        Complex (double re, double im) : real (re), imaginary (im) {};

        double GetReal () const {
            return this->real;
        }
        double GetImaginary () const {
            return this->imaginary;
        }

        bool equals (Complex& other) const;
        bool operator== (Complex& other) const {
            return this->real == other.real && this->imaginary == other.imaginary;
        }
        bool operator!= (Complex& other) const {
            return *this == other;
        }
};