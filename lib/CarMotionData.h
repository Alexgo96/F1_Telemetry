#ifndef CARMOTIONDATA_H
#define CARMOTIONDATA_H

#include <cstdint>

class CarMotionData {
private:
    float m_worldPositionX;
    float m_worldPositionY;
    float m_worldPositionZ;
    float m_worldVelocityX;
    float m_worldVelocityY;
    float m_worldVelocityZ;
    int16_t m_worldForwardDirX;
    int16_t m_worldForwardDirY;
    int16_t m_worldForwardDirZ;
    int16_t m_worldRightDirX;
    int16_t m_worldRightDirY;
    int16_t m_worldRightDirZ;
    float m_gForceLateral;
    float m_gForceLongitudinal;
    float m_gForceVertical;
    float m_yaw;
    float m_pitch;
    float m_roll;

public:
    // Constructor
    CarMotionData();
    CarMotionData(float worldPositionX, float worldPositionY, float worldPositionZ, 
                  float worldVelocityX, float worldVelocityY, float worldVelocityZ,
                  int16_t worldForwardDirX, int16_t worldForwardDirY, int16_t worldForwardDirZ,
                  int16_t worldRightDirX, int16_t worldRightDirY, int16_t worldRightDirZ,
                  float gForceLateral, float gForceLongitudinal, float gForceVertical,
                  float yaw, float pitch, float roll);

    // Getter methods
    float getWorldPositionX() const;
    float getWorldPositionY() const;
    float getWorldPositionZ() const;
    float getWorldVelocityX() const;
    float getWorldVelocityY() const;
    float getWorldVelocityZ() const;
    int16_t getWorldForwardDirX() const;
    int16_t getWorldForwardDirY() const;
    int16_t getWorldForwardDirZ() const;
    int16_t getWorldRightDirX() const;
    int16_t getWorldRightDirY() const;
    int16_t getWorldRightDirZ() const;
    float getGForceLateral() const;
    float getGForceLongitudinal() const;
    float getGForceVertical() const;
    float getYaw() const;
    float getPitch() const;
    float getRoll() const;
};

#endif // CARMOTIONDATA_H
