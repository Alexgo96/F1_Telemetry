#include "ParticipantData.h"
#include <cstring>  // For strncpy

// Default constructor
ParticipantData::ParticipantData() :
    m_aiControlled(0), m_driverId(0), m_networkId(0), m_teamId(0),
    m_myTeam(0), m_raceNumber(0), m_nationality(0),
    m_yourTelemetry(0), m_showOnlineNames(0), m_platform(0) {
    std::memset(m_name, 0, sizeof(m_name)); // Initialize name with null characters
}

// Parameterized constructor
ParticipantData::ParticipantData(uint8_t aiControlled, uint8_t driverId, uint8_t networkId,
                 uint8_t teamId, uint8_t myTeam, uint8_t raceNumber,
                 uint8_t nationality, char name[48], uint8_t yourTelemetry,
                 uint8_t showOnlineNames, uint8_t platform)
    : m_aiControlled(aiControlled), m_driverId(driverId), m_networkId(networkId),
      m_teamId(teamId), m_myTeam(myTeam), m_raceNumber(raceNumber),
      m_nationality(nationality), m_yourTelemetry(yourTelemetry),
      m_showOnlineNames(showOnlineNames), m_platform(platform) {
    std::strncpy(m_name, name, 47); // Copy name and ensure null termination
    m_name[47] = '\0'; // Enforce null termination
}

// Getter method implementations
uint8_t ParticipantData::getAiControlled() const {
    return m_aiControlled;
}

uint8_t ParticipantData::getDriverId() const {
    return m_driverId;
}

uint8_t ParticipantData::getNetworkId() const {
    return m_networkId;
}

uint8_t ParticipantData::getTeamId() const {
    return m_teamId;
}

uint8_t ParticipantData::getMyTeam() const {
    return m_myTeam;
}

uint8_t ParticipantData::getRaceNumber() const {
    return m_raceNumber;
}

uint8_t ParticipantData::getNationality() const {
    return m_nationality;
}

char* ParticipantData::getName() const {
    return const_cast<char*>(m_name); // Return non-const pointer (use with caution)
}

uint8_t ParticipantData::getYourTelemtry() const {
    return m_yourTelemetry;
}

uint8_t ParticipantData::getShowOnlineNames() const {
    return m_showOnlineNames;
}

uint8_t ParticipantData::getPlatform() const {
    return m_platform;
}
