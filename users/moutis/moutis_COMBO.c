#define combo_OLED_row 5

//  (22) keypad combos
const uint16_t PROGMEM PCM1_combo[] = {KC_COMM, KC_P1, COMBO_END};
const uint16_t PROGMEM P01_combo[] = {KC_P0, KC_P1, COMBO_END};
const uint16_t PROGMEM P02_combo[] = {KC_P0, KC_P2, COMBO_END};
const uint16_t PROGMEM P04_combo[] = {KC_P0, KC_P4, COMBO_END};
const uint16_t PROGMEM P05_combo[] = {KC_P0, KC_P5, COMBO_END};
const uint16_t PROGMEM P12_combo[] = {KC_P1, KC_P2, COMBO_END};
const uint16_t PROGMEM P23_combo[] = {KC_P2, KC_P3, COMBO_END};
const uint16_t PROGMEM P13_combo[] = {KC_P1, KC_P3, COMBO_END};
const uint16_t PROGMEM P1E_combo[] = {KC_P1, KC_PEQL, COMBO_END};
const uint16_t PROGMEM P3E_combo[] = {KC_P3, KC_PEQL, COMBO_END};
const uint16_t PROGMEM P45_combo[] = {KC_P4, KC_P5, COMBO_END};
const uint16_t PROGMEM P56_combo[] = {KC_P5, KC_P6, COMBO_END};
const uint16_t PROGMEM P46_combo[] = {KC_P4, KC_P6, COMBO_END};
const uint16_t PROGMEM P5PLS_combo[] = {KC_P5, KC_PPLS, COMBO_END};
const uint16_t PROGMEM P6PLS_combo[] = {KC_P6, KC_PPLS, COMBO_END};
const uint16_t PROGMEM PS7_combo[] = {KC_PSLS, KC_P7, COMBO_END};
const uint16_t PROGMEM P78_combo[] = {KC_P7, KC_P8, COMBO_END};
const uint16_t PROGMEM P79_combo[] = {KC_P7, KC_P9, COMBO_END};
const uint16_t PROGMEM P89_combo[] = {KC_P8, KC_P9, COMBO_END};
const uint16_t PROGMEM P9M_combo[] = {KC_P9, KC_PMNS, COMBO_END};
const uint16_t PROGMEM PSLT_combo[] = {KC_PSLS, KC_PAST, COMBO_END};
const uint16_t PROGMEM PPLMN_combo[] = {KC_PPLS, KC_PMNS, COMBO_END};

// (5) nemnonic same letter, moves with layout,  (ie. diacritics)
//const uint16_t PROGMEM quote_combo[] = {KC_T, KC_E, COMBO_END};
//const uint16_t PROGMEM quotr_combo[] = {KC_T, KC_R, COMBO_END};
//const uint16_t PROGMEM quotu_combo[] = {KC_T, KC_U, COMBO_END};
//const uint16_t PROGMEM quoti_combo[] = {KC_T, KC_I, COMBO_END};
//const uint16_t PROGMEM quotn_combo[] = {KC_T, KC_N, COMBO_END};

// (23) HANDSDOWN spatially arranged
//const uint16_t PROGMEM Hlprn_combo[] = {KC_D, KC_R, COMBO_END}; // ( paren
//const uint16_t PROGMEM Hrprn_combo[] = {KC_R, KC_F, COMBO_END}; // ) paren
//const uint16_t PROGMEM Hlbrk_combo[] = {KC_G, KC_L, COMBO_END}; // [ bracket, l kagikakko
//const uint16_t PROGMEM Hrbrk_combo[] = {KC_L, KC_C, COMBO_END}; // ] bracket, R kagikakko
const uint16_t PROGMEM Hgrav_combo[] = {KC_G, KC_H, COMBO_END}; // ` grave
const uint16_t PROGMEM Hcirc_combo[] = {KC_G, KC_K, COMBO_END}; // ˆ circumflex
const uint16_t PROGMEM Hacut_combo[] = {KC_H, KC_K, COMBO_END}; // ´ acute
const uint16_t PROGMEM Hmacr_combo[] = {KC_F, KC_COMM, COMBO_END}; // - macron
//const uint16_t PROGMEM Hodot_combo[] = {KC_V, KC_O, COoMBO_END}; // ˚ hi o dot over char
const uint16_t PROGMEM Hdier_combo[] = {KC_F, KC_O, COMBO_END}; // ¨ dieresis

