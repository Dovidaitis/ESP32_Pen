#include <Arduino.h>

// GPIO pins for control buttons
#define BTN_BACK_PIN 25
#define BTN_SELECT_PIN 26
#define BTN_UP_PIN 33
#define BTN_DOWN_PIN 32 


// states of button controls
int BTN_BACK;
int BTN_BACK_PREV;
int BTN_SELECT;
int BTN_SELECT_PREV;
int BTN_UP;
int BTN_UP_PREV;
int BTN_DOWN;
int BTN_DOWN_PREV;
unsigned long last_press = 0;
unsigned long btn_wait_time = 100;


void btn_init(){

    pinMode(BTN_BACK_PIN, INPUT_PULLUP);
    pinMode(BTN_SELECT_PIN, INPUT_PULLUP);
    pinMode(BTN_UP_PIN, INPUT_PULLUP);
    pinMode(BTN_DOWN_PIN, INPUT_PULLUP);
}


void btn_check_states(){
    BTN_BACK = digitalRead(BTN_BACK_PIN);
    BTN_SELECT = digitalRead(BTN_SELECT_PIN);
    BTN_UP = digitalRead(BTN_UP_PIN);
    BTN_DOWN = digitalRead(BTN_DOWN_PIN);
}

void update_btn_state(int &prev, int &btn_state, int btn_pin){
    prev = btn_state;
    btn_state = digitalRead(btn_pin);
    if (prev == HIGH && btn_state == LOW && millis() - last_press > btn_wait_time){
        Serial.println(btn_pin);
        last_press = millis();
        btn_state = !btn_state;
    }
}

void update_all_btn_states(){
    update_btn_state(BTN_BACK_PREV, BTN_BACK, BTN_BACK_PIN);
    update_btn_state(BTN_SELECT_PREV, BTN_SELECT, BTN_SELECT_PIN);
    update_btn_state(BTN_UP_PREV, BTN_UP, BTN_UP_PIN);
    update_btn_state(BTN_DOWN_PREV, BTN_DOWN, BTN_DOWN_PIN);
}

void current_btn_state(){
  Serial.print(digitalRead(BTN_BACK_PIN));
  Serial.print(digitalRead(BTN_SELECT_PIN));
  Serial.print(digitalRead(BTN_UP_PIN));
  Serial.println(digitalRead(BTN_DOWN_PIN));
}


