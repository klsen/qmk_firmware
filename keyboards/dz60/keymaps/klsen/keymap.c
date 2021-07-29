// Personal keymap for my DZ60 keyboard.
// I have a readme :)
//
// Kenneth Seneres
// Sept. 2, 2020

#include QMK_KEYBOARD_H

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
    BSPC_OFF,
    RGB_MOOD,
    RGB_SWRL,
    RGB_TWKL,
    RGB_TWKL2,
    WPM_MODE,
    RGB_REAC
};

enum my_layers {
	_base,
	_fn,
    _calc,
    _base2,
    _fn2,
    _calc2,
    _mouse,
    _mouse_mod,
	_rgb,
    _locked
};

static bool swap_space = false;

enum combos {
    SWP_SPC
};

const uint16_t PROGMEM space_backspace_combo[] = {KC_SPC, KC_DEL, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    [SWP_SPC] = COMBO(space_backspace_combo, SWP_SPC)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // primary layout
	[_base] = LAYOUT_all( \
		KC_GESC, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS, KC_EQL , KC_NO  , KC_BSPC2, \
		KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_LBRC, KC_RBRC, KC_BSLS, \
		TG(_calc), KC_A , KC_S   , KC_D   , KC_F   , KC_G   , KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT, KC_ENT , \
		KC_LSFT, KC_NO  , KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_RSFT, KC_UP  , MO(_rgb), \
		KC_LCTL, KC_LGUI, KC_LALT, KC_SPC , MO(_fn), KC_BSPC, KC_RALT, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT),
	// secondary layout for alternate functions
    [_fn] = LAYOUT_all( \
		KC_GRV , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 , KC_NO  , BSPC_OFF, \
		_______, KC_MUTE, KC_VOLU, KC_MPLY, KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , TG(_locked), \
		TG(_mouse),KC_MPRV,KC_VOLD,KC_MNXT, KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , _______, \
		_______, KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , _______, KC_PGUP, _______, \
		_______, _______, _______, _______, KC_TRNS, KC_DEL , _______, _______, KC_HOME, KC_PGDN, KC_END),
    // layer for calculator
    [_calc] = LAYOUT_all( \
        KC_NO  , KC_PPLS, KC_PMNS, KC_PAST, KC_PSLS, KC_PEQL, KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , \
		KC_CALC, KC_NO  , KC_7   , KC_8   , KC_9   , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , \
		_______, KC_NO  , KC_4   , KC_5   , KC_6   , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_ENT , \
		KC_NO  , KC_NO  , KC_0   , KC_1   , KC_2   , KC_3   , KC_DOT , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , _______, KC_NO  , _______, \
		KC_NO  , KC_NO  , KC_NO  , KC_SPC , KC_TRNS, KC_BSPC, KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO ),
    // primary layer with space and backspace swapped
    [_base2] = LAYOUT_all( \
		KC_GESC, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS, KC_EQL , KC_NO  , KC_BSPC2, \
		KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_LBRC, KC_RBRC, KC_BSLS, \
		TG(_calc), KC_A , KC_S   , KC_D   , KC_F   , KC_G   , KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT, KC_ENT , \
		KC_LSFT, KC_NO  , KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_RSFT, KC_UP  , MO(_rgb), \
		KC_LCTL, KC_LGUI, KC_LALT, KC_BSPC, MO(_fn2), KC_SPC , KC_RALT, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT),
	// secondary layer with space and backspace swapped
    [_fn2] = LAYOUT_all( \
		KC_GRV , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 , KC_NO  , BSPC_OFF, \
		_______, KC_MUTE, KC_VOLU, KC_MPLY, KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , TG(_locked), \
		TG(_mouse),KC_MPRV,KC_VOLD,KC_MNXT, KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , _______, \
		_______, KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , _______, KC_PGUP, _______, \
		_______, _______, _______, KC_DEL , KC_TRNS, _______, _______, _______, KC_HOME, KC_PGDN, KC_END),
    // calc layer with space and backspace swapped
    [_calc2] = LAYOUT_all( \
        KC_NO  , KC_PPLS, KC_PMNS, KC_PAST, KC_PSLS, KC_PEQL, KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , \
		KC_CALC, KC_NO  , KC_7   , KC_8   , KC_9   , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , \
		_______, KC_NO  , KC_4   , KC_5   , KC_6   , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_ENT , \
		KC_NO  , KC_NO  , KC_0   , KC_1   , KC_2   , KC_3   , KC_DOT , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , _______, KC_NO  , _______, \
		KC_NO  , KC_NO  , KC_NO  , KC_BSPC, KC_TRNS, KC_SPC , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO ),
    // mouse-mimicking layers
    [_mouse] = LAYOUT_all( \
		KC_NO  , KC_BTN4, KC_BTN3, KC_BTN5, KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , \
		KC_NO  , KC_BTN2, KC_MS_U, KC_BTN1, KC_BTN3, KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , \
		KC_NO  , KC_MS_L, KC_MS_D, KC_MS_R, KC_NO,   KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , \
		KC_ACL0, KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , \
		KC_LCTL, KC_NO  , KC_NO  , KC_ACL2, MO(_mouse_mod),KC_NO, KC_NO, KC_NO, KC_NO  , KC_NO  , KC_NO  ),
    [_mouse_mod] = LAYOUT_all( \
		KC_NO  , _______, _______, _______, KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , \
		KC_NO  , _______, KC_WH_U, _______, KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , \
		TG(_mouse),KC_WH_L,KC_WH_D,KC_WH_R,KC_NO   , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , \
		_______, KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , \
		_______, KC_NO  , KC_NO  , _______, KC_TRNS, KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ),
    // layout for setting rgb
	[_rgb] = LAYOUT_all( \
		RGB_TOG, RGB_M_P, RGB_M_B,RGB_TWKL,RGB_TWKL2,RGB_MOOD,RGB_SWRL,RGB_M_X, RGB_M_G, KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , \
		KC_NO  , KC_NO  , WPM_MODE,KC_NO  , RGB_REAC,KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , RGB_RMOD,RGB_MOD, KC_NO , \
		KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , \
		KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , RGB_VAI, KC_TRNS, \
		KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_TRNS, KC_NO  , RGB_SAD, RGB_SAI, RGB_HUD, RGB_VAD, RGB_HUI),
    // layer where all the keys do nothing so you can just smack them
    [_locked] = LAYOUT_all( \
        KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO , KC_NO  , \
		KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , TG(_locked) , \
		KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , \
		KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , \
		KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  )
};

