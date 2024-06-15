#include QMK_KEYBOARD_H
#include "keymap_uk.h"

enum Layers {
    LAYER_BASE,
    LAYER_NUMPAD,
    LAYER_GAME,
    LAYER_LOWER,
    LAYER_UPPER,
    LAYER_ADJUST,
    LAYER_STATUS
};

#define KC_TGNU TG(LAYER_NUMPAD)
#define KC_TGGA TG(LAYER_GAME)
#define KC_MOST MO(LAYER_STATUS)
#define LED1 B5
#define LED2 B7
#define LED3 D5
#define LED_BLINK_DURATION 1000

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [LAYER_BASE] = LAYOUT_split(
        KC_ESC  , KC_F4   , KC_L    , KC_D    , KC_W    , KC_Q              ,           KC_QUOT , KC_F    , KC_O    , KC_U    , KC_PSCR , KC_BSPC , KC_INS  , KC_HOME , KC_PGUP ,
        KC_TAB  , KC_B    , KC_R    , KC_T    , KC_S    , KC_G              ,           KC_Y    , KC_H    , KC_A    , KC_E    , KC_J    , KC_ENT  , KC_DEL  , KC_END  , KC_PGDN ,
        KC_LSFT , KC_N    , KC_X    , KC_M    , KC_C    , KC_V              ,           KC_K    , KC_P    , KC_COMM , KC_DOT  , KC_I    , KC_RSFT           , KC_UP   ,
        KC_LCTL , KC_Z    ,                     KC_LALT , KC_BSPC , TL_LOWR , TL_UPPR , KC_SPC  , KC_RGUI                     , KC_SLSH , KC_RCTL , KC_LEFT , KC_DOWN , KC_RGHT
    ),
    [LAYER_NUMPAD] = LAYOUT_split(
        _______ , _______ , _______ , _______ , _______ , _______           ,           KC_PSLS , KC_P7   , KC_P8   , KC_P9   , KC_PMNS , _______ , _______ , _______ , _______ ,
        _______ , _______ , _______ , _______ , _______ , _______           ,           KC_PAST , KC_P4   , KC_P5   , KC_P6   , KC_PPLS , KC_PENT , _______ , _______ , _______ ,
        _______ , _______ , _______ , _______ , _______ , _______           ,           KC_NO   , KC_P1   , KC_P2   , KC_P3   , KC_P0   , _______           , _______ ,
        _______ , _______ ,                     _______ , _______ , _______ , _______ , _______ , _______                     , KC_PDOT , _______ , _______ , _______ , _______
    ),
    [LAYER_GAME] = LAYOUT_split(
        _______ , _______ , _______ , _______ , _______ , _______           ,           KC_R    , KC_E    , KC_X    , KC_Q    , KC_ESC  , _______ , _______ , _______ , _______ ,
        _______ , _______ , _______ , _______ , _______ , _______           ,           KC_F    , KC_A    , KC_W    , KC_D    , KC_TAB  , _______ , _______ , _______ , _______ ,
        _______ , _______ , _______ , _______ , _______ , _______           ,           KC_V    , KC_C    , KC_S    , KC_Z    , KC_LSFT , KC_LALT           , _______ ,
        _______ , _______ ,                     _______ , _______ , _______ , _______ , _______ , _______                     , KC_LCTL , UK_BSLS , _______ , _______ , _______
    ),
    [LAYER_LOWER] = LAYOUT_split(
        KC_VOLD , KC_VOLU , UK_HASH , KC_QUOT , KC_SCLN , KC_MOST           ,           KC_NUM  , KC_AMPR , KC_ASTR , KC_LPRN , KC_NO   , _______ , _______ , _______ , _______ ,
        _______ , KC_GRV  , KC_LPRN , KC_RPRN , KC_MINS , KC_MOST           ,           KC_CAPS , KC_DLR  , KC_PERC , KC_CIRC , KC_RPRN , _______ , _______ , _______ , _______ ,
        _______ , KC_EQL  , KC_LCBR , KC_RCBR , KC_NO   , KC_MOST           ,           KC_SCRL , KC_EXLM , UK_DQUO , UK_PND  , KC_NO   , _______           , _______ ,
        _______ , UK_BSLS ,                     _______ , _______ , _______ , _______ , _______ , _______                     , KC_NO   , _______ , _______ , _______ , _______
    ),
    [LAYER_UPPER] = LAYOUT_split(
        KC_VOLD , KC_VOLU , UK_TILD , UK_AT   , KC_COLN , KC_MOST           ,           KC_NUM  , KC_7    , KC_8    , KC_9    , KC_MINS , KC_TGNU , _______ , _______ , _______ ,
        _______ , UK_NOT  , KC_LBRC , KC_RBRC , KC_UNDS , KC_MOST           ,           KC_CAPS , KC_4    , KC_5    , KC_6    , KC_PLUS , KC_PENT , _______ , _______ , _______ ,
        _______ , KC_PLUS , KC_LCBR , KC_RCBR , KC_NO   , KC_MOST           ,           KC_SCRL , KC_1    , KC_2    , KC_3    , KC_0    , _______           , _______ ,
        _______ , UK_PIPE ,                     _______ , _______ , _______ , _______ , _______ , _______                     , KC_DOT  , _______ , _______ , _______ , _______
    ),
    [LAYER_ADJUST] = LAYOUT_split(
        KC_TGGA , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_MOST           ,           KC_NUM  , KC_F9   , KC_F10  , KC_F11  , KC_F12  , _______ , _______ , _______ , _______ ,
        _______ , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_MOST           ,           KC_CAPS , KC_F5   , KC_F6   , KC_F7   , KC_F8   , _______ , _______ , _______ , _______ ,
        _______ , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_MOST           ,           KC_SCRL , KC_F1   , KC_F2   , KC_F3   , KC_F4   , _______           , _______ ,
        _______ , KC_NO   ,                     _______ , _______ , _______ , _______ , _______ , _______                     , KC_NO   , _______ , _______ , _______ , _______
    ),
    [LAYER_STATUS] = LAYOUT_split(
        KC_TGGA , _______ , _______ , _______ , _______ , KC_MOST           ,           _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
        _______ , _______ , _______ , _______ , _______ , KC_MOST           ,           _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
        _______ , _______ , _______ , _______ , _______ , KC_MOST           ,           _______ , _______ , _______ , _______ , _______ , _______           , _______ ,
        _______ , _______ ,                     _______ , _______ , _______ , _______ , _______ , _______                     , _______ , _______ , _______ , _______ , _______
    )
};

