#include <Arduino.h>
#include <RemoteTransmitter.h>
#include "src/LongArray.h"
#include "src/DistanceSensor.h"

KaKuTransmitter Transmitter(13);

const long minStairDistance = 10;
// Change the treshold to make the sensor less or more sensitive for changes
const long peakTreshold = 20;
LongArray stairDistances(10);
boolean detectState = false;
DistanceSensor distanceSensor;

const int trigPin = 12;
const int echoPin = 11;

void setup()
{ }

void loop()
{
  const long distance = distanceSensor.get(trigPin, echoPin);
  const long avgDistance = stairDistances.avg();

  delay(1);

  // First check if the distance is a peak
  if (!detectState && distance > avgDistance + peakTreshold && distance > minStairDistance)
  {
    detectState = true;
    Transmitter.sendSignal('M', 12, false);
  }
  else if (detectState && distance <= avgDistance + peakTreshold)
  {
    detectState = false;
  }

  //Add the new distance
  stairDistances.add(distance);
}
