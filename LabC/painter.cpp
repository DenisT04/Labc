#include "painter.hpp"
#include <iostream>

// Constructor implicit
Painter::Painter() {}

// Constructor de copiere
Painter::Painter(const Painter& other) {}

// Operator de atribuire
Painter& Painter::operator=(const Painter& other) {
    return *this;
}

// Restul metodelor rămân la fel (DrawBoard, DisplayMessage, etc.)


/**
 * @file board.hpp
 * @brief Declares the Board class for managing the game board.
 * @author Your Name
 * @date 2024
 */

#pragma once

#include "point.hpp"

/**
 * @class Board
 * @brief Represents the game board for TicTacToe.
 */
class Board {
    char _grid[3][3];  ///< The 3x3 game board.

public:
    /**
     * @brief Default constructor.
     * Initializes an empty board.
     */
    Board();

    /**
     * @brief Checks if the board is full.
     * @return True if the board is full, otherwise false.
     */
    bool IsFull() const;

    /**
     * @brief Checks if a cell is empty.
     * @param pos The position to check.
     * @return True if the cell is empty, otherwise false.
     */
    bool IsEmpty(const Point& pos) const;

    /**
     * @brief Places a marker on the board.
     * @param pos The position where the marker should be placed.
     * @param marker The marker to place ('X' or 'O').
     */
    void PlaceMarker(const Point& pos, char marker);

    /**
     * @brief Checks if a player has won.
     * @param marker The marker to check for winning.
     * @return True if the player has won, otherwise false.
     */
    bool CheckWin(char marker) const;

    /**
     * @brief Displays the board in the console.
     */
    void Display() const;
};
