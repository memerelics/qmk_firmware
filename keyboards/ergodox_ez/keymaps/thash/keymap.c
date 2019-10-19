#include QMK_KEYBOARD_H
#include "version.h"

// Helpful defines
#define GRAVE_MODS  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT)|MOD_BIT(KC_LGUI)|MOD_BIT(KC_RGUI)|MOD_BIT(KC_LALT)|MOD_BIT(KC_RALT))

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  _______ = KC_TRNS, XXXXXXX = KC_NO (NOOP)                *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#define _BL 0 // base layer - default
#define _SL 1 // symbols layer
#define _NL 2 // numbers layer
#define _RL 3 // reset layer (reset button to load updated keymaps)

enum custom_keycodes {
  EPRM = SAFE_RANGE,
  VRSN,
  RGB_SLD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Layer 0:
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  ESC   |   1  |   2  |   3  |   4  |   5  |   6  |           |   7  |   8  |   9  |   0  |   -  |   =  |   bsp  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |  Tab   |   Q  |   W  |   E  |   R  |   T  |  pst |           |  pst |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LCtrl  |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   '    |
 * |--------+------+------+------+------+------|  cpy |           |  cpy |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |//Ctrl| RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 * |   ESC  |  '"  |  Alt | LGui | LGui |                                       | RGui |   -  |tg _RL|tg _SL| tg _NL |
 * `------------------------------------'                                       `------------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |   ~  |  `   |       |  (   |   )  |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |Alt(Q)|       |   *  |        |      |
 *                                 |Space | [/_SL|------|       |------|  ]/_NL |Enter |
 *                                 |      |      |C(F1) |       |   &  |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*

// ref: https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes.md
[_BL] = LAYOUT_ergodox(
        // left hand
        KC_ESC,         KC_1,         KC_2,   KC_3,   KC_4,   KC_5,   KC_6,
        KC_TAB,         KC_Q,         KC_W,   KC_E,   KC_R,   KC_T,   LGUI(KC_V),
        KC_LCTRL,       KC_A,         KC_S,   KC_D,   KC_F,   KC_G,
        KC_LSFT,        KC_Z,         KC_X,   KC_C,   KC_V,   KC_B,   LGUI(KC_C),

        KC_ESC, KC_QUOT, KC_LALT, KC_LGUI, KC_LGUI,

                                                              S(KC_GRV),  KC_GRV,
                                                                      LALT(KC_Q),
                                            KC_SPC,LT(_SL, KC_LBRC),LCTL(KC_F1),

        // right hand
        KC_7,        KC_8,   KC_9,    KC_0,    KC_MINS, KC_EQL,           KC_BSPC,
        LGUI(KC_V),  KC_Y,   KC_U,    KC_I,    KC_O,    KC_P,             KC_BSLS,
                     KC_H,   KC_J,    KC_K,    KC_L,    KC_SCLN          ,KC_QUOT,
        LGUI(KC_C),  KC_N,   KC_M,    KC_COMM, KC_DOT,  CTL_T(KC_SLSH),   KC_RSFT,

                                      KC_RGUI, KC_MINS, TG(_RL), TG(_SL), TG(_NL),

        S(KC_9), S(KC_0),
        S(KC_7),
        S(KC_8), LT(_NL, KC_RBRC), KC_ENT
),

/* Layer 1: Symbols Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   !  |   @  |   {  |   }  |   |  |      |           |      |      |      |      |      |      |   F12  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        | bsp  | Left |  Up  | Down |Right |------|           |------| Left | Down |  Up  |Right |      | Enter  |
 * |--------+------+------+------+------+------| cut  |           |  cut |------+------+------+------+------+--------|
 * |        |   %  |   ^  |   [  |Enter |   `  |      |           |      |   &  |   [  |   ]  |      |   \  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | dflt |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |Enter |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[_SL] = LAYOUT_ergodox(
       // left hand
       _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , _______,
       _______, KC_EXLM, KC_AT  , KC_LCBR, KC_RCBR, KC_PIPE, _______,
       _______, KC_BSPC, KC_LEFT, KC_UP  , KC_DOWN, KC_RGHT,
       _______, KC_PERC, KC_CIRC, KC_LBRC, KC_ENT , KC_GRV , LGUI(KC_X),
       TO(_BL), _______, _______, _______, _______,
                                         _______, _______,
                                                  _______,
                                KC_ENT , _______, _______,


       // right hand
       _______, KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,
       _______, _______, _______,   _______,    _______,    _______, KC_F12,
                KC_LEFT, KC_DOWN,KC_UP,   KC_RGHT, _______, KC_ENT,
       RGUI(KC_X), KC_AMPR, KC_LBRC,KC_RBRC, _______,    KC_BSLS, _______,
                         _______,_______,  _______,   _______, _______,
       _______, _______,
       _______,
       _______, _______, _______
),

/* Layer 2: Numbers Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |   7  |  8   |  9   |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |   4  |  5   |  6   |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |   1  |  2   |  3   |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | dflt |   0  |   0  |  0   |  .   |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |   *  |  /   |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |   +  |   -  |------|       |------|      |      |
 *                                 |      |      |  =   |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[_NL] = LAYOUT_ergodox(
       // left hand
       _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
       _______, XXXXXXX, KC_7, KC_8, KC_9, XXXXXXX, _______,
       _______, XXXXXXX, KC_4, KC_5, KC_6, XXXXXXX,
       _______, XXXXXXX, KC_1, KC_2, KC_3, XXXXXXX, _______,
       TO(_BL), KC_0   , KC_0, KC_0, KC_DOT,
                                           S(KC_8), KC_SLSH,
                                                    XXXXXXX,
                                S(KC_EQL), KC_MINS, KC_EQL ,

       // right hand
       _______,  _______, _______, _______, _______, _______, _______,
       _______,  _______, _______, _______, _______, _______, _______,
                 _______, _______, _______, _______, _______, _______,
       _______,  _______, _______, _______, _______, _______, _______,
                          _______, _______, _______, _______, _______,
       _______, _______,
       _______,
       _______, _______, _______
),

/* Layer 3: Reset Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | RESET  |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | dflt |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[_RL] = LAYOUT_ergodox(
       // left hand
       RESET  , _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______, _______,
       TO(_BL), _______, _______, _______, _______,
                                           _______, _______,
                                                    _______,
                                  _______, _______, _______,

       // right hand
       _______,  _______, _______, _______, _______, _______, _______,
       _______,  _______, _______, _______, _______, _______, _______,
                 _______, _______, _______, _______, _______, _______,
       _______,  _______, _______, _______, _______, _______, _______,
                          _______, _______, _______, _______, _______,
       _______, _______,
       _______,
       _______, _______, _______
),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
      case EPRM:
        eeconfig_init();
        return false;
      case VRSN:
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        return false;
      #ifdef RGBLIGHT_ENABLE
      case RGB_SLD:
        rgblight_mode(1);
        return false;
      #endif
    }
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs whenever there is a layer state change.
uint32_t layer_state_set_user(uint32_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = biton32(state);
  switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #else
        #ifdef RGBLIGHT_ENABLE
          rgblight_init();
        #endif
        #endif
        break;
      case 1:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_7);
        #endif
        break;
      default:
        break;
    }

  return state;
};
