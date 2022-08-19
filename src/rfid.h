#include <Arduino.h>

#define SS_PIN
#define RST_PIN
#define rfid


void start_rfid();
String scan_rfid(boolean &update_display);