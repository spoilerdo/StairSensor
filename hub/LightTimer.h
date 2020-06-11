#ifndef StairTimer_h
#define StairTimer_h

#include <Arduino.h>

class LightTimer {
   public:
    LightTimer(int maxDelay, int pin);
    void Read(int delay);
    void Reset();

   protected:
    int _maxDelay;
    int _pin;
    int _delay;
    bool _state;

   private:
    void ChangeValue(int delay, boolean state);
};

#endif