#ifndef Light_h
#define Light_h

#include <Arduino.h>
#include "LightTimer.h"

class Light {
   public:
    Light(int maxDelay, int pin);
    void Toggle();
    LightTimer Timer() const;
    int Pin() const;

   protected:
    int _pin;
    LightTimer _timer;
};

#endif