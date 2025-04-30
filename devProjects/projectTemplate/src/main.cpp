/**
 * Testing environment.
 */

/**
 * DEBUG: 
 * E (119) gpio: esp_ipc_call_blocking failed (0x103)
 * [   119][E][esp32-hal-gpio.c:119] __attachInterruptFunctionalArg(): GPIO ISR Service Failed To Start
 * E (132) gpio: gpio_install_isr_service(450): GPIO isr service already installed
 */

#include <Arduino.h>

#define HC_VERSION 0x50
#include "../../../hardwareConfigs/hardwareConfigsSelector.h"

#include "deltaTime.h"
deltaTimeMicros deltaTime;


#include "../../../customLibs/pwmSensor.h"
#if S_PWM_COUNT > 1
pwmSensor pwmSensorObj(S_PWM_PIN_L, S_PWM_PIN_R);
#else
#error Not enough pwm sensors.
#endif

void setup() {
  Serial.begin(115200);
}

void loop() {
  deltaTime.start();

  // Measured code goes here.

  deltaTime.stop();
  
  // Unmeasured code goes here. (serial prints and similar stuff that won't exist in prod).


  // Time measuring an ui.
  int64_t        deltaTimeVar    = deltaTime.check();
  static int64_t deltaTimeVarMax = -1;
  static int64_t deltaTimeVarMin = -1;
  if(deltaTimeVar > deltaTimeVarMax) {
    deltaTimeVarMax = deltaTimeVar;
    Serial.printf("New max: %08llius\n", deltaTimeVarMax);
  } else if(deltaTimeVar < deltaTimeVarMin || deltaTimeVarMin == -1) {
    deltaTimeVarMin = deltaTimeVar;
    Serial.printf("New min: %08llius\n", deltaTimeVarMin);
  }
  Serial.print("\x1b[J\x1b[s\n");
  Serial.printf("Code took: %08llius, max: %08llius, min: %08llius", deltaTimeVar, deltaTimeVarMax, deltaTimeVarMin);
  Serial.print("\x1b[u");

  delay(100);
}
