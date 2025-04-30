#ifndef _PWM_SENSOR_H
#define _PWM_SENSOR_H

#include <Arduino.h>



class pwmSensor
{
private:
  uint32_t trigVal = 0;
  static void callback(void* args);
public:
  pwmSensor(uint8_t pin1, uint8_t pin2);
};



pwmSensor::pwmSensor(uint8_t pin1, uint8_t pin2) {
  size_t callbackArgs[] = {(size_t)&trigVal};
  attachInterruptArg(pin1, callback, (void*)callbackArgs, CHANGE);
  attachInterruptArg(pin2, callback, (void*)callbackArgs, CHANGE);
}

void pwmSensor::callback(void* args) {
  uint32_t* trigVal = (uint32_t*)(((size_t*)args)[0]);
  Serial.println(*trigVal);
}


#endif