void process_combo_event(uint16_t combo_index, bool pressed) {
    switch(combo_index) {
        // code to swap space and backspace keys when space+fn+backspace are pressed
        case SWP_SPC:
            if (pressed) {
                swap_space = !swap_space;
                if (swap_space) default_layer_set(1U << _base2);
                else default_layer_set(1U << _base);
            }
            break;
    }
}

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
    uint8_t val = rgblight_get_val();

    // checks what layer is currently on
    // needs to be able to revert to the old lighting mode when fn is released
    // needs to do nothing when rgb layer is on
    if (rgblight_get_mode() == RGBLIGHT_MODE_STATIC_LIGHT){
        switch(layer) {
            case _base:
            case _base2:
                if (prev_layer != _rgb) rgblight_mode(mode);
                break;
            case _fn:
            case _fn2:
                mode = rgblight_get_mode();
                rgblight_sethsv_range(hue, sat, 180, 8, 16);
                break;
            case _calc:
                rgblight_sethsv_range(hue, sat, val, 8, 16);
                rgblight_sethsv_at(hue, sat, 180, 0);
                rgblight_sethsv_at(hue, sat, 180, 15);
                break;
            case _locked:
                rgblight_sethsv_range(hue, sat, 30, 0, 16);     // not using rgblight_sethsv() to keep the global hue, sat, val values
                break;
            default: break;
        }
    }
    // code for mouse layer is separate since it's using an animation
    switch(layer) {
        case _mouse:
            if (prev_layer != _mouse_mod) rgblight_mode_noeeprom(RGBLIGHT_MODE_TWINKLE+2);
            break;
        case _base:
        case _base2:
            if (prev_layer == _mouse || prev_layer == _mouse_mod) rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
        default:
            break;
    }

    prev_layer = layer;
    return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint8_t mode, hue, sat, val;
	static bool wpm_mode_active = false;
    static bool backspace_light_off = false;
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
                if (!backspace_light_off) {
                    rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
                    rgblight_sethsv_noeeprom(HSV_CUSTOM_RED);
                }
			}
			else {
				unregister_code(KC_BSPC);
				rgblight_mode(mode);
				rgblight_sethsv(hue, sat, val);
			}
			return true;
        // code to turn off the bright backspace lighting on-the-fly
        case BSPC_OFF:
            if (record->event.pressed) backspace_light_off = !backspace_light_off;
            return true;
        // RGB lighting code
        // I want to only use 1 speed for rainbow mood, rainbow swirl, and twinkle modes
        case RGB_MOOD:
            if (record->event.pressed) rgblight_mode(RGBLIGHT_MODE_RAINBOW_MOOD+2);
            return true;
        case RGB_SWRL:
            if (record->event.pressed) rgblight_mode(RGBLIGHT_MODE_RAINBOW_SWIRL+4);
            return true;
        // twinkle lighting mode. it's got its own keycode now, but then I'd have to update this repo.
		case RGB_TWKL:
			if (record->event.pressed) rgblight_mode(RGBLIGHT_MODE_TWINKLE+2);
            return true;
        case RGB_TWKL2:
            if (record->event.pressed) rgblight_mode(RGBLIGHT_MODE_TWINKLE+5);
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
			return true;
	}
}
