#include QMK_KEYBOARD_H

#ifdef COMBO_ENABLE
#include HD_combo_def // this has the combo definitions
#endif

#define _____ KC_TRNS
#define _non_ KC_NONE

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Qwerty Salicylic Acid's Naked 48 is logically a Planck layout
 * ,-----------------------------------------.             ,-----------------------------------------.
 * |   Q  |   W  |   E  |   R  |   T  | mute |             | play |   Y  |   U  |   I  |   O  |   P  |
 * |------+------+------+------+------+------+             +------+------+------+------+------+------|
 * |   A  |   S  |   D  |   F  |   G  | Tab  |             |  '   |   H  |   J  |   K  |   L  |   ;  |
 * |------+------+------+------+------+------+             +------+------+------+------+------+------|
 * |   Z  |   X  |   C  |   V  |   B  | num  |             | nav  |   N  |   M  |   ,  |   .  |   /  |
 * `------+------+------+------+------+------+------+------+------+------+------+------+------+------'
 *        | Down |  Up  | APP  | Bksp | Del  |LANG1 |LANG2 |  spc |  Ent |      | Left |Right |
 *        `-----------------------------------------------------------------------------------'
 */
[L_QWERTY] = LAYOUT(
    KC_Q, KC_W, KC_E, KC_R, KC_T, LT(L_MEDIA_KBD,KC_MUTE), LT(L_MEDIA_KBD,KC_MPLY), KC_Y, KC_U, KC_I, KC_O, KC_P,
    RCTL_T(KC_A), RALT_T(KC_S), RGUI_T(KC_D), RSFT_T(KC_F), LT(L_NUMPAD,KC_G), LT(L_NUMPAD,KC_TAB), KC_QUOT, LT(L_FN_NUM,KC_H), RSFT_T(KC_J), RGUI_T(KC_K), RALT_T(KC_L), RCTL_T(KC_SCLN),
    KC_Z, KC_X, KC_C, KC_V, KC_B, TT(L_NUMPAD), TT(L_NAV), KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH,
    KC_DOWN, KC_UP, KC_APP, LT(L_FN_NUM,KC_BSPC), LT(L_NAV,KC_DEL), LT(L_FN_NUM,KC_LANG2), LT(L_FN_NUM,KC_LANG1), LT(L_PUNCT,KC_SPC), LT(L_NAV,KC_ENT), LT(L_NUMPAD,KC_TAB), KC_LEFT, KC_RGHT),
[L_HDALPHA] = LAYOUT(
    HD_LT4, HD_LT3, HD_LT2, HD_LT1, HD_LT0, LT(L_MEDIA_KBD,KC_MUTE),    LT(L_MEDIA_KBD,KC_MPLY), HD_RT0, HD_RT1, HD_RT2, HD_RT3, HD_RT4,
    HD_LM4, HD_LM3, HD_LM2, HD_LM1, HD_LM0, LT(L_NUMPAD,KC_TAB),        TT(L_NAV), HD_RM0, HD_RM1, HD_RM2, HD_RM3, HD_RM4,
    HD_LB4, HD_LB3, HD_LB2, HD_LB1, HD_LB0, _____,                      _____, HD_RB0, HD_RB1, HD_RB2, HD_RB3, HD_RB4,
                     _____, _____, _____,  HD_LH2, HD_LH1, _____,  _____,  HD_RH1, HD_RH2, _____, _____, _____),
