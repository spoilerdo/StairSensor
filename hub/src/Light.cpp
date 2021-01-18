#include "Light.h"

Light::Light(int maxDelay, int pin): _timer(maxDelay, pin) {
    _pin = pin;
}

// Toggles the lights on, if the lights are already on, reset the time
void Light::Toggle() {
    if (!_timer.State()) {
        Serial.println("PUT ON THE LIGHT!");
        digitalWrite(_pin, HIGH);
    } else {
        _timer.Reset();
    }
}

LightTimer Light::Timer() const {
    return _timer;
}

int Light::Pin() const {
    return _pin;
}