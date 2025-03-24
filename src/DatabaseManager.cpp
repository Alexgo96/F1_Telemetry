#include "../lib/DatabaseManager.h"
//#include <mysql_driver.h>
//#include <mysql_connection.h>
#include <iostream>

DatabaseManager::DatabaseManager(const std::string& host, const std::string& user, const std::string& password, const std::string& database) {
    try {
        driver = get_driver_instance();
        connection = driver->connect(host, user, password);
        connection->setSchema(database);
        std::cout << "Database MAnager initialized correctly" << std::endl;
    } catch (sql::SQLException& e) {
        // Handle connection error
        e.what(); // provides details about the exception
    }
}
DatabaseManager::~DatabaseManager() {
    delete connection;
}

// Execute SQL query
bool DatabaseManager::executeQuery(const std::string& sqlQuery) {
    try {
        Statement* stmt = connection->createStatement();
        stmt->execute(sqlQuery);
        delete stmt;
        std::cout << "Database Manager executed Query correctly" << std::endl;
        return true;
    } catch (sql::SQLException& e) {
        // Handle query execution error
        // e.what() provides details about the exception
        std::cout << "Database Manager did not execute Query correctly" << std::endl;
        std::cout << "DATABASE ERROR = " << e.what() << std::endl;
        return false;
    }
}
// Execute prepared SQL query
bool DatabaseManager::executePreparedStatement(const std::string& sqlQuery, std::vector<std::string>& params) {
    try {
        PreparedStatement* pstmt = connection->prepareStatement(sqlQuery);
        for (size_t i = 0; i < params.size(); ++i) {
            pstmt->setString(i + 1, params[i]);
        }
        pstmt->execute();
        delete pstmt;

        return true;
    } catch (sql::SQLException& e) {
        // Handle query execution error
        // e.what() provides details about the exception
        return false;
    }
}

// Execute SQL query with callback (select)
bool DatabaseManager::executeQueryWithCallback(const std::string& sqlQuery, std::function<void(ResultSet*)> callback) {
    try {
        Statement* stmt = connection->createStatement();
        ResultSet* res = stmt->executeQuery(sqlQuery);
        callback(res);
        delete res;
        delete stmt;
        return true;
    } catch (sql::SQLException& e) {
        // Handle query execution error
        // e.what() provides details about the exception
        return false;
    }
}
