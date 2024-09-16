#pragma once
#include "board.hpp"
#include "player.hpp"

class GameEngine {
    Board _board;                  // Tabla de joc
    Player _player1;               // Jucătorul 1 (X)
    Player _player2;               // Jucătorul 2 (O)
    Player* _currentPlayer;        // Pointer la jucătorul curent
public:
    GameEngine();                  // Constructor care inițializează jocul
    void Init();                   // Inițializează jocul și tabla
    void Run();                    // Rulează bucla principală a jocului
    void SwitchPlayer();           // Schimbă jucătorul curent
    bool IsGameOver() const;       // Verifică dacă jocul s-a terminat (câștig sau egalitate)
};
