#include "gameengine.hpp"
#include <iostream>

// Constructorul jocului, inițializează tabla și jucătorii
GameEngine::GameEngine() : _player1('X'), _player2('O'), _currentPlayer(&_player1) {}

// Inițializează jocul (poate reseta tabla sau alte componente)
void GameEngine::Init() {
    _board = Board(); // Resetează tabla
    _currentPlayer = &_player1; // Începe cu jucătorul 1
}

// Rulare joc, controlul principal al jocului
void GameEngine::Run() {
    while (!IsGameOver()) {
        _board.Display();
        Point move = _currentPlayer->GetMove();
        if (_board.IsEmpty(move)) {
            _board.PlaceMarker(move, _currentPlayer->GetMarker());
            if (_board.CheckWin(_currentPlayer->GetMarker())) {
                std::cout << "Jucătorul " << _currentPlayer->GetMarker() << " a câștigat!" << std::endl;
                _board.Display();
                break;
            }
            SwitchPlayer();
        } else {
            std::cout << "Poziție invalidă! Încearcă din nou." << std::endl;
        }
    }

    if (_board.IsFull()) {
        std::cout << "Jocul s-a terminat cu egalitate!" << std::endl;
    }
}

// Schimbă rândul jucătorului curent
void GameEngine::SwitchPlayer() {
    _currentPlayer = (_currentPlayer == &_player1) ? &_player2 : &_player1;
}

// Verifică dacă jocul s-a terminat (câștig sau egalitate)
bool GameEngine::IsGameOver() const {
    return _board.IsFull() || _board.CheckWin('X') || _board.CheckWin('O');
}
