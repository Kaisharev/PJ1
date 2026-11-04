#pragma once
#include "complex.hpp"

class Array {
    private:
        Complex* array;
        int noElements, capacity;

    public:
        Array () : capacity (1), noElements (0), array (new Complex[1]) {};
        Array (Array&) = delete;
        Array (Array&& other) noexcept : capacity (other.capacity), noElements (other.noElements), array (other.array) {
            other.array = nullptr;
            other.noElements = 0;
            other.capacity = 0;
        }
        Complex operator[] (int index) const {
            return array[index];
        }

        friend std::ostream& operator<< (std::ostream& os, const Array& arr) {
            for (int i = 0; i < arr.noElements; i++) {
                os << arr.array[i];
            }
            return os;
        }

        void append (const Complex& element) {
            if (this->noElements == this->capacity) {
                capacity *= 2;
                Complex* newArray = new Complex[capacity];
                for (int i = 0; i < noElements; i++) {
                    newArray[i] = this->array[i];
                }
                delete[] this->array;
                this->array = newArray;
            }
            this->array[this->noElements++] = element;
        }

        ~Array () {
            delete[] array;
        }
};