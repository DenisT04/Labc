#pragma once
#include "board.hpp"
#include "player.hpp"

class GameEngine : public Entity {
    Board _board;
    Player _player1;
    Player _player2;
    Player* _currentPlayer;

public:
    // Constructor implicit
    GameEngine();

    // Constructor de inițializare
    GameEngine(const Player& p1, const Player& p2);

    // Constructor de copiere
    GameEngine(const GameEngine& other);

    // Operator de atribuire
    GameEngine& operator=(const GameEngine& other);

    // Operator de comparație
    bool operator==(const GameEngine& other) const;
    bool operator!=(const GameEngine& other) const;

    void Init();
    void Run();
    void SwitchPlayer();
    bool IsGameOver() const;

    // Suprascriere metode virtuale din Entity
    void Print(std::ostream& os) const override;
    void Read(std::istream& is) override;
};
