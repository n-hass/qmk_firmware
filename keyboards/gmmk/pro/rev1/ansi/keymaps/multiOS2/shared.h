#pragma once
#include QMK_KEYBOARD_H

// Keymap layer names
#define _MAC 0
#define _WIN 1
#define _FNALL 2
#define _FNREVERT 3
#define _FNMENU 4

enum my_keycodes {
    // LED quick-controls
    LED_TLDE = SAFE_RANGE,
    LED_1,
    LED_2,
    LED_3,
    LED_4,
    LED_5,
    LED_6,
    LED_7,
    LED_8,
    LED_9,
    LED_0,
    LED_MINS,
    LED_EQL,

    // Volume setting toggle for [S]mall [S]tep [V]olume
    SSV_TOG,

    // Caps-lock key custom Mod-Tap
    TG_MOD,
};

#define MT_CAPS MT(MOD_LCTL, KC_ESC)

// rotary functions
void rotary_volume_up(void);
void rotary_volume_down(void);
extern bool smlstp_vol;
