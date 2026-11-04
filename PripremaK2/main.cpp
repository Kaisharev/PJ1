#include <iostream>

#include "Factory.h"
#include "IColor.h"
#include "groupByValue.h"
int main () {
    const std::map<int, std::string> m{{1, "A"}, {2, "B"}, {3, "A"}, {4, "B"}};
    auto x = groupByValue (m);
    for (auto e : x) {
        std::cout << e.first << ": ";
        for (const auto& v : e.second) std::cout << v << " ";
        std::cout << std::endl;
        // Očekivani ispis:
        // A: 1 3
        // B: 2 4
    }
}