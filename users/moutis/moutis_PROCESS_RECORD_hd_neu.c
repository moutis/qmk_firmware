/*
 
 This is compatible with Hands Down Neu, Platinum (neu-lx), Silver (neu-nx), Bronze (neu-hx)
 May not"" play nice with Hands Down Gold (neu-tx) without some duplication (working on it.)
 
 Keyboard should report as ISO/JIS (not ANSI)
 
 */


bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    bool return_state = true;
    uint8_t  saved_mods;

    saved_mods = get_mods();
    return_state = true; // default is we didn't do anything


    // Do we turn off CAPS_WORD?
    if (!process_caps_word(keycode, record)) {
        return false; // took care of that key
    }

        // Do we handle an adaptive key?  (Semkey may send Adaptive?)
    if (!process_adaptive_key(keycode, record)) {
        return false; // took care of that key
    }
 
        // Do we handle a semantic key? Combos or adaptives could have sent one.
    if (!process_semkey(keycode, record)) {
        return false; // took care of that key
    }

    switch (keycode) { // should switch off record_keycode?
        case KC_APP:  // mimic windows app key behavior (only better?)
            if (record->event.pressed) {
                mods_held = (saved_mods & (MOD_MASK_GUI | MOD_MASK_ALT)); // were mods held?
                if (!mods_held) { // gui/alt not down, supply them
                    if (user_config.osIsWindows) {
                        register_code(KC_RALT);
                    } else {
                        register_code(KC_RGUI);
                    }
                }
                state_reset_timer = timer_read(); // (re)start timing hold for keyup below
                tap_code(KC_TAB);
            } else { // key up event
                if (!mods_held) {// just app key, so see if held for menu
                    if (!appmenu_on) {// menu not already up
                        if (timer_elapsed(state_reset_timer) > LINGER_TIME) { // held for menu?
                            appmenu_on = true; // turn on menu (taken down in matrix_scan_user)
                            state_reset_timer = timer_read(); // start timer
                        } else { // no, just a quick tap for app switch.
                            if (user_config.osIsWindows) { // let mod keys up now
                                unregister_code(KC_RALT);
                            } else {
                                unregister_code(KC_RGUI);
                            }
                            state_reset_timer = 0;  // stop the timer            
                        }
                    }
                }
            }
            return_state = false; // don't do more with this record.
            break;

        case CG_SWAP: // SINCE MAC IS MY DEFAULT switch to windows
            user_config.osIsWindows = true;  // Remember platform after powerdown
            OSIndex = 1;
            eeconfig_update_user(user_config.raw);
            break;
        case CG_NORM: // Back to mac
            user_config.osIsWindows = false;  // Remember platform after powerdown
            OSIndex = 0;
            eeconfig_update_user(user_config.raw);
            break;

        case KC_Q:  // for linger Qu (ironically, need to handle this direclty w/o the macros.)
            if (record->event.pressed) { // key down
                if ((!saved_mods) || (saved_mods & MOD_MASK_SHIFT)) { // can this linger?
                    linger_key =  keycode; // may add "u" in matrix_scan_user
                    linger_timer = state_reset_timer = timer_read(); // start timers threshold
                } // can only linger on no mods or shift
                register_code16(keycode);
            } else { //
                unregister_code16(keycode);
                linger_key = 0; // make sure nothing lingers
            }
            return_state = false; // don't do more with this record.
            break;

            /*
             Key overrides here. use SemKey wherever possible (del_wd?)
            */
#ifndef KEY_OVERRIDE_ENABLE
            /*
             QMK KEY_OVERRIDE in 14.1 doesn't release mods on time,
             it is also much larger, and can't integrate semkeys or linger keys,
             so for now I roll my own here.
            */

//        case KC_BSPC:  // make S(KC_BSPC) = KC_DEL; plus word_del L & R
        case LT(L_LANG_NUM,KC_BSPC):  // make S(KC_BSPC) = KC_DEL; plus word_del L & R
            // This logic feels kludgey (but it works).  fix it.
            if (record->event.pressed) { // key down
                if (saved_mods & MOD_MASK_SHIFT) { // shift down with KC_BSPC?
                    clear_keyboard(); // clean record to tinker with.
                    register_code16(KC_DEL);
                    key_trap = true;  // mode monitor on to clear this on keyup
                    return_state = false; // don't do more with this record.
                    set_mods(saved_mods);
                }
            } else { // key up
                if (key_trap) { // did we snag this earlier?
                    unregister_code16(KC_DEL); // make sure KC_DEL isn't held down
                    key_trap = false;  // mode monitor off.
                    return_state = false; // don't do more with this record.
                }
            }
            break;

        case KC_LPRN:  // SHIFT = { (linger=(|))
            if (record->event.pressed) { // key down
                if (!saved_mods) {
                    register_linger_key(keycode); // example of simple linger macro
                    return_state = false; // don't do more with this record.
                } else if ((saved_mods & MOD_MASK_SHIFT)) { // shift down with KC_RPRN?
                    clear_keyboard(); // clean record to tinker with.
                    if ((saved_mods & MOD_MASK_ALT)) { // alt also?
                        tap_code16(KC_LBRC);
                    } else {
                        tap_code16(KC_LCBR);
                    }
                    return_state = false; // don't do more with this record.
                } else {
                    if ((saved_mods & MOD_MASK_ALT)) { // alt down with KC_LPRN?
                        clear_keyboard(); // clean record to tinker with.
                        tap_code16(KC_LBRC);
                        return_state = false; // don't do more with this record.
                    }
                }
            } else { // keyup event
                if (!saved_mods) {
                    unregister_linger_key(); // stop lingering
                    return_state = false; // don't do more with this record.
                }
            }
            break;
        case KC_RPRN:  // send } FOR Shift )
            if (record->event.pressed) { // key downSS
                if ((saved_mods & MOD_MASK_SHIFT)) { // shift down with KC_RPRN?
                    clear_keyboard(); // clean record to tinker with.
                    if ((saved_mods & MOD_MASK_ALT)) { // alt also?
                        tap_code16(KC_RBRC);
                    } else {
                        tap_code16(KC_RCBR);
                    }
                    return_state = false; // don't do more with this record.
                } else {
                    if ((saved_mods & MOD_MASK_ALT)) { // alt down with KC_RPRN?
                        clear_keyboard(); // clean record to tinker with.
                        tap_code16(KC_RBRC);
                        return_state = false; // don't do more with this record.
                    }
                }
            }
            break;
        case KC_LBRC:  // SHIFT = ( (linger=(|))
            if (!saved_mods) {
                if (record->event.pressed) { // key down
                    register_linger_key(keycode); // example of simple linger macro
                } else { // keyup event
                    unregister_linger_key(); // stop lingering
                }
                return_state = false; // don't do more with this record.
            }
            break;
        case KC_LCBR:   // SHIFT = { (linger={|})
            if (!saved_mods) {
                if (record->event.pressed) { // key down
                    register_linger_key(keycode); // example of simple linger macro
                } else { // keyup event
                    unregister_linger_key(); // stop lingering
                }
                return_state = false; // don't do more with this record.
            }
            break;

        case KC_LT:  // SHIFT = ≥,
            if (record->event.pressed) { // key down
                if (saved_mods & MOD_MASK_SHIFT) { // shift down with KC_LT?
                    clear_keyboard(); // clean record to tinker with.
                    tap_code16(A(KC_COMM));
                    return_state = false; // don't do more with this record.
                }
            }
            break;
        case KC_GT:  // SHIFT = ≥,
            if (record->event.pressed) { // key downSS
                if (saved_mods & MOD_MASK_SHIFT) { // shift down with KC_GT?
                    clear_keyboard(); // clean record to tinker with.
                    tap_code16(A(KC_DOT));
                    return_state = false; // don't do more with this record.
                }
            }
            break;

        case KC_COMM:  // SHIFT = ;, ALT=_,
            if (record->event.pressed) { // key down
                if (saved_mods & MOD_MASK_ALT) { // ALT down?
                    clear_keyboard(); // clean record to tinker with.
                    if ((saved_mods & MOD_MASK_SHIFT)) { // SFT too?
                        tap_code16(A(KC_BSLS));
                    } else {
                        tap_code16(KC_UNDS);
                    }
                    return_state = false; // don't do more with this record.
                } else {
                    if (saved_mods & MOD_MASK_SHIFT) { // SHFT?
                        clear_keyboard(); // clean record to tinker with.
                        tap_code16(KC_SCLN); // just semicolon
                        return_state = false; // don't do more with this record.
                    }
                }
            }
            break;
        case KC_DOT:  // SHIFT = :, ALT=…, ALT+SHIFT= \ backslash
            if (record->event.pressed) { // key down
                if (saved_mods & MOD_MASK_ALT) { // ALT down?
                    clear_keyboard(); // clean record to tinker with.
                    if ((saved_mods & MOD_MASK_SHIFT)) { // SHFT too?
                        tap_code16(KC_BSLS);
                    } else {
                        tap_code16(A(KC_SCLN)); //
                    }
                    return_state = false; // don't do more with this record.
                } else {
                    if ((saved_mods & MOD_MASK_SHIFT)) { // SHFT?
                        clear_keyboard(); // clean record to tinker with.
                        tap_code16(KC_COLN);
                        return_state = false; // don't do more with this record.
                    }
                }
            }
            break;

        case KC_QUOT:  // SHIFT = [ (linger=[|]), ALT=‹, ALT+SHIFT=«
            if (record->event.pressed) { // key down
                if (saved_mods & MOD_MASK_ALT) { // ALT (only) down?
                    clear_keyboard(); // clean record to tinker with.
                    if (saved_mods & MOD_MASK_SHIFT) { // SHFT too?
                        tap_code16(A(KC_BSLS));
                    } else {
                        tap_code16(A(S(KC_3)));
                    }
                    return_state = false; // don't do more with this record.
                } else if (saved_mods & MOD_MASK_SHIFT) { // SHFT (only) down?
                    clear_keyboard(); // clean record to tinker with.
                    register_linger_key(KC_LBRC); // example of simple linger macro
                    return_state = false; // don't do more with this record.
                }
            } else { // keyup event (just unregister it)
                unregister_linger_key(); // stop lingering
                unregister_code16(keycode); // may still need to handle this
                return_state = false; // don't do more with this record.
            }
            break;
        case HD_DQUO:
        case KC_DQUO:  // SHIFT = ], ALT=›, ALT+SHIFT=»
            if (record->event.pressed) { // key down
                if (saved_mods) { // any mods?
                    if (saved_mods & MOD_MASK_ALT) { // ALT (only) down?
                        clear_keyboard(); // clean record to tinker with.
                        if (saved_mods & MOD_MASK_SHIFT) { // SHFT too?
                            tap_code16(A(S(KC_BSLS)));
                        } else {
                            tap_code16(A(S(KC_4)));
                        }
                        return_state = false; // don't do more with this record.
                    } else if (saved_mods & MOD_MASK_SHIFT) { // SHFT?
                        clear_keyboard(); // clean record to tinker with.
                        tap_code16(KC_RBRC);
                        return_state = false; // don't do more with this record.
                    }
                } else { // no mods, so linger
                    register_linger_key(keycode); // example of simple linger macro
                    return_state = false; // don't do more with this record.
                }
            } else { // keyup event (just unregister it)
                if (!saved_mods) {
                    unregister_linger_key(); // stop lingering
                    return_state = false; // don't do more with this record.
                }
            }
            break;

        case KC_QUES: // SHFT? = ¿
            if (record->event.pressed) { // key down
                if (saved_mods & MOD_MASK_SHIFT) { // SHFT? = ¿
//                  clear_keyboard(); // clean record to tinker with.
                    del_mods(MOD_MASK_CG); // turn off unused mods (timing off in 14.1)
                    tap_code16(S(A(KC_SLSH)));
                    return_state = false; // don't do more with this record.
                }
            }
            break;

        case KC_MINS:  // SHIFT = +, ALT=–(n-dash), ALT+SHIFT=±
            if (record->event.pressed) { // key down
                if (saved_mods & MOD_MASK_SHIFT) { // shift down?
                    del_mods(MOD_MASK_CG); // turn off unused mods (timing off in 14.1)
                    register_code16(KC_PLUS);
                    key_trap = true;  // mode monitor – enter state
                    return_state = false; // don't do more with this record.
                }
            } else { // key up
                if (key_trap) { // did we snag this earlier?
                    unregister_code16(KC_PLUS); //
                    key_trap = false;  // mode monitor – exit state.
                    return_state = false; // don't do more with this record.
                }
            }
            break;

        case KC_SLSH:  // SHIFT = *, ALT=\, ALT+SHIFT=⁄
            if (record->event.pressed) { // key down
                if (saved_mods & MOD_MASK_ALT) { // ALT down?
                    if (saved_mods & MOD_MASK_SHIFT) { // SHFT too?
                        tap_code16(A(S(KC_1))); // Y:
                    } else {
                        clear_keyboard(); // clean record to tinker with.
                        tap_code16(KC_BSLS); // N: just alt, so
                    }
                    return_state = false; // don't do more with this record.
               } else {
                    if (saved_mods & MOD_MASK_SHIFT) { // only SHFT?
                        del_mods(MOD_MASK_CAG); // turn off unused mods.
                        register_code16(KC_ASTR); // *
                        key_trap = true;  // mode monitor – enter state
                       return_state = false; // don't do more with this record.
                    }
                }
            } else {
                if (key_trap) { // did we snag this earlier?
                    unregister_code16(KC_ASTR); // *
                    key_trap = false;  // mode monitor – exit state.
                    return_state = false; // don't do more with this record.
                }
            }
            break;
        case KC_SCLN:  // SHIFT = ;, ALT=_,
            if (record->event.pressed) { // key down
                if (saved_mods & MOD_MASK_ALT) { // ALT down?
                    if ((saved_mods & MOD_MASK_SHIFT)) { // SHFT too?
                        clear_keyboard(); // clean record to tinker with.
                        tap_code16(KC_PERC); // %
                    } else {
                        tap_SemKey(SK_SECT); // §
                    }
                    return_state = false; // don't do more with this record.
                }
            }
            break;

            // KC_HASH and ilk are behaving weirdly after QMK 14.1
        case HD_HASH:
        case KC_HASH:  // SHIFT = @, ALT= , ALT+SHIFT=
            if (record->event.pressed) { // key down
                if (saved_mods & MOD_MASK_SHIFT) { // shift down?
                    // clear_keyboard(); // clean record to tinker with.
                    register_code16(KC_AT);
                    key_trap = true;  // mode monitor – enter state
                } else {
                    register_code16(KC_HASH);
                }
                return_state = false; // don't do more with this record.
            } else { // key up
                if (key_trap) { // did we snag this earlier?
                    unregister_code16(KC_AT); //
                    key_trap = false;  // mode monitor – exit state.
                } else {
                    unregister_code16(KC_HASH);
                }
                return_state = false; // don't do more with this record.
            }
 
            break;
#endif // KEY_OVERRIDE_ENABLE

    } // switch (keycode) {
//    if (!return_state) set_mods(saved_mods); // unnecessary? (false will dump state anyway)?
    return return_state;  // keep processing record
}


