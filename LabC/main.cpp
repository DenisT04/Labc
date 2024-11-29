#include "gameengine.hpp"
#include <memory>
#include <iostream>

int main() {
    auto player1 = std::make_shared<Player>("Player 1", 'X');
    auto player2 = std::make_shared<Player>("Player 2", 'O');

    GameEngine game(player1, player2);
    game.Run(std::cin, std::cout);

    return 0;
}
