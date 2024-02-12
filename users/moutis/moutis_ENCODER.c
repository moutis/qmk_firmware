
bool encoder_update_user(uint8_t index, bool clockwise) {
static  uint8_t  held_mods; // static so we're not reallocating each time.
static  uint16_t HD_enc[L_CFG+1][2][2][2] = { // [layer][L/R encoder][N/Y shift][ccw, cw] * uint16_t = 112 bytes
    // all other encoder actions in this table, most of these defined in the meta keymap file moutis_layers.h
    // ALL QMK and extended keycodes, including SemKeys work here,
    //
    //              Left encoder                         Right encoder
    //      Unshifted            Shifted             Unshifted              Shifted
    //       CCW, CW             CCW, CW              CCW, CW               CCW, CW
        {{{KC_VOLD,KC_VOLU}, {KC_BRID,KC_BRIU}}, {{KC_LEFT,KC_RIGHT}, {S(KC_LEFT),S(KC_RIGHT)}}}, // L_QWERTY, 0 - QWERTY compatibility layer
        {{{KC_VOLD,KC_VOLU}, {KC_BRID,KC_BRIU}}, {{KC_LEFT,KC_RIGHT}, {S(KC_LEFT),S(KC_RIGHT)}}}, // L_HD,  1 - Hands Down Alpha layer
        {{{LS_LH5,LS_LH4},   {LS_LH4,LS_LH5}},   {{LS_RH4,LS_RH5},    {LS_RH4,LS_RH5}}},          // L_SYM, 2 - symbols, punctuation, off-map alphas
        {{{LF_LH5,LF_LH4},   {LF_LH4,LF_LH5}},   {{LF_RH4,LF_RH5},    {LF_RH4,LF_RH5}}},          // L_FUN, 3 - function & number rows
        {{{LN_LH5,LN_LH4},   {LN_LH4,LN_LH5}},   {{LN_RH4,LN_RH5},    {LN_RH4,LN_RH5}}},          // L_NUM, 4 - numpad (right); navpad (left)
        {{{LV_LH5,LV_LH4},   {LV_LH4,LV_LH5}},   {{LV_RH4,LV_RH5},    {LV_RH4,LV_RH5}}},          // L_NAV, 5 - nav pad (right); meta keys (left)
        {{{LC_LH5,LC_LH4},   {LC_LH4,LC_LH5}},   {{LC_RH5,LC_RH4},    {LC_RH4,LC_RH5}}}           // L_CFG  6 - Media/Consumer controls; Keyboard settings
    };

    held_mods = get_mods(); // fetch mods
    // Mod held Global (All layers) behaviors, all encoders
    if (held_mods & MOD_MASK_GUI) { // App switch // not platform saavy!
        if (held_mods & MOD_MASK_CTRL) { // workspace switch
            unregister_mods(MOD_MASK_SAG); // lift all but ctrl
            if (clockwise) {
                tap_code(KC_RIGHT); // fwd
            } else {
                tap_code(KC_LEFT); // back
            }
        }
        if (clockwise) { // Uses SemKey for Platform flexible app switch
            tap_SemKey(SK_APPNXT); // APP switcher Next (last used)
        } else {
            tap_SemKey(SK_APPPRV); // APP switcher Prev (least recently used)
        }
        goto exit;
    }
    if (held_mods & MOD_MASK_CTRL) { // just ctrl switch
        unregister_mods(MOD_MASK_SAG); // lift all but ctrl
        if (clockwise) { // Uses SemKey for Platform flexible app switch
            //tap_code16(C(KC_TAB)); // fwd
            tap_SemKey(SK_WINNXT); // Window/tab switcher Next
        } else {
            //tap_code16(C(S(KC_TAB))); // fwd
            tap_SemKey(SK_WINPRV); // Window/tab switcher Prev
        }
        goto exit;
    }

    unregister_mods(MOD_MASK_SHIFT); // lift Shift, but leave all others
    // look up the keycode to send for this layer, encoder, shift state, direction
    tap_HDkey(HD_enc[(int)get_highest_layer(layer_state)][(int)index][(int)((held_mods & MOD_MASK_SHIFT) ? 1 : 0)][(int)clockwise]);
exit:
    set_mods(held_mods); // restore mods
    return false;
}

