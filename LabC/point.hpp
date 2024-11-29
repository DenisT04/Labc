#pragma once
#include "entity.hpp"

class Point : public Entity {
public:
    int x, y;

    // Constructor implicit
    Point();

    // Constructor de inițializare
    Point(int x, int y);

    // Constructor de copiere
    Point(const Point& other);

    // Operator de atribuire
    Point& operator=(const Point& other);

    // Operator de comparație
    bool operator==(const Point& other) const;
    bool operator!=(const Point& other) const;

    // Suprascriere metode virtuale din Entity
    void Print(std::ostream& os) const override;
    void Read(std::istream& is) override;
};
