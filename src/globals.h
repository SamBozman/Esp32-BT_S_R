#pragma once

#include <Arduino.h>
#include "BluetoothSerial.h" // Bluetooth Serial -> works ONLY on ESP32
#include <AccelStepper.h>
#define MotorInterfaceType 8

BluetoothSerial ESP_BT; // init Class:
AccelStepper Stepper; //Declare a variable to hold the current stepper object
// function Declarations
void processIncoming(float incoming);