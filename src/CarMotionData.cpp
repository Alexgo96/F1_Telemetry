#include "../lib/CarMotionData.h"

// Default Constructor
CarMotionData::CarMotionData() 
    : m_worldPositionX(0), m_worldPositionY(0), m_worldPositionZ(0),
      m_worldVelocityX(0), m_worldVelocityY(0), m_worldVelocityZ(0),
      m_worldForwardDirX(0), m_worldForwardDirY(0), m_worldForwardDirZ(0),
      m_worldRightDirX(0), m_worldRightDirY(0), m_worldRightDirZ(0),
      m_gForceLateral(0), m_gForceLongitudinal(0), m_gForceVertical(0),
      m_yaw(0), m_pitch(0), m_roll(0) {}

// Parameterized Constructor
CarMotionData::CarMotionData(float worldPositionX, float worldPositionY, float worldPositionZ, 
                             float worldVelocityX, float worldVelocityY, float worldVelocityZ,
                             int16_t worldForwardDirX, int16_t worldForwardDirY, int16_t worldForwardDirZ,
                             int16_t worldRightDirX, int16_t worldRightDirY, int16_t worldRightDirZ,
                             float gForceLateral, float gForceLongitudinal, float gForceVertical,
                             float yaw, float pitch, float roll)
    : m_worldPositionX(worldPositionX), m_worldPositionY(worldPositionY), m_worldPositionZ(worldPositionZ),
      m_worldVelocityX(worldVelocityX), m_worldVelocityY(worldVelocityY), m_worldVelocityZ(worldVelocityZ),
      m_worldForwardDirX(worldForwardDirX), m_worldForwardDirY(worldForwardDirY), m_worldForwardDirZ(worldForwardDirZ),
      m_worldRightDirX(worldRightDirX), m_worldRightDirY(worldRightDirY), m_worldRightDirZ(worldRightDirZ),
      m_gForceLateral(gForceLateral), m_gForceLongitudinal(gForceLongitudinal), m_gForceVertical(gForceVertical),
      m_yaw(yaw), m_pitch(pitch), m_roll(roll) {}

// Getter methods
float CarMotionData::getWorldPositionX() const { return m_worldPositionX; }
float CarMotionData::getWorldPositionY() const { return m_worldPositionY; }
float CarMotionData::getWorldPositionZ() const { return m_worldPositionZ; }
float CarMotionData::getWorldVelocityX() const { return m_worldVelocityX; }
float CarMotionData::getWorldVelocityY() const { return m_worldVelocityY; }
float CarMotionData::getWorldVelocityZ() const { return m_worldVelocityZ; }
int16_t CarMotionData::getWorldForwardDirX() const { return m_worldForwardDirX; }
int16_t CarMotionData::getWorldForwardDirY() const { return m_worldForwardDirY; }
int16_t CarMotionData::getWorldForwardDirZ() const { return m_worldForwardDirZ; }
int16_t CarMotionData::getWorldRightDirX() const { return m_worldRightDirX; }
int16_t CarMotionData::getWorldRightDirY() const { return m_worldRightDirY; }
int16_t CarMotionData::getWorldRightDirZ() const { return m_worldRightDirZ; }
float CarMotionData::getGForceLateral() const { return m_gForceLateral; }
float CarMotionData::getGForceLongitudinal() const { return m_gForceLongitudinal; }
float CarMotionData::getGForceVertical() const { return m_gForceVertical; }
float CarMotionData::getYaw() const { return m_yaw; }
float CarMotionData::getPitch() const { return m_pitch; }
float CarMotionData::getRoll() const { return m_roll; }
