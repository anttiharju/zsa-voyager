#include QMK_KEYBOARD_H
#include "version.h"
#include "i18n.h"
#define MOON_LED_LEVEL LED_LEVEL
#define ML_SAFE_RANGE SAFE_RANGE

enum layers {
  _BASE,
  _LOWER,
  _UPPER,
};

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
  ST_MACRO_0,
  ST_MACRO_1,
  ST_MACRO_2,
  MAC_SPOTLIGHT,
  MAC_DND,
  LEFT_LAYER_KEY,
  RIGHT_LAYER_KEY,
};

static bool left_layer_pressed = false;
static bool right_layer_pressed = false;

typedef struct {
    uint16_t tap;
    uint16_t hold;
    uint16_t held;
} tap_dance_tap_hold_t;
tap_dance_action_t *action;

enum tap_dance_codes {
  DANCE_0,
  DANCE_1,
  DANCE_2,
  DANCE_3,
  DANCE_4,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_voyager(
    KC_ESCAPE,      KC_1,           KC_2,           KC_3,           KC_4,           KC_5,                                           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_BSPC,        
    KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,                                           KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           SE_AA,          
    KC_CAPS,        KC_A,           KC_S,           KC_D,           KC_F,           KC_G,                                           KC_H,           KC_J,           KC_K,           KC_L,           SE_OSLH,        SE_ADIA,        
    KC_LEFT_SHIFT,  KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                                           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         SE_MINS,        KC_RIGHT_SHIFT, 
                                                                    LEFT_LAYER_KEY, KC_SPACE,                                       KC_ENTER,       RIGHT_LAYER_KEY
  ),
  [1] = LAYOUT_voyager(
    KC_AUDIO_MUTE,  KC_AUDIO_VOL_UP,LGUI(LCTL(LSFT(KC_4))),TD(DANCE_0),    TD(DANCE_1),    LGUI(LCTL(KC_SPACE)),                    MAC_DND,        SE_LCBR_MAC,    SE_RCBR_MAC,    SE_CIRC,        SE_TILD,        KC_TRANSPARENT,
    KC_AUDIO_VOL_DOWN,RGB_MODE_FORWARD,LALT(KC_A),     LALT(KC_D),     TD(DANCE_2),    LALT(KC_S),                                  SE_PIPE_MAC,    SE_LESS_MAC,    TD(DANCE_4),    ST_MACRO_0,     ST_MACRO_1,     KC_DELETE,
    TD(DANCE_3),    TOGGLE_LAYER_COLOR,KC_LEFT_CTRL,   KC_LEFT_ALT,    KC_LEFT_GUI,    LALT(KC_4),                                  SE_APOS,        KC_RIGHT_GUI,   KC_RIGHT_ALT,   KC_RIGHT_CTRL,  ST_MACRO_2,     SE_ACUT,
    KC_TRANSPARENT, KC_BRIGHTNESS_DOWN,KC_BRIGHTNESS_UP,KC_MEDIA_PREV_TRACK,KC_MEDIA_NEXT_TRACK,KC_MEDIA_PLAY_PAUSE,                SE_BSLS_MAC,    SE_LBRC,        SE_RBRC,        SE_PLUS,        SE_MINS,        KC_TRANSPARENT,
                                                                    KC_TRANSPARENT,   MAC_SPOTLIGHT,                                MAC_SPOTLIGHT,  KC_TRANSPARENT
  ),
  [2] = LAYOUT_voyager(
    RGB_HUI,        LALT(LGUI(KC_1)),LALT(LGUI(KC_2)),LALT(LGUI(KC_3)),LALT(LGUI(KC_4)),LALT(LGUI(KC_5)),                                LALT(LGUI(KC_6)),LALT(LGUI(KC_7)),LALT(LGUI(KC_8)),LALT(LGUI(KC_9)),LALT(LGUI(KC_0)),KC_TRANSPARENT, 
    RGB_HUD,        KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,                                          KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         
    LED_LEVEL,      RGB_TOG,        KC_LEFT_CTRL,   KC_LEFT_ALT,    KC_LEFT_GUI,    KC_TRANSPARENT,                                 KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_TRANSPARENT, KC_F12,         
    KC_TRANSPARENT, KC_TRANSPARENT, KC_END,         KC_HOME,        KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_PAGE_UP,     KC_PGDN,        KC_TRANSPARENT, KC_TRANSPARENT, 
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

    [1] = { {154,255,255}, {154,255,255}, {14,255,255}, {105,255,255}, {105,255,255}, {14,255,255}, {154,255,255}, {35,255,255}, {154,255,255}, {154,255,255}, {154,255,255}, {154,255,255}, {248,255,255}, {35,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {105,255,255}, {14,255,255}, {0,0,255}, {0,0,255}, {105,255,255}, {105,255,255}, {105,255,255}, {105,255,255}, {0,0,255}, {0,0,255}, {105,255,255}, {105,255,255}, {105,255,255}, {105,255,255}, {14,255,255}, {105,255,255}, {105,255,255}, {154,255,255}, {105,255,255}, {105,255,255}, {14,255,255}, {105,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {105,255,255}, {105,255,255}, {105,255,255}, {105,255,255}, {105,255,255}, {105,255,255}, {105,255,255}, {14,255,255}, {0,0,255}, {105,255,255} },

    [2] = { {35,255,255}, {154,255,255}, {154,255,255}, {154,255,255}, {154,255,255}, {154,255,255}, {35,255,255}, {105,255,255}, {105,255,255}, {105,255,255}, {105,255,255}, {105,255,255}, {35,255,255}, {35,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {0,0,0}, {14,255,255}, {0,0,0}, {154,255,255}, {154,255,255}, {0,0,0}, {0,0,0}, {154,255,255}, {154,255,255}, {154,255,255}, {154,255,255}, {154,255,255}, {154,255,255}, {154,255,255}, {14,255,255}, {105,255,255}, {105,255,255}, {105,255,255}, {105,255,255}, {105,255,255}, {105,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {0,0,0}, {105,255,255}, {0,0,0}, {0,0,0}, {154,255,255}, {154,255,255}, {0,0,0}, {14,255,255}, {154,255,255}, {154,255,255} },

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
    case LEFT_LAYER_KEY:
      if (record->event.pressed) {
        left_layer_pressed = true;

        // If right is already pressed, go to UPPER layer
        if (right_layer_pressed) {
          layer_on(_UPPER);
        } else {
          // Otherwise just LOWER layer
          layer_on(_LOWER);
        }
      } else {
        left_layer_pressed = false;

        if (right_layer_pressed) {
          // Right still pressed, go back to LOWER
          layer_off(_UPPER);
        } else {
          // No layer keys pressed, back to base
          layer_off(_LOWER);
          layer_off(_UPPER);
        }
      }
      return false;

    case RIGHT_LAYER_KEY:
      if (record->event.pressed) {
        right_layer_pressed = true;

        // If left is already pressed, go to UPPER layer
        if (left_layer_pressed) {
          layer_on(_UPPER);
        } else {
          // Otherwise just LOWER layer
          layer_on(_LOWER);
        }
      } else {
        right_layer_pressed = false;

        if (left_layer_pressed) {
          // Left still pressed, go back to LOWER
          layer_off(_UPPER);
        } else {
          // No layer keys pressed, back to base
          layer_off(_LOWER);
          layer_off(_UPPER);
        }
      }
      return false;

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

    case TD(DANCE_0):
    case TD(DANCE_1):
    case TD(DANCE_2):
    case TD(DANCE_3):
    case TD(DANCE_4):
        action = &tap_dance_actions[TD_INDEX(keycode)];
        if (!record->event.pressed && action->state.count && !action->state.finished) {
            tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
            tap_code16(tap_hold->tap);
        }
        break;
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
  }
  return true;
}

void tap_dance_tap_hold_finished(tap_dance_state_t *state, void *user_data) {
    tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

    if (state->pressed) {
        if (state->count == 1
#ifndef PERMISSIVE_HOLD
            && !state->interrupted
#endif
        ) {
            register_code16(tap_hold->hold);
            tap_hold->held = tap_hold->hold;
        } else {
            register_code16(tap_hold->tap);
            tap_hold->held = tap_hold->tap;
        }
    }
}

void tap_dance_tap_hold_reset(tap_dance_state_t *state, void *user_data) {
    tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

    if (tap_hold->held) {
        unregister_code16(tap_hold->held);
        tap_hold->held = 0;
    }
}

#define ACTION_TAP_DANCE_TAP_HOLD(tap, hold) \
    { .fn = {NULL, tap_dance_tap_hold_finished, tap_dance_tap_hold_reset}, .user_data = (void *)&((tap_dance_tap_hold_t){tap, hold, 0}), }


tap_dance_action_t tap_dance_actions[] = {
        [DANCE_0] = ACTION_TAP_DANCE_TAP_HOLD(LALT(LGUI(KC_LEFT)), LGUI(KC_LEFT)),
        [DANCE_1] = ACTION_TAP_DANCE_TAP_HOLD(LALT(LGUI(KC_RIGHT)), LGUI(KC_RIGHT)),
        [DANCE_2] = ACTION_TAP_DANCE_TAP_HOLD(LALT(KC_F), LALT(KC_W)),
        [DANCE_3] = ACTION_TAP_DANCE_TAP_HOLD(LCTL(LGUI(KC_Q)), LGUI(LSFT(KC_Q))),
        [DANCE_4] = ACTION_TAP_DANCE_TAP_HOLD(LGUI(KC_TAB), LCTL(LGUI(KC_TAB))),
};
