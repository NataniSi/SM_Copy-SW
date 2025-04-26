#ifndef _HARDWARE_CONFIGS_SELECTOR_H
#define _HARDWARE_CONFIGS_SELECTOR_H

#if HC_VERSION == 0x30
  #include "hC_mk3_base.h"
#elif HC_VERSION == 0x40
  #include "hC_mk4_base.h"
#elif HC_VERSION == 0x50  // Mk5 base.
  #include "hC_mk5_base.h"
#elif HC_VERSION == 0x51  // Newest version of mk5 on Saturday he12025/04/28.
  #include "hC_mk5_var1.h"
#else  // No or wrong HC_VERSION.
  #error No or unknown HC_VERSION selected. Valid versions are: 0x30, 0x40, 0x50, 0x51.
#endif

#endif
