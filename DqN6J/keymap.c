#include QMK_KEYBOARD_H
#include "version.h"
#include "i18n.h"
#define MOON_LED_LEVEL LED_LEVEL
#define ML_SAFE_RANGE SAFE_RANGE

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
  MAC_MISSION_CONTROL,
};



enum tap_dance_codes {
  DANCE_0,
  DANCE_1,
  DANCE_2,
  DANCE_3,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_voyager(
    MT(MOD_LSFT | MOD_LGUI, KC_EQUAL),KC_1,           KC_2,           KC_3,           KC_4,           KC_5,                                           TO(2),          KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_MINUS,       
    MT(MOD_LCTL | MOD_LGUI, KC_TAB),KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,                                           KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           MT(MOD_RCTL | MOD_RGUI, KC_BSLS),
    LT(2,KC_ESCAPE),MT(MOD_LGUI, KC_A),MT(MOD_LSFT, KC_S),MT(MOD_LALT, KC_D),MT(MOD_LCTL, KC_F),KC_G,                                           KC_H,           MT(MOD_RCTL, KC_J),MT(MOD_RALT, KC_K),MT(MOD_RSFT, KC_L),MT(MOD_RGUI, KC_SCLN),LT(6,KC_QUOTE), 
    TT(1),          MEH_T(KC_Z),    KC_X,           KC_C,           KC_V,           KC_B,                                           KC_N,           KC_M,           TD(DANCE_1),    KC_DOT,         KC_SLASH,       MT(MOD_RCTL, KC_ENTER),
                                                    LT(3,KC_BSPC),  TD(DANCE_0),                                    MT(MOD_RSFT, KC_SPACE),ALL_T(KC_ENTER)
  ),
  [1] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_MINUS,       
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 LGUI(LSFT(KC_Z)),LGUI(KC_Z),     KC_UP,          LGUI(KC_C),     LGUI(KC_V),     KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_LEFT_GUI,    KC_LEFT_SHIFT,  KC_LEFT_ALT,    KC_LEFT_CTRL,   KC_BSPC,                                        LGUI(KC_A),     KC_LEFT,        KC_DOWN,        KC_RIGHT,       LGUI(KC_X),     KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, CW_TOGG,        KC_TRANSPARENT, TO(3),                                          CM_ON,          KC_TRANSPARENT, LCTL(LSFT(KC_TAB)),LCTL(KC_TAB),   KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [2] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_1,           KC_2,           KC_3,           KC_4,           KC_5,                                           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_MINUS,       
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, LGUI(LCTL(KC_SPACE)),KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, RALT(RGUI(RCTL(RSFT(KC_W)))),KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, RALT(RGUI(RCTL(RSFT(KC_S)))),RALT(RGUI(RCTL(RSFT(KC_D)))),LGUI(KC_SPACE), RALT(RGUI(RCTL(RSFT(KC_G)))),                                KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    TO(0),          KC_TRANSPARENT, KC_TRANSPARENT, RALT(RGUI(RCTL(RSFT(KC_C)))),RALT(RGUI(RCTL(RSFT(KC_Q)))),KC_TRANSPARENT,                                 RALT(RGUI(RCTL(RSFT(KC_N)))),LALT(LGUI(LCTL(LSFT(KC_M)))),KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, TO(0)
  ),
  [3] = LAYOUT_voyager(
    KC_ESCAPE,      KC_EXLM,        KC_AT,          KC_HASH,        KC_DLR,         KC_PERC,                                        KC_TRANSPARENT, KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_BSPC,        
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_GRAVE,       KC_LCBR,        KC_RCBR,                                        KC_KP_7,        KC_KP_8,        KC_KP_9,        KC_SLASH,       KC_MINUS,       KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_CIRC,        KC_LPRN,        KC_RPRN,                                        KC_KP_4,        TD(DANCE_2),    KC_KP_6,        KC_ASTR,        KC_PLUS,        KC_TRANSPARENT, 
    TO(0),          KC_TRANSPARENT, KC_TRANSPARENT, KC_AMPR,        KC_LBRC,        KC_RBRC,                                        KC_KP_1,        KC_KP_2,        KC_KP_3,        KC_DOT,         KC_EQUAL,       KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, TD(DANCE_3)
  ),
  [4] = LAYOUT_voyager(
    KC_NO,          KC_NO,          KC_NO,          QK_DYNAMIC_TAPPING_TERM_DOWN,QK_DYNAMIC_TAPPING_TERM_UP,QK_DYNAMIC_TAPPING_TERM_PRINT,                                KC_AUDIO_VOL_UP,KC_MEDIA_PREV_TRACK,KC_MEDIA_PLAY_PAUSE,KC_MEDIA_NEXT_TRACK,KC_NO,          TO(0),          
    RGB_VAI,        RGB_TOG,        RGB_SLD,        RGB_MODE_FORWARD,RGB_SPD,        RGB_SPI,                                        KC_AUDIO_VOL_DOWN,KC_NO,          KC_UP,          KC_NO,          KC_NO,          KC_NO,          
    RGB_VAD,        TOGGLE_LAYER_COLOR,RGB_SAD,        RGB_SAI,        RGB_HUD,        RGB_HUI,                                        KC_AUDIO_MUTE,  KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_NO,          KC_NO,          
    TO(0),          KC_NO,          KC_NO,          CM_TOGG,        KC_BRIGHTNESS_DOWN,KC_BRIGHTNESS_UP,                                KC_APPLICATION, MAC_MISSION_CONTROL,LGUI(KC_COMMA), KC_NO,          KC_NO,          KC_NO,          
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [5] = LAYOUT_voyager(
    KC_NO,          KC_NO,          LALT(LCTL(KC_LBRC)),KC_NO,          LALT(LCTL(KC_RBRC)),KC_NO,                                          KC_NO,          LALT(LCTL(KC_LBRC)),KC_NO,          LALT(LCTL(KC_RBRC)),KC_NO,          TO(0),          
    KC_NO,          KC_NO,          LALT(LCTL(KC_KP_7)),LALT(LCTL(KC_KP_8)),LALT(LCTL(KC_KP_9)),KC_NO,                                          KC_NO,          LALT(LCTL(KC_KP_7)),LALT(LCTL(KC_KP_8)),LALT(LCTL(KC_KP_9)),KC_NO,          KC_NO,          
    KC_NO,          KC_NO,          LALT(LCTL(KC_4)),LALT(LCTL(KC_KP_5)),LALT(LCTL(KC_6)),KC_NO,                                          KC_NO,          LALT(LCTL(KC_4)),LALT(LCTL(KC_KP_5)),LALT(LCTL(KC_6)),KC_NO,          KC_NO,          
    TO(0),          KC_NO,          LALT(LCTL(KC_KP_1)),LALT(LCTL(KC_KP_2)),LALT(LCTL(KC_KP_3)),KC_NO,                                          KC_NO,          LALT(LCTL(KC_KP_1)),LALT(LCTL(KC_KP_2)),LALT(LCTL(KC_KP_3)),KC_NO,          LALT(LCTL(KC_ENTER)),
                                                    LALT(LCTL(KC_DOWN)),LALT(LCTL(US_UNDS)),                                LALT(LCTL(US_PLUS)),KC_TRANSPARENT
  ),
  [6] = LAYOUT_voyager(
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          RALT(RCTL(RSFT(KC_G))),                                RALT(RCTL(RSFT(KC_H))),KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
};

const uint16_t PROGMEM combo0[] = { KC_MINUS, KC_0, COMBO_END};
const uint16_t PROGMEM combo1[] = { KC_BSPC, KC_RIGHT, COMBO_END};
const uint16_t PROGMEM combo2[] = { KC_MINUS, KC_0, COMBO_END};
const uint16_t PROGMEM combo3[] = { MT(MOD_LSFT | MOD_LGUI, KC_EQUAL), KC_1, COMBO_END};
const uint16_t PROGMEM combo4[] = { MT(MOD_LSFT | MOD_LGUI, KC_EQUAL), KC_2, COMBO_END};
const uint16_t PROGMEM combo5[] = { MT(MOD_LSFT | MOD_LGUI, KC_EQUAL), KC_3, COMBO_END};
const uint16_t PROGMEM combo6[] = { MT(MOD_LSFT | MOD_LGUI, KC_EQUAL), KC_M, COMBO_END};
const uint16_t PROGMEM combo7[] = { KC_V, KC_B, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo0, TO(0)),
    COMBO(combo1, TO(0)),
    COMBO(combo2, TO(0)),
    COMBO(combo3, TO(1)),
    COMBO(combo4, TO(2)),
    COMBO(combo5, TO(3)),
    COMBO(combo6, TO(4)),
    COMBO(combo7, TO(5)),
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MT(MOD_RCTL | MOD_RGUI, KC_BSLS):
            return g_tapping_term + 50;
        case TD(DANCE_1):
            return g_tapping_term + 50;
        default:
            return g_tapping_term;
    }
}

extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void)
{
    rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [0] = { {161,255,255}, {161,255,255}, {161,255,255}, {161,255,255}, {161,255,255}, {161,255,255}, {110,255,160}, {15,255,255}, {15,255,255}, {15,255,255}, {15,255,255}, {15,255,255}, {110,255,160}, {236,255,255}, {236,255,255}, {236,255,255}, {236,255,255}, {15,255,255}, {110,255,160}, {236,255,255}, {15,255,255}, {15,255,255}, {15,255,255}, {15,255,255}, {110,250,255}, {0,255,219}, {29,255,255}, {89,255,255}, {89,255,255}, {89,255,255}, {89,255,255}, {161,255,255}, {15,255,255}, {15,255,255}, {15,255,255}, {15,255,255}, {15,255,255}, {110,255,160}, {15,255,255}, {236,255,255}, {236,255,255}, {236,255,255}, {236,255,255}, {110,255,160}, {15,255,255}, {15,255,255}, {17,207,172}, {17,207,172}, {17,207,172}, {110,255,160}, {0,255,219}, {110,250,255} },

    [1] = { {161,255,255}, {161,255,255}, {161,255,255}, {161,255,255}, {161,255,255}, {161,255,255}, {110,255,160}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {110,255,160}, {236,255,255}, {236,255,255}, {236,255,255}, {236,255,255}, {0,255,255}, {110,255,160}, {236,255,255}, {0,0,0}, {141,231,163}, {0,0,0}, {18,222,255}, {110,250,255}, {0,255,255}, {161,255,255}, {161,255,255}, {161,255,255}, {161,255,255}, {161,255,255}, {161,255,255}, {203,255,255}, {203,255,255}, {89,255,255}, {203,255,255}, {203,255,255}, {110,255,160}, {187,255,255}, {89,255,255}, {89,255,255}, {89,255,255}, {203,255,255}, {110,255,160}, {41,112,132}, {0,0,0}, {187,255,255}, {187,255,255}, {110,255,160}, {110,255,160}, {0,255,255}, {110,250,255} },

    [2] = { {161,255,255}, {161,255,255}, {161,255,255}, {161,255,255}, {161,255,255}, {161,255,255}, {110,255,160}, {0,0,0}, {0,0,0}, {81,255,177}, {0,0,0}, {0,0,0}, {110,255,160}, {0,0,0}, {188,186,204}, {188,186,204}, {108,255,255}, {156,217,143}, {110,255,160}, {236,255,255}, {0,0,0}, {32,244,119}, {9,255,199}, {0,0,0}, {186,255,255}, {0,255,255}, {161,255,255}, {161,255,255}, {161,255,255}, {161,255,255}, {161,255,255}, {161,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {184,255,255}, {0,0,0}, {110,255,160}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {110,255,160}, {45,255,255}, {162,227,246}, {0,0,0}, {0,0,0}, {110,255,160}, {110,255,160}, {0,255,255}, {186,255,255} },

    [3] = { {0,255,219}, {40,255,255}, {40,255,255}, {40,255,255}, {40,255,255}, {40,255,255}, {110,255,160}, {0,0,0}, {0,0,0}, {40,255,255}, {225,223,255}, {225,223,255}, {110,255,160}, {0,0,0}, {0,0,0}, {40,255,255}, {225,223,255}, {225,223,255}, {110,255,160}, {236,255,255}, {0,0,0}, {40,255,255}, {225,223,255}, {225,223,255}, {186,255,255}, {0,255,255}, {29,255,255}, {89,255,255}, {89,255,255}, {89,255,255}, {89,255,255}, {0,255,219}, {147,255,255}, {147,255,255}, {147,255,255}, {40,255,255}, {39,255,255}, {110,255,160}, {147,255,255}, {147,255,255}, {147,255,255}, {39,255,255}, {39,255,255}, {110,255,160}, {147,255,255}, {147,255,255}, {147,255,255}, {39,255,255}, {39,255,255}, {110,255,160}, {0,255,255}, {186,255,255} },

    [4] = { {0,0,0}, {0,0,0}, {0,0,0}, {61,178,154}, {83,255,206}, {202,211,219}, {102,250,255}, {132,255,255}, {116,255,255}, {52,255,255}, {32,255,255}, {15,255,255}, {174,255,233}, {156,255,255}, {190,255,255}, {215,255,255}, {232,255,255}, {0,255,255}, {110,255,160}, {0,0,0}, {0,0,0}, {0,255,255}, {32,251,255}, {32,251,255}, {110,250,255}, {0,255,219}, {199,255,255}, {162,223,235}, {162,223,235}, {162,223,235}, {0,0,0}, {110,255,160}, {207,174,226}, {0,0,0}, {89,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {217,219,170}, {89,255,255}, {89,255,255}, {89,255,255}, {0,0,0}, {0,0,0}, {140,233,174}, {27,224,246}, {230,252,192}, {0,0,0}, {0,0,0}, {0,0,0}, {0,255,219}, {110,250,255} },

    [5] = { {0,0,0}, {0,0,0}, {203,255,255}, {0,0,0}, {203,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,218,204}, {154,255,255}, {0,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {154,255,255}, {120,254,255}, {154,255,255}, {0,0,0}, {110,255,160}, {0,0,0}, {0,218,204}, {154,255,255}, {0,218,204}, {0,0,0}, {0,218,204}, {0,255,219}, {0,0,0}, {203,255,255}, {0,0,0}, {203,255,255}, {0,0,0}, {110,255,160}, {0,0,0}, {0,218,204}, {154,255,255}, {0,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {154,255,255}, {120,254,255}, {154,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,218,204}, {154,255,255}, {0,218,204}, {0,0,0}, {0,218,204}, {89,255,255}, {89,255,255} },

    [6] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {110,255,160}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {84,251,148}, {110,255,160}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {110,250,255}, {0,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {84,251,148}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {110,255,160}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,255,255}, {110,250,255} },

};

void set_layer_color(int layer)
{
    for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++)
    {
        HSV hsv = {
            .h = pgm_read_byte(&ledmap[layer][i][0]),
            .s = pgm_read_byte(&ledmap[layer][i][1]),
            .v = pgm_read_byte(&ledmap[layer][i][2]),
        };
        if (!hsv.h && !hsv.s && !hsv.v)
        {
            rgb_matrix_set_color(i, 0, 0, 0);
        }
        else
        {
            RGB rgb = hsv_to_rgb(hsv);
            float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
            rgb_matrix_set_color(i, f * rgb.r, f * rgb.g, f * rgb.b);
        }
    }
}

bool rgb_matrix_indicators_user(void)
{
    if (rawhid_state.rgb_control)
    {
        return false;
    }
    if (keyboard_config.disable_layer_led)
    {
        return false;
    }
    switch (biton32(layer_state))
    {
    case 0:
        set_layer_color(0);
        break;
    case 1:
        set_layer_color(1);
        break;
    case 2:
        set_layer_color(2);
        break;
    case 3:
        set_layer_color(3);
        break;
    case 4:
      set_layer_color(4);
      break;
    case 5:
      set_layer_color(5);
      break;
    case 6:
      set_layer_color(6);
      break;
    default:
        if (rgb_matrix_get_flags() == LED_FLAG_NONE)
            rgb_matrix_set_color_all(0, 0, 0);
        break;
    }
    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case MAC_MISSION_CONTROL:
      HCS(0x29F);

    case RGB_SLD:
        if (record->event.pressed)
        {
            rgblight_mode(1);
        }
        return false;
    }
    return true;
}

typedef struct
{
    bool is_press_action;
    uint8_t step;
} tap;

enum
{
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    MORE_TAPS
};

static tap dance_state[4];

uint8_t dance_step(tap_dance_state_t *state);

uint8_t dance_step(tap_dance_state_t *state)
{
    if (state->count == 1)
    {
        if (state->interrupted || !state->pressed)
            return SINGLE_TAP;
        else
            return SINGLE_HOLD;
    }
    else if (state->count == 2)
    {
        if (state->interrupted)
            return DOUBLE_SINGLE_TAP;
        else if (state->pressed)
            return DOUBLE_HOLD;
        else
            return DOUBLE_TAP;
    }
    return MORE_TAPS;
}

void on_dance_0(tap_dance_state_t *state, void *user_data);
void dance_0_finished(tap_dance_state_t *state, void *user_data);
void dance_0_reset(tap_dance_state_t *state, void *user_data);

void on_dance_0(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LALT(KC_BSPC));
        tap_code16(LALT(KC_BSPC));
        tap_code16(LALT(KC_BSPC));
    }
    if(state->count > 3) {
        tap_code16(LALT(KC_BSPC));
    }
}

