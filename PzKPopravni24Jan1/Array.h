#pragma once
#include <stdexcept>
template <typename T>

class Array {
    private:
        int size, capacity;
        T* array;
        void reallocate () {
            capacity *= 2;
            T* temp = new T[capacity];
            for (int i = 0; i < size; i++) {
                temp[i] = array[i];
            }
            delete[] array;
            array = temp;
        }

    public:
        int getSize () const {
            return this->size;
        }
        Array () : size (0), capacity (1), array (new T[1]) {};
        ~Array () {
            delete[] array;
        }

        Array (const Array& other) : size (other.size), capacity (other.capacity), array (new T[capacity]) {
            for (int i = 0; i < other.capacity; i++) {
                array[i] = other.array[i];
            }
        }
        Array (Array&& other) : size (other.size), capacity (other.capacity), array (other.array) {
            other.array = nullptr;
            other.size = 0;
            other.capacity = 0;
        }
        void append (const T& element) {
            if ((this->size) == capacity) reallocate ();
            array[this->size++] = element;
        }
        T& operator[] (int element) {
            if (element > this->size || element < 0) throw std::out_of_range ("Uneseni element nije u rangeu!");
            return array[element];
        }
        const T& operator[] (int element) const {
            if (element > this->size || element < 0) throw std::out_of_range ("Uneseni element nije u rangeu!");
            return array[element];
        }
};