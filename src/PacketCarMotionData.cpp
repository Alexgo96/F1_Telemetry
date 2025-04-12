#include <cstdint>
#include "../lib/Packet.h"
#include "../lib/PacketHeader.h"
#include "../lib/CarMotionData.h"
#include "../lib/PacketMotionData.h"
#include <vector>
#include "../lib/ByteConverter.h"

// Constructor
PacketMotionData::PacketMotionData(PacketHeader header)
    : m_header(header) {
    std::cout << "IN CONSTRUCTOR PACKET FORMAT IS = " << std::to_string(m_header.getPacketFormat());
}

// Method to create PacketMotionData
void PacketMotionData::createPacketMotionData(std::vector<unsigned char>& dataFrame, uint8_t numCars) {
    for (int i = 0; i < numCars; i++) {
        float m_worldPositionX = ByteConverter::toFloat(dataFrame, 0);
        dataFrame.erase(dataFrame.begin(), dataFrame.begin() + sizeof(float));
        float m_worldPositionY = ByteConverter::toFloat(dataFrame, 0);
        dataFrame.erase(dataFrame.begin(), dataFrame.begin() + sizeof(float));
        float m_worldPositionZ = ByteConverter::toFloat(dataFrame, 0);
        dataFrame.erase(dataFrame.begin(), dataFrame.begin() + sizeof(float));
        float m_worldVelocityX = ByteConverter::toFloat(dataFrame, 0);
        dataFrame.erase(dataFrame.begin(), dataFrame.begin() + sizeof(float));
        float m_worldVelocityY = ByteConverter::toFloat(dataFrame, 0);
        dataFrame.erase(dataFrame.begin(), dataFrame.begin() + sizeof(float));
        float m_worldVelocityZ = ByteConverter::toFloat(dataFrame, 0);
        dataFrame.erase(dataFrame.begin(), dataFrame.begin() + sizeof(float));
        int16_t m_worldForwardDirX = ByteConverter::toInt16(dataFrame, 0);
        dataFrame.erase(dataFrame.begin(), dataFrame.begin() + sizeof(int16_t));
        int16_t m_worldForwardDirY = ByteConverter::toInt16(dataFrame, 0);
        dataFrame.erase(dataFrame.begin(), dataFrame.begin() + sizeof(int16_t));
        int16_t m_worldForwardDirZ = ByteConverter::toInt16(dataFrame, 0);
        dataFrame.erase(dataFrame.begin(), dataFrame.begin() + sizeof(int16_t));
        int16_t m_worldRightDirX = ByteConverter::toInt16(dataFrame, 0);
        dataFrame.erase(dataFrame.begin(), dataFrame.begin() + sizeof(int16_t));
        int16_t m_worldRightDirY = ByteConverter::toInt16(dataFrame, 0);
        dataFrame.erase(dataFrame.begin(), dataFrame.begin() + sizeof(int16_t));
        int16_t m_worldRightDirZ = ByteConverter::toInt16(dataFrame, 0);
        dataFrame.erase(dataFrame.begin(), dataFrame.begin() + sizeof(int16_t));
        float m_gForceLateral = ByteConverter::toFloat(dataFrame, 0);
        dataFrame.erase(dataFrame.begin(), dataFrame.begin() + sizeof(float));
        float m_gForceLongitudinal = ByteConverter::toFloat(dataFrame, 0);
        dataFrame.erase(dataFrame.begin(), dataFrame.begin() + sizeof(float));
        float m_gForceVertical = ByteConverter::toFloat(dataFrame, 0);
        dataFrame.erase(dataFrame.begin(), dataFrame.begin() + sizeof(float));
        float m_yaw = ByteConverter::toFloat(dataFrame, 0);
        dataFrame.erase(dataFrame.begin(), dataFrame.begin() + sizeof(float));
        float m_pitch = ByteConverter::toFloat(dataFrame, 0);
        dataFrame.erase(dataFrame.begin(), dataFrame.begin() + sizeof(float));
        float m_roll = ByteConverter::toFloat(dataFrame, 0);
        dataFrame.erase(dataFrame.begin(), dataFrame.begin() + sizeof(float));

        m_carMotionData[i] = CarMotionData(m_worldPositionX, m_worldPositionY, m_worldPositionZ,
                                            m_worldVelocityX, m_worldVelocityY, m_worldVelocityZ,
                                            m_worldForwardDirX, m_worldForwardDirY, m_worldForwardDirZ,
                                            m_worldRightDirX, m_worldRightDirY, m_worldRightDirZ,
                                            m_gForceLateral, m_gForceLongitudinal, m_gForceVertical,
                                            m_yaw, m_pitch, m_roll);
    }
}

// Getter methods for private member variables
const PacketHeader PacketMotionData::getHeader() const {
    return m_header;
}

const CarMotionData* PacketMotionData::getCarMotionData() const {
    return m_carMotionData;
}

const CarMotionData PacketMotionData::getCarMotionDataPosition(int position) const {
    return m_carMotionData[position];
}
