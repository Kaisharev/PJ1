#pragma once
#include <functional>
#include <vector>
template <typename T>
class Transformer {
    private:
        std::vector<std::function<T (const T&)>> vector_of_functions;

    public:
        void append (std::function<T (const T&)> fun) {
            vector_of_functions.push_back (fun);
        }
        std::vector<T> transform (const std::vector<T>& vec) {
            std::vector<T> temp = vec;
            for (auto function : vector_of_functions) {
                for (auto& element : temp) {
                    element = function (element);
                }
            }
            return temp;
        }
};