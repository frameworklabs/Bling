// module:  string
// project: spook

#include "str.h"

#include <string.h>

blc_01modules01string01_String spk_str(const char* str) {
    blc_01modules01string01_String res;
    res.ptr = (blc_nat32)(str);
    res.len = (blc_nat32)(strlen(str));
    return res;
}
