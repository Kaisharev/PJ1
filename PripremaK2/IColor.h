#pragma once
#include <string>

class IColor {
    public:
        ~IColor () = default;
        virtual std::string getColorName () = 0;
};