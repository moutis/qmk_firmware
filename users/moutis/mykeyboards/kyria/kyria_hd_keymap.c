#include QMK_KEYBOARD_H


#ifdef COMBO_ENABLE
#include HD_combo_def // this has the combo definitions
#endif

#define ______ KC_TRNS
#define __no__ KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [L_QWERTY] = LAYOUT(
        SK_COPY, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LNG2,
        SK_PSTE, RCTL_T(KC_A), RALT_T(KC_S), RGUI_T(KC_D), RSFT_T(KC_F), LT(L_NUMPAD,KC_G), LT(L_FN_NUM,KC_H), RSFT_T(KC_J), RGUI_T(KC_K), RALT_T(KC_L), RCTL_T(KC_SCLN), KC_LNG1,
        KC_AMPR, KC_Z, KC_X, KC_C, KC_V, KC_B, LT(L_MEDIA_KBD,KC_MUTE), LT(L_FN_NUM,KC_ESC), LT(L_FN_NUM,KC_ESC), LT(L_MEDIA_KBD,KC_MPLY), KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_EQL,
        LT(L_FN_NUM,KC_MUTE), KC_APP, LT(L_FN_NUM,KC_BSPC), LT(L_NAV,KC_DEL), LT(L_NUMPAD,KC_LNG2), LT(L_NUMPAD,KC_LNG1), LT(L_PUNCT,KC_SPC), LT(L_NAV,KC_ENT), LT(L_FN_NUM,KC_TAB), LT(L_FN_NUM,KC_MPLY)),
    /* Hands Down Layer
     * ,---------------------------------------.                                  ,---------------------------------------.
     * |  LT4  |  LT3  |  LT2  |  LT1  |  LT0  |                                  |  RT0  |  RT1  |  RT2  |  RT3  |  RT4  |
     * |-------+-------+-------+-------+-------+                                  +-------+-------+-------+-------+-------|
     * |  LM4  |  LM3  |  LM2  |  LM1  |  LM0  |                                  |  RM0  |  RM1  |  RM2  |  RM3  |  RM4  |
     * |-------+-------+-------+-------+-------+-------+-------.  ,-------+-------+-------+-------+-------+-------+-------|
     * |  LB4  |  LB3  |  LB2  |  LB1  |  LB0  | mute  |  esc  |  |  esc  |  cfg  |  RB0  |  RB1  |  RB2  |  RB3  |  RB4  |
     * `-------+-------+-------+-------+-------+-------+-------+  +-------+-------+-------+-------+-------+-------+-------'
     *                 | mute  |  LH0  |  LH2  |  LH1  | MHEN  |  | HENK  |  RH1  |  RH2  |  RH0  |  mply |
     *                 `---------------------------------------'  '---------------------------------------'
     */
    [L_HDALPHA] = LAYOUT(
        ______, HD_LT4, HD_LT3, HD_LT2, HD_LT1, HD_LT0,          HD_RT0, HD_RT1, HD_RT2, HD_RT3, HD_RT4, ______,
        ______, HD_LM4, HD_LM3, HD_LM2, HD_LM1, HD_LM0,          HD_RM0, HD_RM1, HD_RM2, HD_RM3, HD_RM4, ______,
        ______, HD_LB4, HD_LB3, HD_LB2, HD_LB1, HD_LB0, LT(L_MEDIA_KBD,KC_MUTE), LT(L_NUMPAD,KC_ESC), LT(L_NUMPAD,KC_ESC), LT(L_MEDIA_KBD,KC_MPLY), HD_RB0, HD_RB1, HD_RB2, HD_RB3, HD_RB4, ______,
        ______, ______, HD_LH2, HD_LH1, LT(L_NAV,KC_LNG2), LT(L_PUNCT,KC_LNG1), HD_RH1, HD_RH2, ______, ______),
    [L_PUNCT] = LAYOUT(
        ______, KC_Z, KC_Q, RALT(KC_5), LALT(KC_7), LSA(KC_7), LALT(KC_4), KC_DLR, A(S(KC_2)), RALT(KC_3), LALT(KC_Y), ______,
        ______, KC_LT, KC_LBRC, KC_LPRN, KC_LCBR, RSA(KC_5), RALT(KC_1), RSFT_T(KC_PAST), RGUI_T(KC_PEQL), RALT_T(KC_PPLS), RCTL_T(KC_PSLS), ______,
        ______, KC_GT, KC_RBRC, KC_RPRN, KC_RCBR, LALT(KC_8), ______, ______, ______, ______, KC_UNDS, KC_PIPE, KC_AMPR, KC_CIRC, KC_PERC, ______,
        ______, KC_VOLD, SK_DELWDL, SK_DELWDR, KC_VOLU, LALT(KC_9), LSA(KC_8), LSA(KC_9), ______, ______),
	[L_FN_NUM] = LAYOUT(
        RGB_TOG, KC_F9, KC_F10, KC_F11, KC_F12, KC_F13, KC_SLSH, KC_7, KC_8, KC_9, KC_MINS, RGB_MOD,
        RGB_VAI, LCTL_T(KC_F5), LALT_T(KC_F6), LGUI_T(KC_F7), LSFT_T(KC_F8), KC_F14, KC_COMM, RSFT_T(KC_1), RGUI_T(KC_2), RALT_T(KC_3), RCTL_T(KC_PPLS), RGB_HUI,
        RGB_VAD, KC_F1, KC_F2, KC_F3, KC_F4, KC_INS, ______, ______, ______, ______, KC_COMM, KC_4, KC_5, KC_6, KC_EQL, RGB_HUD,
        ______, ______, KC_SCLN, TG(L_NUMPAD), ______, ______, KC_0, KC_DOT, ______, SK_ZOOMRST),
	[L_NUMPAD] = LAYOUT(
        RGB_TOG, KC_ESC, KC_HOME, KC_UP, KC_PGUP, LT(L_MEDIA_KBD, KC_NUM), KC_PSLS, KC_P7, KC_P8, KC_P9, KC_PMNS, RGB_MOD,
        RGB_VAI, SK_WORDPRV, KC_LEFT, KC_DOWN, KC_RGHT, SK_WORDNXT, KC_PAST, RSFT_T(KC_P4), RGUI_T(KC_P5), RALT_T(KC_P6), RCTL_T(KC_PPLS), RGB_HUI,
        RGB_VAD, KC_DEL, KC_END, KC_TAB, KC_PGDN, KC_SPC, TG(5), __no__, __no__, LALT(KC_MINS), KC_PCMM, KC_P1, KC_P2, KC_P3, KC_PEQL, RGB_HUD,
        ______, TG(L_NUMPAD), LT(L_FN_NUM,KC_BSPC), LT(L_NAV,KC_PENT), ______, KC_DEL, LT(L_PUNCT,KC_P0), LT(L_NAV,KC_PDOT), KC_C, SK_ZOOMRST),
	[L_NAV] = LAYOUT(
        ______, SK_QUIT, SK_CLOZ, SK_SCAP, SK_SCLP, SK_FAGN, SK_DOCBEG, KC_HOME, KC_UP, KC_PGUP, SK_PARAPRV, KC_NUM,
        KC_VOLU, KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, SK_FIND, SK_WORDPRV, KC_LEFT, KC_DOWN, KC_RGHT, SK_WORDNXT, ______,
        KC_VOLD, SK_UNDO, SK_CUT, SK_COPY, SK_PSTE, SK_PSTM, ______, ______, ______, ______, SK_DOCEND, KC_END, KC_DOWN, KC_PGDN, SK_PARANXT, ______,
        SK_ZOOMRST, ______, S(KC_APP), KC_APP, ______, SK_ZOOMOUT, SK_HISTPRV, SK_HISTNXT, SK_ZOOMIN, SK_ZOOMRST),
	[L_MEDIA_KBD] = LAYOUT(
        __no__, QK_RBT, AG_SWAP, CG_SWAP, EE_CLR, LCA(KC_DEL), SK_KILL, KC_NUM, KC_EJCT, __no__, SK_ZOOMRST, RGB_MOD,
        RGB_VAI, HD_AdaptKeyToggle, HD_L_QWERTY, HD_L_ALPHA, KC_VOLU, KC_BRIU, __no__, KC_MPRV, KC_MUTE, KC_MNXT, SK_ZOOMOUT, RGB_SAI,
        RGB_HUI, QK_BOOT, AG_NORM, CG_NORM, KC_VOLD, KC_BRID, RGB_VAD, __no__, __no__, RGB_SAD, __no__, KC_MRWD, KC_MPLY, KC_MFFD, SK_ZOOMIN, RGB_HUD,
        __no__, __no__, __no__, TG(L_NUMPAD), __no__, __no__, __no__, __no__, __no__, __no__)
};

