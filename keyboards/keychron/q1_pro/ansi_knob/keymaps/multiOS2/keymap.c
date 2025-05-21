/* Copyright 2023 @ Keychron (https://www.keychron.com)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "shared.h"

// clang-format off

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_MAC] = LAYOUT_ansi_82(
        KC_ESC,  KC_BRID,  KC_BRIU,  KC_MCTL,  KC_LPAD,  RGB_VAD,  RGB_VAI,  KC_F7,    KC_F8,    KC_F9,    KC_MPRV,  KC_MPLY,  KC_MNXT,      KC_DEL,             KC_MUTE,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,       KC_BSPC,            KC_INSERT,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,      KC_BSLS,            KC_PGUP,
        MT_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,                KC_ENT,             KC_PGDN,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,                KC_RSFT,  KC_UP,
        KC_LCTL,  KC_LOPTN, KC_LCMMD,                               KC_SPC,                                 KC_LCMMD, KC_RALT,  MO(_FNMENU),  KC_LEFT,  KC_DOWN,  KC_RGHT
    ),

    [_WIN] = LAYOUT_ansi_82(
        KC_ESC,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    RGB_VAD,  RGB_VAI,  KC_F7,    KC_F8,    KC_F9,    KC_MPRV,  KC_MPLY,  KC_MNXT,      KC_DEL,             KC_MUTE,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,       KC_BSPC,            KC_INSERT,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,      KC_BSLS,            KC_PGUP,
        MT_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,                KC_ENT,             KC_PGDN,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,                KC_RSFT,  KC_UP,
        KC_LGUI,  KC_LALT,  KC_LCTL,                                KC_SPC,                                 KC_RGUI,  KC_RALT,  MO(_FNMENU),  KC_LEFT,  KC_DOWN,  KC_RGHT
    ),

    [_FNALL] = LAYOUT_ansi_82(
        _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,       KC_F13,             _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,      _______,            KC_F14,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,      _______,            KC_F15,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,                _______,            KC_F16,
        _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,                _______,  _______,
        _______,  _______,  _______,                                _______,                                _______,  _______, MO(_FNREVERT), _______,  _______,  _______
    ),


    // hybrid of limited controls from the _FNMENU layer and lower base layers media controls, for temporary switching from _FNALL. must be a subset of _FNMENU
    [_FNREVERT] = LAYOUT_ansi_82(
        _______,  KC_BRID, KC_BRIU, KC_MCTL,   KC_LPAD, RGB_VAD, RGB_VAI,    _______, _______, _______, KC_MPRV, KC_MPLY,  KC_MNXT, _______,           SSV_TOG,
        LED_TLDE, BT_HST1, BT_HST2, BT_HST3,   LED_4,      LED_5,   LED_6,   LED_7,   LED_8,   LED_9,   LED_0,   LED_MINS, LED_EQL, _______,           KC_PSCR,
        _______,  RGB_HUI, RGB_VAI, RGB_SAI,   _______,    RGB_TOG, _______, _______, _______, _______, _______, _______,  _______, RESET,             TO(_MAC),
        _______,  RGB_HUD, RGB_VAD, RGB_SAD,   TG(_FNALL), _______, _______, _______, _______, _______, _______, _______,           _______,           TO(_WIN),
        _______,           _______, _______,   _______,    _______, BAT_LVL, NK_TOGG, _______, _______, _______, _______,           _______, RGB_MOD,
        _______,  _______, KC_LGUI,                                 _______,                            _______, _______,  _______, RGB_SPD, RGB_RMOD, RGB_SPI
    ),

    // Command layout when holding down Fn key modifier
    [_FNMENU] = LAYOUT_ansi_82(
        KC_SLEP,  KC_F1,   KC_F2,   KC_F3,   KC_F4,      KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,    KC_F12,   _______,           SSV_TOG,
        LED_TLDE, BT_HST1, BT_HST2, BT_HST3, LED_4,      LED_5,   LED_6,   LED_7,   LED_8,   LED_9,   LED_0,   LED_MINS,  LED_EQL,  _______,           KC_PSCR,
        _______,  RGB_HUI, RGB_VAI, RGB_SAI, _______,    RGB_TOG, _______, _______, _______, _______, _______, _______,   _______,  RESET,             TO(_MAC),
        _______,  RGB_HUD, RGB_VAD, RGB_SAD, TG(_FNALL), _______, _______, _______, _______, TG_MOD,  _______, _______,             _______,           TO(_WIN),
        _______,           _______, _______, _______,    _______, BAT_LVL, NK_TOGG, _______, _______, _______, _______,             _______,  RGB_MOD,
        _______,  _______, KC_LGUI,                               _______,                            _______, _______, MO(_FNMENU), RGB_SPD, RGB_RMOD, RGB_SPI
    ),

};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [MAC_BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [MAC_FN] = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
    [WIN_BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [WIN_FN] = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI)}
};
#endif // ENCODER_MAP_ENABLE

/**
 * Almost the same as the default, but active swaps to layer 1 not 2
 */
