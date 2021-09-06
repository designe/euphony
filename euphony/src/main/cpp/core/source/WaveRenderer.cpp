#include "../WaveRenderer.h"

using namespace Euphony;

WaveRenderer::WaveRenderer(WaveList waveListSrc) {
    int waveSourceSize = waveListSrc.size() * kBufferSize;
    waveSource = std::make_unique<float[]>(waveSourceSize);

    for(int i = 0; i < waveListSrc.size(); i++) {
        auto waveSrc = waveListSrc[i]->getSource();
        for(int j = 0; j < kBufferSize; j++) {
            waveSource[j + (i * kBufferSize)] = waveSrc[j];
        }
    }
}

void WaveRenderer::renderAudio(float *data, int32_t numFrames) {
    /* TODO: To write renderAudio source
    for(int i = 0; i < numFrames; i++) {
        data[i] =
    }
     */
}

