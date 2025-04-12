#include "CarTelemetryData.h"

// Default constructor
CarTelemetryData::CarTelemetryData()
{
}

// Parameterized constructor
CarTelemetryData::CarTelemetryData(uint16_t speed, float throttle, float steer, float brake, uint8_t clutch,
                                   int8_t gear, uint16_t engineRPM, uint8_t drs, uint8_t revLightsPercent,
                                   uint16_t revLightsBitValue, uint16_t brakesTemperature[4],
                                   uint8_t tyresSurfaceTemperature[4], uint8_t tyresInnerTemperature[4],
                                   uint16_t engineTemperature, float tyresPressure[4], uint8_t surfaceType[4])
    : m_speed(speed), m_throttle(throttle), m_steer(steer), m_brake(brake), m_clutch(clutch),
      m_gear(gear), m_engineRPM(engineRPM), m_drs(drs), m_revLigthsPercent(revLightsPercent),
      m_revLightsBitValue(revLightsBitValue), m_engineTemperature(engineTemperature)
{
    std::copy(brakesTemperature, brakesTemperature + 4, m_brakesTemperature.begin());
    std::copy(tyresSurfaceTemperature, tyresSurfaceTemperature + 4, m_tyresSurfaceTemperature.begin());
    std::copy(tyresInnerTemperature, tyresInnerTemperature + 4, m_tyresInnerTemperature.begin());
    std::copy(tyresPressure, tyresPressure + 4, m_tyresPressure.begin());
    std::copy(surfaceType, surfaceType + 4, m_surfaceType.begin());
}

// Getter implementations
uint16_t CarTelemetryData::getSpeed() const { return m_speed; }
float CarTelemetryData::getThrottle() const { return m_throttle; }
float CarTelemetryData::getSteer() const { return m_steer; }
float CarTelemetryData::getBrake() const { return m_brake; }
uint8_t CarTelemetryData::getClutch() const { return m_clutch; }
int8_t CarTelemetryData::getGear() const { return m_gear; }
uint16_t CarTelemetryData::getENgineRPM() const { return m_engineRPM; }
uint8_t CarTelemetryData::getDRS() const { return m_drs; }
uint8_t CarTelemetryData::getRevLightsPercent() const { return m_revLigthsPercent; }
uint16_t CarTelemetryData::getRevLightsBitValue() const { return m_revLightsBitValue; }
std::array<uint16_t, 4> CarTelemetryData::getBrakesTemperature() const { return m_brakesTemperature; }
std::array<uint8_t, 4> CarTelemetryData::getTyresSurfaceTemperature() const { return m_tyresSurfaceTemperature; }
std::array<uint8_t, 4> CarTelemetryData::getTyresInnerTemperature() const { return m_tyresInnerTemperature; }
uint16_t CarTelemetryData::getEngineTemperature() const { return m_engineTemperature; }
std::array<float, 4> CarTelemetryData::getTyresPressure() const { return m_tyresPressure; }
std::array<uint8_t, 4> CarTelemetryData::getSurfaceType() const { return m_surfaceType; }
