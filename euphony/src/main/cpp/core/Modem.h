#ifndef EUPHONY_MODEM_H
#define EUPHONY_MODEM_H

#include <string>
#include "Definitions.h"
#include "Packet.h"
#include "Wave.h"

using std::string;
using std::vector;
using std::shared_ptr;

namespace Euphony {

    class Modem {
    public:
        virtual WaveList modulate(string code) = 0;
        virtual WaveList modulate(Packet* packet) = 0;

        virtual int demodulate(const float* source, const int size) = 0;

        virtual ~Modem() = default;
    };
}

#endif //EUPHONY_MODEM_H
