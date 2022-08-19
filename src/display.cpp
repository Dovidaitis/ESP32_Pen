#include <Arduino.h>
#include <TFT_eSPI.h>

TFT_eSPI tft = TFT_eSPI();

void start_tft(){
    tft.init();
    tft.setRotation(1);
    tft.fillScreen(TFT_BLACK);
}

void tft_init_selectors(){
  tft.fillScreen(TFT_BLACK);
  tft.drawString("Back", 2, 2);
  tft.drawString("Select", 2, 112);
  tft.drawString("Up", 140, 2);
  tft.drawString("Down", 130, 112);
  delay(10);
  tft.fillScreen(TFT_BLACK);
  // tft.drawRect(0, 0, 26, 12, TFT_WHITE);
}

void tft_show_rfid(String uid, boolean &update_display){
    if (update_display == true){
        tft.fillScreen(TFT_BLACK);
        tft.drawRect(51, 52, 60, 12, TFT_WHITE); // x pos, y pos, width, height
        tft.drawString(uid, 55, 55);

        update_display = false;
    }
}