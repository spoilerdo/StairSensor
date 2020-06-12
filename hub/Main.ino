#include <RemoteReceiver.h>
#include <RemoteTransmitter.h>
#include "src/LightTimer.h"

const int maxStairs = 2;
const int Stairs[] = {13, 11};
vector<LightTimer> timers(2, LightTimer(200)); // boolean StairStates[] = {false, false};

//Start receivers
void setup() {
    RemoteReceiver::init(0, 2, ChangeLightState);

    for (int i = 0; i < maxStairs; i++) {
        pinMode(Stairs[i], OUTPUT);
    }
}
void loop() {
    delay(100);

    for (int i = 0; i < maxStairs; i++) {
        //check stair timer if activated
        timers[i].Read(Stairs[i], StairDelays[i]); // StairTimer(Stairs[i], StairDelays[i], i);
    }
}

//When receiving a signal change the light state (event method)
void ChangeLightState(unsigned long receivedCode, unsigned int period) {
    const unsigned long sensorCodes[] = {57050, 57048, 58346, 58344};

    for (int i = 0; i < maxStairs * 2; i++) {
        if (receivedCode == sensorCodes[i]) {
            //Get the correct led
            int y = (int)i / 2;
            ToggleLight(Stairs[y], StairStates[y], y);
        }
    }
}

//Toggle the light of the correct led
void ToggleLight(int Stair, boolean StairOn, int i) {
    if (StairOn == false) {
        digitalWrite(Stair, HIGH);
    } else {
        timers[i].Reset(Stair); // ResetTimer(Stair, i);
    }
}
