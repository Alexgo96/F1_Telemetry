#include <iostream>
#include <memory>
#include "../lib/Packet.h"
#include "../lib/PacketLapData.h"
#include "../lib/PacketFactory.h"


// Function to create a packet based on a number
std::unique_ptr<Packet> PacketFactory::createPacket(int packetType, PacketHeader packetHeader, std::vector<unsigned char>& dataFrame, uint8_t numCars) {
    //std::unique_ptr<Packet> packet = nullptr;
    std::cout << "Processing pakcet in PacketFactory" << std::endl;
    std::cout << "packetType = " << packetType << std::endl;
    switch (packetType) {
        case 2: {
            std::cout << "Processing LapDataPacket" << std::endl;
            return std::make_unique<PacketLapData>(packetHeader);
            //packet->createPacketLapData(dataFrame, numCars);
            //std::cout << "IN THE FACTORY GAME YEAR IS = " << std::to_string(packet.get()->getHeader().getGameYear()) << std::endl;
            //std::cout << "MY CAR POSITION = " << std::to_string(packet->getLapDataPosition(19).getCarPosition()) << std::endl;
            //break;
        }
        default:
            break;
    }
    return std::make_unique<Packet>();
}

// Function to create a packet based on a number
PacketLapData PacketFactory::createPacketLapData(int packetType, PacketHeader packetHeader, std::vector<unsigned char>& dataFrame, uint8_t numCars) {
    PacketLapData packet = PacketLapData(packetHeader);
    std::cout << "Processing pakcet in PacketFactory" << std::endl;
    std::cout << "packetType = " << packetType << std::endl;
    std::cout << "Processing LapDataPacket" << std::endl;
    packet.createPacketLapData(dataFrame, numCars);
    std::cout << "IN THE FACTORY GAME YEAR IS = " << std::to_string(packet.getHeader().getGameYear()) << std::endl;
    std::cout << "MY CAR POSITION = " << std::to_string(packet.getLapDataPosition(19).getCarPosition()) << std::endl;
    return packet;
}