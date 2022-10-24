
#include "bt.h"


void setup()
{
  Serial.begin(115200);
  ESP_BT.begin("ESP32_Control"); // Name of your Bluetooth interface -> will show up on your phone
  stepper1.setMaxSpeed(1000);
  stepper1.setSpeed(0);
  Serial.println("Stepper Started");
}

void loop()
{

  // -------------------- Receive Bluetooth signal ----------------------
  if (ESP_BT.available()){
    incoming = ESP_BT.read(); // Read what we receive and store in "incoming"
    processSpeed();
  }
  stepper1.runSpeed();
}