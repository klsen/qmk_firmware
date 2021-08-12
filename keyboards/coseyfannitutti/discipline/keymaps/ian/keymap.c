/*
 * Hello, hello.
 * Kenneth Seneres 2021
 */

#include QMK_KEYBOARD_H

enum my_layers {
  _mac,
  _windows,
  _fn,
  _mac2,
  _windows2,
  _locked
};

enum custom_keycodes {
  HELLO = SAFE_RANGE,
};

// '_______' is alternate keycode for KC_TRNS
// 'XXXXXXX' is alternate keycode for KC_NO
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // base layer for mac OS
  [_mac] = LAYOUT_65_split_space(
    KC_GESC,          KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_MPLY,
    KC_TAB,           KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, XXXXXXX,
    MO(_mac2),        KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,           XXXXXXX,
    KC_LSFT,                   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,   TG(_locked),
    KC_LCTL,          KC_LALT, KC_LGUI,          LALT(KC_BSPC),    MO(_fn),          KC_SPC,           KC_RGUI, KC_RALT, KC_LEFT, KC_DOWN, KC_RIGHT),

  // base layer for windows
  [_windows] = LAYOUT_65_split_space(
    _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    MO(_windows2),    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
    _______,                   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, 
    _______,          KC_LGUI, KC_LALT,          LCTL(KC_BSPC),    _______,          _______,          KC_RALT, KC_RGUI, _______, _______, _______),

  // fn layer
  [_fn] = LAYOUT_65_split_space(
    KC_GRV,           KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  _______,
    _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, DF(_mac),DF(_windows),RESET,_______,
    KC_CAPS,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
    _______,                   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______,          _______, _______,          _______,          _______,          _______,          _______, _______, _______, _______, _______),

  // extra layer for mac os
  [_mac2] = LAYOUT_65_split_space(
    LALT(KC_GRV),     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______,          _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,_______, _______, HELLO,            _______,
    _______,                   _______, _______, _______, _______, LALT(KC_LEFT), _______, _______, _______, _______, _______, _______, _______, _______,
    _______,          _______, _______,          _______,          _______,          _______,          _______, _______, _______, _______, _______),

  // extra layer for windows. why ctrl-left on 'b' b-ro
  [_windows2] = LAYOUT_65_split_space(
    _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______,          _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,_______, _______, HELLO,            _______,
    _______,                   _______, _______, _______, _______, LCTL(KC_LEFT), _______, _______, _______, _______, _______, _______, _______, _______,
    _______,          _______, _______,          _______,          _______,          _______,          _______, _______, _______, _______, _______),

  // disables all keys
  [_locked] = LAYOUT_65_split_space(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,
    XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TG(_locked),
    XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX),
};

bool encoder_update_user(uint8_t index, bool clockwise) {
  if (index == 0) { // first encoder (multiple encoders are supported as an array)
    // if on bottom layers, encoder increases/decreases volume, else skips/goes back music tracks
    if (layer_state_is(_mac) || layer_state_is(_windows)) {
      if (clockwise) tap_code(KC_VOLU);
      else tap_code(KC_VOLD);
    }
    else if (layer_state_is(_fn)) {
      if (clockwise) tap_code(KC_MNXT);
      else tap_code(KC_MPRV);
    }
  }
  return true;
}

bool process_recorod_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case HELLO:
      if (record->event.pressed) SEND_STRING("HELLO WORLD!");
      break;
  }
  return true;
}
