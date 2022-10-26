#include QMK_KEYBOARD_H


/* THIS FILE WAS GENERATED!
 *
 * This file was generated by qmk json2c. You may or may not want to
 * edit it directly.
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT_ffkb(KC_NO, KC_W, KC_V, KC_M, KC_G, KC_LPRN, KC_RPRN, KC_DOT, KC_SLSH, KC_J, KC_QUOT, KC_NO, KC_NO, RCTL_T(KC_C), RALT_T(KC_S), RGUI_T(KC_N), RSFT_T(KC_T), LT(L_NUMPAD,KC_K), LT(L_FN_NUM,KC_COMM), RSFT_T(KC_A), RGUI_T(KC_E), RALT_T(KC_I), RCTL_T(KC_H), KC_NO, KC_NO, KC_P, KC_F, KC_L, KC_D, KC_X, KC_MINS, KC_U, KC_O, KC_Y, KC_B, KC_NO, LT(L_MEDIA_KBD,KC_MUTE), LT(L_FN_NUM,KC_BSPC), LT(L_NAV,KC_R), KC_APP, LT(L_MEDIA_KBD,KC_MPLY), LT(L_PUNCT,KC_SPC), LT(L_NAV,KC_ENT), LT(L_MEDIA_KBD,KC_MPLY), KC_NO),
	[1] = LAYOUT_ffkb(KC_NO, KC_J, KC_G, KC_TRNS, KC_P, KC_V, KC_TRNS, KC_TRNS, KC_TRNS, KC_DQUO, KC_TRNS, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_X, KC_TRNS, KC_TRNS, KC_TRNS, KC_B, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_W, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
	[2] = LAYOUT_ffkb(KC_NO, KC_Z, KC_Q, RALT(KC_5), LALT(KC_7), LSA(KC_7), LALT(KC_4), KC_DLR, A(S(KC_2)), RALT(KC_3), LALT(KC_Y), KC_NO, KC_NO, KC_LT, KC_LBRC, KC_LPRN, KC_LCBR, RSA(KC_5), RALT(KC_1), RSFT_T(KC_PAST), RGUI_T(KC_PEQL), RALT_T(KC_PPLS), RCTL_T(KC_PSLS), KC_NO, KC_NO, KC_GT, KC_RBRC, KC_RPRN, KC_RCBR, LALT(KC_8), KC_UNDS, KC_PIPE, KC_AMPR, KC_CIRC, KC_PERC, KC_TRNS, KC_TRNS, SK_DELWDL, SK_DELWDR, KC_TRNS, KC_TRNS, LSA(KC_8), KC_TRNS, KC_TRNS, KC_TRNS),
	[3] = LAYOUT_ffkb(KC_NO, KC_F9, KC_F10, KC_F11, KC_F12, KC_F13, KC_GRV, KC_7, KC_8, KC_9, KC_MINS, KC_NO, KC_NO, LCTL_T(KC_F5), LALT_T(KC_F6), LGUI_T(KC_F7), LSFT_T(KC_F8), KC_F14, KC_COMM, RSFT_T(KC_1), RGUI_T(KC_2), RALT_T(KC_3), RCTL_T(KC_PPLS), KC_NO, KC_NO, KC_F1, KC_F2, KC_F3, KC_F4, KC_INS, KC_COMM, KC_4, KC_5, KC_6, KC_EQL, KC_TRNS, KC_TRNS, KC_SCLN, KC_COLN, TG(L_NUMPAD), SK_ZOOMRST, KC_0, KC_DOT, KC_TRNS, KC_TRNS),
	[4] = LAYOUT_ffkb(KC_NO, TG(L_NUMPAD), KC_HOME, KC_UP, KC_END, KC_PGUP, KC_PSLS, KC_P7, KC_P8, KC_P9, KC_PMNS, KC_NO, KC_NO, LALT_T(KC_TAB), KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, KC_PAST, KC_P4, KC_P5, KC_P6, KC_PPLS, KC_NO, KC_NO, SK_UNDO, SK_CUT, SK_COPY, SK_PSTE, KC_SPC, KC_PCMM, KC_P1, KC_P2, KC_P3, KC_PEQL, KC_TRNS, KC_TRNS, LGUI_T(KC_BSPC), LSFT_T(KC_ENT), SK_ZOOMRST, KC_TRNS, KC_P0, KC_PDOT, KC_TRNS, KC_TRNS),
	[5] = LAYOUT_ffkb(KC_NO, SK_QUIT, SK_CLOZ, SK_SCAP, SK_SCLP, SK_FAGN, SK_DOCBEG, KC_HOME, KC_UP, KC_PGUP, SK_PARAPRV, KC_NO, KC_NO, KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, SK_FIND, SK_WORDPRV, KC_LEFT, KC_DOWN, KC_RGHT, SK_WORDNXT, KC_NO, KC_NO, SK_UNDO, SK_CUT, SK_COPY, SK_PSTE, SK_FAGN, SK_DOCEND, KC_END, KC_DOWN, KC_PGDN, SK_PARANXT, KC_TRNS, KC_TRNS, SK_ZOOMOUT, SK_ZOOMIN, MO(6), MO(L_MEDIA_KBD), SK_HISTPRV, SK_HISTNXT, KC_TRNS, KC_TRNS),
	[6] = LAYOUT_ffkb(KC_NO, QK_BOOT, EE_CLR, AG_SWAP, CG_SWAP, LCA(KC_DEL), SK_KILL, KC_NLCK, KC_EJCT, KC_NO, SK_ZOOMRST, KC_NO, KC_NO, RGB_TOG, HD_L_Bronze, HD_L_Titanium, KC_NO, HD_AdaptKeyToggle, KC_BRIU, KC_MPRV, KC_MUTE, KC_MNXT, SK_ZOOMOUT, KC_NO, KC_NO, AG_NORM, CG_NORM, KC_NO, KC_NO, KC_NO, KC_BRID, KC_MRWD, KC_MPLY, KC_MFFD, SK_ZOOMIN, KC_NO, KC_TRNS, AG_NORM, CG_NORM, KC_MUTE, KC_MPLY, KC_VOLD, KC_VOLU, KC_TRNS, KC_TRNS)
};

