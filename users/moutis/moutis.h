#pragma once

#ifndef USERSPACE
    #define USERSPACE
#endif

enum my_layers {
  L_HANDSDOWN,
  L_QWERTY,
  L_PUNCT,
  L_FN,
  L_MEDIA_NAV,
  L_LANG_NUM,
  L_DIACR
};

// static uint32_t appmenu_timer = 0;
// static bool appmenu_on = false;

uint8_t  combo_on = 0;           // for combo actions to hold before triggering
bool  combo_triggered = false;   // for one-shot-combo-actions
void matrix_scan_user_process_combo(void);
