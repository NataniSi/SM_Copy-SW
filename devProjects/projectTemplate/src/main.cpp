/**
 * Testing environment.
 */

#include <Arduino.h>

#define HC_VERSION 0x51
#include "../../../hardwareConfigs/hardwareConfigsSelector.h"

#include "deltaTime.h"
deltaTimeMicros deltaTime;

#include "../../../customLibs/ledSignals/ledSignals.h"
// Config has max 4 leds right now.
#if S_LED_COUNT > 0
ledSignals led1(S_LED_PIN_1);
  #if S_LED_COUNT > 1
ledSignals led2(S_LED_PIN_2);
    #if S_LED_COUNT > 2
ledSignals led3(S_LED_PIN_3);
      #if S_LED_COUNT > 3
ledSignals led4(S_LED_PIN_4);
      #endif
    #endif
  #endif
#endif

void setup() {
  Serial.begin(115200);
  delay(2000);
  led1.set(0, 200, 200, 50);
  led2.set(0, 200, 200, 50);
  led3.set(0, 200, 200, 50);
  led4.set(0, 200, 200, 50);
}

void loop() {
  deltaTime.start();

  // Measured code goes here.

  deltaTime.stop();

  // Unmeasured code goes here. (serial prints and similar stuff that won't exist in prod).
  led1.loop();
  led2.loop();
  led3.loop();
  led4.loop();

  // Time measuring an ui.
  int64_t        deltaTimeVar    = deltaTime.check();
  static int64_t deltaTimeVarMax = -1;
  static int64_t deltaTimeVarMin = -1;
  if(deltaTimeVar > deltaTimeVarMax) {
    deltaTimeVarMax = deltaTimeVar;
    Serial.printf("New max: %08llius\n", deltaTimeVarMax);
  } else if(deltaTimeVar < deltaTimeVarMin) {
    deltaTimeVarMin = deltaTimeVar;
    Serial.printf("New min: %08llius\n", deltaTimeVarMin);
  }
  if(deltaTimeVarMin == -1) {
    deltaTimeVarMin = deltaTimeVar;
    Serial.printf("New min: %08llius\n", deltaTimeVarMin);
  }

  Serial.printf("\x1b[s\nCode took: %08llius, max: %08llius, min: %08llius", deltaTimeVar, deltaTimeVarMax, deltaTimeVarMin);

  delay(10);

  Serial.print("\x1b[u\x1b[J");
}