const uint16_t PROGMEM Hdquot_combo[] = {KC_QUOT, KC_C, COMBO_END}; // " double quote
const uint16_t PROGMEM Hdash_combo[] = {KC_Q, KC_J, COMBO_END}; // - dash/minus
const uint16_t PROGMEM Hndsh_combo[] = {KC_C, KC_Q, COMBO_END}; // – n dash
const uint16_t PROGMEM Hmdsh_combo[] = {KC_C, KC_J, COMBO_END}; // — m dash
const uint16_t PROGMEM Hstrk_combo[] = {KC_C, KC_SLSH, COMBO_END}; // - strikethrough
const uint16_t PROGMEM Htild_combo[] = {KC_Q, KC_SLSH, COMBO_END}; // ~ tilde
const uint16_t PROGMEM Hcoln_combo[] = {KC_O, KC_DOT, COMBO_END}; // : colon
const uint16_t PROGMEM Hunds_combo[] = {KC_O, KC_COMM, COMBO_END}; // _ underscore
const uint16_t PROGMEM Hbsls_combo[] = {KC_J, KC_SLSH, COMBO_END}; // \ backslash

// Bigram and other multi-input thingies
const uint16_t PROGMEM H_JAPAN_combo[] = {KC_J, KC_P, COMBO_END}; // TYPE "Japan"
//const uint16_t PROGMEM H_QU_combo[] = {KC_Q, KC_P, COMBO_END}; // TYPE "QU"

//const uint16_t PROGMEM Hdbrce_combo[] = {KC_Z, KC_J, COMBO_END}; // {}
//const uint16_t PROGMEM Hdparn_combo[] = {KC_P, KC_W, COMBO_END}; // ()
//const uint16_t PROGMEM Hdbrak_combo[] = {KC_F, KC_Y, COMBO_END}; // []

// Spatially arranged typical functions
const uint16_t PROGMEM Htab_combo[] = {KC_Z, KC_G, COMBO_END}; // tab
const uint16_t PROGMEM Hent_combo[] = {KC_D, KC_B, COMBO_END}; // Enter
const uint16_t PROGMEM Hdel_combo[] = {KC_W, KC_F, COMBO_END}; // tab


const uint16_t PROGMEM Hsall_combo[] = {KC_X, KC_D, COMBO_END}; // select all
const uint16_t PROGMEM Hundo_combo[] = {KC_X, KC_M, COMBO_END}; // undo
const uint16_t PROGMEM Hcut_combo[] = {KC_X, KC_L, COMBO_END}; // cut
const uint16_t PROGMEM Hcopy_combo[] = {KC_L, KC_M, COMBO_END}; // copy
const uint16_t PROGMEM Hpste_combo[] = {KC_L, KC_D, COMBO_END}; // paste
const uint16_t PROGMEM Hpstm_combo[] = {KC_M, KC_D, COMBO_END}; // paste-match

// (15) QWERTY spatially arranged
//const uint16_t PROGMEM Qlparn_combo[] = {KC_R, KC_T, COMBO_END}; // (
//const uint16_t PROGMEM Qrparn_combo[] = {KC_E, KC_F, COMBO_END}; // )
const uint16_t PROGMEM Qgrav_combo[] = {KC_W, KC_E, COMBO_END}; // ` grave
const uint16_t PROGMEM Qcirc_combo[] = {KC_W, KC_R, COMBO_END}; // ˆ circumflex
const uint16_t PROGMEM Qacut_combo[] = {KC_E, KC_R, COMBO_END}; // ´ acute
const uint16_t PROGMEM Qmacr_combo[] = {KC_U, KC_O, COMBO_END}; // - macron
//const uint16_t PROGMEM Qodot_combo[] = {KC_U, KC_I, COMBO_END}; // ˚ hi o dot over char
const uint16_t PROGMEM Qdier_combo[] = {KC_U, KC_I, COMBO_END}; // ¨ dieresis
const uint16_t PROGMEM Qstrk_combo[] = {KC_M, KC_DOT, COMBO_END}; // - strikethrough

