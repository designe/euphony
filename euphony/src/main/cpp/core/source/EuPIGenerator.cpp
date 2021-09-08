//
// Created by desig on 2020-08-15.
//

#include "EuPIGenerator.h"

using namespace Euphony;

EuPIGenerator::EuPIGenerator(int32_t sampleRate, int32_t channelCount)
        : mSampleRate(sampleRate),
          mChannelCount(channelCount),
          mOscillators(std::make_unique<Oscillator[]>(channelCount)){

    double defaultFrequency = 18000.0;
    constexpr float amplitude = 1.0;

    // Set up the oscillators
    for (int i = 0; i < mChannelCount; ++i) {
        mOscillators[i].setFrequency(defaultFrequency);
        mOscillators[i].setSampleRate(mSampleRate);
        mOscillators[i].setAmplitude(amplitude);
    }
}

void EuPIGenerator::renderAudio(float *audioData, int32_t numFrames) {
    // Render each oscillator into its own channel
    std::fill_n(mBuffer.get(), kBufferSize, 0);
    for (int i = 0; i < mChannelCount; ++i) {
        mOscillators[i].renderAudio(mBuffer.get(), numFrames);
        for (int j = 0; j < numFrames; ++j) {
            audioData[(j * mChannelCount) + i] = mBuffer[j];
        }
    }
}

void EuPIGenerator::setFrequency(double frequency) {
    for(int i = 0;  i< mChannelCount; ++i) {
        mOscillators[i].setFrequency(frequency);
    }
}

void EuPIGenerator::tap(bool isDown) {
    for (int i = 0; i < mChannelCount; ++i) {
        mOscillators[i].setWaveOn(isDown);
    }
}

std::unique_ptr<float[]> EuPIGenerator::makeStaticWave(int freq) {
    std::unique_ptr<float[]> waveArray = std::make_unique<float[]>(kBufferSize);
    float phase = 0.0;
    double phaseIncrement = (kTwoPi * freq) / static_cast<double>(kSampleRate);
    for (int i = 0; i < kBufferSize; i++) {
        waveArray[i] = (float) sin(phase);
        phase += phaseIncrement;
        if (phase > kTwoPi) phase -= kTwoPi;
    }

    return waveArray;
}