#include "Array.h"
#include "IObject.h"
#include "Transformer.h"
#include "join.h"
int main () {
    Transformer<int> transformer;
    std::vector<int> values = {1, 2, 3};
    transformer.append ([] (auto x) {
        return x * 2;
    });
    transformer.append ([] (auto x) {
        return x + 1;
    });
    for (auto e : transformer.transform (values)) std::cout << e << " ";  // Očekivani ispis: 3 5 7

    const std::map<int, std::string> m1{{1, "A"}, {2, "B"}};
    const std::map<int, double> m2{{1, 1.5}, {2, 0.5}};
    auto x = join (m1, m2);
    for (const auto& pair : x)
        std::cout << pair.first << ": " << pair.second.first << " " << pair.second.second << std::endl;  // Očekivani ispis:
                                                                                                         // 1: A 1.5
                                                                                                         // 2: B 0.5
}