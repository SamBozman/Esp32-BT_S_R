
#include "setup.h"

void loop() {
  // -------------------- Receive Bluetooth signal ----------------------
  if (ESP_BT.available()) {
    float incoming =
        ESP_BT.read();  // variable to store byte received from phone
    processIncoming(incoming);
  }

  doStepLoop();
}