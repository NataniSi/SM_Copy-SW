#ifndef _HC_MK4_BASE_H
#define _HC_MK4_BASE_H

// Leds.
#define S_LED_COUNT 3
#define S_LED_PIN_1 21
#define S_LED_PIN_2 14
#define S_LED_PIN_3 13

// Buzzers.
#define S_BUZZER_COUNT 0

// Buttons.
#define S_BUTTON_COUNT 2
#define S_BUTTON_1_PIN      48
#define S_BUTTON_1_INVERTED 0
#define S_BUTTON_1_NEEDS_PU 0
#define S_BUTTON_2_PIN      47
#define S_BUTTON_2_INVERTED 0
#define S_BUTTON_2_NEEDS_PU 0

// Motors.
#define S_MOTOR_PIN_L_EN 42  // Speed, pwm.
#define S_MOTOR_PIN_L_PH 40  // Direction. 0 == rev, 1 -- fwd.
#define S_MOTOR_PIN_R_EN 39  // Speed, pwm.
#define S_MOTOR_PIN_R_PH 41  // Direction. 0 == rev, 1 -- fwd.
// NSleep. Low == low power mode, driver offline.
#define S_MOTOR_NSLEEP       1
#define S_MOTOR_PIN_L_NSLEEP 38
#define S_MOTOR_PIN_R_NSLEEP 38
// NFaults. Low == error. Error can be due to low battery voltage (threshold is somewhere between 4.2V and 4.6V), if the output current is more than the threshold somewhere between 6A and 10A for longer than 3us, or if the drivers temperature exceeds a threshold somewhere between 160°C and 190°C.
#define S_MOTOR_NFAULT       1
#define S_MOTOR_PIN_L_NFAULT 37
#define S_MOTOR_PIN_R_NFAULT 37

// Encoders
#define S_ENCODERS    1  // Has encoders?
#define S_ENC_PIN_L_A 09
#define S_ENC_PIN_L_B 10
#define S_ENC_PIN_R_A 12
#define S_ENC_PIN_R_B 11

// Line "QRE" sensors.
#define S_QRE_COUNT 3
#define S_QRE_PIN_L 06  // Left.
#define S_QRE_PIN_R 07  // Right.
#define S_QRE_PIN_B 02  // Rear/back.

// Binary "Sharp" sensors.
#define S_BIN_COUNT 2
#define S_BIN_PIN_L 08
#define S_BIN_PIN_R 04

// PWM "Pololu" sensors.
#define S_PWM_COUNT 3
#define S_PWM_PIN_L 16  // Left.
#define S_PWM_PIN_R 05  // Right.
#define S_PWM_PIN_M 15  // Middle.

// Starting module.
#define S_IR_INPUT_PIN 35  // Probably an external ir module, maybe an ir reciever.

// I2C stuff.
#define S_I2C_PIN_SDA 17
#define S_I2C_PIN_SCL 18
// I2C addresses. Address of 0xff meand this module isn't present as i2c can go only up to 127.
#define S_I2C_ADDR_NVMEM          0xff  // Non-volatile memory, likely an eeprom.
#define S_I2C_ADDR_ACCELEROMETER  0xff
#define S_I2C_ADDR_GYROSCOPE      0xff
#define S_I2C_ADDR_VOLTAGE_READER 0xff

#endif
