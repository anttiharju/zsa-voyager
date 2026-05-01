#include QMK_KEYBOARD_H
#include "version.h"
#include "i18n.h"
#define MOON_LED_LEVEL LED_LEVEL
#ifndef ZSA_SAFE_RANGE
#define ZSA_SAFE_RANGE SAFE_RANGE
#endif

enum layers {
  _BASE,
  _LOWER,
  _UPPER,
  _WORKMAN,
};

enum custom_keycodes {
  RGB_SLD = ZSA_SAFE_RANGE,
  ST_MACRO_0,
  ST_MACRO_1,
  ST_MACRO_2,
  MAC_SPOTLIGHT,
  MAC_DND,
  LEFT_LAYER_KEY,
  RIGHT_LAYER_KEY,
  TOGGLE_BASE_LAYOUT,
};

static inline bool workman_active(void) {
  return get_highest_layer(default_layer_state) == _WORKMAN;
}

static bool left_layer_pressed = false;
static bool right_layer_pressed = false;



#define DUAL_FUNC_0 LT(4, KC_Z)
#define DUAL_FUNC_1 LT(11, KC_R)
#define DUAL_FUNC_2 LT(5, KC_3)

#define WPM_THRESHOLD 100

#define IS_CAPS_RED_LED(i) ((i) == 0 || (i) == 24 || (i) == 25 || (i) == 50 || (i) == 51)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_voyager(
    KC_ESCAPE,      KC_1,           KC_2,           KC_3,           KC_4,           KC_5,                                           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_BSPC,        
    KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,                                           KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           SE_AA,          
    KC_CAPS,        KC_A,           KC_S,           KC_D,           KC_F,           KC_G,                                           KC_H,           KC_J,           KC_K,           KC_L,           SE_OSLH,        SE_ADIA,        
    KC_LEFT_SHIFT,  KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                                           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         SE_MINS,        KC_RIGHT_SHIFT, 
                                                                    LEFT_LAYER_KEY, KC_SPACE,                                       KC_ENTER,       RIGHT_LAYER_KEY
  ),
  [1] = LAYOUT_voyager(
    LGUI(SE_MINS),  LGUI(SE_PLUS),  LGUI(LCTL(LSFT(KC_4))),DUAL_FUNC_0,    DUAL_FUNC_1,    MAC_DND,                                        SE_GRTR_MAC,    SE_PLUS,        SE_LESS_MAC,    ST_MACRO_0,     SE_CIRC,        KC_TRANSPARENT, 
    KC_MEDIA_PREV_TRACK,KC_MEDIA_NEXT_TRACK,KC_MEDIA_PLAY_PAUSE,LGUI(LCTL(KC_TAB)),LGUI(KC_TAB),   KC_PAGE_UP,                                     SE_PIPE_MAC,    SE_LBRC,        SE_RBRC,        ST_MACRO_1,     SE_TILD,        KC_DELETE,      
    DUAL_FUNC_2,    TOGGLE_LAYER_COLOR,KC_LEFT_CTRL,   KC_LEFT_ALT,    KC_LEFT_GUI,    KC_PGDN,                                        SE_APOS,        KC_RIGHT_GUI,   KC_RIGHT_ALT,   KC_RIGHT_CTRL,  KC_BRIGHTNESS_DOWN,KC_BRIGHTNESS_UP,
    KC_TRANSPARENT, KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_END,         KC_HOME,        KC_AUDIO_MUTE,                                  SE_BSLS_MAC,    SE_LCBR_MAC,    SE_RCBR_MAC,    ST_MACRO_2,     SE_ACUT,        KC_TRANSPARENT, 
                                                                      KC_TRANSPARENT, MAC_SPOTLIGHT,                                  MAC_SPOTLIGHT,  KC_TRANSPARENT
  ),
  [2] = LAYOUT_voyager(
    KC_TRANSPARENT, LALT(LGUI(KC_1)),LALT(LGUI(KC_2)),LALT(LGUI(KC_3)),LALT(LGUI(KC_4)),LALT(LGUI(KC_5)),                                LALT(LGUI(KC_6)),LALT(LGUI(KC_7)),LALT(LGUI(KC_8)),LALT(LGUI(KC_9)),LALT(LGUI(KC_0)),KC_TRANSPARENT, 
    RGB_MODE_FORWARD,KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,                                          KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         
    RGB_TOG,        LED_LEVEL,      KC_LEFT_CTRL,   KC_LEFT_ALT,    KC_LEFT_GUI,    TOGGLE_BASE_LAYOUT,                             KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_TRANSPARENT, KC_F12,         
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_SPACE,                                       KC_ENTER,       KC_TRANSPARENT
  ),
  [3] = LAYOUT_voyager(
    KC_ESCAPE,      KC_1,           KC_2,           KC_3,           KC_4,           KC_5,                                           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_BSPC,        
    KC_TAB,         KC_Q,           KC_D,           KC_R,           KC_W,           KC_B,                                           KC_J,           KC_F,           KC_U,           KC_P,           SE_OSLH,        SE_AA,          
    KC_CAPS,        KC_A,           KC_S,           KC_H,           KC_T,           KC_G,                                           KC_Y,           KC_N,           KC_E,           KC_O,           KC_I,           SE_ADIA,        
    KC_LEFT_SHIFT,  KC_Z,           KC_X,           KC_M,           KC_C,           KC_V,                                           KC_K,           KC_L,           KC_COMMA,       KC_DOT,         SE_MINS,        KC_RIGHT_SHIFT, 
                                                                    LEFT_LAYER_KEY, KC_SPACE,                                       KC_ENTER,       RIGHT_LAYER_KEY
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

RGB hsv_to_rgb_with_value(HSV hsv) {
  RGB rgb = hsv_to_rgb( hsv );
  float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
  return (RGB){ f * rgb.r, f * rgb.g, f * rgb.b };
}

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
  rgb_matrix_set_flags(LED_FLAG_NONE);
  keyboard_config.led_level = false;
  STATUS_LED_1(false);
  STATUS_LED_2(false);
  STATUS_LED_3(false);
  STATUS_LED_4(false);
}

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [0] = { {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255} },

    [1] = { {154,255,255}, {154,255,255}, {14,255,255}, {105,255,255}, {105,255,255}, {0,0,255}, {105,255,255}, {105,255,255}, {105,255,255}, {154,255,255}, {154,255,255}, {105,255,255}, {248,255,255}, {35,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {105,255,255}, {14,255,255}, {154,255,255}, {154,255,255}, {105,255,255}, {105,255,255}, {154,255,255}, {105,255,255}, {0,0,255}, {105,255,255}, {105,255,255}, {105,255,255}, {105,255,255}, {105,255,255}, {14,255,255}, {105,255,255}, {105,255,255}, {105,255,255}, {105,255,255}, {105,255,255}, {14,255,255}, {105,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {0,0,255}, {0,0,255}, {105,255,255}, {105,255,255}, {105,255,255}, {105,255,255}, {105,255,255}, {14,255,255}, {0,0,255}, {105,255,255} },

    [2] = { {0,0,0}, {105,255,255}, {105,255,255}, {105,255,255}, {105,255,255}, {105,255,255}, {35,255,255}, {154,255,255}, {154,255,255}, {154,255,255}, {154,255,255}, {154,255,255}, {35,255,255}, {35,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {0,0,255}, {14,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {154,255,255}, {154,255,255}, {105,255,255}, {105,255,255}, {105,255,255}, {105,255,255}, {105,255,255}, {14,255,255}, {154,255,255}, {154,255,255}, {154,255,255}, {154,255,255}, {154,255,255}, {154,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {0,0,0}, {154,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {14,255,255}, {154,255,255}, {154,255,255} },

    [3] = { {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255} },

};

void set_layer_color(int layer) {
  bool swap = workman_active();
  for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (swap) {
      if (hsv.h == 14 && hsv.s == 255 && hsv.v == 255) {
        // orange -> white
        hsv.h = 0; hsv.s = 0; hsv.v = 255;
      } else if (hsv.s == 0 && hsv.v == 255) {
        // white -> orange
        hsv.h = 14; hsv.s = 255; hsv.v = 255;
      }
    }
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb_with_value(hsv);
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
  }
}

bool rgb_matrix_indicators_user(void) {
  if (!keyboard_config.disable_layer_led) { 
    // Check if caps lock is on and we're on layer 0
    led_t led_state = host_keyboard_led_state();
    bool workman = workman_active();
    uint8_t base_layer = workman ? _WORKMAN : _BASE;
    // WPM>100: white in QWERTY, orange (hue 14) in Workman
    const uint8_t WPM_R = 255;
    const uint8_t WPM_G = workman ? 84  : 255;
    const uint8_t WPM_B = workman ? 0   : 255;
    if (led_state.caps_lock && biton32(layer_state) == 0) {
      // Base layer colors first
      if (get_current_wpm() > WPM_THRESHOLD) {
        rgb_matrix_set_color_all(WPM_R, WPM_G, WPM_B);
      } else {
        set_layer_color(base_layer);
      }
      // Static red on caps lock key and thumb clusters
      for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
        if (IS_CAPS_RED_LED(i)) {
          rgb_matrix_set_color(i, 255, 0, 0);
        }
      }
    } else {
      // Normal layer coloring
      switch (biton32(layer_state)) {
        case 0:
          if (get_current_wpm() > WPM_THRESHOLD) {
            rgb_matrix_set_color_all(WPM_R, WPM_G, WPM_B);
          } else {
            set_layer_color(base_layer);
          }
          break;
        case 1:
          set_layer_color(1);
          break;
        case 2:
          set_layer_color(2);
          break;
       default:
          if (rgb_matrix_get_flags() == LED_FLAG_NONE) {
            rgb_matrix_set_color_all(0, 0, 0);
          }
      }
    }
  } else {
    if (rgb_matrix_get_flags() == LED_FLAG_NONE) {
      rgb_matrix_set_color_all(0, 0, 0);
    }
  }

  // Turn off columns for held layer 1 modifiers
  uint8_t mods = get_mods();
  // Left CTRL - left column 2 (LEDs 2, 8, 14, 20)
  if (mods & MOD_BIT(KC_LEFT_CTRL)) {
    rgb_matrix_set_color(2, 0, 0, 0);
    rgb_matrix_set_color(8, 0, 0, 0);
    rgb_matrix_set_color(14, 0, 0, 0);
    rgb_matrix_set_color(20, 0, 0, 0);
  }
  // Left ALT - left column 3 (LEDs 3, 9, 15, 21)
  if (mods & MOD_BIT(KC_LEFT_ALT)) {
    rgb_matrix_set_color(3, 0, 0, 0);
    rgb_matrix_set_color(9, 0, 0, 0);
    rgb_matrix_set_color(15, 0, 0, 0);
    rgb_matrix_set_color(21, 0, 0, 0);
  }
  // Left GUI - left column 4 (LEDs 4, 10, 16, 22)
  if (mods & MOD_BIT(KC_LEFT_GUI)) {
    rgb_matrix_set_color(4, 0, 0, 0);
    rgb_matrix_set_color(10, 0, 0, 0);
    rgb_matrix_set_color(16, 0, 0, 0);
    rgb_matrix_set_color(22, 0, 0, 0);
  }
  // Right GUI - right column 1 (LEDs 27, 33, 39, 45)
  if (mods & MOD_BIT(KC_RIGHT_GUI)) {
    rgb_matrix_set_color(27, 0, 0, 0);
    rgb_matrix_set_color(33, 0, 0, 0);
    rgb_matrix_set_color(39, 0, 0, 0);
    rgb_matrix_set_color(45, 0, 0, 0);
  }
  // Right ALT - right column 2 (LEDs 28, 34, 40, 46)
  if (mods & MOD_BIT(KC_RIGHT_ALT)) {
    rgb_matrix_set_color(28, 0, 0, 0);
    rgb_matrix_set_color(34, 0, 0, 0);
    rgb_matrix_set_color(40, 0, 0, 0);
    rgb_matrix_set_color(46, 0, 0, 0);
  }
  // Right CTRL - right column 3 (LEDs 29, 35, 41, 47)
  if (mods & MOD_BIT(KC_RIGHT_CTRL)) {
    rgb_matrix_set_color(29, 0, 0, 0);
    rgb_matrix_set_color(35, 0, 0, 0);
    rgb_matrix_set_color(41, 0, 0, 0);
    rgb_matrix_set_color(47, 0, 0, 0);
  }

  return true;
}




bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case TOGGLE_BASE_LAYOUT:
      if (record->event.pressed) {
        set_single_persistent_default_layer(workman_active() ? _BASE : _WORKMAN);
      }
      return false;
    case LEFT_LAYER_KEY:
      if (record->event.pressed) {
        left_layer_pressed = true;
        if (right_layer_pressed) {
          layer_on(_UPPER);
        } else {
          layer_on(_LOWER);
        }
      } else {
        left_layer_pressed = false;
        if (right_layer_pressed) {
          layer_off(_UPPER);
        } else {
          layer_off(_LOWER);
          layer_off(_UPPER);
        }
      }
      return false;
    case RIGHT_LAYER_KEY:
      if (record->event.pressed) {
        right_layer_pressed = true;
        if (left_layer_pressed) {
          layer_on(_UPPER);
        } else {
          layer_on(_LOWER);
        }
      } else {
        right_layer_pressed = false;
        if (left_layer_pressed) {
          layer_off(_UPPER);
        } else {
          layer_off(_LOWER);
          layer_off(_UPPER);
        }
      }
      return false;
  case QK_MODS ... QK_MODS_MAX:
    // Mouse and consumer keys (volume, media) with modifiers work inconsistently across operating systems,
    // this makes sure that modifiers are always applied to the key that was pressed.
    if (IS_CONSUMER_KEYCODE(QK_MODS_GET_BASIC_KEYCODE(keycode))) {
      if (record->event.pressed) {
        add_mods(QK_MODS_GET_MODS(keycode));
        send_keyboard_report();
        wait_ms(2);
        register_code(QK_MODS_GET_BASIC_KEYCODE(keycode));
        return false;
      } else {
        wait_ms(2);
        del_mods(QK_MODS_GET_MODS(keycode));
      }
    }
    break;
    case ST_MACRO_0:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_RBRC))SS_DELAY(100)  SS_TAP(X_SPACE));
    }
    break;
    case ST_MACRO_1:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_RBRC))SS_DELAY(100)  SS_TAP(X_SPACE));
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
    case DUAL_FUNC_1:
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
    case DUAL_FUNC_2:
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
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
  }
  return true;
}