[L_PUNCT] = LAYOUT(KC_Z, KC_Q, RALT(KC_5), LALT(KC_7), LSA(KC_7), KC_ESC, KC_TRNS, LALT(KC_4), KC_DLR, A(S(KC_2)), RALT(KC_3), LALT_T(KC_Y), KC_LT, KC_LBRC, KC_LPRN, KC_LCBR, RSA(KC_5), KC_TRNS, KC_TRNS, RALT(KC_1), RSFT_T(KC_PAST), RGUI_T(KC_PEQL), RALT_T(KC_PPLS), RALT_T(KC_R), KC_GT, KC_RBRC, KC_RPRN, KC_RCBR, LALT(KC_8), KC_TRNS, KC_TRNS, KC_UNDS, KC_PIPE, KC_AMPR, KC_CIRC, KC_PERC, KC_TRNS, KC_TRNS, SK_DELWDL, SK_DELWDR, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, LSA(KC_8), LSA(KC_9), LALT(KC_9)),
[L_FN_NUM] = LAYOUT(KC_F9, KC_F10, KC_F11, KC_F12, KC_F13, KC_F16, KC_TRNS, KC_GRV, KC_6, KC_7, KC_8, KC_BSLS, LCTL_T(KC_F5), LALT_T(KC_F6), LGUI_T(KC_F7), LSFT_T(KC_F8), KC_F14, KC_F17, KC_TRNS, KC_COMM, RSFT_T(KC_1), RGUI_T(KC_5), RALT_T(KC_9), RCTL_T(KC_SLSH), KC_F1, KC_F2, KC_F3, KC_F4, KC_F15, KC_F18, KC_TAB, KC_MINS, KC_2, KC_3, KC_4, KC_EQL, KC_PSCR, KC_SLCK, KC_BSPC, KC_ENT, KC_TRNS, KC_PAUS, KC_INS, KC_TRNS, KC_0, KC_DOT, KC_SCLN, KC_PENT),
[L_NUMPAD] = LAYOUT(LALT(KC_RBRC), SK_QUIT, KC_HOME, KC_UP, KC_END, KC_PGUP, KC_TRNS, KC_PSLS, KC_P7, KC_P8, KC_P9, KC_PMNS, LSA(KC_3), LALT_T(KC_TAB), KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, KC_TRNS, KC_PAST, KC_P4, KC_P5, KC_P6, KC_PPLS, LSA(KC_4), SK_UNDO, SK_CUT, SK_COPY, SK_PSTE, KC_ENT, KC_NLCK, KC_PCMM, KC_P1, KC_P2, KC_P3, KC_PEQL, KC_TRNS, KC_TRNS, KC_BSPC, KC_ENT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_P0, KC_PDOT, KC_C, KC_TRNS),
[L_NAV] = LAYOUT(SK_QUIT, SK_CLOZ, SK_SCAP, SK_SCLP, SK_FAGN, KC_TRNS, KC_TRNS, SK_DOCBEG, KC_HOME, KC_UP, KC_PGUP, SK_PARAPRV, KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, SK_FIND, KC_TRNS, KC_TRNS, SK_WORDPRV, KC_LEFT, KC_DOWN, KC_RGHT, SK_WORDNXT, SK_UNDO, SK_CUT, SK_COPY, SK_PSTE, SK_PSTM, KC_TRNS, KC_TRNS, SK_DOCEND, KC_END, KC_DOWN, KC_LALT, SK_PARANXT, KC_TRNS, KC_TRNS, SK_DELWDL, SK_DELWDR, KC_TRNS, KC_TRNS, KC_TRNS, SK_ZOOMRST, SK_HISTPRV, SK_HISTNXT, SK_ZOOMOUT, SK_ZOOMIN),
[L_MEDIA_KBD] = LAYOUT(RESET, AG_SWAP, CG_SWAP, KC_NO, LCA(KC_DEL), KC_TRNS, RGB_TOG, SK_KILL, KC_NLCK, KC_EJCT, KC_NO, KC_NO, KC_NO, HD_L_Bronze, HD_L_Titanium, HD_L_Rhodium, KC_NO, RGB_VAI, RGB_HUI, KC_BRIU, KC_MNXT, KC_MUTE, KC_MPRV, KC_NO, KC_NO, AG_NORM, CG_NORM, KC_NO, HD_AdaptKeyToggle, RGB_VAD, RGB_HUD, KC_BRID, KC_MRWD, KC_MPLY, KC_MFFD, KC_NO, KC_NO, KC_NO, KC_NO, RGB_SPD, RGB_SPI, RGB_SAD, RGB_SAI, RGB_MOD, KC_VOLD, KC_VOLU, KC_VOLU, KC_VOLD)
};