void dance_0_finished(tap_dance_state_t *state, void *user_data)
{
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case SINGLE_TAP: register_code16(LALT(KC_BSPC)); break;
        case SINGLE_HOLD: register_code16(KC_LEFT_GUI); break;
        case DOUBLE_TAP: register_code16(LALT(KC_BSPC)); register_code16(LALT(KC_BSPC)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LALT(KC_BSPC)); register_code16(LALT(KC_BSPC));
    }
}

void dance_0_reset(tap_dance_state_t *state, void *user_data)
{
    wait_ms(10);
    switch (dance_state[0].step) {
        case SINGLE_TAP: unregister_code16(LALT(KC_BSPC)); break;
        case SINGLE_HOLD: unregister_code16(KC_LEFT_GUI); break;
        case DOUBLE_TAP: unregister_code16(LALT(KC_BSPC)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LALT(KC_BSPC)); break;
    }
    dance_state[0].step = 0;
}
void on_dance_1(tap_dance_state_t *state, void *user_data);
void dance_1_finished(tap_dance_state_t *state, void *user_data);
void dance_1_reset(tap_dance_state_t *state, void *user_data);

void on_dance_1(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_COMMA);
        tap_code16(KC_COMMA);
        tap_code16(KC_COMMA);
    }
    if(state->count > 3) {
        tap_code16(KC_COMMA);
    }
}

