#include QMK_KEYBOARD_H


/* THIS FILE WAS GENERATED!
 *
 * This file was generated by qmk json2c. You may or may not want to
 * edit it directly.
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT_split_3x5_3(KC_J, KC_G, KC_M, KC_P, KC_V, KC_HASH, KC_DOT, KC_SLSH, KC_QUOT, KC_DQUO, LCTL_T(KC_R), LALT_T(KC_S), LGUI_T(KC_N), LSFT_T(KC_T), LT(5,KC_K), LT(4,KC_COMM), RSFT_T(KC_A), RGUI_T(KC_E), RALT_T(KC_C), RCTL_T(KC_I), KC_X, KC_F, KC_L, KC_D, KC_B, KC_MINS, KC_U, KC_O, KC_W, KC_Y, LT(7,KC_MUTE), LT(4,KC_BSPC), LT(6,KC_H), LT(3,KC_SPC), LT(6,KC_ENT), LT(7,KC_MPLY)),
	[1] = LAYOUT_split_3x5_3(KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_DQUO, KC_QUOT, LCTL_T(KC_C), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RALT_T(KC_I), RCTL_T(KC_H), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_Y, KC_W, KC_TRNS, KC_TRNS, LT(6,KC_R), KC_TRNS, KC_TRNS, KC_TRNS),
	[2] = LAYOUT_split_3x5_3(KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_DQUO, KC_QUOT, LCTL_T(KC_H), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, LT(6,KC_C), KC_TRNS, KC_TRNS, KC_TRNS),
	[3] = LAYOUT_split_3x5_3(KC_Z, KC_Q, RALT(KC_5), LALT(KC_7), LSA(KC_7), LALT(KC_4), KC_DLR, A(S(KC_2)), RALT(KC_3), LALT(KC_Y), KC_LT, KC_LBRC, KC_LPRN, KC_LCBR, RSA(KC_5), RALT(KC_1), RSFT_T(KC_PAST), RGUI_T(KC_PEQL), RALT_T(KC_PPLS), RCTL_T(KC_PSLS), KC_GT, KC_RBRC, KC_RPRN, KC_RCBR, LALT(KC_8), KC_UNDS, KC_PIPE, KC_AMPR, KC_CIRC, KC_PERC, KC_TRNS, SK_DELWDL, SK_DELWDR, KC_TRNS, LSA(KC_8), KC_TRNS),
	[4] = LAYOUT_split_3x5_3(KC_F9, KC_F10, KC_F11, KC_F12, KC_F13, KC_GRV, KC_6, KC_7, KC_8, KC_MINS, LCTL_T(KC_F5), LALT_T(KC_F6), LGUI_T(KC_F7), LSFT_T(KC_F8), KC_F14, KC_COMM, RSFT_T(KC_1), RGUI_T(KC_5), RALT_T(KC_9), RCTL_T(KC_PPLS), KC_F1, KC_F2, KC_F3, KC_F4, KC_INS, KC_COMM, KC_2, KC_3, KC_4, KC_EQL, KC_TRNS, KC_SCLN, TG(5), KC_0, KC_DOT, SK_ZOOMRST),
	[5] = LAYOUT_split_3x5_3(TG(5), KC_HOME, KC_UP, KC_END, KC_PGUP, KC_PSLS, KC_P7, KC_P8, KC_P9, KC_PMNS, LALT_T(KC_TAB), KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, KC_PAST, KC_P4, KC_P5, KC_P6, KC_PPLS, SK_UNDO, SK_CUT, SK_COPY, SK_PSTE, KC_SPC, KC_PCMM, KC_P1, KC_P2, KC_P3, KC_PEQL, KC_TRNS, LGUI_T(KC_BSPC), LSFT_T(KC_ENT), KC_P0, KC_PDOT, SK_ZOOMRST),
	[6] = LAYOUT_split_3x5_3(SK_QUIT, SK_CLOZ, SK_SCAP, SK_SCLP, SK_FAGN, SK_DOCBEG, KC_HOME, KC_UP, KC_PGUP, SK_PARAPRV, KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, SK_FIND, SK_WORDPRV, KC_LEFT, KC_DOWN, KC_RGHT, SK_WORDNXT, SK_UNDO, SK_CUT, SK_COPY, SK_PSTE, SK_FAGN, SK_DOCEND, KC_END, KC_DOWN, KC_PGDN, SK_PARANXT, SK_ZOOMRST, MO(7), KC_APP, SK_HISTPRV, SK_HISTNXT, SK_ZOOMRST),
	[7] = LAYOUT_split_3x5_3(RESET, AG_SWAP, CG_SWAP, KC_NO, LCA(KC_DEL), SK_KILL, KC_NLCK, KC_EJCT, KC_NO, SK_ZOOMRST, KC_NO, HD_L_Bronze, HD_L_Titanium, HD_L_Rhodium, KC_NO, KC_BRIU, KC_MPRV, KC_MUTE, KC_MNXT, SK_ZOOMOUT, KC_NO, AG_NORM, CG_NORM, KC_NO, HD_AdaptKeyToggle, KC_BRID, KC_MRWD, KC_MPLY, KC_MFFD, SK_ZOOMIN, KC_TRNS, KC_TRNS, KC_TRNS, KC_VOLD, KC_VOLU, KC_TRNS)
};

