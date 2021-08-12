// #include QMK_KEYBOARD_H
#include "discipline/discipline.h"
#include "discipline/config.h"

enum my_layers {
    _base,
    _fn,
    _calc,
    _mouse,
    _mouse_mod,
    _locked
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // base layer
    [_base] = LAYOUT_65_split_space(
        KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_MPLY,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, TG(_calc),
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,           TG(_mouse),
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,   TG(_locked),
        KC_LCTL, KC_LGUI, KC_LALT,          KC_SPC,           MO(_fn),          KC_BSPC,          KC_RALT, KC_RCTL, KC_LEFT, KC_DOWN, KC_RIGHT),

    // function layer. mac os supported by swapping gui/win key and alt lol
    [_fn] = LAYOUT_65_split_space(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, RESET,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, AG_SWAP, AG_NORM, _______, _______,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,          _______,
        _______,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, KC_PGUP, _______,
        _______, _______, _______,          _______,          _______,          KC_DEL,           _______, _______, KC_HOME, KC_PGDN, KC_END),

    // calculator layer
    [_calc] = LAYOUT_65_split_space(
        KC_ESC,  KC_PPLS, KC_PMNS, KC_PAST, KC_PSLS, KC_EQL,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_CALC, XXXXXXX, KC_7,    KC_8,    KC_9,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
        XXXXXXX, XXXXXXX, KC_4,    KC_5,    KC_6,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_ENT,           XXXXXXX,
        XXXXXXX,          KC_0,    KC_1,    KC_2,    KC_3,    KC_DOT,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,          KC_SPC,           XXXXXXX,          KC_BSPC,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX),

    // emulates a sad mouse on wasd
    [_mouse] = LAYOUT_65_split_space(
        XXXXXXX, KC_BTN4, KC_BTN3, KC_BTN5, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, KC_BTN2, KC_MS_U, KC_BTN1, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          _______,
        KC_ACL0,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_LCTL, XXXXXXX, XXXXXXX,          KC_ACL1,          MO(_mouse_mod),   XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX),

    // mouse scrolling
    [_mouse_mod] = LAYOUT_65_split_space(
        XXXXXXX, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, _______, KC_WH_U, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, KC_WH_L, KC_WH_D, KC_WH_R, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          _______,
        _______,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        _______, XXXXXXX, XXXXXXX,          _______,          _______,          XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX),

    // layer that makes most keys do nothing
    [_locked] = LAYOUT_65_split_space(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,
        XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
        XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX),
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { // first encoder (multiple encoders are supported as an array)
        if (layer_state_is(_base)) {
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

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static bool swap_space = false;

    // code that handles 'swap space' feature
    if (swap_space && (keycode == KC_SPC || keycode == KC_BSPC || keycode == KC_DEL)) {
        if (record->event.pressed) {
            if (keycode == KC_SPC) {
                if (layer_state_is(_base)) register_code(KC_BSPC);
                else if (layer_state_is(_fn)) register_code(KC_DEL);
            }
            else if (keycode == KC_BSPC || keycode == KC_DEL) {
                if (layer_state_is(_base)) register_code(KC_SPC);
                else if (layer_state_is(_fn)) swap_space = false;
            }
            return false;
        }
        else {
            unregister_code(KC_SPC);
            unregister_code(KC_BSPC);
            unregister_code(KC_DEL);
            return false;
        }
    }
    else {
        if (keycode == KC_SPC && record->event.pressed && layer_state_is(_fn)) {
            swap_space = true;
            unregister_code(KC_SPC);
            return false;
        }
    }

    return true;
}