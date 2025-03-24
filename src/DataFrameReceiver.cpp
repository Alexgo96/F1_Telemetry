#include "../lib/DataFrameReceiver.h"
#include "../lib/Logger.h"
#include <string.h>
#include <fstream>
#include <unistd.h>

DataFrameReceiver::DataFrameReceiver(int port) {
    Logger::instance().log("Creating UDP socket");
    // Create a UDP socket
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        Logger::instance().log("Error creating socket");
        std::cerr << "Error creating socket" << std::endl;
        return;
    }

    // Initialize server address structure
    Logger::instance().log("Initzializing server address structure");
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(port);

    // Bind the socket with the server address
    Logger::instance().log("Binding the socket with the server address");
    if (bind(sockfd, (const struct sockaddr*)&servaddr, sizeof(servaddr)) < 0) {
        Logger::instance().log("Error binding socket");
        std::cerr << "Error binding socket" << std::endl;
        return;
    }
}

DataFrameReceiver::~DataFrameReceiver() {
    // Close the socket
    close(sockfd);
}

std::vector<unsigned char> DataFrameReceiver::receiveDataFrame() {
    std::vector<unsigned char> buffer(MAX_BUFFER_SIZE);
    struct sockaddr_in cliaddr;
    socklen_t len = sizeof(cliaddr);

    Logger::instance().log("Server starting to listen in UDP port");

    while (true) {
        // Receive data frame
        int n = recvfrom(sockfd, buffer.data(), MAX_BUFFER_SIZE, 0, (struct sockaddr*)&cliaddr, &len);
        if (n < 0) {
            std::cerr << "Error receiving data frame" << std::endl;
            continue;
        }

        // Resize the buffer to the actual size received
        buffer.resize(n);

        return buffer;
    }
}
