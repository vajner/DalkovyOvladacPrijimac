void zpracujPrichoziPrikaz() {
  if(prijato.equals("$$")) {
    zobrazNapovedu();
  }





  
}


void zobrazNapovedu() {
  Serial.print("\n");
  Serial.print("\n");
  Serial.print("$nazevZarizeni:");
  Serial.print("\t");
  Serial.println("\""+nazevZarizeni+"\"");

  Serial.print("$kodovaciKlic:");
  Serial.print("\t");
  String klic = addresses[0];
  Serial.println("\""+klic+"\"");
  Serial.print("\n");
  Serial.print("\n");
  Serial.print("\n");
  Serial.print("\n");
  
  
}
