#ifndef CARSETUPDATA_H
#define CARSETUPDATA_H

#include <cstdint>

class CarSetupData {
private:
    uint8_t m_frontWing;
    uint8_t m_rearWing;
    uint8_t m_onThrottle;
    uint8_t m_offThrottle;
    float m_frontCamber;
    float m_rearCamber;
    float m_frontToe;
    float m_rearToe;
    uint8_t m_frontSuspension;
    uint8_t m_rearSuspension;
    uint8_t m_frontAntiRollBar;
    uint8_t m_rearAntiRollBar;
    uint8_t m_frontSuspensionHeight;
    uint8_t m_rearSuspensionHeight;
    uint8_t m_brakePressure;
    uint8_t m_brakeBias;
    float m_rearLeftTyrePressure;
    float m_rearRightTyrePressure;
    float m_frontLeftTyrePressure;
    float m_frontRightTyrePressure;
    uint8_t m_ballast;
    float m_fuelLoad;

public:
    // Constructor
    CarSetupData();
    CarSetupData(uint8_t frontWing, uint8_t rearWing, uint8_t onThrottle, uint8_t offThrottle,
                 float frontCamber, float rearCamber, float frontToe, float rearToe,
                 uint8_t frontSuspension, uint8_t rearSuspension, uint8_t frontAntiRollBar, uint8_t rearAntiRollBar,
                 uint8_t frontSuspensionHeight, uint8_t rearSuspensionHeight, uint8_t brakePressure, uint8_t brakeBias,
                 float rearLeftTyrePressure, float rearRightTyrePressure, float frontLeftTyrePressure,
                 float frontRightTyrePressure, uint8_t ballast, float fuelLoad);

    // Getter methods
    uint8_t getFrontWing() const;
    uint8_t getRearWing() const;
    uint8_t getOnThrottle() const;
    uint8_t getOffThrottle() const;
    float getFrontCamber() const;
    float getRearCamber() const;
    float getFrontToe() const;
    float getRearToe() const;
    uint8_t getFrontSuspension() const;
    uint8_t getRearSuspension() const;
    uint8_t getFrontAntiRollBar() const;
    uint8_t getRearAntiRollBar() const;
    uint8_t getFrontSuspensionHeight() const;
    uint8_t getRearSuspensionHeight() const;
    uint8_t getBrakePressure() const;
    uint8_t getBrakeBias() const;
    float getRearLeftTyrePressure() const;
    float getRearRightTyrePressure() const;
    float getFrontLeftTyrePressure() const;
    float getFrontRightTyrePressure() const;
    uint8_t getBallast() const;
    float getFuelLoad() const;
};

#endif // CARSETUPDATA_H
