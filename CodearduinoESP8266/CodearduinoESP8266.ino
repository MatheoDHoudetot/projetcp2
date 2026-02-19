//bibliothèque pour le donctionnement de l'ESP8266
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <Arduino_JSON.h>

//bibliothèque pour les servo-moteurs
#include <Servo.h>

//bibliothèque pour le pass RFID
#include <SPI.h>
#include <MFRC522.h>

//nom et mot de passe du wifi
const char* ssid     = "valentin";
const char* password = "valentin";

//noms de chaque servo-moteurs 
Servo servo1;
Servo servo2;

//pin pour le lecteur RFID
#define SS_PIN D8
#define RST_PIN D0

MFRC522 rfid(SS_PIN, RST_PIN);

//fonction qui retourne l'UID de la carte scanné
String getUID() {

  // Pas de carte
  if (!rfid.PICC_IsNewCardPresent()) {
    return "";
  }

  // Impossible de lire
  if (!rfid.PICC_ReadCardSerial()) {
    return "";
  }

  String uidString = "";

  for (byte i = 0; i < rfid.uid.size; i++) {
    if (rfid.uid.uidByte[i] < 0x10) {
      uidString += "0";
    }
    uidString += String(rfid.uid.uidByte[i], HEX);
  }

  uidString.toUpperCase();
  rfid.PICC_HaltA();

  return uidString;
}
//fin fonction


void setup() {
  Serial.begin(115200);
  
  //pin de servo-moteurs
  servo1.attach(D1);
  servo1.attach(D2);
  
  //gestion du lecteur RFID
  SPI.begin();
  rfid.PCD_Init();

  //démarrage du wifi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConnecté !");
}

void loop() {

  //variable de données des servo-moteurs
  int VarServo1=0;
  int VarServo2=0;
  servo1.write(0);

  //Identifiant UID
  String uid = getUID();

  //connectivité avec le serveur
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    WiFiClient client;
    
    //envoie de l'UID au serveur si il y a un identifiant détecté
    if (uid != "") {
      String url = "http://172.19.194.155/NSI/projetcp2/receive.php?UIDactif=" + uid;
      http.begin(client, url);
      http.GET();
      http.end();
    
    
      //lire le php
      http.begin(client, "http://172.19.194.155/NSI/projetcp2/get.php");
      int httpCode = http.GET();
  
      if (httpCode > 0) {
        String data = http.getString();
        Serial.println("JSON reçu :");
        Serial.println(data);
  
        // PARSING JSON (découpe le php pour avoir les données dans deux variable compréhensible par arduino)
        JSONVar obj = JSON.parse(data);
  
        if (JSON.typeof(obj) == "undefined") {
          Serial.println("Erreur JSON");
        } else {
          VarServo1 = atoi((const char*) obj["VarServo1"]);
          VarServo2  = atoi((const char*) obj["VarServo2"]);
  
          Serial.print("VarServo1: ");
          Serial.println(VarServo1);
          Serial.print("VarServo2: ");
          Serial.println(VarServo2);
        }
      }
    }

    
    if ( VarServo1==1){
      Serial.print("servo1");
      
      servo1.write(90);
      delay(2000);
      servo1.write(0);
      //modifie les variable 
      http.begin(client, "http://172.19.194.155/NSI/projetcp2/receive.php?VarServo1=0"); 
      http.GET();
    }


   if ( VarServo2==1){
      Serial.print("servo2");
      
      delay(2000);
      //modifie les variable 
      http.begin(client, "http://172.19.194.155/NSI/projetcp2/receive.php?VarServo2=0"); 
      http.GET();
    }

    
    http.end();
  }


}

