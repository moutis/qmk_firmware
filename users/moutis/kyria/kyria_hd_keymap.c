#include QMK_KEYBOARD_H

/* THIS FILE WAS GENERATED!
 *
 * This file was generated by qmk json2c. You may or may not want to
 * edit it directly.
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT(KC_COPY, KC_J, KC_F, KC_M, KC_P, KC_V, KC_HASH, KC_DOT, KC_SLSH, KC_DQUO, KC_QUOT, KC_MENU, KC_CUT, LCTL_T(KC_R), LALT_T(KC_S), LGUI_T(KC_N), LSFT_T(KC_T), KC_K, KC_COMM, RSFT_T(KC_A), RGUI_T(KC_E), RALT_T(KC_I), RCTL_T(KC_C), KC_FIND, KC_UNDO, KC_X, KC_G, KC_L, KC_D, KC_B, LT(3,KC_LANG2), SH_TT, SH_TT, LT(3,KC_LANG1), KC_MINS, KC_U, KC_O, KC_Y, KC_W, KC_PSTE, LT(6,KC_MUTE), KC_APP, LT(5,KC_BSPC), LT(4,KC_H), LT(3,KC_LANG2), LT(3,KC_LANG1), LT(2,KC_SPC), LT(4,KC_ENT), LT(5,KC_TAB), LT(8,KC_MPLY)),
	[1] = LAYOUT(KC_NO, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_NO, KC_NO, LCTL_T(KC_A), LALT_T(KC_S), LGUI_T(KC_D), LSFT_T(KC_F), KC_G, KC_H, RSFT_T(KC_J), RGUI_T(KC_K), RALT_T(KC_L), RCTL_T(KC_SCLN), KC_NO, KC_NO, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_NO, KC_TRNS, KC_TRNS, KC_BSPC, KC_SPC, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
	[2] = LAYOUT(KC_NO, LALT(KC_RBRC), A(S(KC_RBRC)), LALT(KC_LBRC), A(S(KC_LBRC)), A(S(KC_9)), LALT(KC_4), KC_DLR, A(S(KC_2)), LALT(KC_Y), RALT(KC_3), KC_NO, KC_NO, KC_LT, KC_GT, KC_LPRN, KC_RPRN, LALT(KC_8), RALT(KC_1), LSFT_T(KC_PAST), LGUI_T(KC_PEQL), LALT_T(KC_PPLS), LCTL_T(KC_BSLS), KC_NO, KC_NO, A(S(KC_5)), A(S(KC_7)), KC_LCBR, KC_RCBR, RALT(KC_5), KC_HAEN, KC_TRNS, KC_TRNS, KC_HANJ, KC_UNDS, KC_CIRC, KC_AMPR, KC_PIPE, KC_PERC, KC_NO, KC_VOLD, KC_VOLU, LALT(KC_BSPC), LALT(KC_DEL), KC_TRNS, A(S(KC_9)), KC_TRNS, LALT(KC_9), A(S(KC_8)), TG(5)),
	[3] = LAYOUT(RESET, KC_F7, KC_F3, KC_F1, KC_F5, KC_F9, KC_F8, KC_F2, KC_F10, KC_F4, KC_F6, KC_NO, KC_NO, LCTL_T(KC_9), LALT_T(KC_3), LGUI_T(KC_1), LSFT_T(KC_5), KC_7, KC_6, RSFT_T(KC_2), RGUI_T(KC_0), RALT_T(KC_4), RCTL_T(KC_8), KC_NO, KC_NO, DF(1), TO(1), TO(0), DF(0), KC_F11, RESET, KC_TRNS, KC_TRNS, KC_TRNS, KC_F12, DF(0), TO(0), TO(1), DF(1), KC_NO, KC_TRNS, C(A(KC_DEL)), AG_NORM, AG_SWAP, KC_TRNS, KC_TRNS, CG_SWAP, CG_NORM, C(A(KC_DEL)), RESET),
	[4] = LAYOUT(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, LALT(KC_HOME), KC_HOME, KC_UP, KC_PGUP, LALT(KC_PGUP), KC_NO, KC_NO, KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, KC_NO, LALT(KC_LEFT), KC_LEFT, KC_DOWN, KC_RGHT, LALT(KC_RGHT), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_HAEN, KC_NO, KC_NO, KC_HANJ, LALT(KC_END), KC_END, KC_DOWN, KC_PGDN, LALT(KC_PGDN), KC_NO, KC_BRID, KC_BRIU, KC_NO, KC_NO, KC_NO, LGUI(KC_LBRC), LGUI(KC_RBRC), G(S(KC_EQL)), LGUI(KC_MINS), LGUI(KC_0)),
	[5] = LAYOUT(KC_NO, LALT(KC_RBRC), A(S(KC_RBRC)), LALT(KC_LBRC), A(S(KC_LBRC)), A(S(KC_5)), KC_PSLS, KC_P7, KC_P8, KC_P9, KC_PMNS, KC_NO, KC_NO, KC_LT, KC_GT, KC_LPRN, KC_RPRN, LALT(KC_7), KC_PAST, KC_P4, KC_P5, KC_P6, KC_PPLS, KC_NO, KC_NO, LCTL_T(KC_LBRC), LALT_T(KC_RBRC), KC_LCBR, KC_RCBR, RALT(KC_5), LALT(KC_MINS), KC_TRNS, LALT(KC_SLSH), LALT(KC_EQL), KC_COMM, KC_P1, KC_P2, KC_P3, KC_PEQL, KC_NO, TG(5), KC_TRNS, KC_BSPC, KC_DEL, KC_TRNS, A(S(KC_EQL)), KC_P0, KC_PDOT, KC_C, KC_TRNS),
	[6] = LAYOUT(KC_NO, RALT(KC_W), RALT(KC_E), RALT(KC_6), RALT(KC_GRV), LALT(KC_J), RALT(KC_Q), LALT(KC_U), LALT(KC_K), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, RALT(KC_A), LALT(KC_N), LALT(KC_I), LALT(KC_L), KC_NO, KC_NO, RALT(KC_X), RALT(KC_C), RALT(KC_L), RALT(KC_D), RALT(KC_B), KC_NO, KC_NO, KC_NO, KC_NO, RALT(KC_Z), RALT(KC_C), LALT(KC_H), LALT(KC_P), KC_NO, KC_NO, RESET, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, RESET),
	[7] = LAYOUT(KC_NO, RALT(KC_1), RALT(KC_R), RALT(KC_G), RALT(KC_2), A(S(KC_SCLN)), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, LALT(KC_BSLS), A(S(KC_3)), A(S(KC_4)), A(S(KC_BSLS)), A(S(KC_5)), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, LALT(KC_9), LALT(KC_QUOT), RALT(KC_Q), RALT(KC_F), A(S(KC_7)), KC_CAPS, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, LALT(KC_BSPC), KC_DEL, LALT(KC_DEL), KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO),
	[8] = LAYOUT(KC_NO, KC_PSCR, KC_SLCK, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, LCTL_T(KC_BRIU), LALT_T(KC_MRWD), LGUI_T(KC_MSTP), LSFT_T(KC_MFFD), LT(5,KC_VOLU), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_BRID, KC_MPRV, KC_MUTE, KC_MNXT, KC_VOLD, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, RESET, KC_EJCT, KC_PAUS, KC_MPLY, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, RESET)
};
