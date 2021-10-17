#include QMK_KEYBOARD_H

/* THIS FILE WAS GENERATED!
 *
 * This file was generated by qmk json2c. You may or may not want to
 * edit it directly.
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT(SK_COPY, KC_J, KC_F, KC_M, KC_P, KC_V, HD_HASH, KC_DOT, KC_SLSH, KC_QUOT, KC_DQUO, KC_KANA, SK_PSTE, LCTL_T(KC_R), LALT_T(KC_S), LGUI_T(KC_N), LSFT_T(KC_T), KC_K, KC_COMM, RSFT_T(KC_A), RGUI_T(KC_E), RALT_T(KC_C), RCTL_T(KC_I), KC_HANJ, S(G(KC_4)), KC_X, KC_G, KC_L, KC_D, KC_B, LT(6,KC_LANG2), SH_TT, TG(8), LT(6,KC_LANG1), KC_MINS, KC_U, KC_O, KC_W, KC_Y, KC_EQL, LT(10,KC_MUTE), KC_APP, LT(8,KC_BSPC), LT(7,KC_H), LT(6,KC_LANG2), LT(6,KC_BSPC), LT(5,KC_SPC), LT(7,KC_ENT), LT(8,KC_TAB), LT(10,KC_MPLY)),
	[1] = LAYOUT(KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, LGUI_T(KC_H), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, LT(7,KC_N), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
	[2] = LAYOUT(KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, LGUI_T(KC_N), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_H, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, LT(7,KC_L), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
	[3] = LAYOUT(KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_DQUO, KC_QUOT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, LGUI_T(KC_N), LSFT_T(KC_D), KC_B, KC_TRNS, KC_TRNS, KC_TRNS, RALT_T(KC_I), RCTL_T(KC_H), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_L, KC_C, KC_K, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_Y, KC_W, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, LT(7,KC_T), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
	[4] = LAYOUT(KC_TRNS, KC_V, KC_TRNS, KC_TRNS, KC_TRNS, KC_V, KC_TRNS, KC_TRNS, KC_TRNS, KC_QUOT, KC_DQUO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, LGUI_T(KC_N), LSFT_T(KC_T), KC_G, KC_TRNS, KC_TRNS, KC_TRNS, RALT_T(KC_I), RSFT_T(KC_H), KC_TRNS, KC_TRNS, KC_TRNS, KC_C, KC_L, KC_D, KC_B, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_Y, KC_W, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, LT(7,KC_SPC), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
	[5] = LAYOUT(KC_TRNS, LALT(KC_RBRC), A(S(KC_RBRC)), LALT(KC_LBRC), A(S(KC_LBRC)), LALT(KC_8), LALT(KC_4), KC_DLR, A(S(KC_2)), LALT(KC_Y), RALT(KC_3), KC_TRNS, KC_TRNS, KC_LT, KC_GT, KC_LPRN, KC_RPRN, LALT(KC_7), KC_TRNS, LSFT_T(KC_PAST), LGUI_T(KC_PEQL), LALT_T(KC_PPLS), LCTL_T(KC_BSLS), KC_TRNS, KC_TRNS, A(S(KC_5)), A(S(KC_7)), KC_LCBR, KC_RCBR, RALT(KC_5), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PIPE, KC_AMPR, KC_CIRC, KC_PERC, KC_TRNS, KC_VOLD, KC_VOLU, SK_DELWDL, SK_DELWDR, KC_TRNS, A(S(KC_9)), KC_TRNS, LALT(KC_9), A(S(KC_8)), TG(5)),
	[6] = LAYOUT(KC_TRNS, KC_F11, KC_F12, KC_F13, KC_F14, KC_F15, KC_NO, CG_NORM, AG_NORM, AG_SWAP, CG_SWAP, KC_TRNS, KC_TRNS, LCTL_T(KC_9), LALT_T(KC_3), LGUI_T(KC_1), LSFT_T(KC_5), KC_7, KC_6, RSFT_T(KC_2), RGUI_T(KC_0), RALT_T(KC_4), RCTL_T(KC_8), KC_TRNS, KC_TRNS, KC_F9, KC_F3, KC_F1, KC_F5, KC_F7, RESET, KC_TRNS, KC_TRNS, RESET, KC_F6, KC_F2, KC_F10, KC_F4, KC_F8, KC_TRNS, RESET, LCA(KC_DEL), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, LCA(KC_DEL), RESET),
	[7] = LAYOUT(KC_TRNS, SK_QUIT, SK_CLOZ, SK_SCAP, SK_SCLP, SK_FAGN, SK_DOCBEG, KC_HOME, KC_UP, KC_PGUP, SK_PARAPRV, KC_TRNS, KC_TRNS, KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, SK_FIND, SK_WORDPRV, KC_LEFT, KC_DOWN, KC_RGHT, SK_WORDNXT, KC_TRNS, KC_TRNS, SK_UNDO, SK_CUT, SK_COPY, SK_PSTE, SK_PSTM, KC_HANJ, KC_TRNS, KC_TRNS, KC_HANJ, SK_DOCEND, KC_END, KC_DOWN, KC_PGDN, SK_PARANXT, KC_TRNS, KC_BRID, KC_BRIU, KC_TRNS, KC_TRNS, KC_TRNS, SK_ZOOMOUT, SK_HISTPRV, SK_HISTNXT, SK_ZOOMIN, SK_ZOOMRST),
	[8] = LAYOUT(KC_NO, LALT(KC_RBRC), A(S(KC_RBRC)), LALT(KC_LBRC), A(S(KC_LBRC)), A(S(KC_8)), KC_PSLS, KC_P7, KC_P8, KC_P9, KC_PMNS, KC_NO, KC_NO, KC_LT, KC_GT, KC_LPRN, KC_RPRN, LALT(KC_7), KC_PAST, KC_P4, KC_P5, KC_P6, KC_PPLS, KC_NO, KC_NO, LCTL_T(KC_LBRC), LALT_T(KC_RBRC), KC_LCBR, KC_RCBR, RALT(KC_5), LALT(KC_MINS), TG(0), KC_TRNS, LALT(KC_EQL), KC_COMM, KC_P1, KC_P2, KC_P3, KC_PEQL, KC_NO, KC_TRNS, KC_APP, KC_BSPC, LT(4,KC_DEL), KC_PENT, KC_BSPC, KC_P0, KC_PDOT, KC_C, KC_TRNS),
	[9] = LAYOUT(KC_NO, RALT(KC_1), RALT(KC_R), RALT(KC_G), RALT(KC_2), A(S(KC_SCLN)), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, LALT(KC_BSLS), A(S(KC_3)), A(S(KC_4)), A(S(KC_BSLS)), A(S(KC_5)), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, LALT(KC_9), LALT(KC_QUOT), RALT(KC_Q), RALT(KC_F), A(S(KC_7)), KC_CAPS, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, LALT(KC_BSPC), KC_DEL, LALT(KC_DEL), KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO),
	[10] = LAYOUT(KC_NO, KC_PSCR, KC_SLCK, LCA(KC_DEL), KC_NO, KC_NO, KC_NO, CG_NORM, AG_NORM, AG_SWAP, CG_SWAP, KC_NO, KC_NO, LCTL_T(KC_BRIU), LALT_T(KC_MRWD), LGUI_T(KC_MSTP), LSFT_T(KC_MFFD), LT(5,KC_VOLU), DF(4), DF(0), DF(1), DF(2), DF(3), KC_NO, KC_NO, KC_BRID, KC_MPRV, KC_MUTE, KC_MNXT, KC_VOLD, KC_NO, KC_NO, KC_NO, KC_NO, TO(4), TO(0), TO(1), TO(2), TO(3), KC_NO, RESET, KC_EJCT, KC_PAUS, KC_MPLY, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, RESET)
};
