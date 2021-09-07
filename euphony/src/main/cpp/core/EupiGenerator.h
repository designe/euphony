//
// Created by desig on 2020-08-15.
//

#ifndef EUPHONY_EUPIGENERATOR_H
#define EUPHONY_EUPIGENERATOR_H


#include "Oscillator.h"
#include "EuphonyAudioSource.h"

namespace Euphony {
    class EupiGenerator : public EuphonyAudioSource {
    public:
        EupiGenerator(int32_t sampleRate, int32_t channelCount);
        EupiGenerator(EupiGenerator &&other) = default;
        EupiGenerator &operator=(EupiGenerator &&other) = default;
        ~EupiGenerator() = default;

        void tap(bool isDown) override;
        void renderAudio(float *audioData, int32_t numFrames) override; // from IRenderableAudio
        void setFrequency(double frequency);
        std::unique_ptr<float[]> makeStaticWave(int freq);

    private:
        std::unique_ptr<Oscillator[]> mOscillators;
        std::unique_ptr<float[]> mBuffer = std::make_unique<float[]>(kBufferSize);
        int32_t mChannelCount;
        int32_t mSampleRate;
    };
}


#endif //EUPHONY_EUPIGENERATOR_H
