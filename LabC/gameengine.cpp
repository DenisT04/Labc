#include "gameengine.hpp"
#include "database.hpp"
#include <iostream>

void GameEngine::Run() {
    Database db("tictactoe.db");
    db.Initialize();

    while (!IsGameOver()) {
        _board.Display();
        Point move = _currentPlayer->GetMove();
        if (_board.IsEmpty(move)) {
            _board.PlaceMarker(move, _currentPlayer->GetMarker());
            if (_board.CheckWin(_currentPlayer->GetMarker())) {
                _board.Display();
                std::cout << "Player " << _currentPlayer->GetMarker() << " wins!" << std::endl;

                // Salvare scor în baza de date
                std::string insertQuery = "INSERT INTO scores (player_name, score) VALUES ('Player ";
                insertQuery += _currentPlayer->GetMarker();
                insertQuery += "', 1);";
                db.ExecuteQuery(insertQuery);
                break;
            }
            SwitchPlayer();
        } else {
            std::cout << "Invalid move. Try again." << std::endl;
        }
    }

    if (!IsGameOver()) {
        std::cout << "It's a draw!" << std::endl;
    }
}
