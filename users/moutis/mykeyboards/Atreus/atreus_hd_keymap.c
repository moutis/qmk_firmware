#include QMK_KEYBOARD_H


#ifdef COMBO_ENABLE
#include HD_combo_def // this has the combo definitions
#endif

#define ______ KC_TRNS
#define __no__ KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[L_QWERTY] = LAYOUT(
        KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P,
        RCTL_T(KC_A), RALT_T(KC_S), RGUI_T(KC_D), RSFT_T(KC_F), LT(L_NUMPAD,KC_G), LT(L_FN_NUM,KC_H), RSFT_T(KC_J), RGUI_T(KC_K), RALT_T(KC_L), RCTL_T(KC_SCLN),
        KC_Z, KC_X, KC_C, KC_V, KC_B, TT(L_NUMPAD), LT(L_FN_NUM,KC_MPLY), KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH,
        KC_LEFT, KC_RGHT, KC_APP, LT(L_MEDIA_KBD,KC_MUTE), LT(L_FN_NUM,KC_BSPC), LT(L_NAV,KC_DEL), LT(L_MEDIA_KBD,KC_MUTE), LT(L_PUNCT,KC_SPC), LT(L_NAV,KC_ENT), LT(L_MEDIA_KBD,KC_MPLY), KC_UP, KC_DOWN),
	[L_HDALPHA] = LAYOUT(
        HD_LT4, HD_LT3, HD_LT2, HD_LT1, HD_LT0,                 HD_RT0, HD_RT1, HD_RT2, HD_RT3, HD_RT4,
        HD_LM4, HD_LM3, HD_LM2, HD_LM1, HD_LM0,                 HD_RM0, HD_RM1, HD_RM2, HD_RM3, HD_RM4,
        HD_LB4, HD_LB3, HD_LB2, HD_LB1, HD_LB0, LT(L_NUMPAD, KC_LBRC),        LT(L_NAV,KC_RBRC), HD_RB0, HD_RB1, HD_RB2, HD_RB3, HD_RB4,
        ______, ______, KC_APP, HD_LH2, HD_LH1, LT(L_MEDIA_KBD,KC_MUTE), LT(L_MEDIA_KBD,KC_MPLY), HD_RH1, HD_RH2, TG(L_NUMPAD), ______, ______),
	[L_PUNCT] = LAYOUT(
        KC_Z, KC_Q, RALT(KC_5), LALT(KC_7), LSA(KC_7), LALT(KC_4), KC_DLR, A(S(KC_2)), RALT(KC_3), LALT(KC_Y),
        KC_LT, KC_LBRC, KC_LPRN, KC_LCBR, RSA(KC_5), RALT(KC_1), RSFT_T(KC_PAST), RGUI_T(KC_PEQL), RALT_T(KC_PPLS), RCTL_T(KC_PSLS),
        KC_GT, KC_RBRC, KC_RPRN, KC_RCBR, LALT(KC_8), ______, ______, KC_UNDS, KC_PIPE, KC_AMPR, KC_CIRC, KC_PERC,
        ______, ______, ______, SK_DELWDL, SK_DELWDR, ______, LSA(KC_8), ______, ______, ______, ______, ______),
	[L_FN_NUM] = LAYOUT(
        KC_F9, KC_F10, KC_F11, KC_F12, KC_F13, KC_GRV, KC_7, KC_8, KC_9, KC_BSLS,
        LCTL_T(KC_F5), LALT_T(KC_F6), LGUI_T(KC_F7), LSFT_T(KC_F8), KC_F14, KC_SCLN, RSFT_T(KC_1), RGUI_T(KC_2), RALT_T(KC_3), RCTL_T(KC_SLSH), KC_F1, KC_F2, KC_F3, KC_F4, KC_F15, KC_PAUS, KC_TAB, KC_MINS, KC_4, KC_5, KC_6, KC_EQL, KC_PSCR, KC_LSCR, ______, KC_BSPC, KC_ENT, ______, KC_DEL, KC_0, KC_DOT, KC_COMM, ______, ______),
