#pragma once

#ifndef USERSPACE
    #define USERSPACE
#endif

#include <quantum.h>

enum my_layers {
  L_HANDSDOWN,
  L_QWERTY,
  L_PUNCT,
  L_FN,
  L_MEDIA_NAV,
  L_LANG_NUM,
  L_DIACR
};

/* enum my_keycodes {
    HD_aumlt = SAFE_RANGE,
    HD_amacr,
    HD_aacut,
    HD_acrcm,
    HD_agrav,

    HD_eumlt,
    HD_emacr,
    HD_eacut,
    HD_ecrcm,
    HD_egrav,

    HD_iumlt,
    HD_imacr,
    HD_iacut,
    HD_icrcm,
    HD_igrav,

    HD_oumlt,
    HD_omacr,
    HD_oacut,
    HD_ocrcm,
    HD_ograv,

    HD_uumlt,
    HD_umacr,
    HD_uacut,
    HD_ucrcm,
    HD_ugrav

};

*/

// static uint32_t appmenu_timer = 0;
// static bool appmenu_on = false;

uint8_t  combo_on = 0;           // for combo actions to hold before triggering
bool  combo_triggered = false;   // for one-shot-combo-actions
void matrix_scan_user_process_combo(void);
