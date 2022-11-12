/*
 Adaptive Keys
 Called from within process_record_user
 
 ** This will misbehave w/o QMK 14.1 or later (Sevanteri's early combos)

 This will NOT work with all Hands Down Neu variants (only, Titanium (as Gold) & Bronze)
 Finally getting to the last of imagined features that spurred Hands Down design!
 
 NOTE: assumed dual-function keys (MOD_TAP, LAYER_TAP) have already been handled AND
    FILTERED OUT! The combos handler will have already taken out combo candidates,
    which have a shorter keydown threshhold (COMBO_TERM).

 */


bool process_adaptive_key(uint16_t keycode, const keyrecord_t *record) {
    bool return_state = true; // assume we don't do anything.

    
    // Are we in an adaptive context? (adaptive on is assumed).
    if (timer_elapsed(prior_keydown) > ADAPTIVE_TERM) { // outside adaptive threshhold
        prior_keycode = prior_keydown = 0; // turn off Adaptives.
        return true; // no adaptive conditions, so return.
    }

    // K, this could be adaptive, so process.
    saved_mods = get_mods();

    if (!caps_word_on) { // turn off shift, (first-words & Proper nouns)
        unregister_mods(MOD_MASK_SHIFT);  //CAPS_WORD/LOCK won't be affected.
    }
    switch (keycode & QK_BASIC_MAX) { // process ignoring multi-function keys

/*
// Left hand adaptives (most are single-handed neighbor fingers, bc speed, dexterity limits)
*/
        case KC_C:
            switch (prior_keycode) {
                case KC_T: // roll for tch
                    send_string("ch");
                    return_state = false; // done.
                    break;
            }
            break;

        case KC_W: //
            switch (prior_keycode) { //

                case KC_M:
                    goto PullUpLAndExit;
/*
                case KC_X:  // pull up "P" from bottom row
                    tap_code(KC_P);  // pull up "P" (mp 3x more common than mb)
                    return_state = false; // done.
                    break;
*/
                case KC_G:  //
                    goto ReplacePriorWithL; // results in "LB"
            }
            break;

        case KC_X: //
            switch (prior_keycode) { //
                case KC_M:
                    goto ReplacePriorWithL;
//                case KC_B:
//                    goto ReplacePriorWithL; // short jumps save bytes
            }
            break;
        case KC_G:
            switch (prior_keycode) {
//                case KC_B:
                case KC_K:
PullUpLAndExit:
                    tap_code(KC_L);  // pull up "L" (statistically more common)
                    return_state = false; // done.
                    break;
                case KC_M:
ReplacePriorWithL:
                    tap_code(KC_BSPC);
                    tap_code(KC_L);
                    return_state = true; // send the keycode.
                    break;
            }
            break;

        case KC_M: // M becomes L (pull up "L" to same row)
            switch (prior_keycode) {
                case KC_W:
                    goto ReplacePriorWithL; // short jumps save bytes
                case KC_X:
                case KC_G:
                    goto PullUpLAndExit;
            }
        case KC_K:
            switch (prior_keycode) {
                case KC_G: // GK = LK
                    goto ReplacePriorWithL; // short jumps save bytes
                case KC_T: // TK = CK
                    tap_code(KC_BSPC);
                    tap_code(KC_C);
                    return_state = true; // done.
                    break;
            }
            break;
        case KC_T:  // index and middle (index<->others is easier)
            switch (prior_keycode) {
                case KC_K: // quickly typing "k?" yields "kn"
                    tap_code(KC_N);
                    return_state = false; // done.
                    break;
                case KC_M: // quickly typing "mt" yields "ment"
                    send_string("ent");
                    return_state = false; // done.
                    break;
            }
            break;

/*
// right hand adaptives
*/
        case KC_A:
            switch (prior_keycode) {
                case KC_COMM: //  "/A" yields "UA" eliminating SFB
                    tap_code(KC_BSPC); // get rid of the prior
                    tap_code(KC_U); // first send U
                    return_state = true; // then the keycode.
                    break;
            }
            break;
        case KC_E:
            switch (prior_keycode) {
                case KC_COMM: // "/E" yields "OE" eliminating SFB
                    tap_code(KC_BSPC); // get rid of the prior
                    tap_code(KC_O); // first send O
                    return_state = true; // then the keycode.
                    break;
                case KC_A: // "AE" yields "AU" eliminating SFB
                    goto tapUbreak;
            }
            break;
        case KC_COMM:
            switch (prior_keycode) {
                case KC_A:
tapUbreak:
                    tap_code(KC_U); // "/A" yields "UA" eliminating SFB
                    return_state = false; // send the keycode.
                    break;
                case KC_E: // tight roll controls...so this works
                    tap_code(KC_O); // "E." or "E," yields "EO" eliminating SFB
                    return_state = false; // send the keycode.
            }
            break;
        case KC_SLSH:
            switch (prior_keycode) {
                case KC_A:
                    goto tapUbreak; // "'a" yields "UA" eliminating SFB
                case KC_DOT:
                    tap_code(KC_BSPC); // get rid of the prior
                    send_string(".com");
                    return_state = false; // done.
            }
            break;
        case KC_U:  // "you" adaptive?
            switch (prior_keycode) {
                case KC_Y: // YU = You bc YO (ring-middle) is a tad awk, but yu is easy, and uncommon
                    send_string("ou ");
                    return_state = false; // done.
                    break;
            }
            break;

        case KC_Y:
            switch (prior_keycode) {
                case KC_W: //
                    send_string("hy ");  // bc "HY" is pinky->ring on diff rows
                    return_state = false; // done.
                    break;
            }
            break;
                    
    }
//    (return_state) ? (set_mods(saved_mods);prior_keycode = keycode = 0) : (prior_keycode = keycode);
    if (return_state) {
        set_mods(saved_mods);
        prior_keycode = keycode = 0;
    }
/*    else {
        prior_keycode = keycode;
    }
*/
    return return_state; //
}
