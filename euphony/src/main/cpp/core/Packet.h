#ifndef EUPHONY_PACKET_H
#define EUPHONY_PACKET_H

#include <Definitions.h>
#include <Base16.h>
#include <string>

namespace Euphony {
    class Packet {
    public:
        Packet(const HexVector& source);
        Packet(const BaseType type, const HexVector& source);

        void clear();

        u_int8_t getChecksum();
        u_int8_t getParityCode();
        std::string getPayloadStr() const;
        void setPayload(std::shared_ptr<Base> payloadSrc);
        void setPayload(const HexVector& source);
        std::string toString();

    private:
        BaseType baseType;
        Charset* charset;
        std::shared_ptr<Base> payload;
        //std::shared_ptr<Base> checksum;
        //std::shared_ptr<Base> parityCode;
        u_int8_t checksum;
        u_int8_t parityCode;
        bool isVerified;
        void initialize();
    };
}

#endif //EUPHONY_PACKET_H
