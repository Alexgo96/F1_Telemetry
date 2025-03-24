#ifndef LAPDATA_H
#define LAPDATA_H

#include <cstdint>

class LapData {
private:
    uint32_t m_lastLapTimeInMS;
    uint32_t m_currentLapTimeInMS;
    uint16_t m_sector1TimeInMS;
    uint8_t m_sector1TimeMinutes;
    uint16_t m_sector2TimeInMS;
    uint8_t m_sector2TimeMinutes;
    uint16_t m_deltaToCarInFrontInMS;
    uint16_t m_deltaToRaceLeaderInMS;
    float m_lapDistance;
    float m_totalDistance;
    float m_safetyCarDelta;
    uint8_t m_carPosition;
    uint8_t m_currentLapNum;
    uint8_t m_pitStatus;
    uint8_t m_numPitStops;
    uint8_t m_sector;
    uint8_t m_currentLapInvalid;
    uint8_t m_penalties;
    uint8_t m_totalWarnings;
    uint8_t m_cornerCuttingWarnings;
    uint8_t m_numUnservedDriveThroughPens;
    uint8_t m_numUnservedStopGoPens;
    uint8_t m_gridPosition;
    uint8_t m_driverStatus;
    uint8_t m_resultStatus;
    uint8_t m_pitLaneTimerActive;
    uint16_t m_pitLaneTimeInLaneInMS;
    uint16_t m_pitStopTimerInMS;
    uint8_t m_pitStopShouldServePen;

public:
    LapData();
    // Constructor
    LapData(uint32_t lastLapTimeInMS, uint32_t currentLapTimeInMS,
            uint16_t sector1TimeInMS, uint8_t sector1TimeMinutes,
            uint16_t sector2TimeInMS, uint8_t sector2TimeMinutes,
            uint16_t deltaToCarInFrontInMS, uint16_t deltaToRaceLeaderInMS,
            float lapDistance, float totalDistance, float safetyCarDelta,
            uint8_t carPosition, uint8_t currentLapNum, uint8_t pitStatus,
            uint8_t numPitStops, uint8_t sector, uint8_t currentLapInvalid,
            uint8_t penalties, uint8_t totalWarnings, uint8_t cornerCuttingWarnings,
            uint8_t numUnservedDriveThroughPens, uint8_t numUnservedStopGoPens,
            uint8_t gridPosition, uint8_t driverStatus, uint8_t resultStatus,
            uint8_t pitLaneTimerActive, uint16_t pitLaneTimeInLaneInMS,
            uint16_t pitStopTimerInMS, uint8_t pitStopShouldServePen);

    // Getter methods for private member variables
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

