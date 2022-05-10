void prijmiData() {
  static unsigned long lastRecvTime = 0;
 
  if (radio.available()) {
      radio.read(&data, sizeof(data));
    lastRecvTime = millis();
  }

  // Switch channel
  if (millis() - lastRecvTime > 500) {
    chPointer ++;
    if (chPointer >= sizeof((*NRFchannel) / sizeof(byte))) chPointer = 0;
    radio.setChannel(NRFchannel[chPointer]);
    dataInfo.channel = NRFchannel[chPointer];
  }

  if (millis() - lastRecvTime > 1000) {
    data.rJoyX = stredovaHodnota; 
    data.rJoyY = stredovaHodnota; 
    data.lJoyX = stredovaHodnota; 
    data.lJoyY = stredovaHodnota; 
    //Serial.println(millis() - lastRecvTime);
    #ifdef DEBUG
      Serial.println("Vysilac nedostupny - zkontrolujte vysilac!");
    #endif
  }

  if (millis() - lastRecvTime > 2000) {
    setupRadio(); // re-initialize radio
    lastRecvTime = millis();
  }
}
