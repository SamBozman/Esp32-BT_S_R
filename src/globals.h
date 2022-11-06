#pragma once

#include <AccelStepper.h>
#include <Arduino.h>

#include "BluetoothSerial.h"  // Bluetooth Serial -> works ONLY on ESP32

#define Debug 1  // set to 0 if Serial prints not needed

#if Debug == 1
#define debug(x) Serial.print(x)
#define debugln(x) Serial.println(x)
#else
#define debug(x)    // defined to nothing
#define debugln(x)  // defined to nothing
#endif

#define waterPin 2  // Water off-LOW on - HIGH

#define MotorInterfaceType 8
#define home 0            // All steppers homing position is 0
#define maxPosition 2700  // TEMP for testing (needs to be set for each stepper)

// Hall Effect sensor pins
//#define hHomePin 4
//#define vHomePin 16
#define sHomePin 17

AccelStepper Hstepper = AccelStepper(MotorInterfaceType, 26, 33, 25, 32);
AccelStepper Vstepper = AccelStepper(MotorInterfaceType, 13, 14, 12, 27);
AccelStepper Sstepper = AccelStepper(MotorInterfaceType, 5, 19, 18, 21);

BluetoothSerial ESP_BT;  // init Class:
AccelStepper Stepper;  // Declare a variable to hold the current stepper object

// function Declarations
void homeStepper(AccelStepper Stepper, int homePin);
void processIncoming(float incoming);
void processStepper(float incoming);
void doStepLoop();