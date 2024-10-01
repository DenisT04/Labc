#pragma once
#include "point.hpp"

class Board {
    char _grid[3][3];
public:
    Board(); 
    bool IsFull() const;
    bool IsEmpty(const Point& pos) const;
    void PlaceMarker(const Point& pos, char marker);
    bool CheckWin(char marker) const;
    void Display() const; 
};
