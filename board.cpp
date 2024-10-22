#include "board.hpp"
#include <iostream>

// Constructor: inițializează tabla de joc cu spații goale
Board::Board() {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            _grid[i][j] = ' ';
}

// Verifică dacă tabla este complet plină
bool Board::IsFull() const {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (_grid[i][j] == ' ')
                return false;
    return true;
}

// Verifică dacă o poziție specifică este goală
bool Board::IsEmpty(const Point& pos) const {
    return _grid[pos.x][pos.y] == ' ';
}

// Plasează un marker pe tablă la poziția specificată
void Board::PlaceMarker(const Point& pos, char marker) {
    if (IsEmpty(pos))
        _grid[pos.x][pos.y] = marker;
}

// Verifică dacă un marker a câștigat jocul
bool Board::CheckWin(char marker) const {
    // Verifică rânduri și coloane
    for (int i = 0; i < 3; ++i) {
        if (_grid[i][0] == marker && _grid[i][1] == marker && _grid[i][2] == marker)
            return true;
        if (_grid[0][i] == marker && _grid[1][i] == marker && _grid[2][i] == marker)
            return true;
    }
    // Verifică diagonale
    if (_grid[0][0] == marker && _grid[1][1] == marker && _grid[2][2] == marker)
        return true;
    if (_grid[0][2] == marker && _grid[1][1] == marker && _grid[2][0] == marker)
        return true;

    return false;
}

// Afișează tabla de joc
void Board::Display() const {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << _grid[i][j];
            if (j < 2) std::cout << " | ";
        }
        std::cout << std::endl;
        if (i < 2) std::cout << "---------" << std::endl;
    }
}
