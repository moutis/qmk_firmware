
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint8_t  saved_mods   = 0;
//
//  static uint16_t pre_keycode = KC_RCBR;
#ifdef LEADER_ENABLE
    extern bool leading;
    if (!leading) {
#endif
        uint16_t record_keycode = keycode;
        uint16_t record_timer = timer_read(); // for hold timing
        // Filter out the actual keycode from MT and LT keys.
        if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) || (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) {
            record_keycode &= 0xFF;  // mask off the tap mods
        }

        switch (record_keycode) {
            case KC_APP:  // mimic windows app key behavior?
                if (record->event.pressed) {
                    saved_mods = get_mods(); // keep updating mods while held
                    if (!(saved_mods & MOD_MASK_GUI)) { // gui/alt not down
                        appmenu_timer = record_timer; // time held, or since last pressed alone
                        if (user_config.osIsWindows) {
                            register_code(KC_LALT);
                        } else {
                            register_code(KC_LGUI);
                        }
                    } else {
                        appmenu_on = true; // menu without timer (hold alt/gui)
                    }
                    register_code(KC_TAB);
                } else {
                    unregister_code(KC_TAB);
                    if (!appmenu_on) { // never used the menu mode, so just switch apps/windows
                        if (user_config.osIsWindows) {
                            unregister_code(KC_LALT);
                        } else {
                            unregister_code(KC_LGUI);
                        }
                        appmenu_timer = 0;  // stop timing for the hold
                    }
                    appmenu_timer = timer_read(); // time since last pressed
                }
                break;
            case KC_BSPC:  // make S(KC_BSPC) = KC_DEL
                saved_mods = get_mods(); // keep updating mods while held
                // This logic feels kludgey.  fix it.
                if (record->event.pressed) { // key down
                    if ((saved_mods & MOD_MASK_SHIFT)) { // shift down with KC_BSPC?
                        set_mods(saved_mods & ~MOD_MASK_SHIFT); // turn off shift
                        register_code(KC_DEL);
                        set_mods(saved_mods); // restore shift state
                        key_trap = true;  // mode monitor – enter state
                        return false; // don't do more with this record.
                    }
                } else { // key up
                    if (key_trap) { // did we snag this earlier?
                        unregister_code(KC_DEL); // make sure KC_DEL isn't held down
                        unregister_code(KC_BSPC);
                        key_trap = false;  // mode monitor – exit state.
                        return false; // don't do more with this record.
                    }
                }
                return true; // Didn't handle this, do default
                break;

/*            case KC_Q:  // send "qu" if held
                if (record->event.pressed) {
                    keyhold_timer = 0;
                    register_code(KC_Q);
                    if (!(saved_mods & (MOD_MASK_GUI + MOD_MASK_ALT + MOD_MASK_CTRL))) { // Only allow shift or caps
                        keyhold_timer = timer_read(); // time held, or since last pressed alone
                        clear_mods();
                        tap_code(KC_U);
                        set_mods(saved_mods);
                    }
                    return false; // handled it
                } else {
                    unregister_code(KC_Q);
                    if (keyhold_timer && ((record_timer - keyhold_timer) > TAPPING_TERM)) {
                        tap_code(KC_BSPC);
                    }
                    keyhold_timer = 0;
                    return false; // handled it
                }
                return true;  // Didn't handle this
                break;
*/                case KC_LPRN:  // send "()" with insertion in the middle if held.
                    if (record->event.pressed) {
                        keyhold_timer = 0;
//                        if (!(saved_mods)) { // don't do this if any mods are down
                            keyhold_timer = timer_read(); // time held, or since last pressed alone
//                        }
                        tap_code16(KC_LPRN);
                        return false; // handled it
                    } else {
                        if (((record_timer - keyhold_timer) > TAPPING_TERM) && ((record_timer - keyhold_timer) < TAPPING_TERM * 3)) {
                            tap_code16(KC_RPRN);
                            tap_code16(KC_LEFT);
                        }
                        keyhold_timer = 0;
                        return false; // handled it
                    }
                    return true;  // Didn't handle this
                    break;
            }
#ifdef LEADER_ENABLE
        }
#endif
    return true;  // keep processing record
}
