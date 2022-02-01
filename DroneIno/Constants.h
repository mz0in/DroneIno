// gyro constants
const int gyroFrequency = 250;                                      // (Hz)
const float gyroSensibility = 65.5;                                 
float travelCoeff = 1/((float)gyroFrequency * gyroSensibility);
float convDegToRad = 180.0 / PI;
float travelCoeffToRad = travelCoeff / convDegToRad;
const int correctionPitchRoll = 15;                                 // correction for the pitch and roll

// PWM channels
const int pwmLedChannel    = 0;
const int pwmChannel1      = 1;
const int pwmChannel2      = 2;
const int pwmChannel3      = 3;
const int pwmChannel4      = 4;
const int pwmLedFlyChannel = 5;
// PWM constants
const int freq = 500;                                               // (Hz) for what I know, 500 is the best 
const int resolution = 11;                                          // (bits) 11 is the best guess
const int MAX_DUTY_CYCLE = (int)(pow(2, resolution) - 1);
const int HALF_DUTY_CYCLE = (int)(0.5*MAX_DUTY_CYCLE);

// battery
// total resistance calculations, the important quantity is totalDrop
float res3 = 1.5;
float res2 = 1;
float res4 = 1.;
float dropTo5V = (res2 + res4) / (res3 + res4 + res2);              // first voltage partitor drop
float dropTo3V3 = res4 / (res4 + res2);                             // second voltage partitor drop
float totalDrop = dropTo5V*dropTo3V3;                  // IMPORTANT: this is in my case, you have to calculate YOUR total drop
// digital read bits accuracy
uint8_t adcBits = 12;                                               // (bits) of width when measuring the voltage
float maximumWidth = pow(2., (float)adcBits)-1;
// battery calculations
float fromVtoWidth = maximumWidth / BOARD_LIMIT_VOLTAGE;
float maxBatteryLevelDropped = (float)(MAX_BATTERY_VOLTAGE-DIODE_DROP) * totalDrop;
float correctionBattery = BOARD_LIMIT_VOLTAGE/maxBatteryLevelDropped;
int minBatteryLevelThreshold = (float)(MIN_BATTERY_VOLTAGE-DIODE_DROP) * totalDrop / correctionBattery;
