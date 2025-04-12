#include <cstdint>
#include <vector>
#include "../lib/Packet.h"
#include "../lib/PacketHeader.h"
#include "../lib/ParticipantData.h"
#include "../lib/PacketParticipantData.h"
#include "../lib/ByteConverter.h"

//Constructor
PacketParticipantData::PacketParticipantData(PacketHeader header)
    : m_header(header) {
}

//Method
void PacketParticipantData::createPacketParticipantData(std::vector<unsigned char>& dataFrame, uint8_t m_numCars){
    uint8_t m_numActiveCars = ByteConverter::toInt8(dataFrame, 0);
    dataFrame.erase(dataFrame.begin());
    
    for(int i = 0; i < m_numActiveCars; i++) {
        uint8_t m_aiControlled = ByteConverter::toUInt8(dataFrame, 0);
        dataFrame.erase(dataFrame.begin());
        uint8_t m_driverId = ByteConverter::toUInt8(dataFrame, 0);
        dataFrame.erase(dataFrame.begin());
        uint8_t m_networkId= ByteConverter::toUInt8(dataFrame, 0);
        dataFrame.erase(dataFrame.begin());
        uint8_t m_teamId = ByteConverter::toUInt8(dataFrame, 0);
        dataFrame.erase(dataFrame.begin());
        uint8_t m_myTeam = ByteConverter::toUInt8(dataFrame, 0);
        dataFrame.erase(dataFrame.begin());
        uint8_t m_raceNumber = ByteConverter::toUInt8(dataFrame, 0);
        dataFrame.erase(dataFrame.begin());
        uint8_t m_nationality = ByteConverter::toUInt8(dataFrame, 0);
        dataFrame.erase(dataFrame.begin());
        std::array<char, 48> m_name = ByteConverter::toChar(dataFrame, 0);
        dataFrame.erase(dataFrame.begin(), dataFrame.begin() + sizeof(std::array<char, 48>));
        uint8_t m_yourTelemetry= ByteConverter::toUInt8(dataFrame, 0);
        dataFrame.erase(dataFrame.begin());
        uint8_t m_showOnlineNames = ByteConverter::toUInt8(dataFrame, 0);
        dataFrame.erase(dataFrame.begin());
        uint8_t m_platform = ByteConverter::toUInt8(dataFrame, 0);
        dataFrame.erase(dataFrame.begin());
    }
}