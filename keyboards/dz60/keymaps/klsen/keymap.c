#include QMK_KEYBOARD_H

/* Hello hello
 * i have a readme now
 */

// custom colors here
#define HSV_CUSTOM_GREEN 65, 232, 180
#define HSV_CUSTOM_GREEN2 65, 232, 255
#define HSV_CUSTOM_RED 0, 255, 150

enum my_keycodes {
	KC_BSPC2 = SAFE_RANGE,
	RGB_ALT,
	RGB_TWKL,
	WPM_MODE
};

enum my_layers {
	_base,
	_fn,
	_rgb
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_base] = LAYOUT_all( \
		KC_GESC, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS, KC_EQL , KC_NO  , KC_BSPC2, \
		KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_LBRC, KC_RBRC, KC_BSLS, \
		KC_CAPS, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT, KC_ENT , \
		KC_LSFT, KC_NO  , KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_RSFT, KC_UP  , MO(_rgb), \
		KC_LCTL, KC_LGUI, KC_LALT, KC_SPC , MO(_fn), KC_BSPC, KC_RALT, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT),
	[_fn] = LAYOUT_all( \
		KC_GRV , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 , KC_NO  , _______, \
		_______, KC_MPRV, KC_MPLY, KC_MNXT, KC_VOLD, KC_VOLU, KC_MUTE, KC_7   , KC_8   , KC_9   , KC_PAST, KC_PSLS, KC_NO  , KC_CALC, \
		_______, KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_4   , KC_5   , KC_6   , KC_PPLS, KC_PMNS, KC_NO  , \
		_______, KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_0   , KC_1   , KC_2   , KC_3   , KC_NO  , _______, KC_PGUP, _______, \
		_______, _______, _______, _______, KC_TRNS, KC_DEL , _______, _______, KC_HOME, KC_PGDN, KC_END ),
	[_rgb] = LAYOUT_all( \
		RGB_TOG, RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW, RGB_M_SN, RGB_M_K, RGB_M_X, RGB_M_G, RGB_M_T, RGB_ALT, RGB_TWKL, KC_NO, KC_NO , KC_NO  , \
		KC_NO  , KC_NO  , WPM_MODE, KC_NO , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , RGB_RMOD, RGB_MOD, KC_NO , \
		KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , \
		KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , RGB_VAI, KC_TRNS, \
		KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_TRNS, KC_NO, RGB_SAD, RGB_SAI, RGB_HUD, RGB_VAD, RGB_HUI)
};

// code for rgb lighting layers (following example)
const rgblight_segment_t PROGMEM caps_rgblayer[] = RGBLIGHT_LAYER_SEGMENTS(
	// left side leds green
	{0, 2, HSV_CUSTOM_GREEN2},
	{14, 2, HSV_CUSTOM_GREEN2}
);

const rgblight_segment_t PROGMEM layer1_rgblayer[] = RGBLIGHT_LAYER_SEGMENTS(
	// bottom row green
	{8, 8, HSV_CUSTOM_GREEN}
);

const rgblight_segment_t PROGMEM backspace_rgblayer[] = RGBLIGHT_LAYER_SEGMENTS(
	// all leds red
	{0, 16, HSV_CUSTOM_RED}
);

const rgblight_segment_t* const PROGMEM rgblayers[] = RGBLIGHT_LAYERS_LIST(
	caps_rgblayer,
	layer1_rgblayer,
	backspace_rgblayer
);

void keyboard_post_init_user(void) {
	rgblight_layers = rgblayers;
}

layer_state_t layer_state_set_user(layer_state_t state) {
	// numbering follows order of rgblayers array
	rgblight_set_layer_state(1, layer_state_cmp(state, _fn));
	return state;
}

bool led_update_user(led_t led_state) {
	rgblight_set_layer_state(0, led_state.caps_lock);
	return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	static bool wpm_mode_active = false;
	switch (keycode) {
		// custom keycodes for lighting tricks
		case KC_BSPC2:
			if (record->event.pressed) {
				register_code(KC_BSPC);
				rgblight_set_layer_state(2, true);
			}
			else {
				unregister_code(KC_BSPC);
				rgblight_set_layer_state(2, false);
			}
			return true;
		case RGB_ALT:
			if (record->event.pressed) {
				rgblight_mode(RGBLIGHT_MODE_ALTERNATING);
			}
			return true;
		case RGB_TWKL:
			if (record->event.pressed) {
				// 6 different twinkle modes. cycle through them if pressed repeatedly, else go to 1st mode
				uint8_t mode = rgblight_get_mode();
				if (mode >= RGBLIGHT_MODE_TWINKLE && mode < RGBLIGHT_MODE_TWINKLE+5) { // +5 to avoid %6 tricks
					rgblight_mode(mode+1);
				}
				else rgblight_mode(RGBLIGHT_MODE_TWINKLE);
			}
			return true;
		// code for basic wpm lighting mode
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
			// rough numbers.
			// numbers are not really accurate from what I can feel. think it's higher than it should be.
			if (wpm_mode_active == true) {
				uint8_t wpm = get_current_wpm();
				if (wpm >= 100 && wpm < 150) rgblight_mode_noeeprom(RGBLIGHT_MODE_SNAKE+2);
				else if (wpm >= 150) rgblight_mode_noeeprom(RGBLIGHT_MODE_SNAKE+4);
				else rgblight_mode_noeeprom(RGBLIGHT_MODE_SNAKE);
			}
			return true;
	}
}

/*
void suspend_power_down_user(void) {
	rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_GRADIENT);
	while (rgblight_get_sat() < 255) rgblight_increase_sat_noeeprom();
	while (rgblight_get_val() > 40) rgblight_decrease_val_noeeprom();
}

void suspend_wakeup_init_user(void) {
	rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
}
*/
