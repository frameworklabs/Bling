// module: speaker
// project: spook

#ifndef SPK_SPEAKER_EXT_H
#define SPK_SPEAKER_EXT_H

#include "blech.h"

#ifdef __cplusplus
extern "C" {
#endif  

void spk_speaker_play_tone(blc_float32 frequency, blc_nat32 duration_ms);

#ifdef __cplusplus
}
#endif

#endif
