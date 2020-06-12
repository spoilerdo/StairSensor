#ifndef DistanceSensor_h
#define DistanceSensor_h

#include <Arduino.h>

class DistanceSensor {
   public:
    DistanceSensor();
    long get(int _trigPin, int _echoPin);
};

#endif