/*
    [L_FN_NUM] = LAYOUT(
        LF_LT4, LF_LT3, LF_LT2, LF_LT1, LF_LT0,                 LF_RT0, LF_RT1, LF_RT2, LF_RT3, LF_RT4,
        LF_LM4, LF_LM3, LF_LM2, LF_LM1, LF_LM0,                 LF_RM0, LF_RM1, LF_RM2, LF_RM3, LF_RM4,
        LF_LB4, LF_LB3, LF_LB2, LF_LB1, LF_LB0, LF_LBA, LF_RBA, LF_RB0, LF_RB1, LF_RB2, LF_RB3, LF_RB4,
        ______, ______, LF_LH3, LF_LH2, LF_LH1, LF_LH0, LF_RH0, LF_RH1, LF_RH2, LF_RH3, ______, ______),
*/

 [L_NUMPAD] = LAYOUT(
        KC_LNUM, KC_HOME, KC_UP, KC_END, KC_PGUP, KC_PSLS, KC_P7, KC_P8, KC_P9, KC_PMNS,
        LALT_T(KC_TAB), KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, KC_PAST, KC_P4, KC_P5, KC_P6, KC_PPLS,
        SK_UNDO, SK_CUT, SK_COPY, SK_PSTE, KC_SPC, ______,  ______, KC_PCMM, KC_P1, KC_P2, KC_P3, KC_PEQL,
        ______, ______, ______, LGUI_T(KC_BSPC), LSFT_T(KC_ENT), KC_TAB, KC_DEL, KC_P0, KC_PDOT, ______, ______, ______),
/*
    [L_NUMPAD] = LAYOUT(
        LN_LT4, LN_LT3, LN_LT2, LN_LT1, LN_LT0,                 LN_RT0, LN_RT1, LN_RT2, LN_RT3, LN_RT4,
        LN_LM4, LN_LM3, LN_LM2, LN_LM1, LN_LM0,                 LN_RM0, LN_RM1, LN_RM2, LN_RM3, LN_RM4,
        LN_LB4, LN_LB3, LN_LB2, LN_LB1, LN_LB0, LN_LBA, LN_RBA, LN_RB0, LN_RB1, LN_RB2, LN_RB3, LN_RB4,
        ______, ______, LN_LH3, LN_LH2, LN_LH1, LN_LH0, LN_RH0, LN_RH1, LN_RH2, LN_RH3, ______, ______),
*/
    [L_NAV] = LAYOUT(
        SK_QUIT, SK_CLOZ, SK_SCAP, SK_SCLP, SK_FAGN, SK_DOCBEG, KC_HOME, KC_UP, KC_PGUP, SK_PARAPRV,
        KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, SK_FIND, SK_WORDPRV, KC_LEFT, KC_DOWN, KC_RGHT, SK_WORDNXT,
        SK_UNDO, SK_CUT, SK_COPY, SK_PSTE, SK_PSTM, KC_ESC, KC_TAB, SK_DOCEND, KC_END, KC_DOWN, KC_PGDN, SK_PARANXT,
        SK_HISTPRV, SK_HISTNXT, ______, ______, ______, ______, ______, SK_HISTPRV, SK_HISTNXT, SK_ZOOMRST, SK_ZOOMOUT, SK_ZOOMIN),
    /*
        [L_NAV] = LAYOUT(
            LV_LT4, LV_LT3, LV_LT2, LV_LT1, LV_LT0,                 LV_RT0, LV_RT1, LV_RT2, LV_RT3, LV_RT4,
            LV_LM4, LV_LM3, LV_LM2, LV_LM1, LV_LM0,                 LV_RM0, LV_RM1, LV_RM2, LV_RM3, LV_RM4,
            LV_LB4, LV_LB3, LV_LB2, LV_LB1, LV_LB0, LV_LBA, LV_RBA, LV_RB0, LV_RB1, LV_RB2, LV_RB3, LV_RB4,
            ______, ______, LV_LH3, LV_LH2, LV_LH1, LV_LH0, LV_RH0, LV_RH1, LV_RH2, LV_RH3, ______, ______),
    */
	[L_MEDIA_KBD] = LAYOUT(
        QK_RBT, CG_SWAP, CG_NORM, EE_CLR, SK_KILL, LCA(KC_DEL), KC_NUM, KC_EJCT, __no__, SK_ZOOMRST,
        HD_AdaptKeyToggle, HD_L_QWERTY, HD_L_ALPHA, KC_VOLU, KC_BRIU, __no__, KC_MPRV, KC_MUTE, KC_MNXT, SK_ZOOMOUT,
        QK_BOOT, AG_SWAP, AG_NORM, KC_VOLD, KC_BRID, __no__, __no__, __no__, KC_MRWD, KC_MPLY, KC_MFFD, SK_ZOOMIN,
        __no__, __no__, TG(L_NUMPAD), __no__, __no__, __no__, __no__, __no__, __no__, __no__, __no__, __no__)
};

