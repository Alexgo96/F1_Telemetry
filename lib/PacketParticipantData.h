#ifndef PACKETPARTICIPANTDATA_H
#define PACKETPARTICIPANTDATA_H

#include <cstdint>
#include <vector>
#include "./Packet.h"
#include "./PacketHeader.h"
#include "./ParticipantData.h"

class PacketParticipantData : public Packet{
private:
    PacketHeader m_header;
    uint8_t m_numActiveCars;
    ParticipantData participants[22];

public:
    // Constructor
    PacketParticipantData(PacketHeader header);
    
    //Method to create PackerParticipantData
    void createPacketParticipantData(std::vector<unsigned char>& dataFrame, uint8_t m_numCars);

    // Getter methods for private member variables --> FOLLOW HERE
    const PacketHeader getPacketHeader() const;
    const ParticipantData* getParticipantsData() const;
    const ParticipantData getParticipanDataPosition() const;
    uint8_t getNumActiveCars() const;
};
#endif // PACKETPARTICIPANTDATA_H