void dance_1_finished(tap_dance_state_t *state, void *user_data)
{
    dance_state[1].step = dance_step(state);
    switch (dance_state[1].step) {
        case SINGLE_TAP: register_code16(KC_COMMA); break;
        case DOUBLE_TAP: register_code16(LGUI(KC_COMMA)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_COMMA); register_code16(KC_COMMA);
    }
}

void dance_1_reset(tap_dance_state_t *state, void *user_data)
{
    wait_ms(10);
    switch (dance_state[1].step) {
        case SINGLE_TAP: unregister_code16(KC_COMMA); break;
        case DOUBLE_TAP: unregister_code16(LGUI(KC_COMMA)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_COMMA); break;
    }
    dance_state[1].step = 0;
}
void on_dance_2(tap_dance_state_t *state, void *user_data);
void dance_2_finished(tap_dance_state_t *state, void *user_data);
void dance_2_reset(tap_dance_state_t *state, void *user_data);

void on_dance_2(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_KP_5);
        tap_code16(KC_KP_5);
        tap_code16(KC_KP_5);
    }
    if (state->count > 3)
    {
        tap_code16(KC_KP_5);
    }
}

void dance_2_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[2].step = dance_step(state);
    switch (dance_state[2].step) {
        case SINGLE_TAP: register_code16(KC_KP_5); break;
        case SINGLE_HOLD: register_code16(KC_KP_0); break;
        case DOUBLE_TAP: register_code16(KC_KP_5); register_code16(KC_KP_5); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_KP_5); register_code16(KC_KP_5);
    }
}

