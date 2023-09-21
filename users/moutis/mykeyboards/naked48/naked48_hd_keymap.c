#include QMK_KEYBOARD_H

#ifdef COMBO_ENABLE
#include HD_combo_def // this has the combo definitions
#endif

#define ______ KC_TRNS
#define __no__ KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*                          Salicylic Acid's Naked 48 is logically a Planck 12x4 layout
     * Qwerty Layer
     * ,-----------------------------------------.             ,-----------------------------------------.
     * |   Q  |   W  |   E  |   R  |   T  | mute |             | play |   Y  |   U  |   I  |   O  |   P  |
     * |------+------+------+------+------+------+             +------+------+------+------+------+------|
     * |   A  |   S  |   D  |   F  |   G  | Tab  |             |  '   |   H  |   J  |   K  |   L  |   ;  |
     * |------+------+------+------+------+------+             +------+------+------+------+------+------|
     * |   Z  |   X  |   C  |   V  |   B  | num  |             | nav  |   N  |   M  |   ,  |   .  |   /  |
     * `------+------+------+------+------+------+------+------+------+------+------+------+------+------'
     *        | Left |Right | Bksp | Del  | APP  | MHEN | HENK |  tab |  spc |  Ent |  Up  | Down |
     *        `-----------------------------------------------------------------------------------'
     */
[L_QWERTY] = LAYOUT(
    KC_Q, KC_W, KC_E, KC_R, KC_T, LT(L_MEDIA_KBD,KC_MUTE), LT(L_MEDIA_KBD,KC_MPLY), KC_Y, KC_U, KC_I, KC_O, KC_P,
    RCTL_T(KC_A), RALT_T(KC_S), RGUI_T(KC_D), RSFT_T(KC_F), LT(L_NUMPAD,KC_G), LT(L_NUMPAD,KC_TAB), KC_QUOT, LT(L_FN_NUM,KC_H), RSFT_T(KC_J), RGUI_T(KC_K), RALT_T(KC_L), RCTL_T(KC_SCLN),
    KC_Z, KC_X, KC_C, KC_V, KC_B, TT(L_NUMPAD), TT(L_NAV), KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH,
    KC_LEFT, KC_RGHT, LT(L_FN_NUM,KC_BSPC), LT(L_NAV,KC_DEL),  KC_APP, LT(L_FN_NUM,SK_MHEN), LT(L_FN_NUM,SK_HENK), LT(L_NUMPAD,KC_TAB), LT(L_PUNCT,KC_SPC), LT(L_NAV,KC_ENT), KC_UP, KC_DOWN),

    /* Hands Down Layer
     * ,-----------------------------------------------.              ,-----------------------------------------------.
     * |  LT4  |  LT3  |  LT2  |  LT1  |  LT0  | mute  |              | play  |  RT0  |  RT1  |  RT2  |  RT3  |  RT4  |
     * |-------+-------+-------+-------+-------+-------+              +-------+-------+-------+-------+-------+-------|
     * |  LM4  |  LM3  |  LM2  |  LM1  |  LM0  |  num  |              |  nav  |  RM0  |  RM1  |  RM2  |  RM3  |  RM4  |
     * |-------+-------+-------+-------+-------+-------+              +-------+-------+-------+-------+-------+-------|
     * |  LB4  |  LB3  |  LB2  |  LB1  |  LB0  |   [   |              |   ]   |  RB0  |  RB1  |  RB2  |  RB3  |  RB4  |
     * `-------+-------+-------+-------+-------+-------+------+-------+-------+-------+-------+-------+-------+-------'
     *         | Left  | Right |  LH2  |  LH1  |   (   |  APP |  cfg  |   )   |  RH1  |  RH2  |  Up   | Down  |
     *         `----------------------------------------------------------------------------------------------'
     */
[L_HDALPHA] = LAYOUT(
    HD_LT4, HD_LT3, HD_LT2, HD_LT1, HD_LT0, KC_MUTE,                    KC_MPLY, HD_RT0, HD_RT1, HD_RT2, HD_RT3, HD_RT4,
    HD_LM4, HD_LM3, HD_LM2, HD_LM1, HD_LM0, TT(L_NUMPAD),               TT(L_NAV), HD_RM0, HD_RM1, HD_RM2, HD_RM3, HD_RM4,
    HD_LB4, HD_LB3, HD_LB2, HD_LB1, HD_LB0, KC_LBRC,                    KC_RBRC, HD_RB0, HD_RB1, HD_RB2, HD_RB3, HD_RB4,
            ______, ______, HD_LH2, HD_LH1, LT(L_MEDIA_KBD,KC_LPRN), KC_APP, MO(L_MEDIA_KBD), LT(L_MEDIA_KBD,KC_RPRN),  HD_RH1, HD_RH2, ______, ______),

