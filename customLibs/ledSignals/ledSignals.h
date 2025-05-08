#ifndef _LED_SIGNALS_H
#define _LED_SIGNALS_H

#include <Arduino.h>

#define PIN_UNDEFINED (uint8_t)-1

class ledSignals {
private:
  uint8_t  pin = PIN_UNDEFINED;
  uint8_t  cyclesBurst, cycleBurst;
  uint32_t timeSignalEnd = 0, timeFlip;
  bool     pinState      = 0;
  uint16_t timeBurstOn, timeBurstOff, timeSignalOff;

public:
  ledSignals(uint8_t pin);
  void set(bool force, uint16_t timeBurstOn, uint16_t timeBurstOff, uint8_t cyclesBurst);
  void set(bool     force,
           uint16_t timeBurstOn,
           uint16_t timeBurstOff,
           uint8_t  cyclesBurst,
           uint16_t timeSignalOff,
           uint8_t  cyclesSignal);
  void loop();
  void stop();
};



ledSignals::ledSignals(uint8_t pin) {
  this->pin = pin;
  pinMode(pin, OUTPUT);
}


/**
 * @param force Whether to force the new signal if the old one is still running.
 * @param timeBurstOn How long should the led stay on each burst.
 * @param timeBurstOff How long should the led stay off each burst.
 * @param cyclesBurst Number of flashes in a burst.
 * @brief Set a led to blink in a specific pattern for n cycles. All time related values are in ms.
 * @note Last off pulse is always omitted, both in a single burst and in the whole signal.
 */
void ledSignals::set(bool force, uint16_t timeBurstOn, uint16_t timeBurstOff, uint8_t cyclesBurst) {
  set(force, timeBurstOn, timeBurstOff, cyclesBurst, 0, 1);
}


/**
 * @param force Whether to force the new signal if the old one is still running.
 * @param timeBurstOn How long should the led stay on each burst.
 * @param timeBurstOff How long should the led stay off each burst.
 * @param cyclesBurst Number of flashes in a burst.
 * @param timeSignalOff How long should the led stay off between each burst.
 * @param cyclesSignal Number of bursts.
 * @brief Set a led to blink in a specific pattern for n cycles. All time related values are in ms.
 * @note Last off pulse is always omitted, both in a single burst and in the whole signal. Each burs can be max 65s.
 */
void ledSignals::set(bool     force,
                     uint16_t timeBurstOn,
                     uint16_t timeBurstOff,
                     uint8_t  cyclesBurst,
                     uint16_t timeSignalOff,
                     uint8_t  cyclesSignal) {
  if(pin == PIN_UNDEFINED) {
    return;
  }

  // This would break stuff. Also,,, why would you use this?.
  if(timeBurstOn == 0) {
    return;
  }
  if(cyclesBurst == 0) {
    return;
  }
  if(cyclesSignal == 0) {
    return;
  }
  if(timeSignalOff <= timeBurstOff) {
    if(cyclesSignal != 1) {
      return;
    }
  }

  uint32_t timeNow = millis();

  // Check if a signal is already running.
  if(timeNow < timeSignalEnd) {
    if(force != 1) {
      return;
    }
  }

  uint16_t timeBurstLength = (timeBurstOn + timeBurstOff) * cyclesBurst;
  timeSignalOff -= timeBurstOff;
  uint32_t timeSignalLength = (timeBurstLength + timeSignalOff) * cyclesSignal - timeSignalOff;
  timeSignalEnd             = timeNow + timeSignalLength - timeBurstOff;

  this->timeSignalEnd = timeSignalEnd;
  this->timeBurstOn   = timeBurstOn;
  this->timeBurstOff  = timeBurstOff;
  this->timeSignalOff = timeSignalOff;
  this->cyclesBurst   = cyclesBurst;
  cycleBurst          = 1;

  // Set next flip timestamp and start.
  timeFlip = timeNow + timeBurstOn;
  digitalWrite(pin, 1);
  pinState = 1;
}


/**
 * @brief Updates the output and stuff.
 */
void ledSignals::loop() {
  if(pin == PIN_UNDEFINED) {
    return;
  }

  uint32_t timeNow = millis();
  // Check if ended.
  if(timeNow >= timeSignalEnd) {
    if(pinState == 1) {  // Ended but still on.
      digitalWrite(pin, 0);
      pinState = 0;
    }
    return;
  }

  // Time to flip.
  if(timeNow < timeFlip) {  // No.
    return;
  }

  digitalWrite(pin, !pinState);
  pinState = !pinState;
  if(pinState == 1) {
    timeFlip += timeBurstOn;
    cycleBurst++;
  } else {
    if(cycleBurst == cyclesBurst) {
      timeFlip += timeSignalOff;
      cycleBurst = 0;
    }
    timeFlip += timeBurstOff;
  }
}


/**
 * @brief Ends the signal.
 */
void ledSignals::stop() {
  if(pin == PIN_UNDEFINED) {
    return;
  }

  uint32_t timeNow = millis();
  digitalWrite(pin, 0);
  pinState      = 0;
  timeSignalEnd = timeNow;
}


#undef PIN_UNDEFINED

#endif
