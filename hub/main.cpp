#include <Arduino.h>
#include <RemoteReceiver.h>
#include <RemoteTransmitter.h>
#include <ArduinoSTL.h>
#include "src/Light.h"

using std::vector;

const int maxStairs = 2;
vector<Light> lights{Light(200, 13), Light(200, 11)};

void ChangeLightState(unsigned long receivedCode, unsigned int period) {
    const unsigned long sensorCodes[] = {57050, 57048, 58346, 58344};

    for (int i = 0; i < maxStairs * 2; i++) {
        if(receivedCode == sensorCodes[i]) {
            int y = (int)i / 2;
            lights[y].Toggle();
        }
    }
}

void setup() {
    RemoteReceiver::init(0, 2, ChangeLightState);

    for (int i = 0; i < maxStairs; i++) {
        pinMode(lights[i].Pin(), OUTPUT);
    }
}

void loop() {
    delay(100);

    for (int i = 0; i < maxStairs; i++) {
        lights[i].Timer().Read();
    }
}
