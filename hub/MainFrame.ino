#include <RemoteReceiver.h>
#include <RemoteTransmitter.h>

const int maxStairs = 2;
const int Stairs[] = {13, 11};
boolean StairStates[] = {false, false};

int StairDelays[] = {0, 0};
int ActivatedSensors[] = {0, 0};
int ReceiveDelays[] = {0, 0};

void setup(){  
  RemoteReceiver::init(0, 2, ChangeLightState);
  
  for(int i=0; i<maxStairs; i++){
    pinMode(Stairs[i], OUTPUT);
  }
}
void loop(){
  delay(100);
  
  for(int i=0; i<maxStairs; i++){
    StairTimer(Stairs[i], StairDelays[i], i);
    if(ReceiveDelays[i] != 0){
      CalculateReceiveDelay(ReceiveDelays[i], i);
    }
  }
}
//Calculate the receive delay, must be smaller than max
void CalculateReceiveDelay(int ReceiveDelay, int i){
  const int MaxReceiveDelay = 4;
  if(ReceiveDelay < MaxReceiveDelay){
    ReceiveDelays[i] = ReceiveDelay + 1; 
  }else{
    ReceiveDelays[i] = 0;
  }
}

//When receiving a signal change the light state
void ChangeLightState(unsigned long receivedCode, unsigned int period){
  const unsigned long sensorCodes[] = {57050, 57048, 58346, 58344};
  
  for(int i=0; i<maxStairs*2; i++){
    if(receivedCode == sensorCodes[i]){
      //Get the correct led
      int y=(int) i/2;
      ToggleLight(Stairs[y], StairDelays[y], i + 1, StairStates[y], y);
    }
  }
}

//Toggle the light of the correct led
void ToggleLight(int Stair, int StairDelay, int ActivatedSensor, boolean StairOn, int i){
  if(StairOn == false && ActivatedSensor != ActivatedSensors[i] && ReceiveDelays[i] == 0){
    digitalWrite(Stair, HIGH);
    ToggleActivatedSensor(Stair, ActivatedSensor);
  }
  else if(StairOn == true && ActivatedSensor != ActivatedSensors[i] && ReceiveDelays[i] == 0){
    //ToggleActivatedSensor(Stair, 0); depricated??
    ResetTimer(Stair, i);
  }
  ReceiveDelays[i] = 1;
}

void ToggleActivatedSensor(int Stair, int ActivatedSensor){
  for(int i=0; i<maxStairs; i++){
    if(ActivatedSensors[i] != ActivatedSensor){
      ActivatedSensors[i] = ActivatedSensor;
    }else{
      return;
    }
  }
}
