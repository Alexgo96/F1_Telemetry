#include <iostream>
#include <mysql_driver.h>

int main() {
    try {
        sql::mysql::MySQL_Driver *driver;
        driver = sql::mysql::get_mysql_driver_instance(); // Should not cause an error now
        std::cout << "MySQL Connector/C++ is installed and working!" << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
