/**
 * @file Config.h
 * @author @sebastiano123-c
 * @brief Configuration file.
 * @note * = not available at the moment
 * @version 0.1
 * @date 2022-02-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */


// MICROCONTROLLER BOARD
#define PINMAP                      ESP32                    // (OFF*, ATMEGA32*, ESP32) OFF if the board is Arduino Uno (directly write pin)


// DEBUG MODE
#define DEBUG                       false                    // (true, false) true enable serial prints for debugging


// SKETCH CONSTANTS
#define BAUD_RATE                   115200                   // (9600, 57600, 115200)
#define WIRE_CLOCK                  400000L                  // (100000L, 400000L) 400000L is suggested
#define EEPROM_SIZE                 36                       // eeprom allocatable memory


// AUTO LEVElING
#define AUTO_LEVELING               true                     // (true, false) false disable every autoleveling compensation


// BATTERY
#define MAX_BATTERY_VOLTAGE         11100                    // (mV) battery nominal maximum voltage (use ONLY 11.1V batteries)
#define MIN_BATTERY_VOLTAGE         4000                     // (mV) battery level above which it is dangerous to use


// WIFI
#define WIFI_TELEMETRY              ESP_CAM                  // (NATIVE, ESP_CAM*) 


// SENSORS
#define GYROSCOPE                   MPU6050                  // (MPU6050) unique for now
#define ALTITUDE_SENSOR             BMP280                   // (OFF, BMP280, BME280*)
#define PROXIMITYSENSOR             OFF                      // (OFF, HCSR04*)
#define DANGER_DISTANCE             40                       // (cm) Proximity sensor distance above which is considered a danger zone
