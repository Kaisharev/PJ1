#include <stdexcept>
#include <vector>

#include "IArray.h"
template <typename T>
class Array : public IArray {
    private:
        std::vector<T> array;

    public:
        void append (const T&) override {
            array.push_back (T);
        }
        void erase (int position) override {
            if (position >= array.size ()) throw std::runtime_error ("Šipak! Nema elementa na toj poziciji!");
            array.erase (array.begin () + position);
        }
        int count () override {
            return array.size ();
        }
};