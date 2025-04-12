#ifndef PACKETCARSETUPDATA_H
#define PACKETCARSETUPDATA_H

#include <cstdint>
#include <vector>
#include "./Packet.h"
#include "./PacketHeader.h"
#include "./CarSetupData.h"

class PacketCarSetupData : public Packet {
private:
    PacketHeader m_header;
    CarSetupData m_carSetups[22];

public:
    // Constructor
    PacketCarSetupData(PacketHeader header);

    // Method to create PacketCarSetupData
    void createPacketCarSetupData(std::vector<unsigned char>& dataFrame, uint8_t numCars);

    // Getter methods for private member variables
    const PacketHeader getHeader() const;
    const CarSetupData* getCarSetups() const;
    const CarSetupData getCarSetupPosition(int position) const;
};

#endif // PACKETCARSETUPDATA_H
