
#include "bt.h"

void setup()
{
  Serial.begin(115200);
  ESP_BT.begin("ESP32_Control"); // Name of your Bluetooth interface -> will show up on your phone
  Serial.println("Stepper Started");
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