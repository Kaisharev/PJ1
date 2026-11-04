#include "complex.hpp"

bool Complex::equals (Complex& other) const {
    if (this->real == other.real && this->imaginary == other.imaginary) return true;
    return false;
}