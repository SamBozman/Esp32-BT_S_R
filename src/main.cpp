
#include "functions.h"

void setup()
{
  Serial.begin(115200);
  ESP_BT.begin("ESP32_Control"); // Name of your Bluetooth interface -> will show up on your phone
  debugln("Stepper Setup");
  //homeStepper(Hstepper, hHomePin);
  //homeStepper(Vstepper, vHomePin);
  homeStepper(Sstepper, sHomePin);
 
  // Shutoff water
  // Set homing for each stepper
  // TODO start a timer to shut down steppers after a specific time period.
}

void loop()
{

  // -------------------- Receive Bluetooth signal ----------------------
  if (ESP_BT.available())
  {
    float incoming = ESP_BT.read(); // variable to store byte received from phone
    processIncoming(incoming);
  }
  Stepper.runSpeed();
}