#include "Light.h"

Light::Light(int maxDelay, int pin):_timer(maxDelay, pin) {
    _pin = pin;
}

void Light::Toggle() {
    if (!_timer.State()) {
        digitalWrite(_pin, HIGH);
    } else {
        _timer.Reset();
    }
}

LightTimer Light::Timer() {
    return _timer;
}

int Light::Pin() {
    return _pin;
}