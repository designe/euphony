#ifndef EUPHONY_PACKET_H
#define EUPHONY_PACKET_H

#include <string>
#include <vector>
#include <Base16.h>

using std::string;
using std::vector;

namespace Euphony {
    class Packet {
    public:
        Packet(BaseCodec* baseSource):baseCodec(baseSource) {}

        string create(string source);
        void push(int data);
        void clear();
        string getStrPayload();
        string toString();

    private:
        BaseCodec* baseCodec;
        vector<int> payload;
        int checksum;
        int parityCode;
        bool isVerified;

        string makeErrorDetectorCode();
    };
}

#endif //EUPHONY_PACKET_H
