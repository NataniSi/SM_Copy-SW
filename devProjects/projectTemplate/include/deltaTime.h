/**
 * Small header specifically for "gate" measuring code speed.
 */

#ifndef _DELTATIME_H
#define _DELTATIME_H

#include <Arduino.h>

struct deltaTimeMicros {
private:
  int64_t microsStart = 0;
  int64_t microsEnd = 0;

public:
  void start() {
    microsStart = esp_timer_get_time();
  }

  void stop() {
    microsEnd = esp_timer_get_time();
  }

  int64_t check() {
    return microsEnd - microsStart;
  }
};

#endif