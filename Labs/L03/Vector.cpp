#include "Vector.hpp"

bool Vector::equals (Vector& other) const {
    if (this->size != other.size) return false;
    for (int i = 0; i < this->size; i++) {
        if (this->at (i) != other.at (i)) return false;
    }
    return true;
}
Complex& Vector::at (int i) {
    return vector[i];
}
const Complex& Vector::at (int i) const {}