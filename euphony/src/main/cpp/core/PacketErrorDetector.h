#ifndef EUPHONY_PACKETERRORDETECTOR_H
#define EUPHONY_PACKETERRORDETECTOR_H

#include <vector>
#include <string>
#include "HexVector.h"

using std::string;
using std::vector;

namespace Euphony {

    class PacketErrorDetector {
    public:
        static string makeParityAndChecksum(const HexVector& payload);
        static string makeParityAndChecksum(string payloadStr);
        static int makeChecksum(const HexVector& payload);
        static int makeParallelParity(const HexVector& payload);
        static bool verifyChecksum(const HexVector& payload, int checksum);
        static bool verifyParallelParity(const HexVector& payload, int parity);
    };
}
#endif //EUPHONY_PACKETERRORDETECTOR_H
