#pragma once
#include "globals.h"
int stepper;

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