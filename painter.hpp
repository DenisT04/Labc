#pragma once
#include "board.hpp"

class Painter {
public:
    // Constructor implicit
    Painter();

    // Constructor de copiere
    Painter(const Painter& other);

    // Operator de atribuire
    Painter& operator=(const Painter& other);

    void DrawBoard(const Board& board);
    void DisplayMessage(const char* message);
};
