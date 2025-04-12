#ifndef PACKETCARDAMAGEDATA_H
#define PACKETCARDAMAGEDATA_H

#include <cstdint>
#include <vector>
#include "./Packet.h"
#include "./PacketHeader.h"
#include "./CarDamageData.h"

class PacketCarDamageData : public Packet {
private:
    PacketHeader m_header;
    CarDamageData m_carDamageData[22]; // Data for all cars on track

public:
    // Constructor
    PacketCarDamageData(PacketHeader header);

    // Method to create PacketCarDamageData
    void createPacketCarDamageData(std::vector<unsigned char>& dataFrame, uint8_t numCars);

    // Getter methods for private member variables
    const PacketHeader getHeader() const;
    const CarDamageData* getCarDamageData() const;
    const CarDamageData getCarDamageDataPosition(int position) const;
};

#endif // PACKETCARDAMAGEDATA_H
