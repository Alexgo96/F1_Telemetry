#include <cstdint>
#include "../lib/Packet.h"
#include "../lib/PacketHeader.h"
#include "../lib/CarSetupData.h"
#include "../lib/PacketCarSetupData.h"
#include <vector>
#include "../lib/ByteConverter.h"

// Constructor
PacketCarSetupData::PacketCarSetupData(PacketHeader header)
    : m_header(header)
{
    std::cout << "IN CONSTRUCTOR PACKET FORMAT IS = " << std::to_string(m_header.getPacketFormat());
}

// Method to create PacketCarSetupData
void PacketCarSetupData::createPacketCarSetupData(std::vector<unsigned char>& dataFrame, uint8_t numCars) {
    for (int i = 0; i < numCars; i++) {
        uint8_t m_frontWing = ByteConverter::toUInt8(dataFrame, 0);
        dataFrame.erase(dataFrame.begin());

        uint8_t m_rearWing = ByteConverter::toUInt8(dataFrame, 0);
        dataFrame.erase(dataFrame.begin());

        uint8_t m_onThrottle = ByteConverter::toUInt8(dataFrame, 0);
        dataFrame.erase(dataFrame.begin());

        uint8_t m_offThrottle = ByteConverter::toUInt8(dataFrame, 0);
        dataFrame.erase(dataFrame.begin());

        float m_frontCamber = ByteConverter::toFloat(dataFrame, 0);
        dataFrame.erase(dataFrame.begin(), dataFrame.begin() + sizeof(float));

        float m_rearCamber = ByteConverter::toFloat(dataFrame, 0);
        dataFrame.erase(dataFrame.begin(), dataFrame.begin() + sizeof(float));

        float m_frontToe = ByteConverter::toFloat(dataFrame, 0);
        dataFrame.erase(dataFrame.begin(), dataFrame.begin() + sizeof(float));

        float m_rearToe = ByteConverter::toFloat(dataFrame, 0);
        dataFrame.erase(dataFrame.begin(), dataFrame.begin() + sizeof(float));

        uint8_t m_frontSuspension = ByteConverter::toUInt8(dataFrame, 0);
        dataFrame.erase(dataFrame.begin());

        uint8_t m_rearSuspension = ByteConverter::toUInt8(dataFrame, 0);
        dataFrame.erase(dataFrame.begin());

        uint8_t m_frontAntiRollBar = ByteConverter::toUInt8(dataFrame, 0);
        dataFrame.erase(dataFrame.begin());

        uint8_t m_rearAntiRollBar = ByteConverter::toUInt8(dataFrame, 0);
        dataFrame.erase(dataFrame.begin());

        uint8_t m_frontSuspensionHeight = ByteConverter::toUInt8(dataFrame, 0);
        dataFrame.erase(dataFrame.begin());

        uint8_t m_rearSuspensionHeight = ByteConverter::toUInt8(dataFrame, 0);
        dataFrame.erase(dataFrame.begin());

        uint8_t m_brakePressure = ByteConverter::toUInt8(dataFrame, 0);
        dataFrame.erase(dataFrame.begin());

        uint8_t m_brakeBias = ByteConverter::toUInt8(dataFrame, 0);
        dataFrame.erase(dataFrame.begin());

        float m_rearLeftTyrePressure = ByteConverter::toFloat(dataFrame, 0);
        dataFrame.erase(dataFrame.begin(), dataFrame.begin() + sizeof(float));

        float m_rearRightTyrePressure = ByteConverter::toFloat(dataFrame, 0);
        dataFrame.erase(dataFrame.begin(), dataFrame.begin() + sizeof(float));

        float m_frontLeftTyrePressure = ByteConverter::toFloat(dataFrame, 0);
        dataFrame.erase(dataFrame.begin(), dataFrame.begin() + sizeof(float));

        float m_frontRightTyrePressure = ByteConverter::toFloat(dataFrame, 0);
        dataFrame.erase(dataFrame.begin(), dataFrame.begin() + sizeof(float));

        uint8_t m_ballast = ByteConverter::toUInt8(dataFrame, 0);
        dataFrame.erase(dataFrame.begin());

        float m_fuelLoad = ByteConverter::toFloat(dataFrame, 0);
        dataFrame.erase(dataFrame.begin(), dataFrame.begin() + sizeof(float));

        m_carSetups[i] = CarSetupData(m_frontWing, m_rearWing, m_onThrottle, m_offThrottle,
                                      m_frontCamber, m_rearCamber, m_frontToe, m_rearToe,
                                      m_frontSuspension, m_rearSuspension, m_frontAntiRollBar, m_rearAntiRollBar,
                                      m_frontSuspensionHeight, m_rearSuspensionHeight, m_brakePressure, m_brakeBias,
                                      m_rearLeftTyrePressure, m_rearRightTyrePressure, m_frontLeftTyrePressure,
                                      m_frontRightTyrePressure, m_ballast, m_fuelLoad);
    }
}

// Getter methods for private member variables
const PacketHeader PacketCarSetupData::getHeader() const { return m_header; }
const CarSetupData* PacketCarSetupData::getCarSetups() const { return m_carSetups; }
const CarSetupData PacketCarSetupData::getCarSetupPosition(int position) const { return m_carSetups[position]; }
