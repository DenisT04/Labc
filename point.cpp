#include "point.hpp"

// Constructor care inițializează coordonatele unui punct
Point::Point(int xVal, int yVal) : x(xVal), y(yVal) {}

// Compară două puncte
bool Point::operator==(const Point& other) const {
    return x == other.x && y == other.y;
}

// Compară dacă două puncte sunt diferite
bool Point::operator!=(const Point& other) const {
    return !(*this == other);
}
