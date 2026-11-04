#pragma once
#include <stdexcept>

#include "vector2d.hpp"
class Array {
    private:
        Vector2D* array;
        int noElements, capacity;

    public:
        Array () : noElements (0), capacity (1) {
            array = new Vector2D[1];
        };

        void append (const Vector2D& element) {
            if (this->noElements == this->capacity) {
                capacity *= 2;
                Vector2D* newArray = new Vector2D[capacity];
                for (int i = 0; i < this->noElements; i++) {
                    newArray[i] = array[i];
                }
                delete[] array;
                array = newArray;
            }
            array[noElements++] = element;
        }
        Vector2D& at (int position, bool& success) {
            if (position < 0 || position >= noElements) {
                success = false;
                static Vector2D dummy;
                return dummy;
            }
            success = true;
            return this->array[position];
        }

        Array (Array& other) : capacity (other.capacity), noElements (other.noElements) {
            array = new Vector2D[capacity];
            for (int i = 0; i < capacity; i++) {
                array[i] = other.array[i];
            }
        };

        Array (Array&& other) : array (other.array), capacity (other.capacity), noElements (other.noElements) {
            other.array = nullptr;
            other.capacity = 0;
            other.noElements = 0;
        }
        Array& operator= (Array&& other) = delete;
        Array& operator= (Array& other) = delete;

        ~Array () {
            delete[] array;
        }
};