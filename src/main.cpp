#include <Arduino.h>
#include <display.h>
#include <rfid.h>

void setup() {
  Serial.begin(921600);
  Serial.println("PenTool Initialization");
  start_tft();
  start_rfid();
  tft_init_selectors();
}

void loop() {
  delay(200);
  Serial.println(scan_rfid());
  Serial.println("debug");
  
}