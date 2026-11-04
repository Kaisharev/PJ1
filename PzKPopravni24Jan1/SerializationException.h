#pragma once
#include <stdexcept>
#include <string>
class SerializationException : public std::runtime_error {
    public:
        SerializationException (const std::string& msg) : std::runtime_error (msg) {};
};