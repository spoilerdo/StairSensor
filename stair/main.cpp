#include <Arduino.h>
#include <RemoteTransmitter.h>
#include "src/LongArray.h"
#include "src/DistanceSensor.h"

KaKuTransmitter Transmitter(11);

//const long stairDistance = 50;
const long dBuffer = 0;
LongArray stairDistances(10);
boolean detectState = false;
DistanceSensor distanceSensor;

const int trigPin = 13;
const int echoPin = 12;

void setup(){
  Serial.begin(115200);
}

void loop() {
  const long distance = distanceSensor.get(trigPin, echoPin);
  Serial.println(distance);

  stairDistances.add(distance);
  
  if(!detectState && distance < stairDistances.avg() - dBuffer){
    Serial.println("LightsOn");
    detectState = true;
    Transmitter.sendSignal('M', 10, false);
  } else if(distance > stairDistances.avg() - dBuffer) {
    detectState = false;
  }
}
