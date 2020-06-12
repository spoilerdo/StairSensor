// int MaxDelay = 200;

// //Read the stairs sensor value
// //If the delay is not equal max delay change the stair value
// //Otherwise reset the time
// void StairTimer(int Stair, int StairDelay, int i){
//   if(digitalRead(Stair) == HIGH){
//     if(StairDelay != MaxDelay){
//       ChangeStairValues(Stair, StairDelay + 1, true, i);
//     }else{
//       ResetTimer(Stair, i);
//     }
//   }
// }

// void ResetTimer(int Stair, int i){
//   ActivatedSensors[i] = 0;
//   ChangeStairValues(Stair, 0, false, i);
//   digitalWrite(Stair, LOW);
// }

// void ChangeStairValues(int Stair, int StairDelay, boolean StairOn, int i){
//     StairDelays[i] = StairDelay;
//     StairStates[i] = StairOn;
// }
