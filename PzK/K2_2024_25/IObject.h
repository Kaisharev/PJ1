#pragma once
#include <string>
class IObject {
    public:
        ~IObject () = default;
        std::string toString ();
};