#include "LightTimer.h"

LightTimer::LightTimer(int maxDelay, int pin) {
    Serial.println("CONSTRUCTING....");
    _maxDelay = maxDelay;
    _pin = pin;
    _wait = 0;
    _state = false;
}

void LightTimer::Read() {
    if (digitalRead(_pin) == HIGH) {
        Serial.println(_wait);
        if (_wait < _maxDelay) {
            _wait += 1;
            _state = true;
        } else {
            Serial.println("RESET1");
            Reset();
        }
    }
}

void LightTimer::Reset() {
    Serial.println("RESET");
    _wait = 0;
    _state = false;
    digitalWrite(_pin, LOW);
}

bool LightTimer::State() const {
    return _state;
}
