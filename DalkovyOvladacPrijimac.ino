

//#define DEBUG 
//#define DEBUG_JOY

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Servo.h>
#include <printf.h>
#include <EEPROM.h>

//
// =======================================================================================================
// PIN ASSIGNMENTS & GLOBAL VARIABLES
// =======================================================================================================
//

// Radio channels (126 channels are supported)
byte chPointer = 0; // Channel 1 (the first entry of the array) is active by default
const byte NRFchannel[] {1, 2};
String prijato;
boolean intro = true;

RF24 radio(7, 8); // CE, CSN
const byte addresses[][10] = {"VaPet-A", "VaPet-B"};

//Definice pinu
const byte servoRxPin  = 3;
const byte servoRyPin  = 5;
const byte servoLxPin  = 9;
const byte servoLyPin  = 10;
const byte lJoyBtn     = 15;
const byte rJoyBtn     = 14;



//String nazevZarizeni = "IS-1"; // Osetreno na max 8 znaku
byte   urovenBaterie=35;
byte   chybnychPruchodu = 0;
const byte stredovaHodnota=90;

struct Data_Info {
  char nazevZarizeni[9]="";
  byte urovenBaterie = 0;
  byte channel = 1; // the channel number
};

struct Data_Command {
  byte rJoyX;
  byte rJoyY;
  byte lJoyX;
  byte lJoyY;
  byte rJoyBtn;
  byte lJoyBtn;
};

Data_Command  data;
Data_Info     dataInfo;

Servo servoR_X;
Servo servoR_Y;
Servo servoL_X;
Servo servoL_Y;



void setup() {
  servoR_X.attach(servoRxPin);
  servoR_Y.attach(servoRyPin);
  servoL_X.attach(servoLxPin);
  servoL_Y.attach(servoLyPin);

  pinMode(rJoyBtn, OUTPUT);
  pinMode(lJoyBtn, OUTPUT);
  
  digitalWrite(rJoyBtn, HIGH);
  digitalWrite(lJoyBtn, HIGH);
  
  Serial.begin(115200);
  #ifdef DEBUG
    Serial.println("Inicializace ........");
    //Serial.begin(115200);
    printf_begin();
    //serialCommands = false;
    //delay(3000);
  #endif

  setupRadio();

  // All axes to neutral position
  data.rJoyX = stredovaHodnota;
  data.rJoyY = stredovaHodnota;
  data.lJoyX = stredovaHodnota;
  data.lJoyY = stredovaHodnota;
  data.rJoyBtn=0;
  data.lJoyBtn=0;

  //nazevZarizeni.toCharArray(dataInfo.nazevZarizeni, 9);

  if(intro) {
    zobrazIntro();
    intro=false;
  }
}

// =======================================================================================================
// MAIN LOOP
// =======================================================================================================
//

void loop() {
  #ifdef DEBUG
    //Serial.println("loop .....");
  #endif
  
  if (Serial.available() > 0) {
    String prijato = Serial.readString();  
    if(prijato.length() > 0) {
      zpracujPrichoziPrikaz(prijato);
    }
  }
  
  dataInfo.urovenBaterie=15;
  
  prijmiData();
  odesliData();
  writeServos();
  ////checkBattery();
 
}


void zobrazIntro() {
  Serial.println("========================================");
  Serial.println("= Prijimac dalkoveho ovladace by VaPet =");
  Serial.println("========================================");
  Serial.println("Pro vypis hodnot zadejte $$");
}
