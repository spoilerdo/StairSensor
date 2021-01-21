#include "Light.h"

Light::Light(int maxDelay, int pin) {
    _pin = pin;
    _maxDelay = maxDelay;
    _wait = 0;
    _state = false;
}

// Toggles the lights on, if the lights are already on, reset the time
void Light::Toggle() {
    if (!_state) {
        digitalWrite(_pin, HIGH);
    } else {
        ResetTime();
    }
}

void Light::ReadTime() {
    if (digitalRead(_pin) == HIGH) {
        if (_wait < _maxDelay) {
            _wait += 1;
            _state = true;
        } else {
            ResetTime();
        }
    }
}

void Light::ResetTime() {
    _wait = 0;
    _state = false;
    digitalWrite(_pin, LOW);
}

bool Light::TimeState() const {
    return _state;
}

int Light::Pin() const {
    return _pin;
}