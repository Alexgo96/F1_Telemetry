#include <cstdint>
#include "../lib/Packet.h"
#include "../lib/PacketHeader.h"
#include "../lib/CarTelemetryData.h"
#include "../lib/PacketCarTelemetryData.h"
#include <vector>
#include "../lib/ByteConverter.h"

// Constructor
PacketCarTelemetryData::PacketCarTelemetryData(PacketHeader header)
    : m_header(header)
{
    std::cout << "IN CONSTRUCTOR PACKET FORMAT IS = " << std::to_string(m_header.getPacketFormat());
}
// Method to create PacketCarTelemetryData
void PacketCarTelemetryData::createPacketCarTelemetryData(std::vector<unsigned char>& dataFrame, uint8_t numCars){
    for (int i = 0; i < numCars; i++){
        uint16_t m_speed = ByteConverter::toUInt16(dataFrame, 0);
        dataFrame.erase(dataFrame.begin(), dataFrame.begin() + sizeof(uint16_t));
        float m_throttle = ByteConverter::toFloat(dataFrame, 0);
        dataFrame.erase(dataFrame.begin(), dataFrame.begin() +sizeof(float));
        float m_steer = ByteConverter::toFloat(dataFrame, 0);
        dataFrame.erase(dataFrame.begin(), dataFrame.begin() + sizeof(float));
        float m_brake = ByteConverter::toFloat(dataFrame, 0);
        dataFrame.erase(dataFrame.begin(), dataFrame.begin() +sizeof(float));
        uint8_t m_clutch = ByteConverter::toUInt8(dataFrame, 0);
        dataFrame.erase(dataFrame.begin());
        int8_t m_gear = ByteConverter::toInt8(dataFrame, 0);
        dataFrame.erase(dataFrame.begin());
        uint16_t m_engineRPM = ByteConverter::toUInt16(dataFrame, 0);
        dataFrame.erase(dataFrame.begin(), dataFrame.begin() + sizeof(uint16_t));
        uint8_t m_drs = ByteConverter::toUInt8(dataFrame, 0);
        dataFrame.erase(dataFrame.begin());
        uint8_t m_revLightsPercent = ByteConverter::toUInt8(dataFrame, 0);
        dataFrame.erase(dataFrame.begin());
        uint16_t m_revLightsBitValue = ByteConverter::toUInt16(dataFrame, 0);
        dataFrame.erase(dataFrame.begin(), dataFrame.begin() + sizeof(uint16_t));

        uint16_t m_brakesTemperature[4];
        for(int j = 0; j < 4; j++){
            m_brakesTemperature[j]= ByteConverter::toUInt16(dataFrame, 0);
            // DEBUG
            std::cout << "brakes_temperature[" <<std::to_string(j) << "] = " << std::to_string(m_brakesTemperature[j])<< std::endl;
            dataFrame.erase(dataFrame.begin(), dataFrame.begin() + sizeof(uint16_t));
        }

        uint8_t m_tyresSurfaceTemperature[4];
        for(int j = 0; j < 4; j++){
            m_tyresSurfaceTemperature[j]= ByteConverter::toUInt8(dataFrame, 0);
            dataFrame.erase(dataFrame.begin());
        }

        uint8_t m_tyresInnerTemperature[4];
        for(int j = 0; j < 4; j++){
            m_tyresInnerTemperature[j]= ByteConverter::toUInt8(dataFrame, 0);
            dataFrame.erase(dataFrame.begin());
        }

        uint16_t m_engineTemperature = ByteConverter::toUInt16(dataFrame, 0);
        dataFrame.erase(dataFrame.begin(), dataFrame.begin() + sizeof(uint16_t));

        float m_tyresPressure[4];
        for(int j = 0; j < 4; j++){
            m_tyresPressure[j]= ByteConverter::toFloat(dataFrame, 0);
            dataFrame.erase(dataFrame.begin(), dataFrame.begin() + sizeof(float));
        }

        uint8_t m_surfaceType[4];
        for(int j = 0; j < 4; j++){
            m_surfaceType[j]= ByteConverter::toUInt8(dataFrame, 0);
            dataFrame.erase(dataFrame.begin());
        }

        m_carTelemetryData[i] = CarTelemetryData(m_speed, m_throttle,
            m_steer, m_brake, m_clutch, m_gear, m_engineRPM, m_drs,
            m_revLightsPercent, m_revLightsBitValue, m_brakesTemperature,
            m_tyresSurfaceTemperature, m_tyresInnerTemperature,
            m_engineTemperature, m_tyresPressure, m_surfaceType);
    }
    uint8_t m_mfdPanelIndex = ByteConverter::toUInt8(dataFrame, 0);
    dataFrame.erase(dataFrame.begin());
    uint8_t m_mfdPanelIndexSecondaryPlayer = ByteConverter::toUInt8(dataFrame, 0);
    dataFrame.erase(dataFrame.begin());
    int8_t m_sugestedGear = ByteConverter::toInt8(dataFrame, 0);
    dataFrame.erase(dataFrame.begin());
}
// Getter methods for private member variables
const PacketHeader PacketCarTelemetryData::getHeader() const { return m_header; }
const CarTelemetryData* PacketCarTelemetryData::getCarTelemetryData() const { return m_carTelemetryData; }
const CarTelemetryData PacketCarTelemetryData::getCarTelemetryDataPosition(int position) const { return m_carTelemetryData[position]; }
uint8_t PacketCarTelemetryData::getMfdPanelIndex() const { return m_mfdPanelIndex; }
uint8_t PacketCarTelemetryData::getMfdPanelIndexSecondaryPlayer() const { return m_mfdPanelIndexSecondaryPlayer; }
int8_t PacketCarTelemetryData::getSugestedGear() const { return m_sugestedGear; }