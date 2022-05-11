void zpracujPrichoziPrikaz(String prijato) {

  boolean zobrazitIntro = true;

  if(prijato.equals("$$")) {
    zobrazPromenne();
    zobrazitIntro = false;
  }

  int index = prijato.indexOf("=");
  String prikaz = prijato.substring(0, index);

  if(prikaz.equals("$cisloVozidla")) {
    int hodnota = prijato.substring(index+1).toInt();
    if(hodnota >= 0 and hodnota <= 99) {
      setIdPrijimace((byte)hodnota);
      zobrazPromenne();
      zobrazitIntro = false;
    } else {
      Serial.print("\n");
      Serial.print("\n");
      Serial.println("Zadan prikaz:" + prijato);
      Serial.println("Povolene hodnoty pro cislo vozidla jsou 0 - 99");
      Serial.print("\n");
      Serial.print("\n");
      Serial.print("\n");
    }
  }

  if(prikaz.equals("$nazevZarizeni")) {
    String hodnota = prijato.substring(index+1);
    if(hodnota.length() <= 10) {
      setNazevZarizeni(hodnota);
      zobrazPromenne();
      zobrazitIntro = false;
    } else {
      Serial.print("\n");
      Serial.print("\n");
      Serial.println("Zadan prikaz:" + prijato);
      Serial.println("Maximalni delka textu je 10 znaku");
      Serial.print("\n");
      Serial.print("\n");
      Serial.print("\n");
    }
  }
  
  if(prikaz.equals("$kodovaciKlic")) {
    String hodnota = prijato.substring(index+1);
    if(hodnota.length() <= 5) {
      setSSIDRadia(hodnota);
      zobrazPromenne();
      zobrazitIntro = false;
    } else {
      Serial.print("\n");
      Serial.print("\n");
      Serial.println("Zadan prikaz:" + prijato);
      Serial.println("Maximalni delka textu je 5 znaku");
      Serial.print("\n");
      Serial.print("\n");
      Serial.print("\n");
    }
  }
  
  if(zobrazitIntro) {
    zobrazIntro();
  }
}

void zobrazPromenne() {
  Serial.print("\n");
  Serial.print("\n");
  
  Serial.print("$cisloVozidla:");
  Serial.print("\t");
  Serial.println("\"" + String(getIdPrijimace()) + "\"");
  
  Serial.print("$nazevZarizeni:");
  Serial.print("\t");
  Serial.println("\""+ getNazevZarizeni() + "\"");

  Serial.print("$kodovaciKlic:");
  Serial.print("\t");
  Serial.println("\"" + getSSIDRadia() + "\"");
  Serial.print("\n");
  Serial.print("\n");
  
  Serial.print("Adresa kanalu:");
  Serial.print("\t");
  Serial.print("\"");
  Serial.print(getAdresaKanalu());
  Serial.println("\"");
  
  Serial.print("\n");
  Serial.println("Pro nastaveni nove hodnoty pouzijte prikaz \"$nazevPromenne=hodnota\"");
  Serial.print("\n");
}

String getAdresaKanalu() {
  String klic = getSSIDRadia();
  String cisloStanice = String(getIdPrijimace());

  if(cisloStanice.length() == 1) {
    klic = klic.substring(0, 4) + cisloStanice;
  } else {
    klic = klic.substring(0, 3) + cisloStanice;
  }
  return klic;
}
