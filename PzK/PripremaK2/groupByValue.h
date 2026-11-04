#pragma once
#include <map>
template <typename K, typename V>
auto groupByValue (const std::map<K, V>& map) {
    std::map<V, std::vector<K>> temp;
    for (auto data : map) {
         temp[data.second].push_back (data.first);
    }
    return temp;
}