#pragma once
#include "complex.hpp"

class Vector {
    private:
        int size;
        Complex* const vector;

    public:
        Vector (int size) : size (size), vector (new Complex[size]) {};
        ~Vector () {
            delete[] vector;
        }
        bool equals (Vector& other) const;
        Complex& at (int i);
        const Complex& at (int i) const;
};