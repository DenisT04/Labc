#include "gameengine.hpp"
#include <cassert>

int main() {
    GameEngine game;

    // Testează schimbarea jucătorului
    game.Init();
    game.SwitchPlayer();
    assert(game.IsGameOver() == false);

    // Testează rularea jocului
    game.Run();
    assert(game.IsGameOver() == true);

    return 0;
}
