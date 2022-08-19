#include <Arduino.h>
#include <display.h>
#include <rfid.h>
#include <buttons.h>

void setup() {
  Serial.begin(921600);
  Serial.println("PenTool Initialization");
  start_tft();
  btn_init();
  start_rfid();
  tft_init_selectors();
  btn_check_states();
}

void loop() {
  delay(100);
  Serial.println(scan_rfid());
  // Serial.println("-");
  update_all_btn_states();
}