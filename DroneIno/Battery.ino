/*
* Battery
* @author @sebastiano123-c
*/

float voltagePartitor(int volt){
  /* 
  * @brief voltage partitor 
  * @param (int)volt battery voltage in mV
  */

  return (float)(volt-DIODE_DROP) * totalDrop;
}

float fromWidthToVPin(int width, float corr = 1.){
  return (float)width / (fromVtoWidth * corr);
}

float fromWidthToVBattery(int width, float corr = 1.){
  return (float)width / (totalDrop * fromVtoWidth * corr) + DIODE_DROP;
}

void initBattery(){
  /* 
  * @brief get the initial value of the battery voltage
  */

  // set 2^10=1024 width (analogSetWidth can go from 9-12 (default 12))
  analogSetWidth(adcBits);  
  
  // get battery voltage
  getBatteryVoltage();

  // if(DEBUG) {Serial.print("initBattery: OK; voltage: "); Serial.println(batteryVoltage);}
}

int getBatteryVoltage(){
  /* 
  * @brief get battery voltage
  */

  batteryVoltage = analogRead(PIN_BATTERY_LEVEL) / fromVtoWidth;

}

void batteryVoltageCompensation(){
  /* 
  * @brief compensate the ESCs pulses with battery voltage
  */
 
  //The battery voltage is needed for compensation.
  batteryVoltage = batteryVoltage * 0.92 + analogRead(PIN_BATTERY_LEVEL) / fromVtoWidth * 0.08;
  batteryPercent = batteryVoltage*correctionBattery/maxBatteryLevelDropped;

 if(DEBUG) {
   Serial.print("batteryVoltage: "); Serial.print(batteryVoltage);
   Serial.print(",analog read width: "); Serial.print(analogRead(PIN_BATTERY_LEVEL));
   Serial.print(",analog read volt: "); Serial.print(analogRead(PIN_BATTERY_LEVEL) / fromVtoWidth/1000);
   Serial.print(",minBatteryLevelThreshold: "); Serial.println(minBatteryLevelThreshold);
 }

  //Turn on the led if battery voltage is too low.
  if(batteryVoltage < minBatteryLevelThreshold) ledcWrite(pwmLedChannel, MAX_DUTY_CYCLE);
  else ledcWrite(pwmLedChannel, 0);
}
