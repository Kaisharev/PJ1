#pragma once
#include <ostream>
#include <string>

class Serializable {
    public:
        virtual ~Serializable () = default;
        virtual void writeToStream (std::ostream&) const = 0;
};