#include <RemoteTransmitter.h>
#include "LongArray.h"

KaKuTransmitter Transmitter(11);

const int trigPin = 13;
const int echoPin = 12;

//---old value---//
//const long stairDistance = 50;
const long dBuffer = 0;
LongArray stairDistances(10);

void setup(){
  Serial.begin(115200);
}

void loop() {
  const long distance = GetDistance(trigPin, echoPin);
  Serial.println(distance);

  stairDistances.add(distance);
  
  if(distance < stairDistance.avg() - dBuffer){
    Serial.println("LightsOn");
    Transmitter.sendSignal('M', 10, false);
  }
}