void dance_2_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[2].step) {
        case SINGLE_TAP: unregister_code16(KC_KP_5); break;
        case SINGLE_HOLD: unregister_code16(KC_KP_0); break;
        case DOUBLE_TAP: unregister_code16(KC_KP_5); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_KP_5); break;
    }
    dance_state[2].step = 0;
}
void dance_3_finished(tap_dance_state_t *state, void *user_data);
void dance_3_reset(tap_dance_state_t *state, void *user_data);

void dance_3_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[3].step = dance_step(state);
    switch (dance_state[3].step) {
        case DOUBLE_TAP: layer_move(0); break;
    }
}

void dance_3_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[3].step) {
    }
    dance_state[3].step = 0;
}

tap_dance_action_t tap_dance_actions[] = {
        [DANCE_0] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_0, dance_0_finished, dance_0_reset),
        [DANCE_1] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_1, dance_1_finished, dance_1_reset),
        [DANCE_2] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_2, dance_2_finished, dance_2_reset),
        [DANCE_3] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_3_finished, dance_3_reset),
};

// Custom QMK here
const key_override_t delete_key_override =
    ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL); // This is a custom key override that will replace the default behavior of the shift+BSPC key with the DEL key.

const key_override_t **key_overrides = (const key_override_t *[]){
    &delete_key_override,
    NULL};