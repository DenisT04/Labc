#include "player.hpp"
#include <iostream>

// Constructor implicit
Player::Player() : _marker(' ') {}

// Constructor de inițializare
Player::Player(char marker) : _marker(marker) {}

// Constructor de copiere
Player::Player(const Player& other) : _marker(other._marker) {}

// Operator de atribuire
Player& Player::operator=(const Player& other) {
    if (this != &other) {
        _marker = other._marker;
    }
    return *this;
}

// Operator de comparație
bool Player::operator==(const Player& other) const {
    return _marker == other._marker;
}

bool Player::operator!=(const Player& other) const {
    return !(*this == other);
}

// Suprascrierea operatorului de afișare
void Player::Print(std::ostream& os) const {
    os << "Player Marker: " << _marker;
}

// Suprascrierea operatorului de citire
void Player::Read(std::istream& is) {
    is >> _marker;
}
