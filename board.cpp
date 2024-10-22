#include "board.hpp"
#include <iostream>

// Constructor implicit
Board::Board() {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            _grid[i][j] = ' ';
}

// Constructor de inițializare
Board::Board(char initialGrid[3][3]) {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            _grid[i][j] = initialGrid[i][j];
}

// Constructor de copiere
Board::Board(const Board& other) {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            _grid[i][j] = other._grid[i][j];
}

// Operator de atribuire
Board& Board::operator=(const Board& other) {
    if (this != &other) {
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                _grid[i][j] = other._grid[i][j];
    }
    return *this;
}

// Operator de comparație
bool Board::operator==(const Board& other) const {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (_grid[i][j] != other._grid[i][j])
                return false;
    return true;
}

bool Board::operator!=(const Board& other) const {
    return !(*this == other);
}

// Suprascrierea operatorului de afișare
void Board::Print(std::ostream& os) const {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            os << _grid[i][j] << " ";
        }
        os << std::endl;
    }
}

// Suprascrierea operatorului de citire
void Board::Read(std::istream& is) {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            is >> _grid[i][j];
}
