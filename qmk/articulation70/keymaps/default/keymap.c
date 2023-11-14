#include QMK_KEYBOARD_H
#include "keymap_uk.h"

enum Layers {
    LAYER_BASE,
    LAYER_GAME,
    LAYER_LOWER,
    LAYER_UPPER,
    LAYER_ADJUST,
    LAYER_STATUS
};

#define KC_TGGA TG(LAYER_GAME)
#define KC_MOST MO(LAYER_STATUS)
#define LED1 B5
#define LED2 B7
#define LED3 D5

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [LAYER_BASE] = LAYOUT_split(
        KC_ESC  , KC_F4   , KC_W    , KC_F    , KC_P    , KC_B              ,           KC_J    , KC_L    , KC_U    , KC_Y    , KC_PSCR , KC_BSPC , KC_INS  , KC_HOME , KC_PGUP ,
        KC_TAB  , KC_Q    , KC_R    , KC_S    , KC_T    , KC_G              ,           KC_M    , KC_N    , KC_E    , KC_I    , KC_SCLN , KC_ENT  , KC_DEL  , KC_END  , KC_PGDN ,
        KC_LSFT , KC_A    , KC_X    , KC_C    , KC_D    , KC_V              ,           KC_K    , KC_H    , KC_COMM , KC_DOT  , KC_O    , KC_RSFT           , KC_UP   ,
        KC_LCTL , KC_Z    ,                     TL_LOWR , KC_BSPC , KC_LALT , KC_RGUI , KC_SPC  , TL_UPPR                     , KC_SLSH , KC_RCTL , KC_LEFT , KC_DOWN , KC_RGHT
    ),
    [LAYER_GAME] = LAYOUT_split(
        _______ , _______ , _______ , _______ , _______ , _______           ,           KC_R    , KC_E    , KC_X    , KC_Q    , KC_ESC  , _______ , _______ , _______ , _______ ,
        _______ , _______ , _______ , _______ , _______ , _______           ,           KC_F    , KC_A    , KC_W    , KC_D    , KC_TAB  , _______ , _______ , _______ , _______ ,
        _______ , _______ , _______ , _______ , _______ , _______           ,           KC_V    , KC_C    , KC_S    , KC_Z    , KC_LSFT , KC_LALT           , _______ ,
        _______ , _______ ,                     _______ , _______ , _______ , _______ , _______ , _______                     , KC_LCTL , UK_BSLS , _______ , _______ , _______
    ),
    [LAYER_LOWER] = LAYOUT_split(
        KC_VOLD , KC_VOLU , UK_HASH , KC_QUOT , KC_SCLN , KC_NO             ,           KC_NO   , KC_AMPR , KC_ASTR , KC_LPRN , KC_NO   , _______ , _______ , _______ , _______ ,
        _______ , KC_GRV  , KC_LPRN , KC_RPRN , KC_MINS , KC_NO             ,           KC_NO   , KC_DLR  , KC_PERC , KC_CIRC , KC_RPRN , _______ , _______ , _______ , _______ ,
        _______ , KC_EQL  , KC_LCBR , KC_RCBR , KC_NO   , KC_NO             ,           KC_NO   , KC_EXLM , UK_DQUO , UK_PND  , KC_NO   , _______           , _______ ,
        _______ , UK_BSLS ,                     _______ , _______ , _______ , _______ , _______ , _______                     , KC_NO   , _______ , _______ , _______ , _______
    ),
    [LAYER_UPPER] = LAYOUT_split(
        KC_VOLD , KC_VOLU , UK_TILD , UK_AT   , KC_COLN , KC_NO             ,           KC_NUM  , KC_P7   , KC_P8   , KC_P9   , KC_PMNS , _______ , _______ , _______ , _______ ,
        _______ , UK_NOT  , KC_LBRC , KC_RBRC , KC_UNDS , KC_NO             ,           KC_CAPS , KC_P4   , KC_P5   , KC_P6   , KC_PPLS , KC_PENT , _______ , _______ , _______ ,
        _______ , KC_PLUS , KC_LCBR , KC_RCBR , KC_NO   , KC_NO             ,           KC_SCRL , KC_P1   , KC_P2   , KC_P3   , KC_P0   , _______           , _______ ,
        _______ , UK_PIPE ,                     _______ , _______ , _______ , _______ , _______ , _______                     , KC_PDOT , _______ , _______ , _______ , _______
    ),
    [LAYER_ADJUST] = LAYOUT_split(
        KC_TGGA , KC_MOST , KC_NO   , KC_NO   , KC_NO   , KC_NO             ,           KC_NO   , KC_F9   , KC_F10  , KC_F11  , KC_F12  , _______ , _______ , _______ , _______ ,
        _______ , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO             ,           KC_NO   , KC_F5   , KC_F6   , KC_F7   , KC_F8   , _______ , _______ , _______ , _______ ,
        _______ , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO             ,           KC_NO   , KC_F1   , KC_F2   , KC_F3   , KC_F4   , _______           , _______ ,
        _______ , KC_NO   ,                     _______ , _______ , _______ , _______ , _______ , _______                     , KC_NO   , _______ , _______ , _______ , _______
    ),
    [LAYER_STATUS] = LAYOUT_split(
        KC_TGGA , KC_MOST , _______ , _______ , _______ , _______           ,           _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
        _______ , _______ , _______ , _______ , _______ , _______           ,           _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
        _______ , _______ , _______ , _______ , _______ , _______           ,           _______ , _______ , _______ , _______ , _______ , _______           , _______ ,
        _______ , _______ ,                     _______ , _______ , _______ , _______ , _______ , _______                     , _______ , _______ , _______ , _______ , _______
    )
}; 

led_t g_led_state;
layer_state_t g_layer_state;

void update_leds(void) {
    writePin(LED1, g_led_state.num_lock);
    writePin(LED2, g_led_state.caps_lock);
    writePin(LED3, g_led_state.scroll_lock);
}

bool led_update_user(led_t led_state) {
    g_led_state = led_state;
    if (IS_LAYER_ON_STATE(layer_state, LAYER_STATUS))
        update_leds();
    return true;
}

layer_state_t layer_state_set_user(layer_state_t layer_state) {
    g_layer_state = layer_state;
    if (IS_LAYER_ON_STATE(layer_state, LAYER_STATUS))
        update_leds();
    else {
        writePin(LED1, IS_LAYER_ON_STATE(layer_state, LAYER_LOWER) || IS_LAYER_ON_STATE(layer_state, LAYER_ADJUST));
        writePin(LED2, IS_LAYER_ON_STATE(layer_state, LAYER_UPPER) || IS_LAYER_ON_STATE(layer_state, LAYER_ADJUST));
        writePin(LED3, IS_LAYER_ON_STATE(layer_state, LAYER_GAME));
    }
    return layer_state;
}
