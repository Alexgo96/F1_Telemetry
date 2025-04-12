#include "../lib/CarDamageData.h"

// Default Constructor
CarDamageData::CarDamageData() 
    : m_tyresWear{0.0f, 0.0f, 0.0f, 0.0f},
      m_tyresDamage{0, 0, 0, 0},
      m_brakesDamage{0, 0, 0, 0},
      m_frontLeftWingDamage(0),
      m_frontRightWingDamage(0),
      m_rearWingDamage(0),
      m_floorDamage(0),
      m_diffuserDamage(0),
      m_sidepodDamage(0),
      m_drsFault(0),
      m_ersFault(0),
      m_gearBoxDamage(0),
      m_engineDamage(0),
      m_engineMGUHWear(0),
      m_engineESWear(0),
      m_engineCEWear(0),
      m_engineICEWear(0),
      m_engineMGUKWear(0),
      m_engineTCWear(0),
      m_engineBlown(0),
      m_engineSeized(0) {}

// Parameterized Constructor
CarDamageData::CarDamageData(
    std::array<float, 4> tyresWear, std::array<uint8_t, 4> tyresDamage,
    std::array<uint8_t, 4> brakesDamage, uint8_t frontLeftWingDamage,
    uint8_t frontRightWingDamage, uint8_t rearWingDamage, uint8_t floorDamage,
    uint8_t diffuserDamage, uint8_t sidepodDamage, uint8_t drsFault, uint8_t ersFault,
    uint8_t gearBoxDamage, uint8_t engineDamage, uint8_t engineMGUHWear,
    uint8_t engineESWear, uint8_t engineCEWear, uint8_t engineICEWear,
    uint8_t engineMGUKWear, uint8_t engineTCWear, uint8_t engineBlown, uint8_t engineSeized)
    : m_tyresWear(tyresWear),
      m_tyresDamage(tyresDamage),
      m_brakesDamage(brakesDamage),
      m_frontLeftWingDamage(frontLeftWingDamage),
      m_frontRightWingDamage(frontRightWingDamage),
      m_rearWingDamage(rearWingDamage),
      m_floorDamage(floorDamage),
      m_diffuserDamage(diffuserDamage),
      m_sidepodDamage(sidepodDamage),
      m_drsFault(drsFault),
      m_ersFault(ersFault),
      m_gearBoxDamage(gearBoxDamage),
      m_engineDamage(engineDamage),
      m_engineMGUHWear(engineMGUHWear),
      m_engineESWear(engineESWear),
      m_engineCEWear(engineCEWear),
      m_engineICEWear(engineICEWear),
      m_engineMGUKWear(engineMGUKWear),
      m_engineTCWear(engineTCWear),
      m_engineBlown(engineBlown),
      m_engineSeized(engineSeized) {}

// Getter methods
std::array<float, 4> CarDamageData::getTyresWear() const {
    return m_tyresWear;
}

std::array<uint8_t, 4> CarDamageData::getTyresDamage() const {
    return m_tyresDamage;
}

std::array<uint8_t, 4> CarDamageData::getBrakesDamage() const {
    return m_brakesDamage;
}

uint8_t CarDamageData::getFrontLeftWingDamage() const {
    return m_frontLeftWingDamage;
}

uint8_t CarDamageData::getFrontRightWingDamage() const {
    return m_frontRightWingDamage;
}

uint8_t CarDamageData::getRearWingDamage() const {
    return m_rearWingDamage;
}

uint8_t CarDamageData::getFloorDamage() const {
    return m_floorDamage;
}

uint8_t CarDamageData::getDiffuserDamage() const {
    return m_diffuserDamage;
}

uint8_t CarDamageData::getSidepodDamage() const {
    return m_sidepodDamage;
}

uint8_t CarDamageData::getDrsFault() const {
    return m_drsFault;
}

uint8_t CarDamageData::getErsFault() const {
    return m_ersFault;
}

uint8_t CarDamageData::getGearBoxDamage() const {
    return m_gearBoxDamage;
}

uint8_t CarDamageData::getEngineDamage() const {
    return m_engineDamage;
}

uint8_t CarDamageData::getEngineMGUHWear() const {
    return m_engineMGUHWear;
}

uint8_t CarDamageData::getEngineESWear() const {
    return m_engineESWear;
}

uint8_t CarDamageData::getEngineCEWear() const {
    return m_engineCEWear;
}

uint8_t CarDamageData::getEngineICEWear() const {
    return m_engineICEWear;
}

uint8_t CarDamageData::getEngineMGUKWear() const {
    return m_engineMGUKWear;
}

uint8_t CarDamageData::getEngineTCWear() const {
    return m_engineTCWear;
}

uint8_t CarDamageData::getEngineBlown() const {
    return m_engineBlown;
}

uint8_t CarDamageData::getEngineSeized() const {
    return m_engineSeized;
}
