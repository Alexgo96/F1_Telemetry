#ifndef CARTELEMETRYDATA_H
#define CARTELEMETRYDATA_H

#include <cstdint>
#include <array>

class CarTelemetryData {
private:
    uint16_t m_speed;
    float m_throttle;
    float m_steer;
    float m_brake;
    uint8_t m_clutch;
    int8_t m_gear;
    uint16_t m_engineRPM;
    uint8_t m_drs;
    uint8_t m_revLigthsPercent;
    uint16_t m_revLightsBitValue;
    std::array<uint16_t, 4> m_brakesTemperature;
    std::array<uint8_t, 4> m_tyresSurfaceTemperature;
    std::array<uint8_t, 4> m_tyresInnerTemperature;
    uint16_t m_engineTemperature;
    std::array<float, 4> m_tyresPressure;
    std::array<uint8_t, 4> m_surfaceType;
    

public:
    CarTelemetryData();
    // Constructor
    CarTelemetryData(uint16_t m_speed, float m_throttle, float m_steer, float m_brake, uint8_t m_clutch,
        int8_t m_gear, uint16_t m_engineRPM,  uint8_t m_drs, uint8_t m_revLigthsPercent,  uint16_t m_revLightsBitValue,
        uint16_t m_brakesTemperature[4], uint8_t m_tyresSurfaceTemperature[4],  uint8_t m_tyresInnerTemperature[4],
        uint16_t m_engineTemperature, float m_tyresPressure[4],  uint8_t m_surfaceType[4]);

    // Getter methods for private member variables
    uint16_t getSpeed() const;
    float getThrottle() const;
    float getSteer() const;
    float getBrake() const;
    uint8_t getClutch() const;
    int8_t getGear() const;
    uint16_t getENgineRPM() const;
    uint8_t getDRS() const;
    uint8_t getRevLightsPercent() const;
    uint16_t getRevLightsBitValue() const;
    std::array<uint16_t, 4> getBrakesTemperature() const;
    std::array<uint8_t, 4> getTyresSurfaceTemperature() const;
    std::array<uint8_t, 4> getTyresInnerTemperature() const;
    uint16_t getEngineTemperature() const;
    std::array<float, 4> getTyresPressure() const;
    std::array<uint8_t, 4> getSurfaceType() const;

};
#endif // CARTELEMETRYDATA_H

