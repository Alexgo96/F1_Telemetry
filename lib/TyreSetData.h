#ifndef TYRE_SET_DATA_H
#define TYRE_SET_DATA_H

#include <cstdint>

class TyreSetData {
private:
    uint8_t m_actualTyreCompound;    // Actual tyre compound used
    uint8_t m_visualTyreCompound;    // Visual tyre compound used
    uint8_t m_wear;                  // Tyre wear (percentage)
    uint8_t m_available;             // Whether this set is currently available
    uint8_t m_recommendedSession;    // Recommended session for tyre set
    uint8_t m_lifeSpan;              // Laps left in this tyre set
    uint8_t m_usableLife;            // Max number of laps recommended for this compound
    int16_t m_lapDeltaTime;          // Lap delta time in milliseconds compared to fitted set
    uint8_t m_fitted;                // Whether the set is fitted or not

public:
    // Constructor
    TyreSetData();
    TyreSetData(uint8_t actualTyreCompound, uint8_t visualTyreCompound, uint8_t wear,
                uint8_t available, uint8_t recommendedSession, uint8_t lifeSpan,
                uint8_t usableLife, int16_t lapDeltaTime, uint8_t fitted);

    // Getter methods
    uint8_t getActualTyreCompound() const;
    uint8_t getVisualTyreCompound() const;
    uint8_t getWear() const;
    uint8_t getAvailable() const;
    uint8_t getRecommendedSession() const;
    uint8_t getLifeSpan() const;
    uint8_t getUsableLife() const;
    int16_t getLapDeltaTime() const;
    uint8_t getFitted() const;
};

#endif // TYRE_SET_DATA_H
