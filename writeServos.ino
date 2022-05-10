//
// =======================================================================================================
// WRITE SERVO POSITIONS
// =======================================================================================================
//

void writeServos() {

  servoR_X.write(data.rJoyX);
  servoR_Y.write(data.rJoyY);
  servoL_X.write(data.lJoyX);
  servoL_Y.write(data.lJoyY);
  if(rJoyBtn != HIGH && rJoyBtn != HIGH) {
    digitalWrite(rJoyBtn, data.rJoyBtn);
    digitalWrite(lJoyBtn, data.lJoyBtn);
  }
  
  #ifdef DEBUG_JOY
    Serial.print(data.lJoyX);
    Serial.print("\t");
    Serial.print(data.lJoyY);
    Serial.print("\t");
    Serial.print(data.rJoyX);
    Serial.print("\t");
    Serial.print(data.rJoyY);
    Serial.print("\t");
    Serial.print("L-Joy-Btn:" + String(data.lJoyBtn) + "\t");
    Serial.print("R-Joy-Btn:" + String(data.rJoyBtn) + "\t");
    /*Serial.print("Nazev zarizeni-->");
    Serial.print(dataInfo.nazevZarizeni);
    Serial.print("<--  baterie-->");
    Serial.print(dataInfo.urovenBaterie);*/
    Serial.print("Channel:");
    Serial.print(dataInfo.channel);
    Serial.println();
  #endif
  
}
