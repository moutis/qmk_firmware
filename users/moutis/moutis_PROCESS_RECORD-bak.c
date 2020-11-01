
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint8_t  saved_mods   = 0;
//  static uint16_t  bspc_del = 0;
//
//  static uint16_t tap_timer = 0;
//  static bool app_menu = false;
//  static uint16_t app_menu_timer = 0;
//  static uint16_t pre_keycode = KC_RCBR;
           
    uint16_t tap_keycode = keycode;
      // Filter out the actual keycode from MT and LT keys.
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) || (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) {
        tap_keycode &= 0xFF;  // mask off the mods
    }
//      mod_timer = timer_read(); for sticky keys/features, like menu w/lazy cmd/alt

    switch (tap_keycode) {
        case KC_APP:  // mimic windows app key behavior?
            if (record->event.pressed) {
                saved_mods = get_mods(); // keep updating mods while held
                if (!(saved_mods & MOD_MASK_GUI)) { // gui/alt not down
                    appmenu_timer = timer_read(); // time held, or since last pressed alone
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
//  Revisit this when you know how to handle mod-tap keys properly
/*        case KC_BSPC:  // make S(KC_BSPC) = KC_DEL
            if (record->event.pressed) {
                saved_mods = get_mods(); // keep updating mods while held
                if (!(saved_mods & MOD_MASK_SHIFT)) { // no shift not down
                    bspc_del = tap_keycode; // as is, w/ mods
                } else {
                    bspc_del = KC_DEL; // w/o mods
                }
                register_code(bspc_del);
            } else {
                unregister_code(bspc_del);
            }
*/
            return false; // done with KC_BSPC
    }
    return true;  // keep processing record
}
