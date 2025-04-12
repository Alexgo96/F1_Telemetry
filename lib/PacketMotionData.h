#ifndef PACKETMOTIONDATA_H
#define PACKETMOTIONDATA_H

#include <cstdint>
#include "./Packet.h"
#include "./PacketHeader.h"
#include "./CarMotionData.h"
#include <vector>

class PacketMotionData : public Packet {
private:
    PacketHeader m_header;
    CarMotionData m_carMotionData[22];

public:
    // Constructor
    PacketMotionData(PacketHeader header);

    // Method to create PacketMotionData
    void createPacketMotionData(std::vector<unsigned char>& dataFrame, uint8_t numCars);

    // Getter methods for private member variables
    const PacketHeader getHeader() const;
    const CarMotionData* getCarMotionData() const;
    const CarMotionData getCarMotionDataPosition(int position) const;
};

#endif // PACKETMOTIONDATA_H