const uint16_t PROGMEM Qdquot_combo[] = {KC_O, KC_QUOT, COMBO_END}; // " double quote
const uint16_t PROGMEM Qdash_combo[] = {KC_I, KC_O, COMBO_END}; // - dash/minus
const uint16_t PROGMEM Qndsh_combo[] = {KC_N, KC_M, COMBO_END}; // – n-dash
const uint16_t PROGMEM Qmdsh_combo[] = {KC_M, KC_COMM, COMBO_END}; // — m-dash
//const uint16_t PROGMEM Qtild_combo[] = {KC_M, KC_DOT, COMBO_END}; // ~ tilde
//const uint16_t PROGMEM Qdbrce_combo[] = {KC_T, KC_Y, COMBO_END}; // {|}
//const uint16_t PROGMEM Qdparn_combo[] = {KC_G, KC_H, COMBO_END}; // (|)
//const uint16_t PROGMEM Qdbrak_combo[] = {KC_B, KC_N, COMBO_END}; // [|]
const uint16_t PROGMEM Qtab_combo[] = {KC_Q, KC_W, COMBO_END}; // tab
const uint16_t PROGMEM Qent_combo[] = {KC_B, KC_V, COMBO_END}; // Enter
const uint16_t PROGMEM Qsall_combo[] = {KC_Z, KC_V, COMBO_END}; // Select all
const uint16_t PROGMEM Qundo_combo[] = {KC_Z, KC_X, COMBO_END}; // undo
const uint16_t PROGMEM Qcut_combo[] = {KC_Z, KC_C, COMBO_END}; // cut
const uint16_t PROGMEM Qcopy_combo[] = {KC_X, KC_C, COMBO_END}; // copy
const uint16_t PROGMEM Qpste_combo[] = {KC_C, KC_V, COMBO_END}; // paste
const uint16_t PROGMEM Qpmtch_combo[] = {KC_X, KC_V, COMBO_END}; // paste-match

// (3) functional spatially arranged, but still same on both layouts (shared to conserve memory)
const uint16_t PROGMEM quotq_combo[] = {KC_QUOT, KC_SLSH, COMBO_END};  // "|" double quote insert between
const uint16_t PROGMEM commdot_combo[] = {KC_COMM, KC_DOT, COMBO_END}; // ; semicolon
const uint16_t PROGMEM dotslsh_combo[] = {KC_DOT, KC_SLSH, COMBO_END}; // \ backslash
const uint16_t PROGMEM commslsh_combo[] = {KC_COMM, KC_SLSH, COMBO_END}; // _ underscore

enum my_combos {
    CC_SCLN,   // SIMPLE COMBO must be first-used as FALSE for combo_on
    QC_TAB,
    HC_TAB,
    HC_DEL,
    QC_ENT,
    HC_ENT,
    QC_SALL,
    HC_SALL,

    PC_PENT, // <enter> on num
    PC_BSPC, // <bksp> on num
    PC_DEL, // <del> on num
    PC_TAB, // <tab> on num

    // this block must be contiguous, all using the default hold threshold.
    // puts out the held bigrams if the hold threshold is not met. Repeats if held.
    PC_STAB,  // Shift-<tab>
    PC_DASH, // – on number layer (keypad)
    PC_TILD, // ˜
    PC_ELIP, // …
    PC_COLN, // :
    PC_DEG, //
    PC_NEQL, // ≠
    PC_ENTR, // <enter> on num layer
    PC_DIV, // ÷
    PC_PLMN, // ±
    PC_PERC, // %
    PC_EURO, // €
    PC_DOLR, // $
    PC_CENT, // ¢
    PC_JYEN, // ¥
    PC_BPND, // £
    PC_LPRN,
    PC_RPRN,
    
    CC_2DQUO, // "|" insertion point between double quotes
//    HC_LPRN,
//    HC_RBRK,
//    HC_LBRK,
//    HC_RPRN,
//    HC_2BRAC,
//    HC_2PARN,
//    HC_2BRAK,
    HC_DASH,

    HC_TYPE_JAPAN,

    HC_UNDO,
    HC_CUT,
    HC_COPY,
    HC_PSTE,
    HC_PSTM,

//    QC_LPRN,
//    QC_RPRN,
//    QC_2BRAC,
//    QC_2PARN,
//    QC_2BRAK,
    QC_DASH,
    QC_UNDO,
    QC_CUT,
    QC_COPY,
    QC_PSTE,
    QC_PSTM, // last of contiguous block

    // This group all have custom actions on trigger (no hold-delay), repeat if held
    QC_GRAV, //
    HC_GRAV, // ` grave
    HC_CIRC, // ˆ circumflex
    QC_CIRC, // ˆ circumflex
    HC_ACUT, // ´ acute
    QC_ACUT, // ´ acute
    HC_MACR, // - macron
    QC_MACR, // - macron
    HC_DIER, // ¨ dieresis
    QC_DIER, // ¨ dieresis
//    HC_ODOT, // ˚ hi o dot over char
//    QC_ODOT, // ˚ hi o dot over char
    HC_STRK, // - strikethrough
    QC_STRK, // - strikethrough

    HC_DQUO,
    QC_DQUO,
    HC_NDSH,
    QC_NDSH,

    HC_MDSH,
    HC_TILD,
    HC_COLN,
    HC_UNDS,
    HC_BSLS,
//    QC_MDSH,
//    QC_TILD,
    QC_BSLS,
    QC_UNDS
};


