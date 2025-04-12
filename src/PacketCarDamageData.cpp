#include <cstdint>
#include "../lib/Packet.h"
#include "../lib/PacketHeader.h"
#include "../lib/CarDamageData.h"
#include "../lib/PacketCarDamageData.h"
#include <vector>
#include "../lib/ByteConverter.h"

// Constructor
PacketCarDamageData::PacketCarDamageData(PacketHeader header)
    : m_header(header) {
    std::cout << "IN CONSTRUCTOR PACKET FORMAT IS = " << std::to_string(m_header.getPacketFormat());
}

// Method to create PacketCarDamageData
void PacketCarDamageData::createPacketCarDamageData(std::vector<unsigned char>& dataFrame, uint8_t numCars) {
    for (int i = 0; i < numCars; i++) {
        // Extract tyre wear data
        std::array<float, 4> m_tyresWear;
        for (int j = 0; j < 4; ++j) {
            m_tyresWear[j] = ByteConverter::toFloat(dataFrame, 0);
            dataFrame.erase(dataFrame.begin(), dataFrame.begin() + sizeof(float));
        }

        // Extract tyre damage data
        std::array<uint8_t, 4> m_tyresDamage;
        for (int j = 0; j < 4; ++j) {
            m_tyresDamage[j] = ByteConverter::toUInt8(dataFrame, 0);
            dataFrame.erase(dataFrame.begin(), dataFrame.begin() + sizeof(uint8_t));
        }

        // Extract brakes damage data
        std::array<uint8_t, 4> m_brakesDamage;
        for (int j = 0; j < 4; ++j) {
            m_brakesDamage[j] = ByteConverter::toUInt8(dataFrame, 0);
            dataFrame.erase(dataFrame.begin(), dataFrame.begin() + sizeof(uint8_t));
        }

        // Extract individual damage values
        uint8_t m_frontLeftWingDamage = ByteConverter::toUInt8(dataFrame, 0);
        dataFrame.erase(dataFrame.begin(), dataFrame.begin() + sizeof(uint8_t));

        uint8_t m_frontRightWingDamage = ByteConverter::toUInt8(dataFrame, 0);
        dataFrame.erase(dataFrame.begin(), dataFrame.begin() + sizeof(uint8_t));

        uint8_t m_rearWingDamage = ByteConverter::toUInt8(dataFrame, 0);
        dataFrame.erase(dataFrame.begin(), dataFrame.begin() + sizeof(uint8_t));

        uint8_t m_floorDamage = ByteConverter::toUInt8(dataFrame, 0);
        dataFrame.erase(dataFrame.begin(), dataFrame.begin() + sizeof(uint8_t));

        uint8_t m_diffuserDamage = ByteConverter::toUInt8(dataFrame, 0);
        dataFrame.erase(dataFrame.begin(), dataFrame.begin() + sizeof(uint8_t));

        uint8_t m_sidepodDamage = ByteConverter::toUInt8(dataFrame, 0);
        dataFrame.erase(dataFrame.begin(), dataFrame.begin() + sizeof(uint8_t));

        uint8_t m_drsFault = ByteConverter::toUInt8(dataFrame, 0);
        dataFrame.erase(dataFrame.begin(), dataFrame.begin() + sizeof(uint8_t));

        uint8_t m_ersFault = ByteConverter::toUInt8(dataFrame, 0);
        dataFrame.erase(dataFrame.begin(), dataFrame.begin() + sizeof(uint8_t));

        uint8_t m_gearBoxDamage = ByteConverter::toUInt8(dataFrame, 0);
        dataFrame.erase(dataFrame.begin(), dataFrame.begin() + sizeof(uint8_t));

        uint8_t m_engineDamage = ByteConverter::toUInt8(dataFrame, 0);
        dataFrame.erase(dataFrame.begin(), dataFrame.begin() + sizeof(uint8_t));

        uint8_t m_engineMGUHWear = ByteConverter::toUInt8(dataFrame, 0);
        dataFrame.erase(dataFrame.begin(), dataFrame.begin() + sizeof(uint8_t));

        uint8_t m_engineESWear = ByteConverter::toUInt8(dataFrame, 0);
        dataFrame.erase(dataFrame.begin(), dataFrame.begin() + sizeof(uint8_t));

        uint8_t m_engineCEWear = ByteConverter::toUInt8(dataFrame, 0);
        dataFrame.erase(dataFrame.begin(), dataFrame.begin() + sizeof(uint8_t));

        uint8_t m_engineICEWear = ByteConverter::toUInt8(dataFrame, 0);
        dataFrame.erase(dataFrame.begin(), dataFrame.begin() + sizeof(uint8_t));

        uint8_t m_engineMGUKWear = ByteConverter::toUInt8(dataFrame, 0);
        dataFrame.erase(dataFrame.begin(), dataFrame.begin() + sizeof(uint8_t));

        uint8_t m_engineTCWear = ByteConverter::toUInt8(dataFrame, 0);
        dataFrame.erase(dataFrame.begin(), dataFrame.begin() + sizeof(uint8_t));

        uint8_t m_engineBlown = ByteConverter::toUInt8(dataFrame, 0);
        dataFrame.erase(dataFrame.begin(), dataFrame.begin() + sizeof(uint8_t));

        uint8_t m_engineSeized = ByteConverter::toUInt8(dataFrame, 0);
        dataFrame.erase(dataFrame.begin(), dataFrame.begin() + sizeof(uint8_t));

        // Assign all data to the m_carDamageData array
        m_carDamageData[i] = CarDamageData(m_tyresWear, m_tyresDamage, m_brakesDamage, m_frontLeftWingDamage,
                                            m_frontRightWingDamage, m_rearWingDamage, m_floorDamage, m_diffuserDamage,
                                            m_sidepodDamage, m_drsFault, m_ersFault, m_gearBoxDamage, m_engineDamage,
                                            m_engineMGUHWear, m_engineESWear, m_engineCEWear, m_engineICEWear,
                                            m_engineMGUKWear, m_engineTCWear, m_engineBlown, m_engineSeized);
    }
}

// Getter methods for private member variables
const PacketHeader PacketCarDamageData::getHeader() const {
    return m_header;
}

const CarDamageData* PacketCarDamageData::getCarDamageData() const {
    return m_carDamageData;
}

const CarDamageData PacketCarDamageData::getCarDamageDataPosition(int position) const {
    return m_carDamageData[position];
}
