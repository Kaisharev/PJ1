#pragma once
#include <iostream>
#include <ostream>
#include <stdexcept>

#include "Fraction.h"
class Stack {
    private:
        Fraction* array_;
        int size_, capacity_;

    public:
        Stack () : array_ (new Fraction[1]), size_ (0), capacity_ (1) {};
        ~Stack () {
            delete[] array_;
        }
        Fraction top () {
            return this->array_[this->size_ - 1];
        }
        void push (const Fraction& element) {
            try {
                if (this->size_ >= this->capacity_) {
                    this->capacity_ *= 2;
                    Fraction* temp = new Fraction[this->capacity_];
                    for (int i = 0; i < this->size_; i++) {
                        temp[i] = this->array_[i];
                    }
                    delete[] this->array_;
                    this->array_ = temp;
                }
                this->array_[(this->size_)++] = element;
            } catch (const std::bad_alloc& e) {
                throw std::runtime_error ("Memory allocation failed in push");
            }
        }
        void pop () {
            try {
                if (this->size_ <= 0) {
                    throw std::underflow_error ("Stack is empty");
                }
                this->size_--;
            } catch (const std::underflow_error& e) {
                throw std::runtime_error ("Pop operation failed: stack underflow");
            }
        }

        Stack (const Stack& other) : size_ (other.size_), capacity_ (other.capacity_) {
            this->array_ = new Fraction[capacity_];
            for (int i = 0; i < other.size_; i++) {
                this->array_[i] = other.array_[i];
            }
        }
        Stack operator= (const Stack& other) = delete;

        Stack (Stack&& other) : size_ (other.size_), capacity_ (other.capacity_), array_ (other.array_) {
            other.array_ = nullptr;
            other.capacity_ = 0;
            other.size_ = 0;
        }

        Stack operation (Fraction (*f) (const Fraction&)) const {
            Stack result;
            for (int i = 0; i < this->size_; i++) {
                result.push (f (this->array_[i]));
            }
            return result;
        }
};