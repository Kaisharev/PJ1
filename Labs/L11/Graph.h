#pragma once
#include <map>
#include <memory>
#include <set>
#include <stdexcept>
#include <string>
#include <type_traits>
template <typename T, typename Id = std::string>

class DirectedGraph {
    public:
        class Vertex {
            private:
                T _value;
                Id _id;
                std::set<std::shared_ptr<Vertex>> AdjacencyList;
                friend class DirectedGraph;

            public:
                Vertex (const Id id, T& value) : _Id (id), _value (value) {
                    static_assert (std::is_copy_constructible ("Value mora biti copy konstruktabilan"));
                }
                Vertex (const Id id, T&& value) : _Id (id), _value (value) {
                    static_assert (std::is_move_constructible ("Value mora biti move konstruktabilan"));
                }
        };

    private:
        std::map<Id, std::unique_ptr<Vertex>> verticies;

    public:
        bool add (const Id& id, const T& value) {
            if (verticies.find (id) == verticies.end ()) {
                verticies.emplace (id, std::make_unique<Vertex> (id, value));
                return true
            }
            return false;
        }
        bool add (const Id& id, T&& value) {
            if (verticies.find (id) == verticies.end ()) {
                verticies.emplace (id, std::make_unique<Vertex> (id, std::move (value)));
                return true
            }
            return false;
        }
        void connect (const Id& id1, const Id& id2) {
            if (verticies.find (id1) == verticies.end () || verticies.find (id2) == verticies.end ())
                throw std::out_of_range ("Jedan od IDeva nije u rasponu koji se nalazi u mapi!");
            verticies[id1]->AdjacencyList.emplace (verticies[id2].get ());
        }
        const Vertex& getVertex (const Id& id) const {
            if (verticies.find (id) == verticies.end ())
                throw std::out_of_range ("Jedan od IDeva nije u rasponu koji se nalazi u mapi!");
            return *verticies.at (id);
        }
};
