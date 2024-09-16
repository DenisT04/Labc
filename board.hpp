#pragma once
#include "point.hpp"

class Board {
    char _grid[3][3];  // Reprezintă tabla de joc (3x3)
public:
    Board();                        // Constructor care inițializează tabla goală
    bool IsFull() const;            // Verifică dacă tabla este plină
    bool IsEmpty(const Point& pos) const;  // Verifică dacă o poziție este liberă
    void PlaceMarker(const Point& pos, char marker);  // Pune un marker (X sau O) pe tablă
    bool CheckWin(char marker) const;    // Verifică dacă marker-ul dat a câștigat
    void Display() const;           // Afișează tabla de joc
};