combo_t key_combos[COMBO_COUNT] = {
    // These simple combos trigger on press, repeat.
    [CC_SCLN] = COMBO(commdot_combo, KC_SCLN),  // must be first, used as FALSE for combo_on
    [QC_TAB] = COMBO(Qtab_combo, KC_TAB),
    [HC_TAB] = COMBO(Htab_combo, KC_TAB),
    [HC_DEL] = COMBO(Hdel_combo, KC_DEL),
    [HC_ENT] = COMBO(Hent_combo, KC_ENT),
    [QC_ENT] = COMBO(Qent_combo, KC_ENT),
    [HC_TILD] = COMBO(Htild_combo, KC_TILD),  // ~
    [HC_COLN] = COMBO(Hcoln_combo, KC_COLN),  // :
//    [QC_TILD] = COMBO(Qtild_combo, KC_TILD),  // ~
    [PC_PENT] = COMBO(P3E_combo, KC_PENT), // <enter> on num
    [PC_BSPC] = COMBO(P01_combo, KC_BSPC), // <bksp> on num
    [PC_DEL] = COMBO(P02_combo, KC_DEL), // <del> on num
    [PC_TAB] = COMBO(P05_combo, KC_TAB), // <tab> on num

    // action combos below
    // this block should be contiguous,
    // all using default COMBO_HOLD threshold. No repeat if held (tap_code)
    // may send the held combo keys if COMBO_HOLD is not met.

    // Keypad combos (all need mods, so must be here)
    [PC_STAB] = COMBO_ACTION(P04_combo), // shift-<tab> on num
    [PC_DASH] = COMBO_ACTION(P12_combo), // – for time span on number layer
    [PC_TILD] = COMBO_ACTION(P13_combo), // ~ for time span on number layer
    [PC_ELIP] = COMBO_ACTION(P23_combo), // … for time span on number layer
    [PC_LPRN] = COMBO_ACTION(P45_combo), // ( on number layer
    [PC_RPRN] = COMBO_ACTION(P56_combo), // ) on number layer
    [PC_COLN] = COMBO_ACTION(P46_combo), // : on number layer for time 12:30xx
    [PC_PERC] = COMBO_ACTION(P6PLS_combo), // % on numbers
    [PC_DEG] = COMBO_ACTION(P5PLS_combo), // degree symbol on number layer
    [PC_JYEN] = COMBO_ACTION(PS7_combo), // €
    [PC_DOLR] = COMBO_ACTION(P78_combo), // $
    [PC_CENT] = COMBO_ACTION(P79_combo), // ¢
    [PC_EURO] = COMBO_ACTION(P89_combo), // ¥
    [PC_BPND] = COMBO_ACTION(P9M_combo), // £
    [PC_DIV] = COMBO_ACTION(PSLT_combo), // ÷
    [PC_PLMN] = COMBO_ACTION(PPLMN_combo), // ±
    [PC_NEQL] = COMBO_ACTION(P1E_combo), // ≠

// HANDSDOWN
//    [HC_LPRN] = COMBO_ACTION(Hlprn_combo),
//    [HC_RPRN] = COMBO_ACTION(Hrprn_combo),
//    [HC_LBRK] = COMBO_ACTION(Hlbrk_combo),
//    [HC_RBRK] = COMBO_ACTION(Hrbrk_combo),
//    [HC_2BRAC] = COMBO_ACTION(Hdbrce_combo), // left+right bracket, insertion in the middle
//    [HC_2PARN] = COMBO_ACTION(Hdparn_combo),
//    [HC_2BRAK] = COMBO_ACTION(Hdbrak_combo),
    [HC_UNDS] = COMBO_ACTION(Hunds_combo),
    [HC_BSLS] = COMBO_ACTION(Hbsls_combo),
    [HC_DASH] = COMBO_ACTION(Hdash_combo),
    [HC_NDSH] = COMBO_ACTION(Hndsh_combo),
    [HC_MDSH] = COMBO_ACTION(Hmdsh_combo),
    [HC_GRAV] = COMBO_ACTION(Hgrav_combo), // ` grave
    [HC_CIRC] = COMBO_ACTION(Hcirc_combo), // ˆ circumflex
    [HC_ACUT] = COMBO_ACTION(Hacut_combo), // ´ acute
    [HC_MACR] = COMBO_ACTION(Hmacr_combo), // - macron
    [HC_DIER] = COMBO_ACTION(Hdier_combo), // ¨ dieresis
    [HC_STRK] = COMBO_ACTION(Hstrk_combo), // - strikethrough
    [HC_STRK] = COMBO_ACTION(Hstrk_combo), // - strikethrough
//    [HC_ODOT] = COMBO_ACTION(Hodot_combo), // ˚ hi o dot over char


    [HC_TYPE_JAPAN] = COMBO_ACTION(H_JAPAN_combo),

    [HC_SALL] = COMBO_ACTION(Hsall_combo),
    [HC_UNDO] = COMBO_ACTION(Hundo_combo),
    [HC_CUT] = COMBO_ACTION(Hcut_combo),
    [HC_COPY] = COMBO_ACTION(Hcopy_combo),
    [HC_PSTE] = COMBO_ACTION(Hpste_combo),
    [HC_PSTM] = COMBO_ACTION(Hpstm_combo),

// QWERTY layer
//    [QC_LPRN] = COMBO_ACTION(Qlparn_combo),
//    [QC_RPRN] = COMBO_ACTION(Qrparn_combo),
//    [QC_2BRAC] = COMBO_ACTION(Qdbrce_combo), // left+right brace, insertion in the middle
//    [QC_2PARN] = COMBO_ACTION(Qdparn_combo),
//    [QC_2BRAK] = COMBO_ACTION(Qdbrak_combo),
    [QC_BSLS] = COMBO_ACTION(dotslsh_combo),
    [QC_UNDS] = COMBO_ACTION(commslsh_combo), // _ underscore
    [QC_DASH] = COMBO_ACTION(Qdash_combo),
    [QC_NDSH] = COMBO_ACTION(Qndsh_combo),
//    [QC_MDSH] = COMBO_ACTION(Qmdsh_combo),
    [QC_GRAV] = COMBO_ACTION(Qgrav_combo), // ` grave
    [QC_CIRC] = COMBO_ACTION(Qcirc_combo), // ˆ circumflex
    [QC_ACUT] = COMBO_ACTION(Qacut_combo), // ´ acute
    [QC_MACR] = COMBO_ACTION(Qmacr_combo), // - macron
    [QC_DIER] = COMBO_ACTION(Qdier_combo), // ¨ dieresis
    [QC_STRK] = COMBO_ACTION(Qstrk_combo), // - strikethrough
//    [QC_ODOT] = COMBO_ACTION(Qodot_combo), // ˚ hi o dot over char

    [QC_SALL] = COMBO_ACTION(Qsall_combo),
    [QC_UNDO] = COMBO_ACTION(Qundo_combo),
    [QC_CUT] = COMBO_ACTION(Qcut_combo),
    [QC_COPY] = COMBO_ACTION(Qcopy_combo),
    [QC_PSTE] = COMBO_ACTION(Qpste_combo),
    [QC_PSTM] = COMBO_ACTION(Qpmtch_combo), // This is the last in the switch range below


    // This group have custom actions on trigger (no hold-delay), repeat if held
    [HC_DQUO] = COMBO_ACTION(Hdquot_combo),
    [QC_DQUO] = COMBO_ACTION(Qdquot_combo),
    [CC_2DQUO] = COMBO_ACTION(quotq_combo),
};

