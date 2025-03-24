#ifndef PACKETHEADER_H
#define PACKETHEADER_H

#include <cstdint>
#include "Packet.h"

class PacketHeader : public Packet {
private:
    uint16_t m_packetFormat;
    uint8_t m_gameYear;
    uint8_t m_gameMajorVersion;
    uint8_t m_gameMinorVersion;
    uint8_t m_packetVersion;
    uint8_t m_packetId;
    uint64_t m_sessionUID;
    float m_sessionTime;
    uint32_t m_frameIdentifier;
    uint32_t m_overallFrameIdentifier;
    uint8_t m_playerCarIndex;
    uint8_t m_secondaryPlayerCarIndex;

public:
    // Constructor
    PacketHeader(uint16_t packetFormat, uint8_t gameYear, uint8_t gameMajorVersion,
                 uint8_t gameMinorVersion, uint8_t packetVersion, uint8_t packetId,
                 uint64_t sessionUID, float sessionTime, uint32_t frameIdentifier,
                 uint32_t overallFrameIdentifier, uint8_t playerCarIndex,
                 uint8_t secondaryPlayerCarIndex);

    // Accessor methods for private member variables
    uint16_t getPacketFormat() const;
    uint8_t getGameYear() const;
    uint8_t getGameMajorVersion() const;
    uint8_t getGameMinorVersion() const;
    uint8_t getPacketVersion() const;
    uint8_t getPacketId() const;
    uint64_t getSessionUID() const;
    float getSessionTime() const;
    uint32_t getFrameIdentifier() const;
    uint32_t getOverallFrameIdentifier() const;
    uint8_t getPlayerCarIndex() const;
    uint8_t getSecondaryPlayerCarIndex() const;
};

#endif // PACKETHEADER_H
