#pragma once
#include "point.hpp"
#include "board.hpp"

class Painter {
public:
    void DrawBoard(const Board& board);
    void DisplayMessage(const char* message);
};
