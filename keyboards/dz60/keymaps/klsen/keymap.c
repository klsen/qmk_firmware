// Personal keymap for my DZ60 keyboard.
// I have a readme :)
//
// Kenneth Seneres
// Sept. 2, 2020

#include QMK_KEYBOARD_H
// #include <print.h>

// custom colors here
#define HSV_CUSTOM_GREEN    64 , 216, 104
#define HSV_CUSTOM_ORANGE   16 , 248, 120
#define HSV_CUSTOM_PURPLE   192, 224, 104
#define HSV_CUSTOM_BLUE     120, 176, 104
#define HSV_CUSTOM_RED      0  , 255, 150
static uint8_t plain_color = 0;
#define PLAIN_COLOR_MODES 4

enum my_keycodes {
	KC_BSPC2 = SAFE_RANGE,
	RGB_ALT,
	RGB_TWKL,
	WPM_MODE,
    SWP_SPC,
    RGB_REAC
};

enum my_layers {
	_base,
	_fn,
    _mouse,
    _mouse_mod,
	_rgb
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // primary layout
	[_base] = LAYOUT_all( \
		KC_GESC, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS, KC_EQL , KC_NO  , KC_BSPC2, \
		KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_LBRC, KC_RBRC, KC_BSLS, \
		TG(_mouse), KC_A, KC_S   , KC_D   , KC_F   , KC_G   , KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT, KC_ENT , \
		KC_LSFT, KC_NO  , KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_RSFT, KC_UP  , MO(_rgb), \
		KC_LCTL, KC_LGUI, KC_LALT, KC_SPC , MO(_fn), KC_BSPC, KC_RALT, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT),
	// secondary layout for alternate functions
    [_fn] = LAYOUT_all( \
		KC_GRV , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 , KC_NO  , SWP_SPC, \
		_______, KC_MUTE, KC_VOLU, KC_MPLY, KC_NO  , KC_NO  , KC_NO  , KC_7   , KC_8   , KC_9   , KC_PAST, KC_PSLS, KC_NO  , KC_CALC, \
		_______, KC_MPRV, KC_VOLD, KC_MNXT, KC_NO  , KC_NO  , KC_NO  , KC_4   , KC_5   , KC_6   , KC_PPLS, KC_PMNS, KC_NO  , \
		_______, KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_0   , KC_1   , KC_2   , KC_3   , KC_NO  , _______, KC_PGUP, _______, \
		_______, _______, _______, _______, KC_TRNS, KC_DEL , _______, _______, KC_HOME, KC_PGDN, KC_END),
    [_mouse] = LAYOUT_all( \
		KC_NO  , KC_VOLD, KC_VOLU, KC_MPLY, KC_MPRV, KC_MNXT, KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , \
		KC_NO  , KC_BTN2, KC_MS_U, KC_BTN1, KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , \
		_______, KC_MS_L, KC_MS_D, KC_MS_R, KC_NO  , KC_NO  , KC_NO  , KC_ACL0, KC_ACL1, KC_ACL2, KC_NO  , KC_NO  , KC_NO  , \
		KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , _______, \
		KC_NO  , KC_NO  , KC_NO  , KC_NO  , MO(_mouse_mod),KC_NO, KC_NO, KC_NO, KC_NO  , KC_NO  , KC_NO  ),
    [_mouse_mod] = LAYOUT_all( \
		KC_NO  , KC_VOLD, KC_VOLU, KC_MPLY, KC_MPRV, KC_MNXT, KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , \
		KC_NO  , _______, KC_WH_U, _______, KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , \
		_______, KC_WH_L, KC_WH_D, KC_WH_R, KC_NO  , KC_NO  , KC_NO  , _______, _______, _______, KC_NO  , KC_NO  , KC_NO  , \
		KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , _______, \
		KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_TRNS, KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ),
    // layout for setting rgb
	[_rgb] = LAYOUT_all( \
		RGB_TOG, RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW,RGB_M_SN,RGB_M_K, RGB_M_X, RGB_M_G, RGB_M_T, RGB_ALT, RGB_TWKL,KC_NO  , KC_NO , KC_NO  , \
		KC_NO  , KC_NO  , WPM_MODE,KC_NO  , RGB_REAC,KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , RGB_RMOD,RGB_MOD, KC_NO , \
		KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , \
		KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , RGB_VAI, KC_TRNS, \
		KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_TRNS, KC_NO  , RGB_SAD, RGB_SAI, RGB_HUD, RGB_VAD, RGB_HUI)
};

