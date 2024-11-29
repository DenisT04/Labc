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
