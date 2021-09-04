#ifndef EUPHONY_PACKET_H
#define EUPHONY_PACKET_H

#include <string>
#include <vector>
#include <Base16.h>

namespace Euphony {
    class Packet {
    public:
        Packet(const HexVector& source);

        void clear();

        int8_t getChecksum();
        int8_t getParityCode();
        string getPayloadStr() const;
        void setPayload(Base *payload);
        string toString();

    private:
        Charset* charset;
        Base* payload;

        int8_t checksum;
        int8_t parityCode;
        bool isVerified;
        void initialize();
    };
}

#endif //EUPHONY_PACKET_H
