#include "../lib/TyreSetData.h"

// Default Constructor
TyreSetData::TyreSetData() 
    : m_actualTyreCompound(0),
      m_visualTyreCompound(0),
      m_wear(0),
      m_available(0),
      m_recommendedSession(0),
      m_lifeSpan(0),
      m_usableLife(0),
      m_lapDeltaTime(0),
      m_fitted(0) {}

// Parameterized Constructor
TyreSetData::TyreSetData(
    uint8_t actualTyreCompound, uint8_t visualTyreCompound, uint8_t wear,
    uint8_t available, uint8_t recommendedSession, uint8_t lifeSpan, uint8_t usableLife,
    int16_t lapDeltaTime, uint8_t fitted)
    : m_actualTyreCompound(actualTyreCompound),
      m_visualTyreCompound(visualTyreCompound),
      m_wear(wear),
      m_available(available),
      m_recommendedSession(recommendedSession),
      m_lifeSpan(lifeSpan),
      m_usableLife(usableLife),
      m_lapDeltaTime(lapDeltaTime),
      m_fitted(fitted) {}

// Getter methods
uint8_t TyreSetData::getActualTyreCompound() const {
    return m_actualTyreCompound;
}

uint8_t TyreSetData::getVisualTyreCompound() const {
    return m_visualTyreCompound;
}

uint8_t TyreSetData::getWear() const {
    return m_wear;
}

uint8_t TyreSetData::getAvailable() const {
    return m_available;
}

uint8_t TyreSetData::getRecommendedSession() const {
    return m_recommendedSession;
}

uint8_t TyreSetData::getLifeSpan() const {
    return m_lifeSpan;
}

uint8_t TyreSetData::getUsableLife() const {
    return m_usableLife;
}

int16_t TyreSetData::getLapDeltaTime() const {
    return m_lapDeltaTime;
}

uint8_t TyreSetData::getFitted() const {
    return m_fitted;
}
