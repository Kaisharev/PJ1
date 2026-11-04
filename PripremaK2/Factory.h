#pragma once
#include <functional>
#include <map>
#include <memory>
#include <string>
template <typename I>

class Factory {
    private:
        std::map<std::string, std::function<std::unique_ptr<I> ()>> m;

    public:
        void registerFunction (std::string str, std::function<std::unique_ptr<I> ()> f) {
            m[str] = f;
        }
        std::unique_ptr<I> create (std::string str) {
            return m.at (str);
        }
};