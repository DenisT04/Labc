#include "player.hpp"
#include <iostream>

// Constructorul care inițializează marker-ul jucătorului
Player::Player(char marker) : _marker(marker) {}

// Returnează marker-ul jucătorului
char Player::GetMarker() const {
    return _marker;
}

// Obține mutarea jucătorului
Point Player::GetMove() const {
    int x, y;
    std::cout << "Jucătorul " << _marker << ", introdu poziția (rând și coloană): ";
    std::cin >> x >> y;
    return Point(x, y);
}
