#pragma once

class Vector2D {
    private:
        double x, y;

    public:
        Vector2D () : x (0.0), y (0.0) {};
        double getX () const {
            return this->x;
        }
        double getY () const {
            return this->y;
        }
        Vector2D (double x, double y) : x (x), y (y) {};
        void setX (double input) {
            this->x = input;
        }
        void setY (double input) {
            this->y = input;
        }

        Vector2D operator* (const Vector2D& other) {
            return Vector2D ((this->x * other.x), (this->y * other.y));
        }
};