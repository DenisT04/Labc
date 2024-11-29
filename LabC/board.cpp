#include "board.hpp"
#include <algorithm>

// Constructor implicit
Board::Board() {
    for (auto& row : _grid) {
        std::fill(row.begin(), row.end(), ' ');
    }
}

bool Board::IsFull() const {
    return std::all_of(_grid.begin(), _grid.end(), [](const std::array<char, 3>& row) {
        return std::all_of(row.begin(), row.end(), [](char cell) { return cell != ' '; });
    });
}

bool Board::IsEmpty(const Point& pos) const {
    return _grid[pos.x][pos.y] == ' ';
}

void Board::PlaceMarker(const Point& pos, char marker) {
    if (IsEmpty(pos)) {
        _grid[pos.x][pos.y] = marker;
    }
}

bool Board::CheckWin(char marker) const {
    // Verifică linii, coloane și diagonale
    for (const auto& row : _grid) {
        if (std::all_of(row.begin(), row.end(), [marker](char cell) { return cell == marker; })) {
            return true;
        }
    }
    for (int col = 0; col < 3; ++col) {
        if (_grid[0][col] == marker && _grid[1][col] == marker && _grid[2][col] == marker) {
            return true;
        }
    }
    return (_grid[0][0] == marker && _grid[1][1] == marker && _grid[2][2] == marker) ||
           (_grid[0][2] == marker && _grid[1][1] == marker && _grid[2][0] == marker);
}

void Board::Display(std::ostream& os) const {
    for (const auto& row : _grid) {
        for (char cell : row) {
            os << cell << " ";
        }
        os << "\n";
    }
}
