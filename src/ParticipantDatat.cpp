#ifndef PARTICIPANTDATA_H
#define PARTICIPANTDATA_H

#include <cstdint>

class LapData {
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
    LapData();
    // Constructor
    LapData(uint8_t m_aiControlled, uint8_t m_driverId, uint8_t m_networkId,
        uint8_t m_teamId, uint8_t m_myTeam, uint8_t m_raceNumber, uint8_t m_nationality,
        char m_name[48], uint8_t m_yourTelemetry, uint8_t m_showOnlineNames,
        uint8_t m_platform);

    // Getter methods for private member variables --> FOLLOW HERE
    uint32_t getLastLapTimeInMS() const;
    uint32_t getCurrentLapTimeInMS() const;
    uint16_t getSector1TimeInMS() const;
    uint8_t getSector1TimeMinutes() const;
    uint16_t getSector2TimeInMS() const;
    uint8_t getSector2TimeMinutes() const;
    uint16_t getDeltaToCarInFrontInMS() const;
    uint16_t getDeltaToRaceLeaderInMS() const;
    float getLapDistance() const;
    float getTotalDistance() const;
    float getSafetyCarDelta() const;
    uint8_t getCarPosition() const;
    uint8_t getCurrentLapNum() const;
    uint8_t getPitStatus() const;
    uint8_t getNumPitStops() const;
    uint8_t getSector() const;
    uint8_t getCurrentLapInvalid() const;
    uint8_t getPenalties() const;
    uint8_t getTotalWarnings() const;
    uint8_t getCornerCuttingWarnings() const;
    uint8_t getNumUnservedDriveThroughPens() const;
    uint8_t getNumUnservedStopGoPens() const;
    uint8_t getGridPosition() const;
    uint8_t getDriverStatus() const;
    uint8_t getResultStatus() const;
    uint8_t getPitLaneTimerActive() const;
    uint16_t getPitLaneTimeInLaneInMS() const;
    uint16_t getPitStopTimerInMS() const;
    uint8_t getPitStopShouldServePen() const;
};
#endif // LAPDATA_H

