#include <algorithm>
#include <iostream>

#include "Array.h"
#include "Serializable.h"
#include "SerializableList.h"
#include "Vector3D.h"
int main () {
    Array<Vector3D> array;
    array.append (Vector3D (1, 2, 3));
    array.append (Vector3D (4, 5, 6));
    std::cout << array[0] + array[1] << std::endl;
    Vector3D vec (1, 2, 3);
    Array<Vector3D> move = std::move (array);
    for (int i = 0; i < move.getSize (); i++) {
        std::cout << move[i];
    }
    std::cout << vec << std::endl;

    class Test : public Serializable {
        private:
            std::string text;

        public:
            Test (const std::string& str) : text (str) {};
            void writeToStream (std::ostream& os) const override {
                os << text;
            }
    };

    SerializableList list;
    list.add (std::make_unique<Test> ("Test1"));
    list.add (std::make_unique<Test> ("Test2"));
    list.add (std::make_unique<Test> ("Test3"));

    list.setDelimiter (" | ");
    list.writeToStream (std::cout);
    std::cout << std::endl;
}