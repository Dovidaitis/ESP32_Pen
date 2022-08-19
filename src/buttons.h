#define BTN_BACK_PIN
#define BTN_SELECT_PIN 
#define BTN_UP_PIN
#define BTN_DOWN_PIN

extern int BTN_BACK;
extern int BTN_BACK_PREV;
extern int BTN_SELECT;
extern int BTN_SELECT_PREV;
extern int BTN_UP;
extern int BTN_UP_PREV;
extern int BTN_DOWN;
extern int BTN_DOWN_PREV;
extern unsigned long last_press;
extern unsigned long btn_wait_time;

void btn_check_states();
void btn_init();
void update_btn_state(int &prev, int &btn_state, int btn_pin);
void update_all_btn_states();
void current_btn_state();
