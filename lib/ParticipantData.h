#ifndef PARTICIPANTDATA_H
#define PARTICIPANTDATA_H

#include <cstdint>

class ParticipantData {
private:
    uint8_t m_aiControlled;
    uint8_t m_driverId;
    uint8_t m_networkId;
    uint8_t m_teamId;
    uint8_t m_myTeam;
    uint8_t m_raceNumber;
    uint8_t m_nationality;
    char m_name[48];
    uint8_t m_yourTelemetry;
    uint8_t m_showOnlineNames;
    uint8_t m_platform;
    

public:
    ParticipantData();
    // Constructor
    ParticipantData(uint8_t m_aiControlled, uint8_t m_driverId, uint8_t m_networkId,
        uint8_t m_teamId, uint8_t m_myTeam, uint8_t m_raceNumber, uint8_t m_nationality,
        char m_name[48], uint8_t m_yourTelemetry, uint8_t m_showOnlineNames,
        uint8_t m_platform);

    // Getter methods for private member variables --> FOLLOW HERE
    uint8_t getAiControlled() const;
    uint8_t getDriverId() const;
    uint8_t getNetworkId() const;
    uint8_t getTeamId() const;
    uint8_t getMyTeam() const;
    uint8_t getRaceNumber() const;
    uint8_t getNationality() const;
    char* getName() const;
    uint8_t getYourTelemtry() const;
    uint8_t getShowOnlineNames() const;
    uint8_t getPlatform() const;
};
#endif // PARTICIPANTDATA_H

