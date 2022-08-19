#include <Arduino.h>
#include <SPI.h>
#include <display.h>

void setup() {
  Serial.begin(921600);
  Serial.println("PenTool Initialization");
  start_tft();
  tft_init_selectors();
}

void loop() {
  delay(200);
  Serial.println("debug");
}