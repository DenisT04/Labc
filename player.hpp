#pragma once
#include "point.hpp"

class Player {
    char _marker;                  // Marker-ul jucătorului ('X' sau 'O')
public:
    Player(char marker);           // Constructor care stabilește marker-ul jucătorului
    char GetMarker() const;        // Returnează marker-ul
    Point GetMove() const;         // Jucătorul alege o mutare (introduce coordonate)
};
