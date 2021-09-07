#include "../WaveRenderer.h"

using namespace Euphony;

WaveRenderer::WaveRenderer(WaveList waveListSrc, int32_t channelCountSrc)
: channelCount (channelCountSrc)
, readFrameIndex(0)
{
    waveSourceSize = waveListSrc.size() * kBufferSize;
    waveSource = std::make_unique<float[]>(waveSourceSize);
    std::fill_n(waveSource.get(), waveSourceSize, 0);
    for(int i = 0; i < waveListSrc.size(); i++) {
        auto waveSrc = waveListSrc[i]->getSource();
        for(int j = 0; j < kBufferSize; j++) {
            waveSource[j + (i * kBufferSize)] = waveSrc[j];
        }
    }
}

void WaveRenderer::renderAudio(float *targetData, int32_t numFrames) {
    if(isWaveOn) {
        int64_t framesToRenderFromData = numFrames;
        const float *waveSrcData = waveSource.get();

        if (readFrameIndex + numFrames >= waveSourceSize) {
            framesToRenderFromData = waveSourceSize - readFrameIndex;
        }

        for (int i = 0; i < framesToRenderFromData; ++i) {
            for (int j = 0; j < channelCount; ++j) {
                targetData[(i * channelCount) + j] = waveSrcData[readFrameIndex];
            }
            if (++readFrameIndex >= waveSourceSize)
                readFrameIndex = 0;
        }
    }
}

void WaveRenderer::tap(bool isDown) {
    isWaveOn.store(isDown);
}

