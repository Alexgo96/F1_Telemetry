#include "../lib/ByteConverter_backup.h"

uint8_t ByteConverter_backup::toUInt8(const std::vector<unsigned char>& dataFrame) {
    return dataFrame.empty() ? 0 : dataFrame[0];
}

int8_t ByteConverter_backup::toInt8(const std::vector<unsigned char>& dataFrame) {
    return dataFrame.empty() ? 0 : *reinterpret_cast<const int8_t*>(&dataFrame[0]);
}

uint16_t ByteConverter_backup::toUInt16(const std::vector<unsigned char>& dataFrame) {
    if (dataFrame.size() < 2) return 0;
    uint16_t result = static_cast<uint16_t>(dataFrame[0]);
    result |= static_cast<uint16_t>(dataFrame[1]) << 8;
    return result;
}

int16_t ByteConverter_backup::toInt16(const std::vector<unsigned char>& dataFrame) {
    return static_cast<int16_t>(toUInt16(dataFrame));
}

uint32_t ByteConverter_backup::toUInt32(const std::vector<unsigned char>& dataFrame) {
    if (dataFrame.size() < 4) return 0;
    uint32_t result = static_cast<uint32_t>(dataFrame[0]);
    result |= static_cast<uint32_t>(dataFrame[1]) << 8;
    result |= static_cast<uint32_t>(dataFrame[2]) << 16;
    result |= static_cast<uint32_t>(dataFrame[3]) << 24;
    return result;
}

float ByteConverter_backup::toFloat(const std::vector<unsigned char>& dataFrame) {
    if (dataFrame.size() < sizeof(float)) return 0.0f;
    float result;
    std::memcpy(&result, &dataFrame[0], sizeof(float));
    return result;
}

double ByteConverter_backup::toDouble(const std::vector<unsigned char>& dataFrame) {
    if (dataFrame.size() < sizeof(double)) return 0.0;
    double result;
    std::memcpy(&result, &dataFrame[0], sizeof(double));
    return result;
}

uint64_t ByteConverter_backup::toUInt64(const std::vector<unsigned char>& dataFrame) {
    if (dataFrame.size() < 8) return 0;
    uint64_t result = static_cast<uint64_t>(dataFrame[0]);
    result |= static_cast<uint64_t>(dataFrame[1]) << 8;
    result |= static_cast<uint64_t>(dataFrame[2]) << 16;
    result |= static_cast<uint64_t>(dataFrame[3]) << 24;
    result |= static_cast<uint64_t>(dataFrame[4]) << 32;
    result |= static_cast<uint64_t>(dataFrame[5]) << 40;
    result |= static_cast<uint64_t>(dataFrame[6]) << 48;
    result |= static_cast<uint64_t>(dataFrame[7]) << 56;
    return result;
}

char ByteConverter_backup::toChar(const std::vector<unsigned char>& dataFrame) {
    return dataFrame.empty() ? '\0' : static_cast<char>(dataFrame[0]);
}
