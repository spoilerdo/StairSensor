#ifndef Light_h
#define Light_h

#include <Arduino.h>

class Light {
   public:
    Light(int maxDelay, int pin);
    void Toggle();
    void ReadTime();
    void ResetTime();
    bool TimeState() const;
    int Pin() const;

   protected:
    int _pin;
    int _maxDelay;
    int _wait;
    bool _state;
};

#endif