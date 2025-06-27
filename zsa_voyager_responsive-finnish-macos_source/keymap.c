#include QMK_KEYBOARD_H
#include "version.h"
#include "i18n.h"
#define MOON_LED_LEVEL LED_LEVEL
#ifndef ZSA_SAFE_RANGE
#define ZSA_SAFE_RANGE SAFE_RANGE
#endif

enum custom_keycodes {
  RGB_SLD = ZSA_SAFE_RANGE,
  ST_MACRO_0,
  ST_MACRO_1,
  ST_MACRO_2,
  MAC_SPOTLIGHT,
  MAC_DND,
};



#define DUAL_FUNC_0 LT(1, KC_8)
#define DUAL_FUNC_1 LT(8, KC_Y)
#define DUAL_FUNC_2 LT(15, KC_8)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_voyager(
    KC_ESCAPE,      KC_1,           KC_2,           KC_3,           KC_4,           KC_5,                                           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_BSPC,        
    KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,                                           KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           SE_AA,          
    KC_CAPS,        KC_A,           KC_S,           KC_D,           KC_F,           KC_G,                                           KC_H,           KC_J,           KC_K,           KC_L,           SE_OSLH,        SE_ADIA,        
    KC_LEFT_SHIFT,  KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                                           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         SE_MINS,        KC_RIGHT_SHIFT, 
                                                    MO(1),          KC_SPACE,                                       KC_ENTER,       MO(1)
  ),
  [1] = LAYOUT_voyager(
    DUAL_FUNC_0,    TOGGLE_LAYER_COLOR,LGUI(LCTL(LSFT(KC_4))),DUAL_FUNC_1,    DUAL_FUNC_2,    MAC_DND,                                        SE_PLUS,        SE_GRTR_MAC,    SE_LESS_MAC,    ST_MACRO_0,     SE_TILD,        KC_TRANSPARENT, 
    LGUI(KC_0),     LGUI(SE_MINS),  LGUI(SE_PLUS),  LGUI(LCTL(KC_TAB)),LGUI(KC_TAB),   KC_TRANSPARENT,                                 SE_PIPE_MAC,    SE_LBRC,        SE_RBRC,        ST_MACRO_1,     SE_CIRC,        KC_DELETE,      
    KC_MEDIA_PREV_TRACK,KC_MEDIA_NEXT_TRACK,KC_LEFT_CTRL,   KC_LEFT_ALT,    KC_LEFT_GUI,    KC_MEDIA_PLAY_PAUSE,                                SE_APOS,        KC_RIGHT_GUI,   KC_RIGHT_ALT,   KC_RIGHT_CTRL,  KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_BRIGHTNESS_DOWN,KC_BRIGHTNESS_UP,KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_AUDIO_MUTE,                                  SE_BSLS_MAC,    SE_LCBR_MAC,    SE_RCBR_MAC,    ST_MACRO_2,     SE_ACUT,        KC_TRANSPARENT, 
                                                    MO(2),          MAC_SPOTLIGHT,                                  MAC_SPOTLIGHT,  MO(2)
  ),
  [2] = LAYOUT_voyager(
    LED_LEVEL,      RGB_TOG,        KC_TRANSPARENT, KC_END,         KC_HOME,        KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_PAGE_UP,     KC_PGDN,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    RGB_MODE_FORWARD,LALT(LGUI(KC_1)),LALT(LGUI(KC_2)),LALT(LGUI(KC_3)),LALT(LGUI(KC_4)),LALT(LGUI(KC_5)),                                LALT(LGUI(KC_6)),LALT(LGUI(KC_7)),LALT(LGUI(KC_8)),LALT(LGUI(KC_9)),LALT(LGUI(KC_0)),KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_LEFT_CTRL,   KC_LEFT_ALT,    KC_LEFT_GUI,    KC_TRANSPARENT,                                 KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_F11,         KC_F12,         
    KC_TRANSPARENT, KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,                                          KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_SPACE,                                       KC_ENTER,       KC_TRANSPARENT
  ),
};



uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_SPACE:
            return TAPPING_TERM -100;
        case KC_ENTER:
            return TAPPING_TERM -100;
        default:
            return TAPPING_TERM;
    }
}

extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [0] = { {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255} },

    [1] = { {248,255,255}, {35,255,255}, {14,255,255}, {105,255,255}, {105,255,255}, {0,0,255}, {105,255,255}, {105,255,255}, {105,255,255}, {154,255,255}, {154,255,255}, {0,0,0}, {154,255,255}, {154,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {154,255,255}, {14,255,255}, {0,0,255}, {0,0,255}, {105,255,255}, {105,255,255}, {105,255,255}, {105,255,255}, {0,0,255}, {105,255,255}, {105,255,255}, {105,255,255}, {105,255,255}, {105,255,255}, {14,255,255}, {105,255,255}, {105,255,255}, {105,255,255}, {105,255,255}, {105,255,255}, {14,255,255}, {105,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {0,0,0}, {0,0,0}, {105,255,255}, {105,255,255}, {105,255,255}, {105,255,255}, {105,255,255}, {14,255,255}, {0,0,255}, {105,255,255} },

    [2] = { {35,255,255}, {35,255,255}, {0,0,0}, {154,255,255}, {154,255,255}, {0,0,0}, {35,255,255}, {105,255,255}, {105,255,255}, {105,255,255}, {105,255,255}, {105,255,255}, {0,0,0}, {0,0,0}, {14,255,255}, {14,255,255}, {14,255,255}, {0,0,0}, {14,255,255}, {154,255,255}, {154,255,255}, {154,255,255}, {154,255,255}, {154,255,255}, {154,255,255}, {154,255,255}, {0,0,0}, {154,255,255}, {154,255,255}, {0,0,0}, {0,0,0}, {14,255,255}, {105,255,255}, {105,255,255}, {105,255,255}, {105,255,255}, {105,255,255}, {0,0,0}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {154,255,255}, {154,255,255}, {154,255,255}, {154,255,255}, {154,255,255}, {154,255,255}, {154,255,255}, {14,255,255}, {154,255,255}, {154,255,255} },

};

void set_layer_color(int layer) {
  for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
}

bool rgb_matrix_indicators_user(void) {
  if (keyboard_config.disable_layer_led) { return false; }
  switch (biton32(layer_state)) {
    case 0:
      set_layer_color(0);
      break;
    case 1:
      set_layer_color(1);
      break;
    case 2:
      set_layer_color(2);
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
    case ST_MACRO_0:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_RBRC))SS_DELAY(100)  SS_TAP(X_SPACE));
    }
    break;
    case ST_MACRO_1:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_RBRC))SS_DELAY(100)  SS_TAP(X_SPACE));
    }
    break;
    case ST_MACRO_2:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_EQUAL))SS_DELAY(100)  SS_TAP(X_SPACE));
    }
    break;
    case MAC_SPOTLIGHT:
      HCS(0x221);
    case MAC_DND:
      HSS(0x9B);

    case DUAL_FUNC_0:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(LGUI(LCTL(KC_Q)));
        } else {
          unregister_code16(LGUI(LCTL(KC_Q)));
        }
      } else {
        if (record->event.pressed) {
          register_code16(LGUI(LSFT(KC_Q)));
        } else {
          unregister_code16(LGUI(LSFT(KC_Q)));
        }  
      }  
      return false;
    case DUAL_FUNC_1:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(LALT(LGUI(KC_LEFT)));
        } else {
          unregister_code16(LALT(LGUI(KC_LEFT)));
        }
      } else {
        if (record->event.pressed) {
          register_code16(LGUI(KC_LEFT));
        } else {
          unregister_code16(LGUI(KC_LEFT));
        }  
      }  
      return false;
    case DUAL_FUNC_2:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(LALT(LGUI(KC_RIGHT)));
        } else {
          unregister_code16(LALT(LGUI(KC_RIGHT)));
        }
      } else {
        if (record->event.pressed) {
          register_code16(LGUI(KC_RIGHT));
        } else {
          unregister_code16(LGUI(KC_RIGHT));
        }  
      }  
      return false;
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
  }
  return true;
}


