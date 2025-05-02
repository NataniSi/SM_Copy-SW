#ifndef _HC_MK5_BASE_H
#define _HC_MK5_BASE_H

// Leds.
#define S_LED_COUNT 4
#define S_LED_PIN_1 44
#define S_LED_PIN_2 43
#define S_LED_PIN_3 36
#define S_LED_PIN_4 01

// Buzzers.
#define S_BUZZER_COUNT 1
#define S_BUZZER_PIN_1 02

// Buttons.
#define S_BUTTON_COUNT      2
#define S_BUTTON_1_PIN_1    04
#define S_BUTTON_1_INVERTED 1
#define S_BUTTON_1_NEEDS_PU 0
#define S_BUTTON_1_PIN_2    05
#define S_BUTTON_1_INVERTED 1
#define S_BUTTON_1_NEEDS_PU 0

// Motors.
#define S_MOTOR_PIN_L_EN 07  // Speed, pwm.
#define S_MOTOR_PIN_L_PH 06  // Direction. 0 == rev, 1 -- fwd.
#define S_MOTOR_PIN_R_EN 08  // Speed, pwm.
#define S_MOTOR_PIN_R_PH 18  // Direction. 0 == rev, 1 -- fwd.
// NSleep. Low == low power mode, driver offline.
#define S_MOTOR_NSLEEP 0
//#define S_MOTOR_PIN_L_NSLEEP
//#define S_MOTOR_PIN_R_NSLEEP
// NFaults. Low == error. Error can be due to low battery voltage (threshold is somewhere between 4.2V and 4.6V), if the output current is more than the threshold somewhere between 6A and 10A for longer than 3us, or if the drivers temperature exceeds a threshold somewhere between 160°C and 190°C.
#define S_MOTOR_NFAULT 0
//#define S_MOTOR_PIN_L_NFAULT
//#define S_MOTOR_PIN_R_NFAULT

// Encoders
#define S_ENCODERS 1  // Has encoders?
#define S_ENC_PIN_L_A 
#define S_ENC_PIN_L_B 
#define S_ENC_PIN_R_A 
#define S_ENC_PIN_R_B 

// Line "QRE" sensors.
#define S_QRE_COUNT 3
#define S_QRE_PIN_L 14  // Left.
#define S_QRE_PIN_R 13  // Right.
#define S_QRE_PIN_B 16  // Rear/back.

// Binary "Sharp" sensors.
#define S_BIN_COUNT 2
#define S_BIN_PIN_L 38
#define S_BIN_PIN_R 10

// PWM "Pololu" sensors.
#define S_PWM_COUNT 3
#define S_PWM_PIN_L 35  // Left.
#define S_PWM_PIN_R 12  // Right.
#define S_PWM_PIN_M 11  // Middle.

// Starting module.
#define S_IR_INPUT_PIN 37  // Probably an external ir module, maybe an ir reciever.

// I2C stuff.
#define S_I2C_PIN_SDA 41
#define S_I2C_PIN_SCL 42
// I2C addresses. Address of 0xff meand this module isn't present as i2c can go only up to 127.
#define S_I2C_ADDR_NVMEM          0x50  // Non-volatile memory, likely an eeprom.
#define S_I2C_ADDR_ACCELEROMETER  0x19
#define S_I2C_ADDR_GYROSCOPE      0x69
#define S_I2C_ADDR_VOLTAGE_READER 0x40

#endif
