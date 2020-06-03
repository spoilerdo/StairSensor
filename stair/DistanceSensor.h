#ifdef DistanceSensor_h
#define DistanceSensor_h

#include <Arduino.h>

class DistanceSensor {
   public:
    static long get(int _trigPin, int _echoPin);

   private:
    DistanceSensor();
};

#endif