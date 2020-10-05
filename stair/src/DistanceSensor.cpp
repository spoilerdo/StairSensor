#include "DistanceSensor.h"

DistanceSensor::DistanceSensor() {}

long DistanceSensor::get(int _trigPin, int _echoPin)
{
    long duration, cm;

    pinMode(_trigPin, OUTPUT);
    digitalWrite(_trigPin, LOW);
    delayMicroseconds(1);
    digitalWrite(_trigPin, HIGH);
    delayMicroseconds(3);
    digitalWrite(_trigPin, LOW);

    pinMode(_echoPin, INPUT);
    duration = pulseIn(_echoPin, HIGH);

    cm = duration / 29 / 2;
    if (cm > 0 && cm < 1000)
    {
        return cm;
    }
    else
    {
        return 1000;
    }
}