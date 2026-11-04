
#pragma once
#include <iostream>
#include <stdexcept>
#include <vector>

#include "IObject.h"
class Array : public IObject {
    private:
        std::vector<IObject*> array;

    public:
        void add (IObject* ptr_object) {
            array.push_back (ptr_object);
        }
        std::string toString () {
            std::string stringify;
            for (auto object : array) {
                stringify += object->toString () + " ";
            }
            return stringify;
        }

        void writeToStream (std::ostream& os, std::string delimiter) {
            for (auto object : array) {
                if (object->toString ().find (delimiter) != std::string::npos) throw std::invalid_argument ("Postoji već delimiter");
                os << object->toString () << delimiter;
            }
        }
};