bool dip_switch_update_user(uint8_t index, bool active) {
    if (index == 0) {
        default_layer_set(1UL << (active ? 1 : 0));
    }
    return true;
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    // make rgb alterations only possible when in the Fn menu layer
    if (IS_LAYER_ON(_FNMENU)) {
        // https://beta.docs.qmk.fm/using-qmk/simple-keycodes/feature_advanced_keycodes#alt-escape-for-alt-tab-id-alt-escape-for-alt-tab
        if (get_mods() & MOD_MASK_CTRL) { // If CTRL is held
            uint8_t mod_state = get_mods(); // Store all  modifiers that are held
            unregister_mods(MOD_MASK_CTRL); // Immediately unregister the CRTL key (don't send CTRL-PgDn) - del_mods doesn't work here (not immediate)
            if (clockwise) {
                rgblight_increase_hue();
            } else {
                rgblight_decrease_hue();
            }
            set_mods(mod_state); // Add back in the CTRL key - so ctrl-key will work if ctrl was never released after paging.
        }
        else if (get_mods() & MOD_MASK_ALT) {
            uint8_t mod_state = get_mods();
            unregister_mods(MOD_MASK_ALT);
            if (clockwise) {
                rgblight_increase_sat();
            } else {
                rgblight_decrease_sat();
            }
            set_mods(mod_state);
        }
        else if (get_mods() & MOD_MASK_GUI) {
            uint8_t mod_state = get_mods();
            unregister_mods(MOD_MASK_GUI);
            if (clockwise) {
                rgblight_increase_val();
            } else {
                rgblight_decrease_val();
            }
            set_mods(mod_state);
        } // only run shift rotary edit when not in Mac mode. Mac users may use shift for adjusting smaller volume increments
        else if (get_mods() & MOD_MASK_SHIFT) {
            uint8_t mod_state = get_mods();
            unregister_mods(MOD_MASK_SHIFT);
            if (clockwise) {
                rgblight_increase_speed();
            } else {
                rgblight_decrease_speed();
            }
            set_mods(mod_state);
        }
    }
    // volume and media control when not in Fn menu. includes exponential increases
    else {
        if (get_mods() & MOD_MASK_SHIFT) { // media controls with shift modifier
            if (clockwise) {
                tap_code(KC_MFFD);
            } else {
                tap_code(KC_MRWD);
            }
        } else { // volume control
            if (clockwise){
                rotary_volume_up();
            } else {
                rotary_volume_down();
            }
        }
    }
    return false;
}

#define LED_FLAG_CAPS LED_FLAG_NONE
#define LED_FLAG_EFFECTS LED_FLAG_INDICATOR
static bool caps_mod_enabled = true;

#if RGB_CONFIRMATION_BLINKING_TIME > 0
    static uint16_t effect_started_time = 0;
    static uint8_t r_effect = 0x0, g_effect = 0x0, b_effect = 0x0;
    static void trigger_flash_effect(void);

    /* The higher this is, the slower the blinking will be */
    #ifndef TIME_SELECTED_BIT
        #define TIME_SELECTED_BIT 8
    #endif
    #if TIME_SELECTED_BIT < 0 || TIME_SELECTED_BIT >= 16
        #error "TIME_SELECTED_BIT must be a positive integer smaller than 16"
    #endif
    #define effect_red() r_effect = 0xFF, g_effect = 0x0, b_effect = 0x0
    #define effect_green() r_effect = 0x0, g_effect = 0xFF, b_effect = 0x0
