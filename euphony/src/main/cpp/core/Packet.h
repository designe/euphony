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
        string getPayloadStr() const;
        string toString();

    private:
        Charset* charset;
        Base* payload;
    public:
        void setPayload(Base *payload);

    private:
        int checksum;
        int parityCode;
        bool isVerified;
        void initialize();
    };
}

#endif //EUPHONY_PACKET_H