[L_PUNCT] = LAYOUT(
    KC_Z,   KC_Q,    RALT(KC_5), LALT(KC_7), LSA(KC_7), KC_ESC,         ______, LALT(KC_4), KC_DLR, A(S(KC_2)), RALT(KC_3), LALT_T(KC_Y),
    KC_LT,  KC_LBRC, KC_LPRN, KC_LCBR, RSA(KC_5), ______,               ______, RALT(KC_1), RSFT_T(KC_PAST), RGUI_T(KC_PEQL), RALT_T(KC_PPLS), RALT_T(KC_R),
    KC_GT,  KC_RBRC, KC_RPRN, KC_RCBR, LALT(KC_8), ______,              ______, KC_UNDS, KC_PIPE, KC_AMPR, KC_CIRC, KC_PERC,
            ______,  ______,  SK_DELWDL, SK_DELWDR, ______, ______,  ______,  ______, LSA(KC_8), LSA(KC_9), LALT(KC_9), ______),

[L_FN_NUM] = LAYOUT(
    KC_F9, KC_F10, KC_F11, KC_F12, KC_F13, KC_F16, ______, KC_SLSH, KC_7, KC_8, KC_9, KC_BSLS,
    LCTL_T(KC_F5), LALT_T(KC_F6), LGUI_T(KC_F7), LSFT_T(KC_F8), KC_F14, KC_F17, TG(L_NAV), KC_COMM, RSFT_T(KC_1), RGUI_T(KC_2), RALT_T(KC_3), RCTL_T(KC_SLSH),
    KC_F1, KC_F2, KC_F3, KC_F4, KC_F15, KC_F18, KC_TAB, KC_MINS, KC_4, KC_5, KC_6, KC_EQL,
            KC_PSCR, KC_SCRL, KC_BSPC, KC_ENT, ______, KC_PAUS,   KC_INS, ______, KC_0, KC_DOT, KC_SCLN, KC_PENT),

[L_NUMPAD] = LAYOUT(
    LALT(KC_RBRC), SK_QUIT, KC_HOME, KC_UP, KC_END, KC_PGUP,            KC_NUM, KC_PSLS, KC_P7, KC_P8, KC_P9, KC_PMNS,
    LSA(KC_3), LALT_T(KC_TAB), KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,      ______, KC_PAST, KC_P4, KC_P5, KC_P6, KC_PPLS,
    LSA(KC_4), SK_UNDO, SK_CUT, SK_COPY, SK_PSTE, KC_ENT,               TG(L_NUMPAD), KC_PCMM, KC_P1, KC_P2, KC_P3, KC_PEQL,
                    ______, ______, ______, KC_BSPC, KC_ENT, ______,    ______,   KC_P0, KC_PDOT, KC_C, ______, ______),

[L_NAV] = LAYOUT(
    SK_QUIT, SK_CLOZ, SK_SCAP, SK_SCLP, SK_FAGN, ______,                  ______, SK_DOCBEG, KC_HOME, KC_UP, KC_PGUP, SK_PARAPRV,
    KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, SK_FIND, ______,                  TG(L_NAV), SK_WORDPRV, KC_LEFT, KC_DOWN, KC_RGHT, SK_WORDNXT,
    SK_UNDO, SK_CUT, SK_COPY, SK_PSTE, SK_PSTM, TG(L_NAV),              ______, SK_DOCEND, KC_END, KC_DOWN, KC_LALT, SK_PARANXT,
            ______, ______, SK_DELWDL, SK_DELWDR, ______, ______,   SK_ZOOMRST, SK_HISTPRV, SK_HISTNXT, ______, SK_ZOOMOUT, SK_ZOOMIN),
    

[L_MEDIA_KBD] = LAYOUT(
    QK_RBT, AG_SWAP, CG_SWAP, EE_CLR, LCA(KC_DEL), ______, RGB_TOG, SK_KILL, KC_NUM, KC_EJCT, __no__, SK_ZOOMRST,
    HD_AdaptKeyToggle, HD_L_QWERTY, HD_L_ALPHA, KC_VOLU, KC_BRIU, ______, ______, __no__, KC_MPRV, KC_MUTE, KC_MNXT, SK_ZOOMOUT,

    QK_BOOT, AG_NORM, CG_NORM, KC_VOLD, KC_BRID, AG_NORM, CG_NORM, __no__, KC_MRWD, KC_MPLY, KC_MFFD, SK_ZOOMIN,

                    ______, ______, ______, ______, TG(L_NUMPAD), ______,     ______, ______, ______, ______, ______, ______)
};
