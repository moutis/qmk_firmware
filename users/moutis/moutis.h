#pragma once

//
// which HD alpha variation are we using?
//
// defines all variation dependent constants/files/keycodes, etc.
#include "handsdown/mi-config.h"


#ifndef USERSPACE
    #define USERSPACE
#endif

#include <quantum.h>

#ifdef EE_HANDS
    #include "split_util.h"
#endif

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
    #define RGBLIGHT_SPLIT
    #define RGBLIGHT_SLEEP

    #ifdef RGBLIGHT_ANIMATIONS
        #undef RGBLIGHT_ANIMATIONS
    #endif
    //#define RGBLIGHT_EFFECT_BREATHING
    //#define RGBLIGHT_EFFECT_TWINKLE
    //#define RGBLIGHT_SLEEP
    //#define RGBLIGHT_EFFECT_SNAKE
    //#define RGBLIGHT_MODE_ALTERNATING

    #ifdef RGBLIGHT_HUE_STEP
        #undef RGBLIGHT_HUE_STEP
    #endif
    #define RGBLIGHT_HUE_STEP 4

    #ifdef RGBLIGHT_SAT_STEP
        #undef RGBLIGHT_SAT_STEP
    #endif
    #define RGBLIGHT_SAT_STEP 4

    #ifdef RGBLIGHT_VAL_STEP
        #undef RGBLIGHT_VAL_STEP
    #endif
    #define RGBLIGHT_VAL_STEP 4
#endif



#ifdef COMBO_ENABLE
    #include "process_combo.h"
#endif

#include "moutis_casemods.h"

#include "moutis_combo.h"  //

//
// These COULD be made variation dependent, to allow
// them to adapt to geometry differences. Ex.
// most NEU variations have " ' on ring/pinky
// but Bronze/Silver heve ' " (inverted)
// since [ ] and « » are SHIFT/ALT of " '
// the paired brackets would be inverted.
// Perhaps simply redefining these in the xx-config.h
// to override these defs would be the right approach?
//
#define DQUO_S  KC_RBRC // ]
#define DQUO_A  A(S(KC_BSLS)) // »
#define DQUO_SA A(S(KC_4)) // ›
#define SQUO_S  KC_LBRC // [
#define SQUO_A  A(KC_BSLS) // «
#define SQUO_SA A(S(KC_3)) // ‹
#define JRQU KC_RBRC // keycode for "[" in Japanese mode
#define JLQU KC_LBRC // keycode for "]" in Japanese mode


typedef union {
    uint32_t raw;
    struct {
        uint8_t OSIndex; // index of platforms (0=mac, 1=win, 2=lux)? // used by semantickeys
        bool AdaptiveKeys; // Adaptive Keys On? (and advanced combos)
    };
} user_config_t;


enum my_layers {  // must be difined before semantickeys.h
// enum my_layers for layout layers for HD Neu family
    L_QWERTY,    // 0 - QWERTY compatibility layer
    L_HDALPHA,   // 1 - Hands Down Alpha layer
    L_PUNCT,     // 2 - symbols, punctuation, off-map alphas
    L_FN_NUM,    // 3 - number row & function row
    L_NUMPAD,    // 4 - numpad (right); navpad (left)
    L_NAV,       // 5 - nav pad (right); meta keys (left)
//  L_SYMBOLS,   //  diacritics are better handled by combos and semantickeys?
    L_MEDIA_KBD  // 6 - Media/Consumer controls; Keyboard settings
};

enum OS_Platform { // Used for platform support via SemKeys
    OS_Mac,     // uses ANSI_US_EXTENDED layout
    OS_Win,
    OS_count
};

#include "moutis_semantickeys.h"

#define register_linger_key(kc) {register_code16(kc);linger_key = kc;linger_timer = state_reset_timer = timer_read();}
#define unregister_linger_key() {unregister_code16(linger_key);linger_key = 0;}


void matrix_scan_user_process_combo(void);
