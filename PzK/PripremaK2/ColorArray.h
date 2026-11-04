#pragma once
#include <istream>
#include <memory>
#include <ostream>
#include <vector>

#include "Factory.h"
#include "IColor.h"
class ColorArray {
    private:
        std::vector<std::unique_ptr<IColor>> array;

    public:
        void add (std::unique_ptr<IColor>&& color) {
            array.push_back (std::move (color));
        }
        std::string toString () {
            std::string stringify;
            for (auto& color : array) {
                stringify += color->getColorName () + " ";
            }
            stringify.pop_back ();
            return stringify;
        }
        void serialize (std::ostream& os) {
            os << toString ();
        }
        static ColorArray deserialize (std::istream& is, Factory<IColor> color) {
            std::string str;
            ColorArray ca;
            while (is >> str) {
                ca.add (std::move (color.create (str)));
            }
            return ca;
        }
};