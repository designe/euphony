#ifndef EUPHONY_FSK_H
#define EUPHONY_FSK_H

#include "FFTModel.h"
#include "Modem.h"
#include <string>
#include <vector>

namespace Euphony {
    class FSK : public Modem {
    public:
        FSK();
        WaveList modulate(std::string code);
        WaveList modulate(Packet* packet);
        int getMaxIdxFromSource(const float* fft_source);
        std::shared_ptr<Packet> demodulate(const WaveList& waveList);
        std::shared_ptr<Packet> demodulate(const float* source, int sourceLength, int bufferSize);
    private:
        std::unique_ptr<FFTModel> fftModel;
        static const int getStartFreqIdx() ;
        static const int getEndFreqIdx() ;
    };
}
#endif //EUPHONY_FSK_H
