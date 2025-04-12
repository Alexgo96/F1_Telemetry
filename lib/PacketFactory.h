#ifndef PACKETFACTORY_H
#define PACKETFACTORY_H

#include <iostream>
#include <memory>
#include <vector>
#include "../lib/Packet.h"
#include "../lib/PacketLapData.h"
#include "../lib/PacketHeader.h" // Assuming you have this header for PacketHeader
#include "../lib/PacketCarTelemetryData.h"

class PacketFactory {
public:
    // Function to create a packet based on a number
    static std::unique_ptr<Packet> createPacket(int packetType, PacketHeader packetHeader, std::vector<unsigned char>& dataFrame, uint8_t numCars);
    static PacketLapData createPacketLapData(int packetType, PacketHeader packetHeader, std::vector<unsigned char>& dataFrame, uint8_t numCars);
    static PacketCarTelemetryData createPacketCarTelemetryData(int packetType, PacketHeader packetHeader, std::vector<unsigned char>& dataFrame, uint8_t numCars);
};

#endif // PACKETFACTORY_H