void keyboard_post_init_user(void) {
	// debug_enable = true;
}

// This is used for turning the lower row of LEDs brighter to show the fn layer.
layer_state_t layer_state_set_user(layer_state_t state) {
    uint8_t layer = biton32(state);
    static uint8_t mode = RGBLIGHT_MODE_STATIC_LIGHT;
    static uint8_t prev_layer = _base;
    uint8_t hue = rgblight_get_hue();
    uint8_t sat = rgblight_get_sat();

    // checks what layer is currently on
    // needs to be able to revert to the old lighting mode when fn is released
    // needs to do nothing when rgb layer is on
    if (rgblight_get_mode() == RGBLIGHT_MODE_STATIC_LIGHT){
        switch(layer) {
            case _base:
                if (prev_layer != _rgb) rgblight_mode(mode);
                break;
            case _fn:
                mode = rgblight_get_mode();
                rgblight_sethsv_range(hue, sat, 180, 8, 16);
                break;
            default: break;
        }
        prev_layer = layer;
    }

    return state;
}

// This is used to brighten the two leftmost LEDs to show that caps lock is on.
// Only runs when the lighting mode is static/plain.
bool led_update_user(led_t led_state) {
    static uint8_t caps_pressed = false;
    uint8_t mode = rgblight_get_mode();
    uint8_t hue = rgblight_get_hue();
    uint8_t sat = rgblight_get_sat();
    uint8_t val = rgblight_get_val();

    if (mode == RGBLIGHT_MODE_STATIC_LIGHT) {
        // code after caps has just turned off. led_state.caps_lock doesnt work because it'll run all the time
        // reverts leds back to previous color
        if (caps_pressed == true) {
            caps_pressed = false;
            rgblight_sethsv_at(hue, sat, val, 0);
            rgblight_sethsv_at(hue, sat, val, 15);
        }
        // code for caps on
        if (led_state.caps_lock == true) {
            caps_pressed = true;
            rgblight_sethsv_at(hue, sat, 255, 0);
            rgblight_sethsv_at(hue, sat, 255, 15);
        }
    }
    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint8_t mode, hue, sat, val;
	static bool wpm_mode_active = false;
    static bool swap_space = false;
    static bool reactive_lighting = false;
	uint8_t prev_mode = rgblight_get_mode();

	switch (keycode) {
		// custom keycodes for lighting tricks
        // turn all lights red when pressing the wrong backspace. revert to previous lighting mode when released
		case KC_BSPC2: ; // ; because of declaration after label (in start of case) error
			if (record->event.pressed) {
				register_code(KC_BSPC);
				mode = rgblight_get_mode();
				hue = rgblight_get_hue();
				sat = rgblight_get_sat();
				val = rgblight_get_val();
				rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
				rgblight_sethsv_noeeprom(HSV_CUSTOM_RED);
			}
			else {
				unregister_code(KC_BSPC);
				rgblight_mode(mode);
				rgblight_sethsv(hue, sat, val);
			}
			return true;
        // code to swap functionality of spacebar and backspace keys on a toggle.
        // using custom keycode instead of DF() keycode provided so I can turn on some lights
        case SWP_SPC:
            if (record->event.pressed) {
                swap_space = !swap_space;
                mode = rgblight_get_mode();
				hue = rgblight_get_hue();
				sat = rgblight_get_sat();
				val = rgblight_get_val();
                if (mode == RGBLIGHT_MODE_STATIC_LIGHT) {
                    rgblight_sethsv_at(hue, sat, 255, 7);
                }
            }
            else {
                rgblight_sethsv_at(hue, sat, val, 7);
            }
            return true;
        // keycode for alternating lighting mode. didn't have its own keycode before.
		case RGB_ALT:
			if (record->event.pressed) {
				rgblight_mode(RGBLIGHT_MODE_ALTERNATING);
			}
			return true;
        // same for twinkle lighting mode. guess it's not mature enough for QMK.
		case RGB_TWKL:
			if (record->event.pressed) {
				// 6 different twinkle modes. cycle through them if pressed repeatedly, else go to 1st mode
				uint8_t mode = rgblight_get_mode();
				if (mode >= RGBLIGHT_MODE_TWINKLE && mode < RGBLIGHT_MODE_TWINKLE+5) { // +5 instead of +6 to avoid %6 tricks
					rgblight_mode(mode+1);
				}
				else rgblight_mode(RGBLIGHT_MODE_TWINKLE);
			}
			return true;
        // using the rgb_mode_plain keycode to cycle through different colors instead of just keeping one.
        // add more cases if you add more colors (and also change the defines on top thx)
		case RGB_M_P:
			if (record->event.pressed) {
                if (prev_mode == RGBLIGHT_MODE_STATIC_LIGHT) plain_color = (plain_color + 1) % PLAIN_COLOR_MODES;
				switch(plain_color) {
					case 0: rgblight_sethsv(HSV_CUSTOM_GREEN); break;
					case 1:	rgblight_sethsv(HSV_CUSTOM_ORANGE);	break;
					case 2:	rgblight_sethsv(HSV_CUSTOM_PURPLE);	break;
					case 3:	rgblight_sethsv(HSV_CUSTOM_BLUE); break;
					default: break;
				}
			}
			return true;
        // enables/disables reactive lighting hack
        case RGB_REAC:
            if (record->event.pressed) {
                reactive_lighting = !reactive_lighting;
                if (reactive_lighting == true) {
                    mode = rgblight_get_mode();
                    hue = rgblight_get_hue();
                    sat = rgblight_get_sat();
                    val = rgblight_get_val();
                    rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
                    rgblight_sethsv_noeeprom(0, 0, 0);
                }
                else {
                    rgblight_mode(mode);
				    rgblight_sethsv(hue, sat, val);
                }
            }
        // runs the snake lighting animation at different speeds depending on wpm
        // uses QMK's get_current_wpm() implementation.
		case WPM_MODE:
			if (record->event.pressed) {
				if (wpm_mode_active == true) {
					wpm_mode_active = false;
					rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
				}
				else wpm_mode_active = true;
			}
			return true;
		default:
			// rough numbers. had to adjust, but this feels right.
			if (wpm_mode_active == true) {
				uint8_t wpm = get_current_wpm();
				if (wpm >= 100 && wpm < 150) rgblight_mode_noeeprom(RGBLIGHT_MODE_SNAKE+2);
				else if (wpm >= 150) rgblight_mode_noeeprom(RGBLIGHT_MODE_SNAKE+4);
				else rgblight_mode_noeeprom(RGBLIGHT_MODE_SNAKE);
			}
            // code for handling space and backspace swap
            if (swap_space && (keycode == KC_SPC || keycode == KC_BSPC || keycode == KC_DEL)) {
                if (record->event.pressed) {
                    if (keycode == KC_SPC) {
                        unregister_code(KC_SPC);
                        if (IS_LAYER_ON(_base)) register_code(KC_BSPC);
                        if (IS_LAYER_ON(_fn)) register_code(KC_DEL);
                    }
                    else if (keycode == KC_BSPC || keycode == KC_DEL) {
                        unregister_code(KC_BSPC);
                        unregister_code(KC_DEL);
                        register_code(KC_SPC);
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
            if (reactive_lighting == true) {
                int ledi = rand()%16;
                // mode = rgblight_get_mode();
				// hue = rgblight_get_hue();
				// sat = rgblight_get_sat();
				// val = rgblight_get_val();
                if (record->event.pressed) {
                    // only flashes for an instant and turns off before key up if i dont have the 2 lines i thought i didnt need.
                    rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
                    rgblight_sethsv_noeeprom(0, 0, 0);
                    rgblight_sethsv_at(hue, sat, val, ledi);
                }
                else {
                    // rgblight_mode(mode);
                    // rgblight_sethsv(hue, sat, val);
                    // rgblight_sethsv_at(0, 0, 0, ledi);
                }
            }
			return true;
	}
}

// tried to do lighting on computer sleep. doesn't work
// void suspend_power_down_user(void) {
// 	rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_GRADIENT);
// 	while (rgblight_get_sat() < 255) rgblight_increase_sat_noeeprom();
// 	while (rgblight_get_val() > 40) rgblight_decrease_val_noeeprom();
// }

// void suspend_wakeup_init_user(void) {
// 	rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
// }
