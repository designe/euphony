#ifndef EUPHONY_FSK_H
#define EUPHONY_FSK_H

#include "Modem.h"
#include <string>
#include <vector>

namespace Euphony {
    class FSK : public Modem {
    public:
        std::vector<std::shared_ptr<Wave>> modulate(std::string code);
        std::vector<std::shared_ptr<Wave>> modulate(Packet* packet);
        int demodulate(const float* source, const int size);
    private:
        const int getStartFreqIdx() const;
        const int getEndFreqIdx() const;
    };
}
#endif //EUPHONY_FSK_H
