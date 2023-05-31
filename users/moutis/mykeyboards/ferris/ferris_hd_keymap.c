#include QMK_KEYBOARD_H


/* THIS FILE WAS GENERATED!
 *
 * This file was generated by qmk json2c. You may or may not want to
 * edit it directly.
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT_split_3x5_2(KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, RCTL_T(KC_A), RALT_T(KC_S), RGUI_T(KC_D), RSFT_T(KC_F), LT(L_NUMPAD,KC_G), LT(L_FN_NUM,KC_H), RSFT_T(KC_J), RGUI_T(KC_K), RALT_T(KC_L), RCTL_T(KC_SCLN), KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, LT(L_FN_NUM,KC_BSPC), LT(L_NAV,KC_DEL), LT(L_PUNCT,KC_SPC), LT(L_NAV,KC_ENT)),
    [1] = LAYOUT_split_3x5_2(
                             HD_LT4, HD_LT3, HD_LT2, HD_LT1, HD_LT0, HD_RT0, HD_RT1, HD_RT2, HD_RT3, HD_RT4,
                             HD_LM4, HD_LM3, HD_LM2, HD_LM1, HD_LM0, HD_RM0, HD_RM1, HD_RM2, HD_RM3, HD_RM4,
                             HD_LB4, HD_LB3, HD_LB2, HD_LB1, HD_LB0, HD_RB0, HD_RB1, HD_RB2, HD_RB3, HD_RB4,
                                                     HD_LH2, HD_LH1, HD_RH1, HD_RH2),
	[2] = LAYOUT_split_3x5_2(KC_Z, KC_Q, RALT(KC_5), LALT(KC_7), LSA(KC_7), LALT(KC_4), KC_DLR, A(S(KC_2)), RALT(KC_3), LALT(KC_Y), KC_LT, KC_LBRC, KC_LPRN, KC_LCBR, RSA(KC_5), RALT(KC_1), RSFT_T(KC_PAST), RGUI_T(KC_PEQL), RALT_T(KC_PPLS), RCTL_T(KC_PSLS), KC_GT, KC_RBRC, KC_RPRN, KC_RCBR, LALT(KC_8), KC_UNDS, KC_PIPE, KC_AMPR, KC_CIRC, KC_PERC, SK_DELWDL, SK_DELWDR, KC_TRNS, LSA(KC_8)),
	[3] = LAYOUT_split_3x5_2(KC_F9, KC_F10, KC_F11, KC_F12, KC_F13, KC_GRV, KC_7, KC_8, KC_9, KC_MINS, LCTL_T(KC_F5), LALT_T(KC_F6), LGUI_T(KC_F7), LSFT_T(KC_F8), KC_F14, KC_COMM, RSFT_T(KC_1), RGUI_T(KC_2), RALT_T(KC_3), RCTL_T(KC_PPLS), KC_F1, KC_F2, KC_F3, KC_F4, KC_INS, KC_COMM, KC_4, KC_5, KC_6, KC_EQL, KC_TRNS, KC_SCLN, TG(L_NUMPAD), KC_0),
	[4] = LAYOUT_split_3x5_2(KC_ESC, KC_HOME, KC_UP, KC_PGUP, LT(L_MEDIA_KBD, KC_NUM), KC_PSLS, KC_P7, KC_P8, KC_P9, KC_PMNS, SK_WORDPRV, KC_LEFT, KC_DOWN, KC_RGHT, SK_WORDNXT, KC_PAST, RSFT_T(KC_P4), RGUI_T(KC_P5), RALT_T(KC_P6), RCTL_T(KC_PPLS), KC_DEL, KC_END, KC_TAB, KC_PGDN, KC_SPC, KC_PCMM, KC_P1, KC_P2, KC_P3, KC_PEQL, LT(L_FN_NUM,KC_BSPC), LT(L_NAV,KC_PENT), LT(L_PUNCT,KC_P0), LT(L_NAV,KC_PDOT)),
	[5] = LAYOUT_split_3x5_2(SK_QUIT, SK_CLOZ, SK_SCAP, SK_SCLP, SK_FAGN, SK_DOCBEG, KC_HOME, KC_UP, KC_PGUP, SK_PARAPRV, KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, SK_FIND, SK_WORDPRV, KC_LEFT, KC_DOWN, KC_RGHT, SK_WORDNXT, SK_UNDO, SK_CUT, SK_COPY, SK_PSTE, SK_FAGN, SK_DOCEND, KC_END, KC_DOWN, KC_PGDN, SK_PARANXT, MO(L_MEDIA_KBD), KC_APP, SK_HISTPRV, SK_HISTNXT),
	[6] = LAYOUT_split_3x5_2(KC_NO, EE_CLR, AG_SWAP, CG_SWAP, LCA(KC_DEL), SK_KILL, KC_NUM, KC_EJCT, KC_NO, SK_ZOOMRST, HD_AdaptKeyToggle, HD_L_QWERTY, HD_L_Titanium, KC_VOLU, KC_BRIU, KC_NO, KC_MPRV, KC_MUTE, KC_MNXT, SK_ZOOMOUT, QK_BOOT, AG_NORM, CG_NORM, KC_VOLD, KC_BRID, KC_NO, KC_MRWD, KC_MPLY, KC_MFFD, SK_ZOOMIN, KC_NO, TG(L_NUMPAD), KC_NO, KC_NO)
};

