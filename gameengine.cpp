#include "gameengine.hpp"
#include <iostream>

// Constructor de inițializare
GameEngine::GameEngine(const std::shared_ptr<Player>& p1, const std::shared_ptr<Player>& p2)
    : _player1(p1), _player2(p2), _currentPlayer(p1) {}

void GameEngine::Run(std::istream& is, std::ostream& os) {
    char winner = ' ';
    while (!IsGameOver(winner)) {
        _board.Display(os);
        Point move = _currentPlayer->GetMove(is);
        if (_board.IsEmpty(move)) {
            _board.PlaceMarker(move, _currentPlayer->GetMarker());
            SwitchPlayer();
        } else {
            os << "Cell is already occupied. Try again.\n";
        }
    }
    _board.Display(os);
    if (winner != ' ') {
        os << "Player " << (_currentPlayer == _player1 ? _player2->GetName() : _player1->GetName()) << " wins!\n";
    } else {
        os << "It's a draw!\n";
    }
}

void GameEngine::SwitchPlayer() {
    _currentPlayer = (_currentPlayer == _player1) ? _player2 : _player1;
}

bool GameEngine::IsGameOver(char& winner) const {
    if (_board.CheckWin(_player1->GetMarker())) {
        winner = _player1->GetMarker();
        return true;
    }
    if (_board.CheckWin(_player2->GetMarker())) {
        winner = _player2->GetMarker();
        return true;
    }
    if (_board.IsFull()) {
        winner = ' ';
        return true;
    }
    return false;
}

