#ifndef EUPHONY_WAVERENDERER_H
#define EUPHONY_WAVERENDERER_H

#include "Definitions.h"
#include <IRenderableAudio.h>

namespace Euphony {

    class WaveRenderer : public IRenderableAudio {
    public:
        WaveRenderer(WaveList waveListSrc);

        ~WaveRenderer() = default;

        //From IRenderableAudio
        void renderAudio(float *data, int32_t numFrames);

    private:
        std::unique_ptr<float[]> waveSource;
    };
}
#endif //EUPHONY_WAVERENDERER_H
