#include "../lib/PacketHeader.h"

// Implementations of member functions go here

// Constructor
PacketHeader::PacketHeader(uint16_t packetFormat, uint8_t gameYear, uint8_t gameMajorVersion,
                           uint8_t gameMinorVersion, uint8_t packetVersion, uint8_t packetId,
                           uint64_t sessionUID, float sessionTime, uint32_t frameIdentifier,
                           uint32_t overallFrameIdentifier, uint8_t playerCarIndex,
                           uint8_t secondaryPlayerCarIndex)
    : m_packetFormat(packetFormat),
      m_gameYear(gameYear),
      m_gameMajorVersion(gameMajorVersion),
      m_gameMinorVersion(gameMinorVersion),
      m_packetVersion(packetVersion),
      m_packetId(packetId),
      m_sessionUID(sessionUID),
      m_sessionTime(sessionTime),
      m_frameIdentifier(frameIdentifier),
      m_overallFrameIdentifier(overallFrameIdentifier),
      m_playerCarIndex(playerCarIndex),
      m_secondaryPlayerCarIndex(secondaryPlayerCarIndex)
{
}

// Accessor methods for private member variables
uint16_t PacketHeader::getPacketFormat() const {
    return m_packetFormat;
}

uint8_t PacketHeader::getGameYear() const {
    return m_gameYear;
}

uint8_t PacketHeader::getGameMajorVersion() const {
    return m_gameMajorVersion;
}

uint8_t PacketHeader::getGameMinorVersion() const {
    return m_gameMinorVersion;
}

uint8_t PacketHeader::getPacketVersion() const {
    return m_packetVersion;
}

uint8_t PacketHeader::getPacketId() const {
    return m_packetId;
}

uint64_t PacketHeader::getSessionUID() const {
    return m_sessionUID;
}

float PacketHeader::getSessionTime() const {
    return m_sessionTime;
}

uint32_t PacketHeader::getFrameIdentifier() const {
    return m_frameIdentifier;
}

uint32_t PacketHeader::getOverallFrameIdentifier() const {
    return m_overallFrameIdentifier;
}

uint8_t PacketHeader::getPlayerCarIndex() const {
    return m_playerCarIndex;
}

uint8_t PacketHeader::getSecondaryPlayerCarIndex() const {
    return m_secondaryPlayerCarIndex;
}
