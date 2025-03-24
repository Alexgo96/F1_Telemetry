#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <string>
#include <vector>
#include <functional>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>

using namespace sql;

class DatabaseManager {
private:
    sql::Driver* driver;
    sql::Connection* connection;

public:
    // Constructor
    DatabaseManager(const std::string& host, const std::string& user, const std::string& password, const std::string& database);

    // Destructor
    ~DatabaseManager();

    // Execute SQL query
    bool executeQuery(const std::string& sqlQuery);

    // Execute prepared SQL query
    bool executePreparedStatement(const std::string& sqlQuery, std::vector<std::string>& params);

    // Execute SQL query with callback (select)
    bool executeQueryWithCallback(const std::string& sqlQuery, std::function<void(ResultSet*)> callback);
};

#endif // DATABASEMANAGER_H
