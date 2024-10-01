#pragma once
#include "point.hpp"

class Player {
    char _marker;
public:
    Player(char marker);
    char GetMarker() const;
    Point GetMove() const;
    };
