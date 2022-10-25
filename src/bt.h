#pragma once
#include "globals.h"

void processIncoming(float incoming)
{
   float stepperSpeed;
   
   Stepper = AccelStepper(MotorInterfaceType, 26, 33, 25, 32);
   Stepper.setMaxSpeed(1000);

   if (incoming <= 65 && incoming >= 55)
   {
      stepperSpeed = 0;
      ESP_BT.write(stepperSpeed);
      Stepper.disableOutputs();
      exit;
   }
   else
   {
      if (incoming > 65)
      {
         stepperSpeed = pow(1.12, incoming - 60);
         ESP_BT.write(stepperSpeed);
         Stepper.enableOutputs();
      }

      if (incoming < 55)
      {
         stepperSpeed = -(pow(1.12, -(incoming - 60)));
         ESP_BT.write(-stepperSpeed);
         Stepper.enableOutputs();
      }
   }

   Serial.print("Stepper Speed: ");
   Serial.println(stepperSpeed);
   Stepper.setSpeed(stepperSpeed);
}