bool g_blink_leds;
led_t g_led_state;
layer_state_t g_layer_state;

void update_leds(void) {
    if (g_blink_leds) {
        writePinHigh(LED1);
        writePinHigh(LED2);
        writePinHigh(LED3);
    } else {
        if (IS_LAYER_ON_STATE(layer_state, LAYER_STATUS)) {
            writePin(LED1, g_led_state.num_lock);
            writePin(LED2, g_led_state.caps_lock);
            writePin(LED3, g_led_state.scroll_lock);
        } else {
            writePin(LED1, IS_LAYER_ON_STATE(g_layer_state, LAYER_LOWER) || IS_LAYER_ON_STATE(g_layer_state, LAYER_ADJUST));
            writePin(LED2, IS_LAYER_ON_STATE(g_layer_state, LAYER_NUMPAD) || IS_LAYER_ON_STATE(g_layer_state, LAYER_UPPER) || IS_LAYER_ON_STATE(g_layer_state, LAYER_ADJUST));
            writePin(LED3, IS_LAYER_ON_STATE(g_layer_state, LAYER_GAME));
        }
    }
}

uint32_t after_led_blink(uint32_t trigger_time, void * args) {
    g_blink_leds = false;
    update_leds();
    return 0u;
}

void keyboard_post_init_user(void) {
    g_blink_leds = true;
    update_leds();
    defer_exec(LED_BLINK_DURATION, after_led_blink, NULL);
}

bool led_update_user(led_t led_state) {
    g_led_state = led_state;
    update_leds();
    return true;
}

layer_state_t layer_state_set_user(layer_state_t layer_state) {
    g_layer_state = layer_state;
    update_leds();
    return layer_state;
}
