#include <RemoteTransmitter.h>
#include "LongArray.h"
#include "DistanceSensor.h"

KaKuTransmitter Transmitter(11);

const int trigPin = 13;
const int echoPin = 12;

//---old value---//
//const long stairDistance = 50;
const long dBuffer = 0;
LongArray stairDistances(10);
boolean detectState = false;

void setup(){
  Serial.begin(115200);
}

void loop() {
  const long distance = DistanceSensor.get(trigPin, echoPin);
  Serial.println(distance);

  stairDistances.add(distance);
  
  if(!detectState && distance < stairDistance.avg() - dBuffer){
    Serial.println("LightsOn");
    detectState = true;
    Transmitter.sendSignal('M', 10, false);
  } else if(distance > stairDistances.avg() - dBuffer) {
    detectState = false;
  }
}
