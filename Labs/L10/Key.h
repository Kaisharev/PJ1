#pragma once
#include <functional>
#include <memory>
#include <vector>
template <typename K, typename V, size_t MAX_VALUE = 0>

class Map {
    private:
        struct Pair {
                K key;
                V value;
        };
        std::vector<Pair> pairs;

    public:
        const K& operator[] (const K key) const {
            for (const auto& pair : pairs) {
                if (pair.key == key) return pair.value;
            }
            if (MAX_VALUE > 0 && pairs.size () > MAX_VALUE) throw std::exception ("Ne mere");
        }
        K& operator[] (const K key) {
            for (const auto& pair : pairs) {
                if (pair.key == key) return pair.value;
            }
            if (MAX_VALUE > 0 && pairs.size () > MAX_VALUE) throw std::exception ("Ne mere");
            pairs.push_back ({key, V ()});
            return pairs.back ().value;
        }

        bool contains (const K& key) const {
            for (const auto& pair : pairs) {
                if (pair.key == key) return true;
            }
            return false;
        }
        void add (const K& key, const V& value) {
            for (const auto& pair : pairs) {
                if (contains (key)) throw std::exception ("Ne mere!");
            }
            if (MAX_VALUE > 0 && pairs.size () > MAX_VALUE) throw std::exception ("Ne mere");

            pairs.push_back ({key, value});
        }
        std::unique_ptr<Map<K, V, MAX_VALUE>> clone () {
            auto clone_arr = std::make_unique<Map<K, V, MAX_VALUE>> ();
            for (const auto& pair : pairs) {
                clone_arr->add ({pair.key, pair.value});
            }
            return clone_arr;
        }
        Map<K, V, MAX_VALUE> filter (std::function<bool (K, V)> f) {
            Map<K, V, MAX_VALUE> result;
            for (const auto& pair : pairs) {
                if (f (pair.key, pair.value)) result.add (pair.key, pair.value);
            }
            return result;
        }
        template <typename E>
        Map<K, E, MAX_VALUE> transformValue (std::function<E(V)> f) const {
            Map<K, E, MAX_VALUE> result;
            for (const auto& pair : pairs) {
                result.add(pair.key, f(pair.value));
            }
            return result;
        }
};