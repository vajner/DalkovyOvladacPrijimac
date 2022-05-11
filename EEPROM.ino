//=============================================================
//       EEPROM
//=============================================================
#define ID_PRIJIMACE     0
#define SIFROVACI_KLIC   1  // "VaPetxxxxx" - MAX 10 znaku
#define NAZEV_VOZIDLA    11 // "Tiger-1xxx"     - MAX 10 znaku
// dalsi volna pozice 21

byte getIdPrijimace() {
  byte value = EEPROM.read(ID_PRIJIMACE);
  if (isnan(value)) {
    value = 1;
    setIdPrijimace(value);
  }
  return value;
}

void setIdPrijimace(byte idPrijimace) {
  EEPROM.write(ID_PRIJIMACE, idPrijimace);
}

String getSSIDRadia() {
  String nazev = TextFromEEPROM(SIFROVACI_KLIC, 10);
  if(nazev.length() == 0) {
    nazev = "Nezadano";
    TextToEEPROM(SIFROVACI_KLIC, 10, nazev);
  }
  return nazev;
}

void setSSIDRadia(String nazev) {
  TextToEEPROM(SIFROVACI_KLIC, 10, nazev);
}

void setNazevZarizeni(String nazev) {
  TextToEEPROM(NAZEV_VOZIDLA, 10, nazev);
}

String getNazevZarizeni() {
  String nazev = TextFromEEPROM(NAZEV_VOZIDLA, 10);
  if(nazev.length() == 0) {
    nazev = "Nezadano";
    TextToEEPROM(NAZEV_VOZIDLA, 10, nazev);
  }
  return nazev;
}

void TextToEEPROM(int adresa, int maxVelikost, String text) {
  for (int i = 0;i < text.length();i++) {
    EEPROM.write(adresa + i, (byte)text[i]);
  }
  for (int i = text.length();i < maxVelikost;i++) {
    EEPROM.write(adresa + i, ' ');
  }  
}

String TextFromEEPROM(int adresa, int maxVelikost) {
  String TextFromEEPROM = "";
  for (int i = 0;i < maxVelikost;i++) {
    char znak = (char)EEPROM.read(adresa + i);
    if (isAlphaNumeric(znak) or znak == '-') {
      TextFromEEPROM = TextFromEEPROM + String(znak);  
    } else {
      //Serial.print("nahrazujeme znak:");
      //Serial.println(znak);
      TextFromEEPROM = TextFromEEPROM + " ";  
    }
    //Serial.println(TextFromEEPROM);
  }
  while (TextFromEEPROM[TextFromEEPROM.length() - 1] == ' ') {  
    TextFromEEPROM = TextFromEEPROM.substring(0,TextFromEEPROM.length() - 1);
  }
  return  TextFromEEPROM;
}
