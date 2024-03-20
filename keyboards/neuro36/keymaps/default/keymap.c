// Copyright 2022 Steven Karrmann (@skarrmann)
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H


#define COMBO_COUNT 7
uint16_t COMBO_LEN = 7;

const uint16_t PROGMEM esc_combo[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM tab_combo[] = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM minus_combo[] = {KC_J, KC_L, COMBO_END};
const uint16_t PROGMEM quote_combo[] = {KC_U, KC_O, COMBO_END};
const uint16_t PROGMEM bspc_combo[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM del_combo[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM ctld_combo[] = {KC_S, KC_D, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(esc_combo, KC_ESC),
    COMBO(tab_combo, KC_TAB),
    COMBO(minus_combo, KC_MINS),
    COMBO(quote_combo, KC_QUOT),
    COMBO(bspc_combo, KC_BSPC),
    COMBO(del_combo, KC_DEL),
    COMBO(ctld_combo, C(KC_D)),
};


enum unicode_names {
    AUMLAUT,
    AUMLAUT_UC,
    UUMLAUT,
    UUMLAUT_UC,
    OUMLAUT,
    OUMLAUT_UC,
    SZET
};

const uint32_t unicode_map[] PROGMEM = {
    [AUMLAUT]  = 0x00E4,    // ä
    [AUMLAUT_UC] = 0x00C4,  // Ä
    [UUMLAUT]  = 0x00FC,    // ü
    [UUMLAUT_UC] = 0x00DC,  // Ü
    [OUMLAUT]  = 0x00F6,    // ö
    [OUMLAUT_UC] = 0x00D6,  // Ö
    [SZET]  = 0x1E9E,       // ß
};


enum layer_names {
    _BASE,
    _SHIFT,
    _NUMBER,
    _SYMBOL,
    _COMMAND,
};

// layer control
#define MO_SYM MO(_SYMBOL)
#define NUM_SPC LT(_NUMBER, KC_SPC)
#define SYM_ENT LT(_SYMBOL, KC_ENT)
#define SFT OSM(MOD_LSFT)

// modifier keys
#define CTL_SCLN CTL_T(KC_SCLN)
#define C_X CTL_T(KC_X)
#define GUI_Z GUI_T(KC_Z)
#define GUI_SLSH GUI_T(KC_SLSH)
#define ALT_C ALT_T(KC_C)

// german special characters
#define AE XP(AUMLAUT, AUMLAUT_UC)
#define UE XP(UUMLAUT, UUMLAUT_UC)
#define OE XP(OUMLAUT, OUMLAUT_UC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_split_3x5_3(
                  KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,        KC_Y   , KC_U   , KC_I   , KC_O   , KC_P    ,
                  KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,        KC_H   , KC_J   , KC_K   , KC_L   , CTL_SCLN,
                  GUI_Z  , C_X    , ALT_C  , KC_V   , KC_B   ,        KC_N   , KC_M   , KC_COMM, KC_DOT , GUI_SLSH,
                                    C(KC_A), SFT    , SYM_ENT,        MO_SYM , NUM_SPC, OSL(_COMMAND)
    ),
    [_NUMBER] = LAYOUT_split_3x5_3(
                  KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,        KC_6   , KC_7   , KC_8   , KC_9   , KC_0   ,
                  KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,        KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, KC_VOLU,
                  KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 ,        KC_F11 , KC_F12 , KC_MPLY, KC_MNXT, KC_VOLD,
                                    _______, _______, _______,        _______, _______, _______
    ),
    [_SYMBOL] = LAYOUT_split_3x5_3(
         S(KC_1), S(KC_2), S(KC_LBRC), S(KC_RBRC) , X(SZET)  ,        AE     , UE       , S(KC_BSLS), KC_BSLS, OE     ,
         S(KC_3), S(KC_4), S(KC_9)   , S(KC_0)    , KC_GRV   ,        XXXXXXX, S(KC_EQL), XXXXXXX   , S(KC_8), S(KC_5),
         S(KC_5), S(KC_6), KC_LBRC   , KC_RBRC    , S(KC_GRV),        S(KC_7), KC_EQL   , XXXXXXX   , XXXXXXX, XXXXXXX,
                           _______   , _______    , _______  ,        _______, _______  , _______
    ),
    [_COMMAND] = LAYOUT_split_3x5_3(
        XXXXXXX, SGUI(KC_1), SGUI(KC_3), SGUI(KC_5), KC_CUT  ,        XXXXXXX, G(KC_1), G(KC_3), G(KC_5), XXXXXXX,
        XXXXXXX, SGUI(KC_2), SGUI(KC_4), SGUI(KC_6), KC_COPY ,        XXXXXXX, G(KC_2), G(KC_4), G(KC_6), XXXXXXX,
        XXXXXXX, XXXXXXX   , XXXXXXX   , XXXXXXX   , KC_PASTE,        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                             _______   , _______   , _______ ,        _______, _______, _______
    ),
};