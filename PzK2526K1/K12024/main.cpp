#include <iostream>

#include "array.hpp"
int main () {
    std::cout << "=== Testing Vector2D ===" << std::endl;

    // Test default constructor and getters
    Vector2D a;
    std::cout << "Default vector a: (" << a.getX () << ", " << a.getY () << ")" << std::endl;

    // Test parameterized constructor
    Vector2D b (3, 2);
    std::cout << "Parameterized vector b: (" << b.getX () << ", " << b.getY () << ")" << std::endl;

    // Test setters
    a.setX (1.5);
    a.setY (3.14);
    std::cout << "After setters, vector a: (" << a.getX () << ", " << a.getY () << ")" << std::endl;

    // Test scalar product (dot product)
    Vector2D v1 (3, 4);
    Vector2D v2 (2, 1);
    double dotProduct = (v1.getX () * v2.getX ()) + (v1.getY () * v2.getY ());  // 3*2 + 4*1 = 10
    std::cout << "Dot product of (" << v1.getX () << ", " << v1.getY () << ") and (" << v2.getX () << ", " << v2.getY ()
              << ") = " << dotProduct << std::endl;

    std::cout << "\n=== Testing Array ===" << std::endl;

    // Test default constructor
    Array arr;
    std::cout << "Array created with default constructor" << std::endl;

    // Test append
    arr.append (Vector2D (1, 2));
    arr.append (Vector2D (3, 4));
    arr.append (Vector2D (5, 6));
    std::cout << "Added 3 vectors to array" << std::endl;

    // Test at method with success flag
    bool success;
    Vector2D& elem = arr.at (1, success);
    if (success) {
        std::cout << "Element at index 1: (" << elem.getX () << ", " << elem.getY () << ")" << std::endl;
        elem.setX (10);
        elem.setY (20);
        std::cout << "Modified element at index 1: (" << arr.at (1, success).getX () << ", " << arr.at (1, success).getY () << ")"
                  << std::endl;
    }

    // Test invalid index
    arr.at (100, success);
    if (!success) {
        std::cout << "Successfully detected invalid index" << std::endl;
    }

    // Test copy constructor
    Array arr2 = arr;
    std::cout << "Deep copy created, element at index 0: (" << arr2.at (0, success).getX () << ", " << arr2.at (0, success).getY ()
              << ")" << std::endl;

    // Test move constructor
    Array arr3 = std::move (arr2);
    std::cout << "Move constructor used, element at index 2: (" << arr3.at (2, success).getX () << ", " << arr3.at (2, success).getY ()
              << ")" << std::endl;

    return 0;
}