#pragma once

#ifndef USERSPACE
    #define USERSPACE
#endif

#include <quantum.h>

#ifdef EE_HANDS
    #include "split_util.h"
#endif

#ifdef COMBO_ENABLE
    #include "process_combo.h"
#endif

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;

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

#include "keiji_casemods.h"

#ifdef COMBO_ENABLE
    #include "keiji_COMBO_hd.h"
#endif


enum OS_Platform { // Used for platform support via SemKeys
    OS_Mac,
    OS_Win,
    OS_count
};

void matrix_scan_user_process_combo(void);

typedef union {
    uint32_t raw;
    struct {
        uint8_t LBRC_key;  // keycode for "["'"
        uint8_t RBRC_key;  // keycode for "]"
        uint8_t OSIndex; // index of platforms (0=mac, 1=win, 2=lux)?
        bool AdaptiveKeys; // Adaptive Keys On?
    };
} user_config_t;


enum my_layers {
    L_HDBRONZE,
    L_PUNCT,
    L_FN_NUM,
    L_NUMPAD,
    L_NAV,
    L_MEDIA_KBD
};

#include "keiji_semantickeys.h"


#define register_linger_key(kc) {register_code16(kc);linger_key = kc;linger_timer = state_reset_timer = timer_read();}
#define unregister_linger_key() {unregister_code16(linger_key);linger_key = 0;}
/*
#define register_linger_key(kc) register_code16(kc);
#define unregister_linger_key(kc) unregister_code16(kc);
*/

