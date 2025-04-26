#ifndef _HC_MK5_N1_H
#define _HC_MK5_N1_H
#include "hC_mk5_base.h"

// PWM "Pololu" sensors.
#undef S_PWM_COUNT
#undef S_PWM_PIN_L
#undef S_PWM_PIN_M
#define S_PWM_COUNT 2
#define S_PWM_PIN_L 11  // Left.

// Encoders
#undef S_ENCODERS
#undef S_ENC_PIN_L_A
#undef S_ENC_PIN_L_B
#undef S_ENC_PIN_R_A
#undef S_ENC_PIN_R_B
#define S_ENCODERS 0  // Has encoders?

// I2C stuff.
#undef S_I2C_ADDR_NVMEM
#undef S_I2C_ADDR_ACCELEROMETER
#undef S_I2C_ADDR_GYROSCOPE
#define S_I2C_ADDR_NVMEM         0xff
#define S_I2C_ADDR_ACCELEROMETER 0xff
#define S_I2C_ADDR_GYROSCOPE     0xff

#endif
