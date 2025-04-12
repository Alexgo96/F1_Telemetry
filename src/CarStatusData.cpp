#include "../lib/CarStatusData.h"

// Default constructor
CarStatusData::CarStatusData() {}

// Parameterized constructor
CarStatusData::CarStatusData(uint8_t tractionControl, uint8_t antiLockBrakes, uint8_t fuelMix, uint8_t frontBrakeBias,
                             uint8_t pitLimiterStatus, float fuelInTank, float fuelCapacity, float fuelRemainingLaps,
                             uint16_t maxRPM, uint16_t idleRPM, uint8_t maxGears, uint8_t drsAllowed,
                             uint16_t drsActivationDistance, uint8_t actualTyreCompound, uint8_t visualTyreCompound,
                             uint8_t tyresAgeLaps, int8_t vehicleFiaFlags, float enginePowerICE, float enginePowerMGUK,
                             float ersStoreEnergy, uint8_t ersDeployMode, float ersHarvestedThisLapMGUK,
                             float ersHarvestedThisLapMGUH, float ersDeployedThisLap, uint8_t networkPaused)
    : m_tractionControl(tractionControl), m_antiLockBrakes(antiLockBrakes), m_fuelMix(fuelMix),
      m_frontBrakeBias(frontBrakeBias), m_pitLimiterStatus(pitLimiterStatus), m_fuelInTank(fuelInTank),
      m_fuelCapacity(fuelCapacity), m_fuelRemainingLaps(fuelRemainingLaps), m_maxRPM(maxRPM), m_idleRPM(idleRPM),
      m_maxGears(maxGears), m_drsAllowed(drsAllowed), m_drsActivationDistance(drsActivationDistance),
      m_actualTyreCompound(actualTyreCompound), m_visualTyreCompound(visualTyreCompound), m_tyresAgeLaps(tyresAgeLaps),
      m_vehicleFiaFlags(vehicleFiaFlags), m_enginePowerICE(enginePowerICE), m_enginePowerMGUK(enginePowerMGUK),
      m_ersStoreEnergy(ersStoreEnergy), m_ersDeployMode(ersDeployMode),
      m_ersHarvestedThisLapMGUK(ersHarvestedThisLapMGUK), m_ersHarvestedThisLapMGUH(ersHarvestedThisLapMGUH),
      m_ersDeployedThisLap(ersDeployedThisLap), m_networkPaused(networkPaused) {}

// Getter implementations
uint8_t CarStatusData::getTractionControl() const { return m_tractionControl; }
uint8_t CarStatusData::getAntiLockBrakes() const { return m_antiLockBrakes; }
uint8_t CarStatusData::getFuelMix() const { return m_fuelMix; }
uint8_t CarStatusData::getFrontBrakeBias() const { return m_frontBrakeBias; }
uint8_t CarStatusData::getPitLimiterStatus() const { return m_pitLimiterStatus; }
float CarStatusData::getFuelInTank() const { return m_fuelInTank; }
float CarStatusData::getFuelCapacity() const { return m_fuelCapacity; }
float CarStatusData::getFuelRemainingLaps() const { return m_fuelRemainingLaps; }
uint16_t CarStatusData::getMaxRPM() const { return m_maxRPM; }
uint16_t CarStatusData::getIdleRPM() const { return m_idleRPM; }
uint8_t CarStatusData::getMaxGears() const { return m_maxGears; }
uint8_t CarStatusData::getDrsAllowed() const { return m_drsAllowed; }
uint16_t CarStatusData::getDrsActivationDistance() const { return m_drsActivationDistance; }
uint8_t CarStatusData::getActualTyreCompound() const { return m_actualTyreCompound; }
uint8_t CarStatusData::getVisualTyreCompound() const { return m_visualTyreCompound; }
uint8_t CarStatusData::getTyresAgeLaps() const { return m_tyresAgeLaps; }
int8_t CarStatusData::getVehicleFiaFlags() const { return m_vehicleFiaFlags; }
float CarStatusData::getEnginePowerICE() const { return m_enginePowerICE; }
float CarStatusData::getEnginePowerMGUK() const { return m_enginePowerMGUK; }
float CarStatusData::getErsStoreEnergy() const { return m_ersStoreEnergy; }
uint8_t CarStatusData::getErsDeployMode() const { return m_ersDeployMode; }
float CarStatusData::getErsHarvestedThisLapMGUK() const { return m_ersHarvestedThisLapMGUK; }
float CarStatusData::getErsHarvestedThisLapMGUH() const { return m_ersHarvestedThisLapMGUH; }
float CarStatusData::getErsDeployedThisLap() const { return m_ersDeployedThisLap; }
uint8_t CarStatusData::getNetworkPaused() const { return m_networkPaused; }
