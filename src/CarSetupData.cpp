#include "../lib/CarSetupData.h"

// Default constructor
CarSetupData::CarSetupData()
    : m_frontWing(0), m_rearWing(0), m_onThrottle(0), m_offThrottle(0),
      m_frontCamber(0.0f), m_rearCamber(0.0f), m_frontToe(0.0f), m_rearToe(0.0f),
      m_frontSuspension(0), m_rearSuspension(0), m_frontAntiRollBar(0), m_rearAntiRollBar(0),
      m_frontSuspensionHeight(0), m_rearSuspensionHeight(0), m_brakePressure(0), m_brakeBias(0),
      m_rearLeftTyrePressure(0.0f), m_rearRightTyrePressure(0.0f), 
      m_frontLeftTyrePressure(0.0f), m_frontRightTyrePressure(0.0f),
      m_ballast(0), m_fuelLoad(0.0f) {}

// Parameterized constructor
CarSetupData::CarSetupData(uint8_t frontWing, uint8_t rearWing, uint8_t onThrottle, uint8_t offThrottle,
                           float frontCamber, float rearCamber, float frontToe, float rearToe,
                           uint8_t frontSuspension, uint8_t rearSuspension, uint8_t frontAntiRollBar, uint8_t rearAntiRollBar,
                           uint8_t frontSuspensionHeight, uint8_t rearSuspensionHeight, uint8_t brakePressure, uint8_t brakeBias,
                           float rearLeftTyrePressure, float rearRightTyrePressure, float frontLeftTyrePressure,
                           float frontRightTyrePressure, uint8_t ballast, float fuelLoad)
    : m_frontWing(frontWing), m_rearWing(rearWing), m_onThrottle(onThrottle), m_offThrottle(offThrottle),
      m_frontCamber(frontCamber), m_rearCamber(rearCamber), m_frontToe(frontToe), m_rearToe(rearToe),
      m_frontSuspension(frontSuspension), m_rearSuspension(rearSuspension),
      m_frontAntiRollBar(frontAntiRollBar), m_rearAntiRollBar(rearAntiRollBar),
      m_frontSuspensionHeight(frontSuspensionHeight), m_rearSuspensionHeight(rearSuspensionHeight),
      m_brakePressure(brakePressure), m_brakeBias(brakeBias),
      m_rearLeftTyrePressure(rearLeftTyrePressure), m_rearRightTyrePressure(rearRightTyrePressure),
      m_frontLeftTyrePressure(frontLeftTyrePressure), m_frontRightTyrePressure(frontRightTyrePressure),
      m_ballast(ballast), m_fuelLoad(fuelLoad) {}

// Getter methods
uint8_t CarSetupData::getFrontWing() const { return m_frontWing; }
uint8_t CarSetupData::getRearWing() const { return m_rearWing; }
uint8_t CarSetupData::getOnThrottle() const { return m_onThrottle; }
uint8_t CarSetupData::getOffThrottle() const { return m_offThrottle; }
float CarSetupData::getFrontCamber() const { return m_frontCamber; }
float CarSetupData::getRearCamber() const { return m_rearCamber; }
float CarSetupData::getFrontToe() const { return m_frontToe; }
float CarSetupData::getRearToe() const { return m_rearToe; }
uint8_t CarSetupData::getFrontSuspension() const { return m_frontSuspension; }
uint8_t CarSetupData::getRearSuspension() const { return m_rearSuspension; }
uint8_t CarSetupData::getFrontAntiRollBar() const { return m_frontAntiRollBar; }
uint8_t CarSetupData::getRearAntiRollBar() const { return m_rearAntiRollBar; }
uint8_t CarSetupData::getFrontSuspensionHeight() const { return m_frontSuspensionHeight; }
uint8_t CarSetupData::getRearSuspensionHeight() const { return m_rearSuspensionHeight; }
uint8_t CarSetupData::getBrakePressure() const { return m_brakePressure; }
uint8_t CarSetupData::getBrakeBias() const { return m_brakeBias; }
float CarSetupData::getRearLeftTyrePressure() const { return m_rearLeftTyrePressure; }
float CarSetupData::getRearRightTyrePressure() const { return m_rearRightTyrePressure; }
float CarSetupData::getFrontLeftTyrePressure() const { return m_frontLeftTyrePressure; }
float CarSetupData::getFrontRightTyrePressure() const { return m_frontRightTyrePressure; }
uint8_t CarSetupData::getBallast() const { return m_ballast; }
float CarSetupData::getFuelLoad() const { return m_fuelLoad; }
