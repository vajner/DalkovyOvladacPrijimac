//
// =======================================================================================================
// CHECK RX BATTERY & VCC VOLTAGES
// =======================================================================================================
//

boolean battSense;

void checkBattery() {

  /*//if (boardVersion < 1.2) battSense = false;
  //else battSense = true;
  boolean battSense = true;
  // Every 1000 ms, take measurements
  static unsigned long lastTrigger;
  if (millis() - lastTrigger >= 1000) {
    lastTrigger = millis();

    // Read both averaged voltages
    payload.batteryVoltage = batteryAverage();
    payload.vcc = vccAverage();

    if (battSense) { // Observe battery voltage
      if (payload.batteryVoltage <= cutoffVoltage) payload.batteryOk = false;
    }
    else { // Observe vcc voltage
      if (payload.vcc <= cutoffVoltage) payload.batteryOk = false;
    }
  }
}

// Voltage read & averaging subfunctions -----------------------------------------
// vcc ----
float vccAverage() {
  static int raw[6];

  if (raw[0] == 0) {
    for (int i = 0; i <= 5; i++) {
      raw[i] = readVcc(); // Init array
    }
  }

  raw[5] = raw[4];
  raw[4] = raw[3];
  raw[3] = raw[2];
  raw[2] = raw[1];
  raw[1] = raw[0];
  raw[0] = readVcc();
  float average = (raw[0] + raw[1] + raw[2] + raw[3] + raw[4] + raw[5]) / 6000.0;
  return average;
}

// battery ----
float batteryAverage() {
  static int raw[6];

  if (!battSense) return 0;

  if (raw[0] == 0) {
    for (int i = 0; i <= 5; i++) {
      raw[i] = analogRead(BATTERY_DETECT_PIN); // Init array
    }
  }

  raw[5] = raw[4];
  raw[4] = raw[3];
  raw[3] = raw[2];
  raw[2] = raw[1];
  raw[1] = raw[0];
  raw[0] = analogRead(BATTERY_DETECT_PIN); // else take the real voltage (compensates voltage drop while driving)
  float average = (raw[0] + raw[1] + raw[2] + raw[3] + raw[4] + raw[5]) / 619.999; // 1023steps / 9.9V * 6 = 619.999
  return average;*/
}
