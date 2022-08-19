#include <MFRC522.h>
#include <SPI.h>

// GPIO pins for RFID
#define SS_PIN 5
#define RST_PIN 27

// creating RFID instance
MFRC522 rfid(SS_PIN, RST_PIN);

String uid = "";


void start_rfid(){
  SPI.begin();
  rfid.PCD_Init();
}

String scan_rfid(boolean &update_display){
 
  // Look for new cards
  if ( ! rfid.PICC_IsNewCardPresent()){
    return "";
  }
  // Select one of the cards
  if ( ! rfid.PICC_ReadCardSerial()){
    return "";
  }

  uid = "";
  byte letter;
  for (byte i = 0; i < rfid.uid.size; i++) 
  {
     uid.concat(String(rfid.uid.uidByte[i] < 0x10 ? "0" : ""));
     uid.concat(String(rfid.uid.uidByte[i], HEX));
  }
  update_display  = true;
  return uid;
}