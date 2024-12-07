#include "database.hpp"
#include <iostream>

Database::Database(const std::string& dbName) : _db(nullptr), _dbName(dbName) {
    if (sqlite3_open(dbName.c_str(), &_db) != SQLITE_OK) {
        std::cerr << "Error opening database: " << sqlite3_errmsg(_db) << std::endl;
    }
}

Database::~Database() {
    if (_db) {
        sqlite3_close(_db);
    }
}

bool Database::ExecuteQuery(const std::string& query) {
    char* errorMessage = nullptr;
    if (sqlite3_exec(_db, query.c_str(), nullptr, nullptr, &errorMessage) != SQLITE_OK) {
        std::cerr << "SQL error: " << errorMessage << std::endl;
        sqlite3_free(errorMessage);
        return false;
    }
    return true;
}

std::vector<std::vector<std::string>> Database::FetchQuery(const std::string& query) {
    sqlite3_stmt* stmt;
    std::vector<std::vector<std::string>> results;

    if (sqlite3_prepare_v2(_db, query.c_str(), -1, &stmt, nullptr) == SQLITE_OK) {
        while (sqlite3_step(stmt) == SQLITE_ROW) {
            int cols = sqlite3_column_count(stmt);
            std::vector<std::string> row;
            for (int i = 0; i < cols; i++) {
                const char* value = reinterpret_cast<const char*>(sqlite3_column_text(stmt, i));
                row.push_back(value ? value : "NULL");
            }
            results.push_back(row);
        }
        sqlite3_finalize(stmt);
    } else {
        std::cerr << "Failed to execute query: " << sqlite3_errmsg(_db) << std::endl;
    }
    return results;
}

void Database::Initialize() {
    const std::string createTableQuery =
        "CREATE TABLE IF NOT EXISTS scores ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT, "
        "player_name TEXT NOT NULL, "
        "score INTEGER NOT NULL);";
    ExecuteQuery(createTableQuery);
}

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
