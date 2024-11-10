#pragma once
#include "board.hpp"
#include "player.hpp"
#include <memory>
#include <iostream>

class GameEngine {
    Board _board;
    std::shared_ptr<Player> _player1;
    std::shared_ptr<Player> _player2;
    std::shared_ptr<Player> _currentPlayer;

public:
    GameEngine(const std::shared_ptr<Player>& p1, const std::shared_ptr<Player>& p2);
    void Run(std::istream& is, std::ostream& os);
    void SwitchPlayer();
    bool IsGameOver(char& winner) const;
};
