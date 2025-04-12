#ifndef CARSTATUSDATA_H
#define CARSTATUSDATA_H

#include <cstdint>

class CarStatusData {
private:
    uint8_t m_tractionControl;
    uint8_t m_antiLockBrakes;
    uint8_t m_fuelMix;
    uint8_t m_frontBrakeBias;
    uint8_t m_pitLimiterStatus;
    float m_fuelInTank;
    float m_fuelCapacity;
    float m_fuelRemainingLaps;
    uint16_t m_maxRPM;
    uint16_t m_idleRPM;
    uint8_t m_maxGears;
    uint8_t m_drsAllowed;
    uint16_t m_drsActivationDistance;
    uint8_t m_actualTyreCompound;
    uint8_t m_visualTyreCompound;
    uint8_t m_tyresAgeLaps;
    int8_t m_vehicleFiaFlags;
    float m_enginePowerICE;
    float m_enginePowerMGUK;
    float m_ersStoreEnergy;
    uint8_t m_ersDeployMode;
    float m_ersHarvestedThisLapMGUK;
    float m_ersHarvestedThisLapMGUH;
    float m_ersDeployedThisLap;
    uint8_t m_networkPaused;

public:
    CarStatusData();
    
    // Constructor
    CarStatusData(uint8_t tractionControl, uint8_t antiLockBrakes, uint8_t fuelMix, uint8_t frontBrakeBias,
                  uint8_t pitLimiterStatus, float fuelInTank, float fuelCapacity, float fuelRemainingLaps,
                  uint16_t maxRPM, uint16_t idleRPM, uint8_t maxGears, uint8_t drsAllowed,
                  uint16_t drsActivationDistance, uint8_t actualTyreCompound, uint8_t visualTyreCompound,
                  uint8_t tyresAgeLaps, int8_t vehicleFiaFlags, float enginePowerICE, float enginePowerMGUK,
                  float ersStoreEnergy, uint8_t ersDeployMode, float ersHarvestedThisLapMGUK,
                  float ersHarvestedThisLapMGUH, float ersDeployedThisLap, uint8_t networkPaused);

    // Getter methods
    uint8_t getTractionControl() const;
    uint8_t getAntiLockBrakes() const;
    uint8_t getFuelMix() const;
    uint8_t getFrontBrakeBias() const;
    uint8_t getPitLimiterStatus() const;
    float getFuelInTank() const;
    float getFuelCapacity() const;
    float getFuelRemainingLaps() const;
    uint16_t getMaxRPM() const;
    uint16_t getIdleRPM() const;
    uint8_t getMaxGears() const;
    uint8_t getDrsAllowed() const;
    uint16_t getDrsActivationDistance() const;
    uint8_t getActualTyreCompound() const;
    uint8_t getVisualTyreCompound() const;
    uint8_t getTyresAgeLaps() const;
    int8_t getVehicleFiaFlags() const;
    float getEnginePowerICE() const;
    float getEnginePowerMGUK() const;
    float getErsStoreEnergy() const;
    uint8_t getErsDeployMode() const;
    float getErsHarvestedThisLapMGUK() const;
    float getErsHarvestedThisLapMGUH() const;
    float getErsDeployedThisLap() const;
    uint8_t getNetworkPaused() const;
};

#endif // CARSTATUSDATA_H
