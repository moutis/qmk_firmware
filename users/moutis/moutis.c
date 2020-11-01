
#include QMK_KEYBOARD_H

#include <stdio.h>
#include "process_combo.h"
#include "moutis.h"


bool is_keyboard_left(void) {
    #if defined(MASTER_LEFT)
        return is_keyboard_master();
    #elif defined(MASTER_RIGHT)
        return !is_keyboard_master();
    #elif defined(SPLIT_HAND_PIN)
        // Test pin SPLIT_HAND_PIN for High/Low, if low it's right hand
        setPinInputHigh(SPLIT_HAND_PIN);
        bool x = !readPin(SPLIT_HAND_PIN);
        setPinInput(SPLIT_HAND_PIN);
        return x;
    #elif defined(EE_HANDS)
        return eeprom_read_byte(EECONFIG_HANDEDNESS);
    #endif

    return is_keyboard_master();
}

// this borrowed from Thomas Bart
typedef union {
    uint32_t raw;
    struct {
        bool osIsWindows;
    };
} user_config_t;

user_config_t user_config;

static uint32_t keyhold_timer = 0;
static uint32_t appmenu_timer = 0;
static bool appmenu_on = false;


#ifdef OLED_DRIVER_ENABLE
    #include "moutis_OLED.c"
#endif

#ifdef COMBO_ENABLE
    #include "moutis_COMBO.c"
#endif

#include "moutis_PROCESS_RECORD.c"

// leader is handled in matrix.c
#include "moutis_MATRIX.c"


void keyboard_post_init_user(void) {
    // swap ctrl-cmd-alt keys as appropriate for platform
    // Read the user config from EEPROM
    user_config.raw = eeconfig_read_user();

#ifdef OLED_DRIVER_ENABLE
    oled_clear();
        if (user_config.osIsWindows) {
            oled_set_cursor(oled_max_chars() - 3, 0);
            oled_write_P(PSTR("WIN"), false);
        } else {
            oled_set_cursor(oled_max_chars() - 3, 0);
            oled_write_P(PSTR("MAC"), false);
        }
    oled_render();
    oled_on();
#endif
}
