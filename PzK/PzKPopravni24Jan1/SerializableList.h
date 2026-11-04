#pragma once
#include <memory>
#include <sstream>
#include <vector>

#include "Serializable.h"
#include "SerializationException.h"
class SerializableList {
    private:
        std::vector<std::unique_ptr<Serializable>> vec;
        std::string delimiter = "\n";

    public:
        void add (std::unique_ptr<Serializable>&& ptr) {
            vec.push_back (std::move (ptr));
        }

        void writeToStream (std::ostream& os) {
            for (auto& str : vec) {
                std::ostringstream oss;
                str->writeToStream (oss);
                std::string output = oss.str ();
                if (output.find (delimiter) != std::string::npos) SerializationException ("Greska");
                os << output;
                os << delimiter;
            }
        }

        void setDelimiter (const std::string& del) {
            delimiter = del;
        }

        std::string getDelimiter () const {
            return delimiter;
        }
};