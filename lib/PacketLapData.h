#ifndef PACKETLAPDATA_H
#define PACKETLAPDATA_H

#include <cstdint>
#include <vector>
#include "./Packet.h"
#include "./PacketHeader.h"
#include "./LapData.h"

class PacketLapData : public Packet {
private:
    PacketHeader m_header;
    LapData m_lapData[22];
    uint8_t m_timeTrialPBCarIdx;
    uint8_t m_timeTrialRivalCarIdx;

public:
    // Constructor
    PacketLapData(PacketHeader header);

    // Method to create PacketLapData
    void createPacketLapData(std::vector<unsigned char>& dataFrame, uint8_t numCars);

    // Getter methods for private member variables
    const PacketHeader getHeader() const;
    const LapData* getLapData() const;
    const LapData getLapDataPosition(int position) const;
    uint8_t getTimeTrialPBCarIdx() const;
    uint8_t getTimeTrialRivalCarIdx() const;
};

#endif // PACKETLAPDATA_H
