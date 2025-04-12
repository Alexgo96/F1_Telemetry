#include <cstdint>
#include "../lib/Packet.h"
#include "../lib/PacketHeader.h"
#include "../lib/CarStatusData.h"
#include "../lib/PacketCarStatusData.h"
#include <vector>
#include "../lib/ByteConverter.h"

// Constructor
PacketCarStatusData::PacketCarStatusData(PacketHeader header)
    : m_header(header)
{
    std::cout << "IN CONSTRUCTOR PACKET FORMAT IS = " << std::to_string(m_header.getPacketFormat());
}

// Method to create PacketCarStatusData
void PacketCarStatusData::createPacketCarStatusData(std::vector<unsigned char>& dataFrame, uint8_t numCars) {
    for (int i = 0; i < numCars; i++) {
        uint8_t m_tractionControl = ByteConverter::toUInt8(dataFrame, 0);
        dataFrame.erase(dataFrame.begin());
        uint8_t m_antiLockBrakes = ByteConverter::toUInt8(dataFrame, 0);
        dataFrame.erase(dataFrame.begin());
        uint8_t m_fuelMix = ByteConverter::toUInt8(dataFrame, 0);
        dataFrame.erase(dataFrame.begin());
        uint8_t m_frontBrakeBias = ByteConverter::toUInt8(dataFrame, 0);
        dataFrame.erase(dataFrame.begin());
        uint8_t m_pitLimiterStatus = ByteConverter::toUInt8(dataFrame, 0);
        dataFrame.erase(dataFrame.begin());
        float m_fuelInTank = ByteConverter::toFloat(dataFrame, 0);
        dataFrame.erase(dataFrame.begin(), dataFrame.begin() + sizeof(float));
        float m_fuelCapacity = ByteConverter::toFloat(dataFrame, 0);
        dataFrame.erase(dataFrame.begin(), dataFrame.begin() + sizeof(float));
        float m_fuelRemainingLaps = ByteConverter::toFloat(dataFrame, 0);
        dataFrame.erase(dataFrame.begin(), dataFrame.begin() + sizeof(float));
        uint16_t m_maxRPM = ByteConverter::toUInt16(dataFrame, 0);
        dataFrame.erase(dataFrame.begin(), dataFrame.begin() + sizeof(uint16_t));
        uint16_t m_idleRPM = ByteConverter::toUInt16(dataFrame, 0);
        dataFrame.erase(dataFrame.begin(), dataFrame.begin() + sizeof(uint16_t));
        uint8_t m_maxGears = ByteConverter::toUInt8(dataFrame, 0);
        dataFrame.erase(dataFrame.begin());
        uint8_t m_drsAllowed = ByteConverter::toUInt8(dataFrame, 0);
        dataFrame.erase(dataFrame.begin());
        uint16_t m_drsActivationDistance = ByteConverter::toUInt16(dataFrame, 0);
        dataFrame.erase(dataFrame.begin(), dataFrame.begin() + sizeof(uint16_t));
        uint8_t m_actualTyreCompound = ByteConverter::toUInt8(dataFrame, 0);
        dataFrame.erase(dataFrame.begin());
        uint8_t m_visualTyreCompound = ByteConverter::toUInt8(dataFrame, 0);
        dataFrame.erase(dataFrame.begin());
        uint8_t m_tyresAgeLaps = ByteConverter::toUInt8(dataFrame, 0);
        dataFrame.erase(dataFrame.begin());
        int8_t m_vehicleFiaFlags = ByteConverter::toInt8(dataFrame, 0);
        dataFrame.erase(dataFrame.begin());
        float m_enginePowerICE = ByteConverter::toFloat(dataFrame, 0);
        dataFrame.erase(dataFrame.begin(), dataFrame.begin() + sizeof(float));
        float m_enginePowerMGUK = ByteConverter::toFloat(dataFrame, 0);
        dataFrame.erase(dataFrame.begin(), dataFrame.begin() + sizeof(float));
        float m_ersStoreEnergy = ByteConverter::toFloat(dataFrame, 0);
        dataFrame.erase(dataFrame.begin(), dataFrame.begin() + sizeof(float));
        uint8_t m_ersDeployMode = ByteConverter::toUInt8(dataFrame, 0);
        dataFrame.erase(dataFrame.begin());
        float m_ersHarvestedThisLapMGUK = ByteConverter::toFloat(dataFrame, 0);
        dataFrame.erase(dataFrame.begin(), dataFrame.begin() + sizeof(float));
        float m_ersHarvestedThisLapMGUH = ByteConverter::toFloat(dataFrame, 0);
        dataFrame.erase(dataFrame.begin(), dataFrame.begin() + sizeof(float));
        float m_ersDeployedThisLap = ByteConverter::toFloat(dataFrame, 0);
        dataFrame.erase(dataFrame.begin(), dataFrame.begin() + sizeof(float));
        uint8_t m_networkPaused = ByteConverter::toUInt8(dataFrame, 0);
        dataFrame.erase(dataFrame.begin());

        m_carStatusData[i] = CarStatusData(
            m_tractionControl, m_antiLockBrakes, m_fuelMix, m_frontBrakeBias, m_pitLimiterStatus,
            m_fuelInTank, m_fuelCapacity, m_fuelRemainingLaps, m_maxRPM, m_idleRPM, m_maxGears,
            m_drsAllowed, m_drsActivationDistance, m_actualTyreCompound, m_visualTyreCompound,
            m_tyresAgeLaps, m_vehicleFiaFlags, m_enginePowerICE, m_enginePowerMGUK, m_ersStoreEnergy,
            m_ersDeployMode, m_ersHarvestedThisLapMGUK, m_ersHarvestedThisLapMGUH, m_ersDeployedThisLap,
            m_networkPaused
        );
    }
}

// Getter methods for private member variables
const PacketHeader PacketCarStatusData::getHeader() const { return m_header; }
const CarStatusData* PacketCarStatusData::getCarStatusData() const { return m_carStatusData; }
const CarStatusData PacketCarStatusData::getCarStatusDataPosition(int position) const { return m_carStatusData[position]; }
