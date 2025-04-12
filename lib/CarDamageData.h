#ifndef CARDAMAGEDATA_H
#define CARDAMAGEDATA_H

#include <cstdint>
#include <array>

class CarDamageData {
private:
    std::array<float, 4> m_tyresWear;           // Tyre wear (percentage)
    std::array<uint8_t, 4> m_tyresDamage;       // Tyre damage (percentage)
    std::array<uint8_t, 4> m_brakesDamage;      // Brakes damage (percentage)
    uint8_t m_frontLeftWingDamage;              // Front left wing damage (percentage)
    uint8_t m_frontRightWingDamage;             // Front right wing damage (percentage)
    uint8_t m_rearWingDamage;                   // Rear wing damage (percentage)
    uint8_t m_floorDamage;                      // Floor damage (percentage)
    uint8_t m_diffuserDamage;                   // Diffuser damage (percentage)
    uint8_t m_sidepodDamage;                    // Sidepod damage (percentage)
    uint8_t m_drsFault;                         // Indicator for DRS fault, 0 = OK, 1 = fault
    uint8_t m_ersFault;                         // Indicator for ERS fault, 0 = OK, 1 = fault
    uint8_t m_gearBoxDamage;                    // Gear box damage (percentage)
    uint8_t m_engineDamage;                     // Engine damage (percentage)
    uint8_t m_engineMGUHWear;                   // Engine wear MGU-H (percentage)
    uint8_t m_engineESWear;                     // Engine wear ES (percentage)
    uint8_t m_engineCEWear;                     // Engine wear CE (percentage)
    uint8_t m_engineICEWear;                    // Engine wear ICE (percentage)
    uint8_t m_engineMGUKWear;                   // Engine wear MGU-K (percentage)
    uint8_t m_engineTCWear;                     // Engine wear TC (percentage)
    uint8_t m_engineBlown;                      // Engine blown, 0 = OK, 1 = fault
    uint8_t m_engineSeized;                     // Engine seized, 0 = OK, 1 = fault

public:
    // Constructor
    CarDamageData();
    CarDamageData(std::array<float, 4> tyresWear, std::array<uint8_t, 4> tyresDamage,
                  std::array<uint8_t, 4> brakesDamage, uint8_t frontLeftWingDamage,
                  uint8_t frontRightWingDamage, uint8_t rearWingDamage, uint8_t floorDamage,
                  uint8_t diffuserDamage, uint8_t sidepodDamage, uint8_t drsFault, uint8_t ersFault,
                  uint8_t gearBoxDamage, uint8_t engineDamage, uint8_t engineMGUHWear,
                  uint8_t engineESWear, uint8_t engineCEWear, uint8_t engineICEWear,
                  uint8_t engineMGUKWear, uint8_t engineTCWear, uint8_t engineBlown, uint8_t engineSeized);

    // Getter methods
    std::array<float, 4> getTyresWear() const;
    std::array<uint8_t, 4> getTyresDamage() const;
    std::array<uint8_t, 4> getBrakesDamage() const;
    uint8_t getFrontLeftWingDamage() const;
    uint8_t getFrontRightWingDamage() const;
    uint8_t getRearWingDamage() const;
    uint8_t getFloorDamage() const;
    uint8_t getDiffuserDamage() const;
    uint8_t getSidepodDamage() const;
    uint8_t getDrsFault() const;
    uint8_t getErsFault() const;
    uint8_t getGearBoxDamage() const;
    uint8_t getEngineDamage() const;
    uint8_t getEngineMGUHWear() const;
    uint8_t getEngineESWear() const;
    uint8_t getEngineCEWear() const;
    uint8_t getEngineICEWear() const;
    uint8_t getEngineMGUKWear() const;
    uint8_t getEngineTCWear() const;
    uint8_t getEngineBlown() const;
    uint8_t getEngineSeized() const;
};

#endif // CARDAMAGEDATA_H
