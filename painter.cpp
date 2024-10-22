#include "painter.hpp"
#include <iostream>

// Desenează tabla de joc pe ecran
void Painter::DrawBoard(const Board& board) {
    board.Display();
}

// Afișează un mesaj general
void Painter::DisplayMessage(const char* message) {
    std::cout << message << std::endl;
}
