#include <Arduino.h>
#include <RemoteTransmitter.h>
#include "src/LongArray.h"
#include "src/DistanceSensor.h"

KaKuTransmitter Transmitter(13);

const long minStairDistance = 10;
const long peakTreshold = 10;
LongArray stairDistances(10);
boolean detectState = false;
DistanceSensor distanceSensor;

const int trigPin = 12;
const int echoPin = 11;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  const long distance = distanceSensor.get(trigPin, echoPin);
  const long avgDistance = stairDistances.avg();

  // First check if the distance is a peak
  if (!detectState && distance > avgDistance + peakTreshold && distance > minStairDistance)
  {
    //Serial.println("LightsOn");
    detectState = true;
    Transmitter.sendSignal('M', 12, false);
  }
  else if (detectState && distance <= avgDistance + peakTreshold)
  {
    //Serial.println("LightsOff");
    detectState = false;
  }

  //Add the new distance
  stairDistances.add(distance);
}
