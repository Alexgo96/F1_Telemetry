#include "../lib/ByteConverter.h"
#include <array>

// Function to convert a byte array to uint8_t
uint8_t ByteConverter::toUInt8(const std::vector<unsigned char>& dataFrame, size_t offset) {
    return dataFrame[offset];
}

// Function to convert a byte array to int8_t
int8_t ByteConverter::toInt8(const std::vector<unsigned char>& dataFrame, size_t offset) {
    return static_cast<int8_t>(dataFrame[offset]);
}

// Function to convert a byte array to uint16_t
uint16_t ByteConverter::toUInt16(const std::vector<unsigned char>& dataFrame, size_t offset) {
    uint16_t value;
    std::memcpy(&value, dataFrame.data() + offset, sizeof(uint16_t));
    return value;
}

// Function to convert a byte array to int16_t
int16_t ByteConverter::toInt16(const std::vector<unsigned char>& dataFrame, size_t offset) {
    int16_t value;
    std::memcpy(&value, dataFrame.data() + offset, sizeof(int16_t));
    return value;
}

// Function to convert a byte array to uint32_t
uint32_t ByteConverter::toUInt32(const std::vector<unsigned char>& dataFrame, size_t offset) {
    uint32_t value;
    std::memcpy(&value, dataFrame.data() + offset, sizeof(uint32_t));
    return value;
}

// Function to convert a byte array to float
float ByteConverter::toFloat(const std::vector<unsigned char>& dataFrame, size_t offset) {
    float value;
    std::memcpy(&value, dataFrame.data() + offset, sizeof(float));
    return value;
}

// Function to convert a byte array to double
double ByteConverter::toDouble(const std::vector<unsigned char>& dataFrame, size_t offset) {
    double value;
    std::memcpy(&value, dataFrame.data() + offset, sizeof(double));
    return value;
}

// Function to convert a byte array to uint64_t
uint64_t ByteConverter::toUInt64(const std::vector<unsigned char>& dataFrame, size_t offset) {
    uint64_t value;
    std::memcpy(&value, dataFrame.data() + offset, sizeof(uint64_t));
    return value;
}

// Function to convert a byte array to char
std::array<char, 48> ByteConverter::toChar(const std::vector<unsigned char>& dataFrame, size_t offset) {
    std::array<char, 48> charArray{};
    
    for (size_t i = 0; i < 48 && (offset + i) < dataFrame.size(); ++i) {
        charArray[i] = static_cast<char>(dataFrame[offset + i]);
    }
    
    return charArray; // Returns a copy (safe and easy to use)
}
