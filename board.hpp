#pragma once
#include "point.hpp"
#include <array>
#include <iostream>

class Board {
    std::array<std::array<char, 3>, 3> _grid;

public:
    Board();
    bool IsFull() const;
    bool IsEmpty(const Point& pos) const;
    void PlaceMarker(const Point& pos, char marker);
    bool CheckWin(char marker) const;
    void Display(std::ostream& os) const;
};
