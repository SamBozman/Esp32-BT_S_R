#pragma once
#include "globals.h"
// int stepper; ??

void homeStepper(AccelStepper Stepper, int homePin)
{
   int move_finished = 1;    // Used to check if move is completed
   long initial_homing = -1; // Used to Home Stepper at startup
   pinMode(homePin, INPUT_PULLUP);
   Stepper.setMaxSpeed(100);
   Stepper.setAcceleration(100.0);

   Serial.print("Stepper is Homing ");
   Serial.print("Micro Switch is: ");
   Serial.println(digitalRead(homePin));

   while (digitalRead(homePin)) // Do WHILE switch not activated (NOT true)
   {
      Serial.print("Micro Switch is: ");
      Serial.println(digitalRead(homePin)); // Make the Stepper move CCW until the switch is activated
      Stepper.moveTo(initial_homing);       // Set the position to move to
      initial_homing--;                     // Decrease by 1 for next move if needed
      Stepper.run();                        // Start moving the stepper
      delay(5);
   }

   Stepper.setCurrentPosition(0);  // Set the current position as zero for now
   Stepper.setMaxSpeed(100.0);     // Set Max Speed of Stepper (Slower to get better accuracy)
   Stepper.setAcceleration(100.0); // Set Acceleration of Stepper
   initial_homing = 1;

   while (!digitalRead(homePin))
   { // Make the Stepper move CW until the switch is deactivated
      Stepper.moveTo(initial_homing);
      Stepper.run();
      initial_homing++;
      delay(5);
   }

   Stepper.setCurrentPosition(0);
   Serial.println("Homing Completed");
   Serial.println("");
}

void processIncoming(float incoming)
{
   int result = (int)floorf(incoming);
   switch (result)
   {
   case 201:
      Stepper = Hstepper;
      ESP_BT.write(result); // Call back to app
      debugln("Sending 201");
      break;
   case 202:
      Stepper = Vstepper;
      ESP_BT.write(result); // Call back to app
      debugln("Sending 202");
      break;
   case 203:
      Stepper = Sstepper;
      ESP_BT.write(result); // Call back to app
      debugln("Sending 203");
      break;

   default:
      processStepper(incoming);
      break;
   }
}

void processStepper(float incoming)
{
   float stepperSpeed;

   if (incoming <= 65 && incoming >= 55)
   {
      stepperSpeed = 0;
      ESP_BT.write(stepperSpeed);
      exit;
   }
   else
   {
      if (incoming > 65)
      {
         stepperSpeed = pow(1.12, incoming - 60);
         ESP_BT.write(stepperSpeed);
      }

      if (incoming < 55)
      {
         stepperSpeed = -(pow(1.12, -(incoming - 60)));
         ESP_BT.write(-stepperSpeed);
      }
   }

   debug("Stepper Speed: ");
   debugln(stepperSpeed);
   Stepper.setSpeed(stepperSpeed);
}