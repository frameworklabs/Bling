// module:  logging
// project: spook

#ifndef SPK_LOGGING_EXT_H
#define SPK_LOGGING_EXT_H

#include "modules/string.h"
#include "modules/logging_types.h"

#ifdef __cplusplus
extern "C" {
#endif

void spk_logging_log_int32(blc_int32 num, blc_01modules01logging_types01_Format* format);
void spk_logging_log_nat32(blc_int32 nat, blc_01modules01logging_types01_Format* format);
void spk_logging_log_str(blc_01modules01string01_String* str, blc_01modules01logging_types01_Format* format);

#ifdef __cplusplus
}
#endif

#endif
