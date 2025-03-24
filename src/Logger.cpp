#include "../lib/Logger.h"

Logger::Logger() {}

Logger& Logger::instance() {
    static Logger logger;
    return logger;
}

void Logger::initialize(const std::string& filename) {
    logFile.open(filename, std::ios::app);
}

void Logger::log(const std::string& message) {
    std::lock_guard<std::mutex> lock(mutex);
    if (logFile.is_open()) {
        logFile << getCurrentTimestamp() << " " << message << std::endl;
    }
}

std::string Logger::getCurrentTimestamp() const {
    time_t rawTime;
    struct tm* timeInfo;
    char buffer[80];

    time(&rawTime);
    timeInfo = localtime(&rawTime);

    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", timeInfo);
    return std::string(buffer);
}
