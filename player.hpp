#pragma once
#include "point.hpp"
#include <string>
#include <memory>

class Player {
    char _marker;
    std::string _name;

public:
    Player(const std::string& name, char marker);
    char GetMarker() const;
    std::string GetName() const;
    Point GetMove(std::istream& is) const;
};