void process_combo_event(uint8_t combo_index, bool pressed) {
#ifdef OLED_DRIVER_ENABLE
    oled_set_cursor(0, combo_OLED_row);
#endif
    if (pressed) {
#ifdef OLED_DRIVER_ENABLE
//        oled_write_P(PSTR("Combo: "), false);
#endif
        keyhold_timer = timer_read();
        switch(combo_index) {
            case CC_SCLN ... QC_PSTM:  // these have a hold delay before triggering
                combo_on = combo_index; // queue for matrix_scan_user_process_combo
                break;
            case HC_DQUO:
            case QC_DQUO:
                register_code16(KC_DQUO);
                break;
            case HC_GRAV:
            case QC_GRAV:
                register_code16(KC_GRV);
                break;
            case HC_CIRC:
            case QC_CIRC:
                tap_code16(A(KC_6));
                break;
            case HC_ACUT:
            case QC_ACUT:
                tap_code16(A(KC_E));
                break;
            case HC_MACR:
            case QC_MACR:
                tap_code16(A(KC_A));
                break;
            case HC_DIER:
//            case QC_DIER:
                tap_code16(A(KC_U));
                break;
            case HC_STRK:
            case QC_STRK:
                tap_code16(A(KC_L));
                break;
/*            case HC_ODOT:
            case QC_ODOT:
                tap_code16(A(KC_K));
                break;
            case CC_ENYE:
                register_code16(A(KC_N));
                break;
*/
            case HC_NDSH:
            case QC_NDSH:
                register_code16(A(KC_MINS));
                break;
            case HC_MDSH:
//            case QC_MDSH:
                register_code16(A(S(KC_MINS)));
                break;
            case HC_UNDS:
            case QC_UNDS:
                register_code16(KC_UNDS);
                break;
            case HC_BSLS:
            case QC_BSLS:
                register_code(KC_BSLS);
                break;
        } // end switch (combo_index)
    } else { // end if (pressed)


/*/
 
 This is the NOT pressed switch (key up event)
 
/*/
#ifdef OLED_DRIVER_ENABLE
        oled_set_cursor(0,combo_OLED_row);
        oled_write_P(PSTR("                     "), false);
#endif
        switch(combo_index) {
// make this smarter/smaller. lookup keys to output from the key_combos table, bypassing switch
            case PC_DASH:
                if (combo_on && !combo_triggered) {// no combo, so send the keys
                    tap_code(KC_P4);
                    tap_code(KC_P5);
                }
                break;
            case PC_TILD:
                if (combo_on && !combo_triggered) {// no combo, so send the keys
                    tap_code(KC_P5);
                    tap_code(KC_P6);
                }
                break;
            case PC_ELIP:
                if (combo_on && !combo_triggered) {// no combo, so send the keys
                    tap_code(KC_P2);
                    tap_code(KC_P3);
                }
                break;
            case PC_COLN:
                if (combo_on && !combo_triggered) {// no combo, so send the keys
                    tap_code(KC_P4);
                    tap_code(KC_P6);
                }
                break;
            case PC_PERC:
                if (combo_on && !combo_triggered) {// no combo, so send the keys
                    tap_code(KC_P1);
                    tap_code(KC_P2);
                }
                break;
            case PC_DOLR:
                if (combo_on && !combo_triggered) {// no combo, so send the keys
                    tap_code(KC_7);
                    tap_code(KC_8);
                }
                break;
            case PC_CENT:
                if (combo_on && !combo_triggered) {// no combo, so send the keys
                    tap_code(KC_7);
                    tap_code(KC_9);
                }
                break;
            case PC_JYEN:
                if (combo_on && !combo_triggered) {// no combo, so send the keys
                    tap_code(KC_8);
                    tap_code(KC_9);
                }
                break;
/*/            case QC_LPRN:
                if (combo_on && !combo_triggered) {// no combo, so send the keys
                    tap_code(KC_W);
                    tap_code(KC_E);
                }
                break;
            case QC_RPRN:
                if (combo_on && !combo_triggered) {// no combo, so send the keys
                    tap_code(KC_E);
                    tap_code(KC_R);
                }
                break;
            case QC_2BRAC:
                if (combo_on && !combo_triggered) {// no combo, so send the keys
                    tap_code(KC_T);
                    tap_code(KC_Y);
                }
                break;
            case QC_2PARN:
                if (combo_on && !combo_triggered) {// no combo, so send the keys
                    tap_code(KC_G);
                    tap_code(KC_H);
                }
                break;
            case QC_2BRAK:
                if (combo_on && !combo_triggered) {// no combo, so send the keys
                    tap_code(KC_B);
                    tap_code(KC_N);
                }
                break;
/*/
            case HC_DASH:
                if (combo_on && !combo_triggered) {// no combo, so send the keys
                    tap_code(KC_K);
                    tap_code(KC_L);
                }
                break;
            case QC_DASH:
                if (combo_on && !combo_triggered) {// no combo, so send the keys
                    tap_code(KC_I);
                    tap_code(KC_O);
                }
                break;
            case CC_2DQUO:
                if (combo_on && !combo_triggered) {// no combo, so send the keys
                    tap_code(KC_Q);
                    tap_code(KC_QUOT);
                }
                break;
            case HC_DQUO:
            case QC_DQUO:
                unregister_code16(KC_DQUO);
                break;
            case HC_GRAV:
            case QC_GRAV:
                unregister_code16(KC_GRV);
                break;
            case HC_NDSH:
                 if (combo_on && !combo_triggered) {// no combo, so send the keys
                    tap_code(KC_V);
                    tap_code(KC_D);
                } else { // stop repeating
                    unregister_code16(A(KC_MINS));
                }
                break;
             case QC_NDSH:
                if (combo_on && !combo_triggered) {// no combo, so send the keys
                    tap_code(KC_N);
                    tap_code(KC_M);
                } else { // stop repeating
                    unregister_code16(A(KC_MINS));
                }
                break;
            case HC_MDSH:
//            case QC_MDSH:
                unregister_code16(A(S(KC_MINS)));
                break;
            case HC_BSLS:
            case QC_BSLS:
                unregister_code(KC_BSLS);
                break;
            case HC_UNDS:
            case QC_UNDS:
                unregister_code16(KC_UNDS);
                break;
            case HC_SALL:
                if (combo_on && !combo_triggered) {// no combo, so send the keys
                    tap_code(KC_Z);
                    tap_code(KC_D);
                }
                break;
            case QC_SALL:
                if (combo_on && !combo_triggered) {// no combo, so send the keys
                    tap_code(KC_X);
                    tap_code(KC_V);
                }
                break;
            case HC_UNDO:
                if (combo_on && !combo_triggered) {// no combo, so send the keys
                    tap_code(KC_Z);
                    tap_code(KC_M);
                } else {  // combo triggered, so unregister to stop repeating
                    if (user_config.osIsWindows) {
                        unregister_code16(C(KC_Z));
                    } else {
                        unregister_code16(G(KC_Z));
                    }
                }
                break;
            case QC_UNDO:
                if (combo_on && !combo_triggered) {// no combo, so send the keys
                    tap_code(KC_Z);
                    tap_code(KC_X);
                } else {  // combo triggered, so unregister to stop repeating
                    if (user_config.osIsWindows) {
                        unregister_code16(C(KC_Z));
                    } else {
                        unregister_code16(G(KC_Z));
                    }
                }
                break;
            case HC_CUT:
                if (combo_on && !combo_triggered) {// no combo, so send the keys
                    tap_code(KC_Z);
                    tap_code(KC_L);
                }
                break;
            case QC_CUT:
                if (combo_on && !combo_triggered) {// no combo, so send the keys
                    tap_code(KC_Z);
                    tap_code(KC_X);
                }
                break;
            case HC_COPY:
                if (combo_on && !combo_triggered) {// no combo, so send the keys
                    tap_code(KC_M);
                    tap_code(KC_L);
                }
                break;
            case QC_COPY:
                if (combo_on && !combo_triggered) {// no combo, so send the keys
                    tap_code(KC_X);
                    tap_code(KC_C);
                }
                break;
            case HC_PSTE:
                if (combo_on && !combo_triggered) {// no combo, so send the keys
                    tap_code(KC_L);
                    tap_code(KC_D);
                } else {  // combo triggered, so stop repeating
                    if (user_config.osIsWindows) {
                        unregister_code16(C(KC_V));
                    } else {
                        unregister_code16(G(KC_V));
                    }
                }
                break;
            case QC_PSTE:
                if (combo_on && !combo_triggered) {// no combo, so send the keys
                    tap_code(KC_C);
                    tap_code(KC_V);
                } else {  // combo triggered, so stop repeating
                    if (user_config.osIsWindows) {
                        unregister_code16(C(KC_V));
                    } else {
                        unregister_code16(G(KC_V));
                    }
                }
                break;
            case HC_PSTM:
                if (combo_on && !combo_triggered) {// no combo, so send the keys
                    tap_code(KC_M);
                    tap_code(KC_D);
                } else {  // combo triggered, so stop repeating
                    if (user_config.osIsWindows) {
                        unregister_code16(C(S(A(KC_V))));
                    } else {
                        unregister_code16(G(S(A(KC_V))));
                    }
                }
                break;
            case QC_PSTM:
                if (combo_on && !combo_triggered) {// no combo, so send the keys
                    tap_code(KC_V);
                    tap_code(KC_B);
                } else {  // combo triggered, so stop repeating
                    if (user_config.osIsWindows) {
                        unregister_code16(C(S(A(KC_V))));
                    } else {
                        unregister_code16(G(S(A(KC_V))));
                    }
                }
                break;
        }  // end switch(combo_index) {
        combo_on = 0;
        combo_triggered = false;
    } // else if (pressed)
#ifdef OLED_DRIVER_ENABLE
//    oled_render();
#endif
    return;
}

