#include "player.hpp"
#include <iostream>

Player::Player(const std::string& name, char marker) : _name(name), _marker(marker) {}

char Player::GetMarker() const {
    return _marker;
}

std::string Player::GetName() const {
    return _name;
}

Point Player::GetMove(std::istream& is) const {
    int x, y;
    std::cout << _name << ", enter your move (row and column): ";
    is >> x >> y;
    return Point(x, y);
}
