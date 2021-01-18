#ifndef LightTimer_h
#define LightTimer_h

#include <Arduino.h>

class LightTimer {
   public:
    LightTimer(int maxDelay, int pin);
    void Read();
    void Reset();
    bool State() const;

   protected:
    int _maxDelay;
    int _pin;
    int _wait;
    bool _state;
};

#endif