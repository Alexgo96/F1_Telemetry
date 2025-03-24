#include <cstdint>
#include "../lib/LapData.h"

    // Constructor
    LapData::LapData(){}
    LapData::LapData(uint32_t lastLapTimeInMS, uint32_t currentLapTimeInMS,
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
            uint16_t pitStopTimerInMS, uint8_t pitStopShouldServePen)
        : m_lastLapTimeInMS(lastLapTimeInMS),
          m_currentLapTimeInMS(currentLapTimeInMS),
          m_sector1TimeInMS(sector1TimeInMS),
          m_sector1TimeMinutes(sector1TimeMinutes),
          m_sector2TimeInMS(sector2TimeInMS),
          m_sector2TimeMinutes(sector2TimeMinutes),
          m_deltaToCarInFrontInMS(deltaToCarInFrontInMS),
          m_deltaToRaceLeaderInMS(deltaToRaceLeaderInMS),
          m_lapDistance(lapDistance),
          m_totalDistance(totalDistance),
          m_safetyCarDelta(safetyCarDelta),
          m_carPosition(carPosition),
          m_currentLapNum(currentLapNum),
          m_pitStatus(pitStatus),
          m_numPitStops(numPitStops),
          m_sector(sector),
          m_currentLapInvalid(currentLapInvalid),
          m_penalties(penalties),
          m_totalWarnings(totalWarnings),
          m_cornerCuttingWarnings(cornerCuttingWarnings),
          m_numUnservedDriveThroughPens(numUnservedDriveThroughPens),
          m_numUnservedStopGoPens(numUnservedStopGoPens),
          m_gridPosition(gridPosition),
          m_driverStatus(driverStatus),
          m_resultStatus(resultStatus),
          m_pitLaneTimerActive(pitLaneTimerActive),
          m_pitLaneTimeInLaneInMS(pitLaneTimeInLaneInMS),
          m_pitStopTimerInMS(pitStopTimerInMS),
          m_pitStopShouldServePen(pitStopShouldServePen)
    {
    }

    // Getter methods for private member variables
    uint32_t LapData::getLastLapTimeInMS() const { return m_lastLapTimeInMS; }
    uint32_t LapData::getCurrentLapTimeInMS() const { return m_currentLapTimeInMS; }
    uint16_t LapData::getSector1TimeInMS() const { return m_sector1TimeInMS; }
    uint8_t LapData::getSector1TimeMinutes() const { return m_sector1TimeMinutes; }
    uint16_t LapData::getSector2TimeInMS() const { return m_sector2TimeInMS; }
    uint8_t LapData::getSector2TimeMinutes() const { return m_sector2TimeMinutes; }
    uint16_t LapData::getDeltaToCarInFrontInMS() const { return m_deltaToCarInFrontInMS; }
    uint16_t LapData::getDeltaToRaceLeaderInMS() const { return m_deltaToRaceLeaderInMS; }
    float LapData::getLapDistance() const { return m_lapDistance; }
    float LapData::getTotalDistance() const { return m_totalDistance; }
    float LapData::getSafetyCarDelta() const { return m_safetyCarDelta; }
    uint8_t LapData::getCarPosition() const { return m_carPosition; }
    uint8_t LapData::getCurrentLapNum() const { return m_currentLapNum; }
    uint8_t LapData::getPitStatus() const { return m_pitStatus; }
    uint8_t LapData::getNumPitStops() const { return m_numPitStops; }
    uint8_t LapData::getSector() const { return m_sector; }
    uint8_t LapData::getCurrentLapInvalid() const { return m_currentLapInvalid; }
    uint8_t LapData::getPenalties() const { return m_penalties; }
    uint8_t LapData::getTotalWarnings() const { return m_totalWarnings; }
    uint8_t LapData::getCornerCuttingWarnings() const { return m_cornerCuttingWarnings; }
    uint8_t LapData::getNumUnservedDriveThroughPens() const { return m_numUnservedDriveThroughPens; }
    uint8_t LapData::getNumUnservedStopGoPens() const { return m_numUnservedStopGoPens; }
    uint8_t LapData::getGridPosition() const { return m_gridPosition; }
    uint8_t LapData::getDriverStatus() const { return m_driverStatus; }
    uint8_t LapData::getResultStatus() const { return m_resultStatus; }
    uint8_t LapData::getPitLaneTimerActive() const { return m_pitLaneTimerActive; }
    uint16_t LapData::getPitLaneTimeInLaneInMS() const { return m_pitLaneTimeInLaneInMS; }
    uint16_t LapData::getPitStopTimerInMS() const { return m_pitStopTimerInMS; }
    uint8_t LapData::getPitStopShouldServePen() const { return m_pitStopShouldServePen; }
