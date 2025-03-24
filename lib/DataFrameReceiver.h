#ifndef DATA_FRAME_RECEIVER_H
#define DATA_FRAME_RECEIVER_H

#include <vector>
#include <netinet/in.h>

class DataFrameReceiver {
private:
    int sockfd;
    struct sockaddr_in servaddr;
    const static int MAX_BUFFER_SIZE = 2048; // Maximum size of the buffer

public:
    DataFrameReceiver(int port);

    ~DataFrameReceiver();

    std::vector<unsigned char> receiveDataFrame();
};

#endif // DATA_FRAME_RECEIVER_H
