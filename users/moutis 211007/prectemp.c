uint8_t  saved_mods;

saved_mods = get_mods();
return_state = true; // default is we didn't do anything

// Filter out the actual keycode from MT and LT keys.
if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) || (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) {
    record_keycode &= 0xFF;  // mask off the tap mods
}

// Do we turn off CAPS_WORD?
if (!process_caps_word(keycode, record)) {
    return false; // took care of that key
}

    // Do we handle an adaptive key?
if (!process_adaptive_key(keycode, record)) {
    return false; // took care of that key
}
    // Do we handle a semantic key? Combos or adaptives could have sent one.
if (!process_semkey(keycode, record)) {
    return false; // took care of that key
}

record_keycode = (keycode & 0xFF); // just the basic keycode? THIS IS WRONG!!!
switch (keycode) {
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

#ifdef RGBLIGHT_ENABLE
      case RGB_MOD:
          if (record->event.pressed) {
            rgblight_mode(RGB_current_mode);
            rgblight_step();
            RGB_current_mode = rgblight_config.mode;
          }
        break;
/* undefined custom keycode (kyria/naked48). Sort this out
    case RGB_RST:
          if (record->event.pressed) {
            eeconfig_update_rgblight_default();
            rgblight_enable();
            RGB_current_mode = rgblight_config.mode;
          }
        break;
*/
#endif
    case CG_SWAP: // SINCE MAC IS MY DEFAULT switch to windows
        user_config.osIsWindows = true;  // Remember platform after powerdown
        OSIndex = 1;
        eeconfig_update_user(user_config.raw);
#ifdef OLED_DRIVER_ENABLE
        oled_set_cursor(oled_max_chars() - 3, 0);
        oled_write_P(PSTR("WIN"), false);
#endif // OLED_DRIVER_ENABLE
        break;
    case CG_NORM: // Back to mac
        user_config.osIsWindows = false;  // Remember platform after powerdown
        OSIndex = 0;
        eeconfig_update_user(user_config.raw);
#ifdef OLED_DRIVER_ENABLE
        oled_set_cursor(oled_max_chars() - 3, 0);
        oled_write_P(PSTR("MAC"), false);
#endif // OLED_DRIVER_ENABLE
        break;

        /*
            overrides here for off-map keys
         * QMK v14.1 overrides footprint is too big.
        */
    case KC_J:  // send Z FOR Alt-J
        // This logic feels kludgey, but it works. fix it?
        if (record->event.pressed) { // key down
            if ((saved_mods & MOD_MASK_ALT)) { // alt down with KC_J?
                clear_mods(); // turn off unused mods
                if (saved_mods & MOD_MASK_CTRL) {
                    if (saved_mods & MOD_MASK_ALT) { // so we need to check this
                        tap_code16(A(KC_J)); // reclaim access to this via ctrl
                    }
                } else {
                    if (saved_mods & MOD_MASK_SHIFT) { // alt down with KC_J?
                        register_code16(S(KC_Z));
                    } else {
                        register_code16(KC_Z);
                    }
                }
                return_state = false; // don't do more with this record.
            }
        } else {
            unregister_code16(KC_Z);
            return_state = false; // don't do more with this record.
        }
        break;
    case KC_X:  // send Q FOR Alt-X
        // This logic feels kludgey, but it works. fix it?
        if (record->event.pressed) { // key down
            if ((saved_mods & MOD_MASK_ALT)) { // alt down with KC_X?
                clear_mods(); // turn off unused mods
                if (saved_mods & MOD_MASK_CTRL) {
                    if (saved_mods & MOD_MASK_ALT) { // so we need to check this
                        tap_code16(A(KC_X)); // reclaim access to this via ctrl
                    }
                } else {
                    if (saved_mods & MOD_MASK_SHIFT) { // so we need to check this
                        register_code16(S(KC_Q));
                    } else {
                        register_code16(KC_Q);
                    }
                }
                return_state = false; // don't do more with this record.
            }
        } else {
            unregister_code16(KC_Q);
            return_state = false; // don't do more with this record.
        }
        break;

    case KC_Q:  //
        if (record->event.pressed) { // key down
            if ((!saved_mods) || (saved_mods & MOD_MASK_SHIFT)) { // can this linger?
//                    register_linger_key(kc);
                linger_key =  keycode; // may add "u" in matrix_scan_user
                linger_timer = state_reset_timer = timer_read(); // start timers threshold
            } // can only linger on no mods or shift
            register_code16(keycode);
        } else {
//                register_linger_key(keycode);
            unregister_code16(keycode);
            linger_key = 0; //
        }
        return_state = false; // don't do more with this record.
        break;

        /*
            Key overrides here. Should be updated to use SemKey
        */
    case KC_LPRN:  // send { FOR Shift (
        // This logic feels kludgey, but it works. fix it? convert to SemKey
        if (record->event.pressed) { // key down
            if (!saved_mods) {
                register_linger_key(keycode); // example of simple linger macro
                return_state = false; // don't do more with this record.
            } else if ((saved_mods & MOD_MASK_SHIFT)) { // shift down with KC_RPRN?
                clear_mods(); // turn off unused mods
                if ((saved_mods & MOD_MASK_ALT)) { // alt also?
                    tap_code16(KC_LBRC);
                } else {
                    tap_code16(KC_LCBR);
                }
                return_state = false; // don't do more with this record.
            } else {
                if ((saved_mods & MOD_MASK_ALT)) { // alt down with KC_LPRN?
                    clear_mods(); // turn off unused mods
                    tap_code16(KC_LBRC);
                    return_state = false; // don't do more with this record.
                }
            }
        } else { // keyup event
            if (!saved_mods) {
                unregister_linger_key(keycode); // example of simple linger macro
                return_state = false; // don't do more with this record.
            }
        }
        break;
    case KC_RPRN:  // send } FOR Shift )
        // This logic feels kludgey, but it works. fix it? convert to SemKey
        if (record->event.pressed) { // key downSS
            if ((saved_mods & MOD_MASK_SHIFT)) { // shift down with KC_RPRN?
                clear_mods(); // turn off unused mods
                if ((saved_mods & MOD_MASK_ALT)) { // alt also?
                    tap_code16(KC_RBRC);
                } else {
                    tap_code16(KC_RCBR);
                }
                return_state = false; // don't do more with this record.
            } else {
                if ((saved_mods & MOD_MASK_ALT)) { // alt down with KC_RPRN?
                    clear_mods(); // turn off unused mods
                    tap_code16(KC_RBRC);
                    return_state = false; // don't do more with this record.
                }
            }
        }
        break;
    case KC_LBRC:  //
        // This logic feels kludgey, but it works. fix it? convert to SemKey
        if (!saved_mods) { // this order saves code space in this case
            if (record->event.pressed) { // key down
                register_linger_key(keycode); // example of simple linger macro
            } else { // keyup event
                unregister_linger_key(keycode); // example of simple linger macro
            }
            return_state = false; // don't do more with this record.
        }
        break;
    case KC_LCBR:  //
        // This logic feels kludgey, but it works. fix it? convert to SemKey
        if (!saved_mods) { // this order saves code space in this case
            if (record->event.pressed) { // key down
                register_linger_key(keycode); // example of simple linger macro
            } else { // keyup event
                unregister_linger_key(keycode); // example of simple linger macro
            }
            return_state = false; // don't do more with this record.
        }
        break;
    case KC_LT:  // send ≤ FOR Shift (
        // This logic feels kludgey, but it works. fix it? convert to SemKey
        if (record->event.pressed) { // key down
            if ((saved_mods & MOD_MASK_SHIFT)) { // shift down with KC_LT?
                clear_mods(); // turn off unused mods
                tap_code16(A(KC_COMM));
                return_state = false; // don't do more with this record.
            }
        }
        break;
    case KC_GT:  // send ≥ FOR Alt )
        // This logic feels kludgey, but it works. fix it? convert to SemKey
        if (record->event.pressed) { // key downSS
            if ((saved_mods & MOD_MASK_SHIFT)) { // shift down with KC_GT?
                clear_mods(); // turn off unused mods
                tap_code16(A(KC_DOT));
                return_state = false; // don't do more with this record.
            }
        }
        break;
    case KC_COMM:  // send ; FOR SHIFT ,
        // This logic feels kludgey, but it works. fix it? convert to SemKey
        if (record->event.pressed) { // key down
            if ((saved_mods & MOD_MASK_ALT)) { // ALT down?
                clear_mods(); // turn off unused mods
                if ((saved_mods & MOD_MASK_SHIFT)) { // SFT too?
                    tap_code16(A(KC_BSLS));
                } else {
                    tap_code16(KC_UNDS);
                }
                return_state = false; // don't do more with this record.
            } else {
                if ((saved_mods & MOD_MASK_SHIFT)) { // SHFT?
                    clear_keyboard(); // clean record to tinker with.
                    tap_code_delay(KC_SCLN, 10); // just semicolon
                    return_state = false; // don't do more with this record.
                }
            }
        }
        break;
    case KC_DOT:  // send : FOR SHIFT .
        // This logic feels kludgey, but it works. fix it? convert to SemKey
        if (record->event.pressed) { // key down
            if ((saved_mods & MOD_MASK_ALT)) { // ALT down?
                clear_mods(); // turn off unused mods
                if ((saved_mods & MOD_MASK_SHIFT)) { // SHFT too?
                    tap_code16(KC_BSLS);
                } else {
                    tap_code16(A(KC_SCLN));
                }
                return_state = false; // don't do more with this record.
            } else {
                if ((saved_mods & MOD_MASK_SHIFT)) { // SHFT?
                    clear_mods(); // turn off unused mods
                    tap_code16(KC_COLN);
                    return_state = false; // don't do more with this record.
                }
            }
        }
        break;

    case KC_QUOT:  //
        // This logic feels kludgey, but it works. fix it? convert to SemKey
        if (record->event.pressed) { // key down
            if (saved_mods & MOD_MASK_ALT) { // ALT (only) down?
                del_mods(MOD_MASK_CSG); // turn off unused mods (mods timing off in 14.1)
                if (saved_mods & MOD_MASK_SHIFT) { // SHFT too?
                    tap_code16(A(KC_BSLS));
                } else {
                    tap_code16(A(S(KC_3)));
                }
                return_state = false; // don't do more with this record.
            } else if (saved_mods & MOD_MASK_SHIFT) { // SHFT (only) down?
                clear_keyboard(); // turn off unused mods (set/del_mods sequence broke in 14.1)
                register_linger_key(KC_LBRC); // example of simple linger macro
                return_state = false; // don't do more with this record.
            }
        } else { // keyup event (just unregister it)
            unregister_linger_key(KC_LBRC); // can linger a different key than pressed
            unregister_code16(keycode); // but still need to handle this
            return_state = false; // don't do more with this record.
        }
        break;
    case KC_DQUO:  // send  on shift
        // This logic feels kludgey, but it works. fix it? convert to SemKey
        if (record->event.pressed) { // key down
            if (saved_mods & MOD_MASK_ALT) { // ALT (only) down?
                del_mods(MOD_MASK_CSG); // turn off unused mods (mods timing off in 14.1)
                if ((saved_mods & MOD_MASK_SHIFT)) { // SHFT too?
                    tap_code16(A(S(KC_BSLS)));
                } else {
                    tap_code16(A(S(KC_4)));
                }
                return_state = false; // don't do more with this record.
            } else if (saved_mods & MOD_MASK_SHIFT) { // SHFT?
                clear_keyboard(); // turn off unused mods (set/del_mods sequence broke in 14.1)
                tap_code16(KC_RBRC);
                return_state = false; // don't do more with this record.
            } else if (!saved_mods) { // no mods?
                register_linger_key(keycode); // example of simple linger macro
                return_state = false; // don't do more with this record.
            }
        } else { // keyup event (just unregister it)
            unregister_linger_key(keycode); // can linger a different key than pressed
            return_state = false; // don't do more with this record.
        }
        break;


    case KC_QUES:
        // This logic feels kludgey, but it works. fix it? convert to SemKey
        if (record->event.pressed) { // key down
            if ((saved_mods & MOD_MASK_ALT)) { // ALT down?
                clear_mods(); // turn off unused mods (timing off in 14.1)
                if ((saved_mods & MOD_MASK_SHIFT)) { // SHFT too?
                    tap_code16(KC_AT);
                } else {
                    tap_code16(KC_HASH);
                }
                return_state = false; // don't do more with this record.
            } else if (saved_mods & MOD_MASK_SHIFT) { // SHFT?
                clear_mods(); // turn off unused mods (timing off in 14.1)
                tap_code16(KC_EXLM);
                return_state = false; // don't do more with this record.
            }
        }
        break;
    case KC_MINS:  // send + FOR SHIFT - (_)
        // This logic feels kludgey, but it works. fix it? convert to SemKey
        if (record->event.pressed) { // key down
            if ((saved_mods & MOD_MASK_SHIFT)) { // shift down with KC_HASH?
//                    clear_keyboard(); // clean record to tinker with.
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
    case KC_SLSH:  // send  FOR ALT /(?)
        // This logic feels kludgey, but it works. fix it? convert to SemKey
        if (record->event.pressed) { // key down
            if ((saved_mods & MOD_MASK_ALT)) { // ALT down?
                clear_mods(); // turn off unused mods
                if ((saved_mods & MOD_MASK_SHIFT)) { // SHFT too?
                    tap_code16(A(S(KC_1))); //
                } else {
                    tap_code16(KC_BSLS); //
                }
                return_state = false; // don't do more with this record.
           } else {
                if ((saved_mods & MOD_MASK_SHIFT)) { // SHFT?
                    del_mods(MOD_MASK_CAG); // turn off unused mods (timing off in 14.1)
                    tap_code16(KC_ASTR); // *
                    return_state = false; // don't do more with this record.
                }
            }
        }
        break;
    case KC_SCLN:  // send
        // This logic feels kludgey, but it works. fix it? convert to SemKey
        if (record->event.pressed) { // key down
            if ((saved_mods & MOD_MASK_ALT)) { // ALT down?
                if ((saved_mods & MOD_MASK_SHIFT)) { // SHFT too?
                    del_mods(MOD_MASK_CAG); // turn off unused mods (timing off in 14.1)
                    tap_code16(KC_PERC); // %
                } else {
                    tap_SemKey(SK_SECT); // §
                }
                return_state = false; // don't do more with this record.
            }
        }
        break;
    case KC_PERC:  // % + shft = ‰
        // This logic feels kludgey, but it works. fix it? convert to SemKey
        if (record->event.pressed) { // key down
            if (saved_mods & MOD_MASK_SHIFT) { // shift down?
                del_mods(MOD_MASK_CG); // turn off unused mods (timing off in 14.1)
                tap_code16(A(S(KC_R))); // ‰
                return_state = false; // don't do more with this record.
            }
        }
        break;
    case KC_HASH:  //
        // This logic feels kludgey, but it works. fix it? convert to SemKey?
        if (record->event.pressed) { // key down
            if (saved_mods & MOD_MASK_ALT) { // alt down?
                del_mods(MOD_MASK_CAG); // turn off unused mods (timing off in 14.1)
                register_code16(S(KC_GRV)); // ~
                return_state = false; // don't do more with this record.
            } else if (saved_mods & MOD_MASK_SHIFT) { // shft down?
                del_mods(MOD_MASK_CAG); // turn off unused mods (timing off in 14.1)
                register_code16(KC_AT); //
                return_state = false; // don't do more with this record.
            }
        } else { // make sure all options are released.
            unregister_code16(KC_AT);
            unregister_code16(KC_GRV);
        }
        break;

    default: // total hack to deal with mod/layer taps
        switch (keycode & 0x00FF) { // Is this mask still needed?
            case KC_BSPC:  // make S(KC_BSPC) = KC_DEL; plus word_del L & R
                // This logic feels kludgey (but it works).  fix it.
                if (record->event.pressed) { // key down
                    if (saved_mods & MOD_MASK_SHIFT) { // shift down with KC_BSPC?
                        del_mods(MOD_MASK_SHIFT); // turn off shift (leave others)
//                            clear_keyboard(); // clean record to tinker with.
                        register_code16(KC_DEL);
                        key_trap = true;  // mode monitor on to clear this on keyup
                        return_state = false; // don't do more with this record.
                    }
                } else { // key up
                    if (key_trap) { // did we snag this earlier?
                        unregister_code16(KC_DEL); // make sure KC_DEL isn't held down
                        // unregister_code16(KC_BSPC);
                        key_trap = false;  // mode monitor off.
                        return_state = false; // don't do more with this record.
                    }
                }
                break;
        }
        break; // default
} // switch (keycode) {
if (!return_state) set_mods(saved_mods); // restore mod state if we tickled anything
