#pragma once
#include "point.hpp"

class Player : public Entity {
    char _marker;

public:
    // Constructor implicit
    Player();

    // Constructor de inițializare
    Player(char marker);

    // Constructor de copiere
    Player(const Player& other);

    // Operator de atribuire
    Player& operator=(const Player& other);

    // Operator de comparație
    bool operator==(const Player& other) const;
    bool operator!=(const Player& other) const;

    char GetMarker() const;
    Point GetMove() const;

    // Suprascriere metode virtuale din Entity
    void Print(std::ostream& os) const override;
    void Read(std::istream& is) override;
};
