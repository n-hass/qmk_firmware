#pragma once

enum my_keycodes {
  KC_MSCTRL = SAFE_RANGE,
  KC_LNPD,
  LED_TLDE,
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
  SSV_TOG
};

// Keymap layer names
#define _MAC 0
#define _WIN 1
#define _FNALL 2
#define _FNREVERT 3
#define _FNMENU 4

#ifdef ENCODER_ENABLE
	// rotary functions
	void rotary_volume_up(void);
	void rotary_volume_down(void);
	extern bool smlstp_vol; 
#endif
