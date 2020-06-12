#include "Light.h"

Light::Light(int maxDelay, int pin) {
    _maxDelay = maxDelay;
    _pin = pin;
    _timer = LightTimer(maxDelay, pin);
}

Light::Toggle(int delay, boolean state)