#pragma once
#include "globals.h"

void processSpeed()
{
   float stepperSpeed;


   if (incoming <= 65 && incoming >= 55)
   {
      stepperSpeed = 0;
      stepper1.disableOutputs();
      exit;
   }
   else
   {
      if (incoming > 65)
         stepperSpeed = pow(1.12, incoming-60);
         stepper1.enableOutputs();

      if (incoming < 55)
         stepperSpeed = -(pow(1.12, -(incoming-60)));
         stepper1.enableOutputs();
   }
   Serial.print("Stepper Speed: ");
   Serial.println(stepperSpeed);
   stepper1.setSpeed(stepperSpeed);
   ESP_BT.write(stepperSpeed);
}


