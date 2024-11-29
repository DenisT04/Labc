#pragma once
#include <sqlite3.h>
#include <string>
#include <vector>

class Database {
private:
    sqlite3* _db;
    std::string _dbName;

public:
    Database(const std::string& dbName);
    ~Database();

    bool ExecuteQuery(const std::string& query);
    std::vector<std::vector<std::string>> FetchQuery(const std::string& query);

    void Initialize();
};
