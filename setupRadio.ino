void setupRadio() {

  #ifdef DEBUG
    Serial.println("Nastavuji radio ....");
  #endif
  radio.begin();
  radio.setChannel(NRFchannel[chPointer]);
  radio.setPALevel(RF24_PA_MIN); // Set Power Amplifier (PA) level to one of four levels: RF24_PA_MIN, RF24_PA_LOW, RF24_PA_HIGH and RF24_PA_MAX
  radio.setDataRate(RF24_250KBPS);
  //radio.openReadingPipe(1, getRadioAdress());
  //radio.openReadingPipe(1, addresses[0]);
  //radio.openReadingPipe(1, addresa);
  
  String adresa = getAdresaKanalu();
  byte adresaKanalu[6] = "";
  adresa.getBytes(adresaKanalu, 6);
  radio.openReadingPipe(1, adresaKanalu);
  radio.enableAckPayload();
  radio.startListening();
  radio.writeAckPayload(1, &dataInfo, sizeof(struct Data_Info));

  #ifdef DEBUG
    Serial.println("setChannel:" + String(NRFchannel[chPointer]));
    Serial.println();
    radio.printDetails();
    delay(5000);
  #endif
  
}
