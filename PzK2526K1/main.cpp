#include <iostream>

#include "complex.hpp"
int main () {
    Complex a (3, 2);
    Complex b (6, 8);

    std::cout << a.getRe () << a.getIm () << std::endl;
    Complex c = a + b;
    std::cout << c.getRe () << c.getIm () << std::endl;
    std::cout << c << std::endl;
}