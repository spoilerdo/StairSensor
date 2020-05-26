#include <RemoteTransmitter.h>

KaKuTransmitter Transmitter(11);

const int trigPin = 13;
const int echoPin = 12;

const long stairDistance = 50;

void setup(){
  Serial.begin(9600);
}

void loop() {
  Serial.println(GetDistance(trigPin, echoPin));
  
  if(GetDistance(trigPin, echoPin) < stairDistance){
    Serial.println("LightsON");
    Transmitter.sendSignal('M', 10, false);
  }
}
