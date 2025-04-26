/**
 * Testing environment.
 */

#include <Arduino.h>

#define HC_VERSION 0x
#include "../../../hardwareConfigs/hardwareConfigsSelector.h"

#include "deltaTime.h"
deltaTimeMicros deltaTime;


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
