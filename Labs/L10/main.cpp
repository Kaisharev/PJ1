#include <iostream>

#include "Key.h"
int main () {
    Map<std::string, std::string> map;

    map["Name"] = "Nebojša";
    map["Lastname"] = "Kaišarević";

    for (auto& key : map.keys ()) {
        std::cout << key << std::endl;
    }
}