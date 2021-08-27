
#ifdef OLED_DRIVER_ENABLE
  #define OLED_DISPLAY_128X64
    #ifdef OLED_TIMEOUT
        #undef OLED_TIMEOUT
    #endif
    #define OLED_TIMEOUT 9000
#endif



// Allows media codes to properly register in macros and rotary encoder code
#define TAP_CODE_DELAY 5
#define TAPPING_TOGGLE 2

// #define RETRO_TAPPING
// #define TAPPING_FORCE_HOLD
#define TAPPING_TERM 180 // TAP VS HOLD timing in milliseconds
#define TAP_HOLD_CAPS_DELAY 0
#define PERMISSIVE_HOLD
#define BILATERAL_COMBINATIONS
#define IGNORE_MOD_TAP_INTERRUPT

// for some reason, these must all be here
#ifdef COMBO_ENABLE
    #ifdef COMBO_COUNT
        #undef COMBO_COUNT
    #endif
    #define COMBO_COUNT 99

    #define COMBO_ALLOW_ACTION_KEYS

    #ifdef COMBO_TERM
        #undef COMBO_TERM
    #endif
    #define COMBO_TERM (TAPPING_TERM/4) // time to get all combo keys down
    #define COMBO_HOLD (COMBO_TERM*3) // time to hold to trigger combo
#endif

#define ENCODER_DIRECTION_FLIP

// The Leader key allows to flexibly assign macros to key sequences.
#ifdef LEADER_ENABLE
    #define LEADER_PER_KEY_TIMING
    #define LEADER_TIMEOUT 750
    #define LEADER_NO_TIMEOUT
#endif

