#ifndef _HC_MK3_BASE_H
#define _HC_MK3_BASE_H

// Leds.
#define S_LED_COUNT 2
#define S_LED_PIN_1 47
#define S_LED_PIN_2 48

// Buzzers.
#define S_BUZZER_COUNT 0

// Buttons.
#define S_BUTTON_COUNT      1
#define S_BUTTON_1_PIN      02
#define S_BUTTON_1_INVERTED 0
#define S_BUTTON_1_NEEDS_PU 0

// Motors.
#define S_MOTOR_PIN_L_EN 14  // Speed, pwm.
#define S_MOTOR_PIN_L_PH 12  // Direction. 0 == rev, 1 -- fwd.
#define S_MOTOR_PIN_R_EN 21  // Speed, pwm.
#define S_MOTOR_PIN_R_PH 13  // Direction. 0 == rev, 1 -- fwd.
// NSleep. Low == low power mode, driver offline.
#define S_MOTOR_NSLEEP       1
#define S_MOTOR_PIN_L_NSLEEP 11
#define S_MOTOR_PIN_R_NSLEEP 11
// NFaults. Low == error. Error can be due to low battery voltage (threshold is somewhere between 4.2V and 4.6V), if the output current is more than the threshold somewhere between 6A and 10A for longer than 3us, or if the drivers temperature exceeds a threshold somewhere between 160°C and 190°C.
#define S_MOTOR_NFAULT       0

// Encoders
#define S_ENCODERS 0  // Has encoders?

// Line "QRE" sensors.
#define S_QRE_COUNT 3
#define S_QRE_PIN_L 10  // Left.
#define S_QRE_PIN_R 09  // Right.
#define S_QRE_PIN_B 08  // Rear/back.

// Binary "Sharp" sensors.
#define S_BIN_COUNT 2
#define S_BIN_PIN_L 06
#define S_BIN_PIN_R 16

// PWM "Pololu" sensors.
#define S_PWM_COUNT 0

// Starting module.
#define S_IR_INPUT_PIN 38  // Probably an external ir module, maybe an ir reciever.

// I2C stuff.
#define S_I2C_PIN_SDA 18
#define S_I2C_PIN_SCL 17
// I2C addresses. Address of 0xff meand this module isn't present as i2c can go only up to 127.
#define S_I2C_ADDR_NVMEM          0xff  // Non-volatile memory, likely an eeprom.
#define S_I2C_ADDR_ACCELEROMETER  0xff
#define S_I2C_ADDR_GYROSCOPE      0xff
#define S_I2C_ADDR_VOLTAGE_READER 0xff

#endif
