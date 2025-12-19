// module: speaker
// project: spook

#include "speaker.ext.h"

#include <M5Capsule.h>

void spk_speaker_play_tone(blc_float32 frequency, blc_nat32 duration_ms) {
    M5Capsule.Speaker.tone(frequency, duration_ms);
}
