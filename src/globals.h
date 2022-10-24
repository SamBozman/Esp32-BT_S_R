#pragma once

#include <Arduino.h>
#include "BluetoothSerial.h" // Bluetooth Serial -> works ONLY on ESP32
#include <AccelStepper.h>

// Motor pin definitions for stepper1:
#define motorPin1 26 // IN1 on the ULN2003 driver
#define motorPin2 25 // IN2 on the ULN2003 driver
#define motorPin3 33 // IN3 on the ULN2003 driver
#define motorPin4 32 // IN4 on the ULN2003 driver

// Define the AccelStepper interface type; 4 wire motor in half step mode:
#define MotorInterfaceType 8

// Initialize with pin sequence IN1-IN3-IN2-IN4
// for using the AccelStepper library with 28BYJ-48 stepper motor:
AccelStepper stepper1 = AccelStepper(MotorInterfaceType, motorPin1, motorPin3, motorPin2, motorPin4);
BluetoothSerial ESP_BT;      // init Class:

float incoming; // variable to store byte received from phone

//function Declarations
void processSpeed(); 