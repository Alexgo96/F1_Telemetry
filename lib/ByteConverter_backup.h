#ifndef BYTE_CONVERTER_H
#define BYTE_CONVERTER_H

#include <iostream>
#include <cstdint>
#include <cstring>
#include <vector>

class ByteConverter_backup {
public:
    // Convert from bytes to uint8
    static uint8_t toUInt8(const std::vector<unsigned char>& dataFrame);

    // Convert from bytes to int8
    static int8_t toInt8(const std::vector<unsigned char>& dataFrame);

    // Convert from bytes to uint16 (little endian)
    static uint16_t toUInt16(const std::vector<unsigned char>& dataFrame);

    // Convert from bytes to int16 (little endian)
    static int16_t toInt16(const std::vector<unsigned char>& dataFrame);

    // Convert from bytes to uint32 (little endian)
    static uint32_t toUInt32(const std::vector<unsigned char>& dataFrame);

    // Convert from bytes to float (little endian)
    static float toFloat(const std::vector<unsigned char>& dataFrame);

    // Convert from bytes to double (little endian)
    static double toDouble(const std::vector<unsigned char>& dataFrame);

    // Convert from bytes to uint64 (little endian)
    static uint64_t toUInt64(const std::vector<unsigned char>& dataFrame);

    // Convert from bytes to char
    static char toChar(const std::vector<unsigned char>& dataFrame);
};

#endif // BYTE_CONVERTER_H
