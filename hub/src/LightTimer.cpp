#include "LightTimer.h"

LightTimer::LightTimer(int maxDelay, int pin) {
    _maxDelay = maxDelay;
    _pin = pin;
    _delay = 0;
    _state = false;
}

void LightTimer::Read() {
    if (digitalRead(_pin) == HIGH) {
        if (delay < _maxDelay) {
            ChangeValue(_delay + 1, true);
        } else {
            Reset();
        }
    }
}

void LightTimer::Reset() {
    ChangeValue(0, false);
    digitalWrite(_pin, LOW);
}

bool LightTimer::State() {
    return _state;
}

void LightTimer::ChangeValue(int delay, boolean state) {
    _delay = delay;
    _state = state;
}
