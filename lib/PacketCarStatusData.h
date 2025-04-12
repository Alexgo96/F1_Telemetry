#ifndef PACKETCARSTATUSDATA_H
#define PACKETCARSTATUSDATA_H

#include <cstdint>
#include <vector>
#include "./Packet.h"
#include "./PacketHeader.h"
#include "./CarStatusData.h"

class PacketCarStatusData : public Packet {
private:
    PacketHeader m_header;
    CarStatusData m_carStatusData[22];

public:
    // Constructor
    PacketCarStatusData(PacketHeader header);

    // Method to create PacketCarStatusData
    void createPacketCarStatusData(std::vector<unsigned char>& dataFrame, uint8_t numCars);

    // Getter methods for private member variables
    const PacketHeader getHeader() const;
    const CarStatusData* getCarStatusData() const;
    const CarStatusData getCarStatusDataPosition(int position) const;
};

#endif // PACKETCARSTATUSDATA_H
