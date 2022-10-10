#include QMK_KEYBOARD_H
#include "shared.h"

#ifdef ENCODER_ENABLE
	static uint16_t key_rotary_timer; // initialise timer for exponential volume changing
	bool smlstp_vol = false; // small-step volume control on Mac (modified with SHIFT+ALT), default to off

	void twoEx_tap(uint16_t keycode) {
		tap_code_delay(keycode, 10);
    	if (timer_elapsed(key_rotary_timer) < 60) {
    		tap_code_delay(keycode, 10); // if less than 60ms have passed, hit vol up again.
        	key_rotary_timer = timer_read();
      	} else {
        	key_rotary_timer = timer_read();
        	// do nothing if 60ms or more have passed
      	}
	}

	void threeEx_tap(uint16_t keycode) {
		tap_code_delay(keycode, 10);
	    if (timer_elapsed(key_rotary_timer) < 115) {
	    	tap_code_delay(keycode, 10); // if less than 115ms have passed, hit volume down another two times.
	        tap_code_delay(keycode, 10);
	        key_rotary_timer = timer_read();
	    } else {
	        key_rotary_timer = timer_read();
	        // do nothing if 100ms or more have passed
	    }
	}


	void rotary_volume_up(void) {
		if (IS_LAYER_ON(_MAC)) {
			// plan to make mac hold SHIFT+ALT to have smaller increments of volume change.
			if (smlstp_vol) {
				uint8_t mod_state = get_mods(); // save modifiers state
				clear_mods();
				register_mods(MOD_MASK_SA); // add the SHIFT+ALT mod mask
				
				threeEx_tap(KC_VOLU); // make the volume adjustment

				unregister_mods(MOD_MASK_SA);
				set_mods(mod_state); // reset modifiers to saved state
			} else {
				twoEx_tap(KC_VOLU);
			}
		} else {
        	twoEx_tap(KC_VOLU);
		}
	}


	void rotary_volume_down(void) {
		if(IS_LAYER_ON(_MAC)) {
			if (smlstp_vol) {
				uint8_t mod_state = get_mods(); // save modifiers state
				clear_mods();
				register_mods(MOD_MASK_SA); // add the SHIFT+ALT mod mask
				
				threeEx_tap(KC_VOLD); // make the volume adjustment

				unregister_mods(MOD_MASK_SA);
				set_mods(mod_state); // reset modifiers to saved state
			} else {
				twoEx_tap(KC_VOLD);
			}
		} else {
			twoEx_tap(KC_VOLD);
		}
	}

#endif // ENCODER_ENABLE