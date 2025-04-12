#ifndef PACKETCARTELEMETRYDATA_H
#define PACKETCARTELEMETRYDATA_H

#include <cstdint>
#include <vector>
#include "./Packet.h"
#include "./PacketHeader.h"
#include "./CarTelemetryData.h"

class PacketCarTelemetryData : public Packet {
private:
    PacketHeader m_header;
    CarTelemetryData m_carTelemetryData[22];
    uint8_t m_mfdPanelIndex;
    uint8_t m_mfdPanelIndexSecondaryPlayer;
    int8_t m_sugestedGear;

public:
    // Constructor
    PacketCarTelemetryData(PacketHeader header);

    // Method to create PacketCarTelemetryData
    void createPacketCarTelemetryData(std::vector<unsigned char>& dataFrame, uint8_t numCars);

    // Getter methods for private member variables
    const PacketHeader getHeader() const;
    const CarTelemetryData* getCarTelemetryData() const;
    const CarTelemetryData getCarTelemetryDataPosition(int position) const;
    uint8_t getMfdPanelIndex() const;
    uint8_t getMfdPanelIndexSecondaryPlayer() const;
    int8_t getSugestedGear() const;
};

#endif // PACKETCARTELEMETRYDATA_H
