#pragma once
template <typename T>
class IArray {
    public:
        ~IArray () = default;
        virtual void append (const T&) = 0;
        virtual void erase (int) = 0;
        virtual int count () = 0;
};