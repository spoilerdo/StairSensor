#include <Arduino.h>
#include <RemoteTransmitter.h>
#include "src/LongArray.h"
#include "src/DistanceSensor.h"

KaKuTransmitter Transmitter(13);

const long stairDistance = 50;
const long minStairDistance = 10;
const long dBuffer = 0;
LongArray stairDistances(10);
boolean detectState = false;
DistanceSensor distanceSensor;

const int trigPin = 12;
const int echoPin = 11;

void setup()
{
}

void loop()
{
  const long distance = distanceSensor.get(trigPin, echoPin);
  Serial.println(distance);

  // stairDistances.add(distance);
  // stairDistances.avg();

  if (!detectState && distance < stairDistance - dBuffer && distance > minStairDistance)
  {
    Serial.println("LightsOn");
    detectState = true;
    Transmitter.sendSignal('M', 12, false);
  }
  else if (distance > stairDistance - dBuffer)
  {
    Serial.println("LightsOff");
    detectState = false;
  }
}
