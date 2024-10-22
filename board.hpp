#pragma once
#include "point.hpp"

class Board : public Entity {
    char _grid[3][3];

public:
    // Constructor implicit
    Board();

    // Constructor de inițializare
    Board(char initialGrid[3][3]);

    // Constructor de copiere
    Board(const Board& other);

    // Operator de atribuire
    Board& operator=(const Board& other);

    // Operator de comparație
    bool operator==(const Board& other) const;
    bool operator!=(const Board& other) const;

    bool IsFull() const;
    bool IsEmpty(const Point& pos) const;
    void PlaceMarker(const Point& pos, char marker);
    bool CheckWin(char marker) const;

    // Suprascriere metode virtuale din Entity
    void Print(std::ostream& os) const override;
    void Read(std::istream& is) override;
};
