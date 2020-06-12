#ifndef Light_h
#define Light_h

#include <Arduino.h>
#include "LightTimer.h"

class Light {
   public:
    Light(int maxDelay, int pin);
    void Toggle(int delay, boolean state, int i);
    LightTimer Timer();

   protected:
    int _maxDelay;
    int _pin;
    LightTimer _timer;
    
};

#endif