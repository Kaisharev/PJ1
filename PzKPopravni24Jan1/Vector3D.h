#pragma once
#include <ostream>

class Vector3D {
    private:
        double _x, _y, _z;

    public:
        Vector3D () : _x (0), _y (0), _z (0) {};
        Vector3D (double x, double y, double z) : _x (x), _y (y), _z (z) {};
        const double getX () const {
            return _x;
        }
        const double getY () const {
            return _y;
        }
        const double getZ () const {
            return _z;
        }

        void setX (double x) {
            this->_x = x;
        }

        void setY (double y) {
            this->_y = y;
        }

        void setZ (double z) {
            this->_z = z;
        }

        Vector3D operator+ (const Vector3D& other) const {
            return Vector3D (this->_x + other.getX (), this->_y + other.getY (), this->_z + other.getZ ());
        }

        Vector3D& operator+= (const Vector3D& other) {
            this->_x += other.getX ();
            this->_y += other.getY ();
            this->_z += other.getZ ();
            return *this;
        }
        Vector3D operator* (const double& other) const {
            return Vector3D (this->_x * other, this->_y * other, this->_z * other);
        }

        friend Vector3D operator* (double other, const Vector3D& vec) {
            return vec * other;
        }
        friend std::ostream& operator<< (std::ostream& os, const Vector3D& vec) {
            os << "(" << vec.getX () << ", " << vec.getY () << ", " << vec.getZ () << ")";
            return os;
        }
};