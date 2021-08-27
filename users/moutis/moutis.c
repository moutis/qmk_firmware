
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
static bool mods_held = false;
static bool key_trap = false; // used for shift BS = del (right)


#ifdef OLED_DRIVER_ENABLE
    #include "moutis_OLED.c"
#endif

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
  /* With an if statement we can check which encoder was turned. */
  if (!index) { /* First (left) encoder */
      switch(get_highest_layer(layer_state)){
          case L_MEDIA_NAV: // media/nav layer
              /* for audio scrub bk/fwd. */
              if (clockwise) {
                  tap_code16(KC_BRIU); // BRIGHTNESS UP
              } else {
                  tap_code16(KC_BRID);  // BRIGHTNESS DN
              }
              break;
          default:
              if (clockwise) {
                tap_code(KC_VOLU); // media vol up
              } else {
                tap_code(KC_VOLD); // media vol dn
              }
              break;
      }
  } else  {  // Second (right) encoder
      switch(get_highest_layer(layer_state)){
          case L_MEDIA_NAV: // media/nav layer
//              if (clockwise) {
//                  tap_code16(G(KC_RBRC)); // prev page
//              } else {
//                  tap_code16(G(KC_LBRC)); // next page
//              }
//              break;
          case L_LANG_NUM: // punctuation layer
              if (clockwise) {
                  tap_code16(G(S(KC_EQL))); // ZOOM IN
              } else {
                  tap_code16(G(KC_MINS)); // ZOOM OUT
              }
              break;
          default:
              if (clockwise) {
                tap_code(KC_MNXT); // media next track
              } else {
                tap_code(KC_MPRV); // media prev track
              }
              break;
      }
  }
    return true;
}

#endif

#ifdef COMBO_ENABLE
    #include "moutis_COMBO_hd_bronze.c"
#endif

#include "moutis_PROCESS_RECORD_hd_bronze.c"

// leader is handled in matrix.c
uint8_t  saved_mods   = 0; // to pass state between process_record_user and matrix_scan_user

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
