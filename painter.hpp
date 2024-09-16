#pragma once
#include "point.hpp"
#include "board.hpp"

class Painter {
public:
    void DrawBoard(const Board& board);  // Afișează tabla de joc
    void DisplayMessage(const char* message);  // Afișează un mesaj pe ecran
};
