#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <fstream>
#include <ctime>
#include <mutex>

class Logger {
private:
    std::ofstream logFile;
    std::mutex mutex;

    Logger(); // Private constructor to prevent instantiation

public:
    static Logger& instance();

    void initialize(const std::string& filename);

    void log(const std::string& message);

private:
    std::string getCurrentTimestamp() const;
};

#endif // LOGGER_H