#endif // RGB_CONFIRMATION_BLINKING_TIME > 0

static void trigger_flash_effect() {
    effect_started_time = sync_timer_read();
    if (!rgb_matrix_is_enabled()) {
        /* Turn it ON, signal the cause (EFFECTS) */
        rgb_matrix_set_flags(LED_FLAG_EFFECTS);
        rgb_matrix_enable_noeeprom();
    } else if (rgb_matrix_get_flags() == LED_FLAG_CAPS) {
        /* It's already ON, promote the cause from CAPS to EFFECTS */
        rgb_matrix_set_flags(LED_FLAG_EFFECTS);
    }
}

bool rgb_matrix_indicators_user() {
    #if RGB_CONFIRMATION_BLINKING_TIME > 0
        if (effect_started_time > 0) {
            /* Render blinking EFFECTS */
            uint16_t deltaTime = sync_timer_elapsed(effect_started_time);
            if (deltaTime <= RGB_CONFIRMATION_BLINKING_TIME) {
                uint8_t led_state = ((~deltaTime) >> TIME_SELECTED_BIT) & 0x01;
                uint8_t val_r = led_state * r_effect;
                uint8_t val_g = led_state * g_effect;
                uint8_t val_b = led_state * b_effect;
                rgb_matrix_set_color_all(val_r, val_g, val_b);
            } else {
                /* EFFECTS duration is finished */
                effect_started_time = 0;
                if (rgb_matrix_get_flags() == LED_FLAG_EFFECTS) {
                    /* It was turned ON because of EFFECTS */
                    if (host_keyboard_led_state().caps_lock) {
                        /* CAPS is still ON. Demote to CAPS */
                        rgb_matrix_set_flags(LED_FLAG_CAPS);
                    } else {
                        /* There is nothing else keeping RGB enabled. Reset flags and turn if off. */
                        rgb_matrix_set_flags(LED_FLAG_ALL);
                        rgb_matrix_disable_noeeprom();
                    }
                }

            }

            if (rgb_matrix_get_flags() == LED_FLAG_CAPS) {
                rgb_matrix_set_color_all(0x0, 0x0, 0x0);
            }
            return false;
        }
    #endif // RGB_CONFIRMATION_BLINKING_TIME > 0

    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SSV_TOG:
            if (record->event.pressed) {
                if (smlstp_vol) {
                    smlstp_vol = false;
                    effect_red();
                } else {
                    smlstp_vol = true;
                    effect_green();
                }
                trigger_flash_effect();
            }
        return false;

        #if RGB_CONFIRMATION_BLINKING_TIME > 0
            case NK_TOGG:
                if (record->event.pressed) {
                    if (keymap_config.nkro) {
                        /* Turning NKRO OFF */
                        effect_red();
                    } else {
                        /* Turning NKRO ON */
                        effect_green();
                    }
                    trigger_flash_effect();
                }
            break;
        #endif // RGB_CONFIRMATION_BLINKING_TIME > 0

        #if RGB_CONFIRMATION_BLINKING_TIME > 0
        case TG(_FNALL):
            if (record->event.pressed) {
                if (IS_LAYER_OFF(_FNALL)) {
                    effect_red();
                } else {
                    effect_green();
                }
                trigger_flash_effect();
            }
        break;
        #endif // RGB_CONFIRMATION_BLINKING_TIME > 0

        /* LED quick preset keys assignments */
        case LED_TLDE:
            rgb_matrix_mode(RGB_MATRIX_DEFAULT_VAL);          // Can use RGB_M_P built-in keycode instead.
        break;
        case LED_1:
            rgb_matrix_mode(RGB_MATRIX_SOLID_COLOR);
        break;
        case LED_2:
            rgb_matrix_mode(RGB_MATRIX_CYCLE_UP_DOWN);
        break;
        case LED_3:
            rgb_matrix_mode(RGB_MATRIX_JELLYBEAN_RAINDROPS);
        break;
        case LED_4:
            rgb_matrix_mode(RGB_MATRIX_DUAL_BEACON);
        break;
        case LED_5:
            rgb_matrix_mode(RGB_MATRIX_VAL_STEP);
        break;
        case LED_6:
            rgb_matrix_mode(RGB_MATRIX_BAND_SPIRAL_VAL);
        break;
        case LED_7:
            rgb_matrix_mode(RGB_MATRIX_CYCLE_LEFT_RIGHT);    // Can use RGB_M_R built-in keycode instead.
        break;
        case LED_8:
            rgb_matrix_mode(RGB_MATRIX_BREATHING);    // Can use RGB_M_SW built-in keycode instead.
        break;

        #ifdef RGB_MATRIX_KEYPRESSES                         // Reactive effects require RGB_MATRIX_KEYPRESSES in config.h
        case LED_9:
            rgb_matrix_mode(RGB_MATRIX_SPLASH);       // Can use RGB_M_B built-in keycode instead.
        break;

        case LED_0:
            rgb_matrix_mode(RGB_MATRIX_SOLID_SPLASH);
        break;
        #endif //RGB_MATRIX_KEYPRESSES

        #ifdef RGB_MATRIX_FRAMEBUFFER_EFFECTS               // Heatmap and Rain require #define RGB_MATRIX_FRAMEBUFFER_EFFECTS in config.h
        case LED_MINS:
            rgb_matrix_mode(RGB_MATRIX_DIGITAL_RAIN);
        break;
        case LED_EQL:
            rgb_matrix_mode(RGB_MATRIX_TYPING_HEATMAP);
        break;
        #endif //RGB_MATRIX_FRAMEBUFFER_EFFECTS


        // case RGB_MOD:
        // case RGB_RMOD:
        // case RGB_HUI:
        // case RGB_HUD:
        // case RGB_SAI:
        // case RGB_SAD:
        // case RGB_VAI:
        // case RGB_VAD:
        // case RGB_SPI:
        case RGB_SPD:
            if (record->event.pressed) {
                if (rgb_matrix_get_flags() != LED_FLAG_ALL) {
                    /* Ignore changes to RGB settings while only it's supposed to be OFF */
                    return false;
                }
            }
        break;

        case RGB_TOG:
            if (record->event.pressed) {
                if (rgb_matrix_is_enabled()) {
                    switch (rgb_matrix_get_flags()) {
                        #if RGB_CONFIRMATION_BLINKING_TIME > 0
                        case LED_FLAG_EFFECTS:
                        #endif
                        case LED_FLAG_CAPS:
                        /* Turned ON because of EFFECTS or CAPS, is actually OFF */
                        /* Change to LED_FLAG_ALL to signal it's really ON */
                        rgb_matrix_set_flags(LED_FLAG_ALL);
                        /* Will be re-enabled by the processing of the toggle */
                        rgb_matrix_disable_noeeprom();
                        break;
                        case LED_FLAG_ALL:
                        /* Is actually ON */
                        #if RGB_CONFIRMATION_BLINKING_TIME > 0
                        if (effect_started_time > 0) {
                            /* Signal EFFECTS */
                            rgb_matrix_set_flags(LED_FLAG_EFFECTS);
                            /* Will be re-enabled by the processing of the toggle */
                            rgb_matrix_disable_noeeprom();
                        } else
                        #endif
                        if (host_keyboard_led_state().caps_lock) {
                            /* Signal CAPS */
                            rgb_matrix_set_flags(LED_FLAG_CAPS);
                            /* Will be re-enabled by the processing of the toggle */
                            rgb_matrix_disable_noeeprom();
                        }
                        break;
                    }
                }
            }
        break;

        case TG_MOD:
            if (record->event.pressed) {
                #if RGB_CONFIRMATION_BLINKING_TIME > 0
                    if (caps_mod_enabled) {
                        effect_red();
                    } else {
                        effect_green();
                    }
                    trigger_flash_effect();
                #endif
                caps_mod_enabled = !caps_mod_enabled;
            }
            return false;
        break;

        case MT_CAPS:
            if (!caps_mod_enabled) {
                if (record->event.pressed) {
                    register_code(KC_CAPS);
                } else {
                    unregister_code(KC_CAPS);
                }
                return false;
            }
        break;

        case KC_ESC:
            if (caps_mod_enabled) {
                if (record->event.pressed) {
                    register_code(KC_CAPS);
                } else {
                    unregister_code(KC_CAPS);
                }
                return false;
            }
        break;
    }

    return true;
}