void matrix_scan_user_process_combo() {  // called from matrix_scan_user

    // These combos are to be held for TAPPING_TERM before triggering
    // to avoid accidental triggers while fast typing these common rolls.
    // I've used tap_code here because repeats aren't deemed necessary for these
    // combos, though holds could be enabled with register_code and adding
    // unregister_code to the !pressed switch in process_combo_event above.
    // Checking combo_triggered above can enable sending untriggered keys
    // and thus allow for longer COMBO_TERM. (recommend < TAPPING_TERM / 2)
    // still, really fast rolls, esp if they can go both ways, are going to be
    // a problem for this (ex er, re; io oi), so maybe best to avoid them.
    if (!combo_triggered) {
        // do simple "on" on first press actions here,
        // then turn on combo state for hold acions
        if (combo_on && (timer_elapsed(keyhold_timer) > COMBO_HOLD)) {
            switch(combo_on) {  // combo_on is global, set in process_combo above
/*/                case CC_WERE:
                    tap_code(KC_W);
                    tap_code(KC_E);
                    tap_code(KC_QUOT);
                    tap_code(KC_R);
                    tap_code(KC_E);
                    break;
/*/
                case PC_STAB:
                    tap_code16(S(KC_TAB));
                    break;
                case PC_DASH:
                    tap_code16(A(KC_MINS));
                    break;
                case PC_TILD:
                    tap_code16(KC_TILD);
                    break;
                case PC_ELIP:
                    tap_code16(A(KC_SCLN));
                    break;
                case PC_COLN:
                    tap_code16(KC_COLN);
                    break;
                case PC_PERC:
                    tap_code16(KC_PERC);
                    break;
                case PC_EURO:
                    tap_code16(A(S(KC_2)));
                    break;
                case PC_DOLR:
                    tap_code16(S(KC_4));
                    break;
                case PC_CENT:
                    tap_code16(A(KC_4));
                    break;
                case PC_JYEN:
                    tap_code16(A(KC_Y));
                    break;
                case PC_BPND:
                    tap_code16(A(KC_3));
                    break;
                case PC_NEQL:
                    tap_code16(A(KC_EQL));
                    break;
                case PC_DIV:
                    tap_code16(A(KC_SLSH));
                    break;
                case PC_PLMN:
                    tap_code16(A(S(KC_EQL)));
                    break;
                case PC_DEG:
                    tap_code16(A(KC_0));
                    break;
                case PC_LPRN:
//                case HC_LPRN:
//                case QC_LPRN:
                    tap_code16(KC_LPRN);
                    break;
                case PC_RPRN:
//                case HC_RPRN:
//                case QC_RPRN:
                    tap_code16(KC_RPRN);
                    break;
/*                case HC_LBRK:
                    tap_code16(KC_LCBR);
                    break;
                case HC_RBRK:
                    tap_code16(KC_RCBR);
                    break;
                case NC_2BRAC:
                case QC_2BRAC:
                    tap_code16(KC_LCBR);
                    tap_code16(KC_RCBR);
                    tap_code(KC_LEFT);
                    break;
                case NC_2PARN:
                case QC_2PARN:
                    tap_code16(KC_LPRN);
                    tap_code16(KC_RPRN);
                    tap_code(KC_LEFT);
                    break;
                case NC_2BRAK:
                case QC_2BRAK:
                    tap_code16(KC_LBRC);
                    tap_code16(KC_RBRC);
                    tap_code(KC_LEFT);
                    break;
*/
                case CC_2DQUO:
                    tap_code16(A(KC_LBRC));
                    tap_code16(A(S(KC_LBRC)));
                    tap_code(KC_LEFT);
                    break;
                case HC_DASH:
                case QC_DASH:
                    tap_code(KC_MINS);
                    break;
                case HC_TYPE_JAPAN:
                    SEND_STRING("Japan");
                    break;
                case HC_SALL:
                case QC_SALL:
                    if (user_config.osIsWindows) { // eventuall this will be replaced with smart table lookup by platform (mac, ios, win, linux, vim, etc.)
                        tap_code16(C(KC_A));
                    } else {
                        tap_code16(G(KC_A));
                    }
                    break;
                case HC_UNDO:
                case QC_UNDO:
                    if (user_config.osIsWindows) { // eventuall this will be replaced with smart table lookup by platform (mac, ios, win, linux, vim, etc.)
                        register_code16(C(KC_Z));
                    } else {
                        register_code16(G(KC_Z));
                    }
                    break;
                case HC_CUT:
                case QC_CUT:
                    if (user_config.osIsWindows) {
                        tap_code16(C(KC_X));
                    } else {
                        tap_code16(G(KC_X));
                    }
                    break;
                case HC_COPY:
                case QC_COPY:
                    if (user_config.osIsWindows) {
                        tap_code16(C(KC_C));
                    } else {
                        tap_code16(G(KC_C));
                    }
                    break;
                case HC_PSTE:  // These may be held and repeated
                case QC_PSTE:  // These may be held and repeated
                    if (user_config.osIsWindows) {
                        register_code16(C(KC_V));
                    } else {
                        register_code16(G(KC_V));
                    }
                    break;
                case HC_PSTM:
                case QC_PSTM:
                    if (user_config.osIsWindows) {
                        register_code16(C(S(A(KC_V))));
                    } else {
                        register_code16(G(S(A(KC_V))));
                    }
                    break;
            } // switch
            combo_triggered = true;
            #ifdef OLED_DRIVER_ENABLE
                oled_set_cursor(oled_max_chars() - 5, combo_OLED_row);
                oled_write_P(PSTR(" sent"), false);
            #endif
        }
    }
}
