#include <Arduino.h>
#include <display.h>
#include <rfid.h>
#include <buttons.h>

boolean update_display = false;
String new_uid = "";

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
  new_uid = scan_rfid(update_display);
  tft_show_rfid(new_uid, update_display);
  // Serial.println("-");
  update_all_btn_states();
}