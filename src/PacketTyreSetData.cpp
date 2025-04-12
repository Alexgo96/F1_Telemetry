#include <cstdint>
#include "../lib/Packet.h"
#include "../lib/PacketHeader.h"
#include "../lib/TyreSetData.h"
#include "../lib/PacketTyreSetData.h"
#include <vector>
#include "../lib/ByteConverter.h"

// Constructor
PacketTyreSetsData::PacketTyreSetsData(PacketHeader header)
    : m_header(header) {
    std::cout << "IN CONSTRUCTOR PACKET FORMAT IS = " << std::to_string(m_header.getPacketFormat());
}

// Method to create PacketTyreSetsData
void PacketTyreSetsData::createPacketTyreSetsData(std::vector<unsigned char>& dataFrame) {
    // Extract car index
    m_carIdx = ByteConverter::toUInt8(dataFrame, 0);
    dataFrame.erase(dataFrame.begin(), dataFrame.begin() + sizeof(uint8_t));

    // Extract fitted tyre index
    m_fittedIdx = ByteConverter::toUInt8(dataFrame, 0);
    dataFrame.erase(dataFrame.begin(), dataFrame.begin() + sizeof(uint8_t));

    // Extract tyre set data for 20 tyres (13 dry + 7 wet)
    for (int i = 0; i < 20; ++i) {
        // Declare temporary variables to hold the tyre set data
        uint8_t m_actualTyreCompound, m_visualTyreCompound, m_wear, m_available, m_recommendedSession;
        uint8_t m_lifeSpan, m_usableLife, m_fitted;
        int16_t m_lapDeltaTime;

        // Extract data into temporary variables
        m_actualTyreCompound = ByteConverter::toUInt8(dataFrame, 0);
        dataFrame.erase(dataFrame.begin(), dataFrame.begin() + sizeof(uint8_t));

        m_visualTyreCompound = ByteConverter::toUInt8(dataFrame, 0);
        dataFrame.erase(dataFrame.begin(), dataFrame.begin() + sizeof(uint8_t));

        m_wear = ByteConverter::toUInt8(dataFrame, 0);
        dataFrame.erase(dataFrame.begin(), dataFrame.begin() + sizeof(uint8_t));

        m_available = ByteConverter::toUInt8(dataFrame, 0);
        dataFrame.erase(dataFrame.begin(), dataFrame.begin() + sizeof(uint8_t));

        m_recommendedSession = ByteConverter::toUInt8(dataFrame, 0);
        dataFrame.erase(dataFrame.begin(), dataFrame.begin() + sizeof(uint8_t));

        m_lifeSpan = ByteConverter::toUInt8(dataFrame, 0);
        dataFrame.erase(dataFrame.begin(), dataFrame.begin() + sizeof(uint8_t));

        m_usableLife = ByteConverter::toUInt8(dataFrame, 0);
        dataFrame.erase(dataFrame.begin(), dataFrame.begin() + sizeof(uint8_t));

        m_lapDeltaTime = ByteConverter::toInt16(dataFrame, 0);
        dataFrame.erase(dataFrame.begin(), dataFrame.begin() + sizeof(int16_t));

        m_fitted = ByteConverter::toUInt8(dataFrame, 0);
        dataFrame.erase(dataFrame.begin(), dataFrame.begin() + sizeof(uint8_t));

        // Now use the temporary variables to create the TyreSetData object
        m_tyreSetData[i] = TyreSetData(m_actualTyreCompound, m_visualTyreCompound, m_wear, m_available,
                                       m_recommendedSession, m_lifeSpan, m_usableLife, m_lapDeltaTime, m_fitted);
    }
}

// Getter methods for private member variables
const PacketHeader PacketTyreSetsData::getHeader() const {
    return m_header;
}

const uint8_t PacketTyreSetsData::getCarIdx() const {
    return m_carIdx;
}

const TyreSetData* PacketTyreSetsData::getTyreSetData() const {
    return m_tyreSetData;
}

const TyreSetData PacketTyreSetsData::getTyreSetDataPosition(int position) const {
    return m_tyreSetData[position];
}

const uint8_t PacketTyreSetsData::getFittedIdx() const {
    return m_fittedIdx;
}
