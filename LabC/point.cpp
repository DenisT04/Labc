#include "point.hpp"
#include <iostream>

// Constructor implicit
Point::Point() : x(0), y(0) {}

// Constructor de inițializare
Point::Point(int xVal, int yVal) : x(xVal), y(yVal) {}

// Constructor de copiere
Point::Point(const Point& other) : x(other.x), y(other.y) {}

// Operator de atribuire
Point& Point::operator=(const Point& other) {
    if (this != &other) {
        x = other.x;
        y = other.y;
    }
    return *this;
}

// Operator de comparație
bool Point::operator==(const Point& other) const {
    return x == other.x && y == other.y;
}

bool Point::operator!=(const Point& other) const {
    return !(*this == other);
}

// Suprascrierea operatorului de afișare
void Point::Print(std::ostream& os) const {
    os << "(" << x << ", " << y << ")";
}

// Suprascrierea operatorului de citire
void Point::Read(std::istream& is) {
    is >> x >> y;
}
