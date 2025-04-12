#ifndef PACKETTYRESETSDATA_H
#define PACKETTYRESETSDATA_H

#include <cstdint>
#include <vector>
#include "./Packet.h"
#include "./PacketHeader.h"
#include "./TyreSetData.h"

class PacketTyreSetsData : public Packet {
private:
    PacketHeader m_header;
    uint8_t m_carIdx;                // Index of the car this data relates to
    TyreSetData m_tyreSetData[20];   // 13 (dry) + 7 (wet)
    uint8_t m_fittedIdx;             // Index into array of fitted tyre

public:
    // Constructor
    PacketTyreSetsData(PacketHeader header);

    // Method to create PacketTyreSetsData
    void createPacketTyreSetsData(std::vector<unsigned char>& dataFrame);

    // Getter methods for private member variables
    const PacketHeader getHeader() const;
    const uint8_t getCarIdx() const;
    const TyreSetData* getTyreSetData() const;
    const TyreSetData getTyreSetDataPosition(int position) const;
    const uint8_t getFittedIdx() const;
};

#endif // PACKETTYRESETSDATA_H
