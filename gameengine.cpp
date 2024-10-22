#include "gameengine.hpp"

// Constructor implicit
GameEngine::GameEngine() : _player1('X'), _player2('O'), _currentPlayer(&_player1) {}

// Constructor de inițializare
GameEngine::GameEngine(const Player& p1, const Player& p2) : _player1(p1), _player2(p2), _currentPlayer(&_player1) {}

// Constructor de copiere
GameEngine::GameEngine(const GameEngine& other) : _board(other._board), _player1(other._player1), _player2(other._player2), _currentPlayer(other._currentPlayer == &other._player1 ? &_player1 : &_player2) {}

// Operator de atribuire
GameEngine& GameEngine::operator=(const GameEngine& other) {
    if (this != &other) {
        _board = other._board;
        _player1 = other._player1;
        _player2 = other._player2;
        _currentPlayer = (other._currentPlayer == &other._player1) ? &_player1 : &_player2;
    }
    return *this;
}

// Operator de comparație
bool GameEngine::operator==(const GameEngine& other) const {
    return _board == other._board && _player1 == other._player1 && _player2 == other._player2;
}

bool GameEngine::operator!=(const GameEngine& other) const {
    return !(*this == other);
}

// Suprascrierea operatorului de afișare
void GameEngine::Print(std::ostream& os) const {
    os << "Game Engine Status: \n";
    os << _board;
    os << "\nCurrent Player: " << (_currentPlayer == &_player1 ? "Player 1" : "Player 2") << "\n";
}

// Suprascrierea operatorului de citire
void GameEngine::Read(std::istream& is) {
    is >> _board;
    // Citire mai complexă ar trebui implementată pentru jucători
}
