#ifndef EUPHONY_WAVERENDERER_H
#define EUPHONY_WAVERENDERER_H

#include "Definitions.h"
#include "EuphonyAudioSource.h"

namespace Euphony {

    class WaveRenderer : public EuphonyAudioSource{
    public:
        WaveRenderer(WaveList waveListSrc, int32_t channelCountSrc);
        ~WaveRenderer() = default;

        void renderAudio(float *targetData, int32_t numFrames) override; //From IRenderableAudio
        void tap(bool isDown) override;

    private:
        std::unique_ptr<float[]> waveSource;
        std::atomic<bool> isWaveOn { false };
        int32_t channelCount;
        int32_t readFrameIndex;
        int32_t waveSourceSize;
    };
}
#endif //EUPHONY_WAVERENDERER_H
