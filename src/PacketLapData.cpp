#include <cstdint>
#include "../lib/Packet.h"
#include "../lib/PacketHeader.h"
#include "../lib/LapData.h"
#include "../lib/PacketLapData.h"
#include <vector>
#include "../lib/ByteConverter.h"

// Constructor
PacketLapData::PacketLapData(PacketHeader header)
    : m_header(header)
{
    std::cout << "IN CONSTRUCTOR PACKET FORMAT IS = " << std::to_string(m_header.getPacketFormat());
}
// Method to create PacketLapData
void PacketLapData::createPacketLapData(std::vector<unsigned char>& dataFrame, uint8_t numCars){
    for (int i = 0; i < numCars; i++){
        uint32_t m_lastLapTimeInMS = ByteConverter::toUInt32(dataFrame, 0);
        dataFrame.erase(dataFrame.begin(), dataFrame.begin() + sizeof(uint32_t));
        uint32_t m_currentLapTimeInMS = ByteConverter::toUInt32(dataFrame, 0);
        dataFrame.erase(dataFrame.begin(), dataFrame.begin() +sizeof(uint32_t));
        uint16_t m_sector1TimeInMS = ByteConverter::toUInt16(dataFrame, 0);
        dataFrame.erase(dataFrame.begin(), dataFrame.begin() + sizeof(uint16_t));
        uint8_t m_sector1TimeMinutes = ByteConverter::toUInt8(dataFrame, 0);
        dataFrame.erase(dataFrame.begin());
        uint16_t m_sector2TimeInMS = ByteConverter::toUInt16(dataFrame, 0);
        dataFrame.erase(dataFrame.begin(), dataFrame.begin() + sizeof(uint16_t));
        uint8_t m_sector2TimeMinutes = ByteConverter::toUInt8(dataFrame, 0);
        dataFrame.erase(dataFrame.begin());
        uint16_t m_deltaToCarInFrontInMS = ByteConverter::toUInt16(dataFrame, 0);
        dataFrame.erase(dataFrame.begin(), dataFrame.begin() + sizeof(uint16_t));
        uint16_t m_deltaToRaceLeaderInMS = ByteConverter::toUInt16(dataFrame, 0);
        dataFrame.erase(dataFrame.begin(), dataFrame.begin() + sizeof(uint16_t));
        float m_lapDistance = ByteConverter::toFloat(dataFrame, 0);
        dataFrame.erase(dataFrame.begin(), dataFrame.begin() + sizeof(float));
        float m_totalDistance = ByteConverter::toFloat(dataFrame, 0);
        dataFrame.erase(dataFrame.begin(), dataFrame.begin() + sizeof(float));
        float m_safetyCarDelta = ByteConverter::toFloat(dataFrame, 0);
        dataFrame.erase(dataFrame.begin(), dataFrame.begin() + sizeof(float));
        uint8_t m_carPosition = ByteConverter::toUInt8(dataFrame, 0);
        dataFrame.erase(dataFrame.begin());
        uint8_t m_currentLapNum = ByteConverter::toUInt8(dataFrame, 0);
        dataFrame.erase(dataFrame.begin());
        uint8_t m_pitStatus = ByteConverter::toUInt8(dataFrame, 0);
        dataFrame.erase(dataFrame.begin());
        uint8_t m_numPitStops = ByteConverter::toUInt8(dataFrame, 0);
        dataFrame.erase(dataFrame.begin());
        uint8_t m_sector = ByteConverter::toUInt8(dataFrame, 0);
        dataFrame.erase(dataFrame.begin());
        uint8_t m_currentLapInvalid = ByteConverter::toUInt8(dataFrame, 0);
        dataFrame.erase(dataFrame.begin());
        uint8_t m_penalties = ByteConverter::toUInt8(dataFrame, 0);
        dataFrame.erase(dataFrame.begin());
        uint8_t m_totalWarnings = ByteConverter::toUInt8(dataFrame, 0);
        dataFrame.erase(dataFrame.begin());
        uint8_t m_cornerCuttingWarnings = ByteConverter::toUInt8(dataFrame, 0);
        dataFrame.erase(dataFrame.begin());
        uint8_t m_numUnservedDriveThroughPens = ByteConverter::toUInt8(dataFrame, 0);
        dataFrame.erase(dataFrame.begin());
        uint8_t m_numUnservedStopGoPens = ByteConverter::toUInt8(dataFrame, 0);
        dataFrame.erase(dataFrame.begin());
        uint8_t m_gridPosition = ByteConverter::toUInt8(dataFrame, 0);
        dataFrame.erase(dataFrame.begin());
        uint8_t m_driverStatus = ByteConverter::toUInt8(dataFrame, 0);
        dataFrame.erase(dataFrame.begin());
        uint8_t m_resultStatus = ByteConverter::toUInt8(dataFrame, 0);
        dataFrame.erase(dataFrame.begin());
        uint8_t m_pitLaneTimerActive = ByteConverter::toUInt8(dataFrame, 0);
        dataFrame.erase(dataFrame.begin());
        uint16_t m_pitLaneTimeInLineInMS = ByteConverter::toUInt16(dataFrame, 0);
        dataFrame.erase(dataFrame.begin(), dataFrame.begin() + sizeof(uint16_t));
        uint16_t m_pitStopTimerInMS = ByteConverter::toUInt16(dataFrame, 0);
        dataFrame.erase(dataFrame.begin(), dataFrame.begin() + sizeof(uint16_t));
        uint8_t m_pitStopShouldServePen = ByteConverter::toUInt8(dataFrame, 0);
        dataFrame.erase(dataFrame.begin());
        m_lapData[i] = LapData(m_lastLapTimeInMS, m_currentLapTimeInMS,
            m_sector1TimeInMS, m_sector1TimeMinutes,
            m_sector2TimeInMS, m_sector2TimeMinutes,
            m_deltaToCarInFrontInMS, m_deltaToRaceLeaderInMS,
            m_lapDistance, m_totalDistance, m_safetyCarDelta,
            m_carPosition, m_currentLapNum, m_pitStatus,
            m_numPitStops, m_sector, m_currentLapInvalid,
            m_penalties, m_totalWarnings, m_cornerCuttingWarnings,
            m_numUnservedDriveThroughPens, m_numUnservedStopGoPens,
            m_gridPosition, m_driverStatus, m_resultStatus,
            m_pitLaneTimerActive, m_pitLaneTimeInLineInMS,
            m_pitStopTimerInMS, m_pitStopShouldServePen);
    }
    uint8_t m_timeTrialPBCarIdx = ByteConverter::toUInt8(dataFrame, 0);
    dataFrame.erase(dataFrame.begin());
    uint8_t m_timeTrialRivalCarIdx = ByteConverter::toUInt8(dataFrame, 0);
    dataFrame.erase(dataFrame.begin());
}
// Getter methods for private member variables
const PacketHeader PacketLapData::getHeader() const { return m_header; }
const LapData* PacketLapData::getLapData() const { return m_lapData; }
const LapData PacketLapData::getLapDataPosition(int position) const { return m_lapData[position]; }
uint8_t PacketLapData::getTimeTrialPBCarIdx() const { return m_timeTrialPBCarIdx; }
uint8_t PacketLapData::getTimeTrialRivalCarIdx() const { return m_timeTrialRivalCarIdx; }