//
//  moutis_layers.h
//  
//
//  Created by Alan on 6/23/23.
//

#ifndef moutis_layers_h
#define moutis_layers_h
#endif /* moutis_layers_h */


//     Key Position Names for a 34 (-54) key split form factor
//        Should cover Ferris through Atreus-Kyria-Ergodox
//     ╭─────────────────────╮                  ╭─────────────────────╮
// LT5 │ LT4 LT3 LT2 LT1 LT0 │ LTA          RTB │ RT0 RT1 RT2 RT3 RT4 │ RT5
// LM5 │ LM4 LM3 LM2 LM1 LM0 | LMA          RMA | RT0 RM1 RM2 RM3 RM4 │ RM5
// LB5 │ LB4 LB3 LB2 LB1 LB0 │ LBA LBB  RBB RBA │ RB0 RB1 RB2 RB3 RB4 │ RB5
//     ╰───────────╮ LH2 LH1 │ LH0 LHA  RHA RH0 │ RH1 RH2 ╭───────────╯
//     LH5 LH4 LH3 ╰─────────╯                  ╰─────────╯ RH3 RH4 RH5



/*  L_SYM Symbols and punctuation
   ╭──────────────────────────────────────────╮                  ╭───────────────────────────────────────────────╮
__ │   QUIT     CLOZ    SCAP    SCLP    FAGN  │                  │  DOCBEG     HOME    UP      PGUP    PARAPRV   │ __
__ │   LCTL     LALT    LGUI    LSFT    FIND  |                  |  WORDPRV    LEFT    DOWN    RGHT    WORDNXT   │ __
__ │   UNDO     CUT     COPY    PSTE    PSTM  │ TAB  __  __  ESC │  DOCEND     END     DOWN    PGDN    PARANXT   │ __
   ╰──────────────────╮  __   S(MENU)   MENU  │ __           __  │  HISTPRV  HISTNXT    __    ╭──────────────────╯
      HISTPRV HISTNXT ╰───────────────────────╯                  ╰────────────────────────────╯ ZOOMRST ZOOMOUT
*/

/* L_SYM Symbols & punctuation (Much of this should be handled by SemKeys/unicode for platform independance
    ______, KC_Z, KC_Q, RALT(KC_5), LALT(KC_7), LSA(KC_7), LALT(KC_4), KC_DLR, A(S(KC_2)), RALT(KC_3), LALT(KC_Y), ______,
    ______, KC_LT, KC_LBRC, KC_LPRN, KC_LCBR, RSA(KC_5), RALT(KC_1), RSFT_T(KC_PAST), RGUI_T(KC_PEQL), RALT_T(KC_PPLS), RCTL_T(KC_PSLS), ______,
    ______, KC_GT, KC_RBRC, KC_RPRN, KC_RCBR, LALT(KC_8), ______, ______, ______, ______, KC_UNDS, KC_PIPE, KC_AMPR, KC_CIRC, KC_PERC, ______,
    ______, KC_VOLD, SK_DELWDL, SK_DELWDR, KC_VOLU, LALT(KC_9), LSA(KC_8), LSA(KC_9), ______, ______),

*/
#define LS_LT5 KC_TRNS
#define LS_LT4 KC_Z
#define LS_LT3 KC_Q
#define LS_LT2 RALT(KC_5)
#define LS_LT1 LALT(KC_7)
#define LS_LT0 LSA(KC_7)
#define LS_RT0 LALT(KC_4)
#define LS_RT1 KC_DLR
#define LS_RT2 A(S(KC_2))
#define LS_RT3 RALT(KC_3)
#define LS_RT4 LALT(KC_Y)
#define LS_RT5 KC_TRNS

#define LS_LM5 KC_TRNS
#define LS_LM4 KC_LT
#define LS_LM3 KC_LBRC
#define LS_LM2 KC_LPRN
#define LS_LM1 KC_LCBR
#define LS_LM0 RSA(KC_5)
#define LS_RM0 RALT(KC_1)
#define LS_RM1 RSFT_T(KC_PAST)
#define LS_RM2 RGUI_T(KC_PEQL)
#define LS_RM3 RALT_T(KC_PPLS)
#define LS_RM4 RCTL_T(KC_PSLS)
#define LS_RM5 KC_TRNS

#define LS_LB5 KC_TRNS
#define LS_LB4 KC_GT
#define LS_LB3 KC_RBRC
#define LS_LB2 KC_RPRN
#define LS_LB1 KC_RCBR
#define LS_LB0 LALT(KC_8)
#define LS_LBA KC_TRNS
#define LS_LBB KC_TRNS
#define LS_RBB KC_TRNS
#define LS_RBA KC_TRNS
#define LS_RB0 KC_UNDS
#define LS_RB1 KC_PIPE
#define LS_RB2 KC_AMPR
#define LS_RB3 KC_CIRC
#define LS_RB4 KC_PERC
#define LS_RB5 KC_TRNS

#define LS_LH5 KC_TRNS
#define LS_LH4 KC_TRNS
#define LS_LH3 KC_VOLD
#define LS_LH2 SK_DELWDL
#define LS_LH1 SK_DELWDR
#define LS_LH0 KC_VOLU
#define LS_LHA KC_NO
#define LS_RHA KC_NO
#define LS_RH0 LALT(KC_9)
#define LS_RH1 LSA(KC_8)
#define LS_RH2 LSA(KC_9)
#define LS_RH3 KC_TRNS
#define LS_RH4 KC_TRNS
#define LS_RH5 KC_TRNS


/* L_FUN LAYER K-key row (left) and Num row (right)
         ╭──────────────────────────────────────────╮               ╭──────────────────────────────────────────╮
 RGB_TOG │ F9       F10     F11     F12     F13     │               │ /       7       8       9       -        │ RGB_MOD
 RGB_VAI │ C_T(F5)  A_T(F6) G_T(F7) S_T(L8) F14     |               | *       S_T(1)  G_T(2)  A_T(3)  C_T(+)   │ RGB_HUI
 RGB_VAD │ F1       F2      F3      F4      INS     │ __ __   __ __ │ ,       4       5       3       =        │ RGB_HUD
         ╰────────────────╮ __      __      __      │ __         __ │ 0       .       TG(LN)  ╭────────────────╯
              __      __  ╰─────────────────────────╯               ╰─────────────────────────╯ __       __
*/
/*
    RGB_TOG, KC_F9, KC_F10, KC_F11, KC_F12, KC_F13, KC_SLSH, KC_7, KC_8, KC_9, KC_MINS, RGB_MOD,
    RGB_VAI, LCTL_T(KC_F5), LALT_T(KC_F6), LGUI_T(KC_F7), LSFT_T(KC_F8), KC_F14, KC_COMM, RSFT_T(KC_1), RGUI_T(KC_2), RALT_T(KC_3), RCTL_T(KC_PPLS), RGB_HUI,
    RGB_VAD, KC_F1, KC_F2, KC_F3, KC_F4, KC_INS, ______, ______, ______, ______, KC_COMM, KC_4, KC_5, KC_6, KC_EQL, RGB_HUD,
    ______, ______, KC_SCLN, TG(L_NUM), ______, ______, KC_0, KC_DOT, ______, SK_ZOOMRST),
*/

#define LF_LT5 RGB_TOG
#define LF_LT4 KC_F9
#define LF_LT3 KC_F10
#define LF_LT2 KC_F11
#define LF_LT1 KC_F12
#define LF_LT0 KC_F13
#define LF_RT0 KC_SLSH
#define LF_RT1 KC_7
#define LF_RT2 KC_8
#define LF_RT3 KC_9
#define LF_RT4 KC_MINS
#define LF_RT5 RGB_MOD

#define LF_LM5 RGB_VAI
#define LF_LM4 LCTL_T(KC_F5)
#define LF_LM3 LALT_T(KC_F6)
#define LF_LM2 LGUI_T(KC_F7)
#define LF_LM1 LSFT_T(KC_F8)
#define LF_LM0 KC_F14
#define LF_RM0 KC_COMM
#define LF_RM1 RSFT_T(KC_1)
#define LF_RM2 RGUI_T(KC_2)
#define LF_RM3 RALT_T(KC_3)
#define LF_RM4 RCTL_T(KC_PPLS)
#define LF_RM5 RGB_HUI

#define LF_LB5 RGB_VAD
#define LF_LB4 KC_F1
#define LF_LB3 KC_F2
#define LF_LB2 KC_F3
#define LF_LB1 KC_F4
#define LF_LB0 KC_INS
#define LF_LBA KC_TRNS
#define LF_LBB KC_TRNS
#define LF_RBB KC_TRNS
#define LF_RBA KC_TRNS
#define LF_RB0 KC_COMM
#define LF_RB1 KC_4
#define LF_RB2 KC_5
#define LF_RB3 KC_6
#define LF_RB4 KC_EQL
#define LF_RB5 RGB_HUD

#define LF_LH5 KC_TRNS
#define LF_LH4 KC_TRNS
#define LF_LH3 KC_TRNS
#define LF_LH2 KC_SCLN
#define LF_LH1 TG(L_NUM)
#define LF_LH0 KC_TRNS
#define LF_LHA KC_NO
#define LF_RHA KC_NO
#define LF_RH0 KC_TRNS
#define LF_RH1 KC_0
#define LF_RH2 KC_DOT
#define LF_RH3 KC_TRNS
#define LF_RH4 SK_ZOOMRST
#define LF_RH5 KC_TRNS


/*  L_NUM Layer (LN)
   ╭──────────────────────────────────────────╮               ╭──────────────────────────────────────────╮
__ │ TAB      PGUP    UP      PGDN      TAB   │               │  PSLS      P7      P8      P9      PMNS  │ __
__ │ W_LEFT   LEFT    DOWN    RGHT     W_RGHT |               |  PAST      P4      P5      P6      PPLS  │ __
__ │ UNDO     CUT     COPY    PSTE      SPC   │ __ __   __ __ │  PCMM      P1      P2      P3      PEQL  │ __
   ╰────────────────╮  __   G_T(BSP)  C_T(ENT)│ __         __ │  P0        PDOT    __   ╭────────────────╯
        __      __  ╰─────────────────────────╯               ╰─────────────────────────╯ __       __
*/
/*
 // L_NUM THE NUMPAD LAYER (right) with nav/editing on left (the 10-Key/Spreadsheet layer)
    KC_NUM,     KC_PGDN, KC_UP,   KC_PGUP, KC_TAB,              KC_PSLS,    KC_P7,         KC_P8,         KC_P9,         KC_PMNS,
    SK_WORDPRV, KC_LEFT, KC_DOWN, KC_RGHT, SK_WORDNXT,          KC_PAST,    RSFT_T(KC_P4), RGUI_T(KC_P5), RALT_T(KC_P6), RCTL_T(KC_PPLS),
    SK_UNDO,    SK_CUT,  SK_COPY, SK_PSTE, KC_SPC, KC_ESC,  KC_ESC, KC_PCMM, KC_P1, KC_P2, KC_P3, KC_PEQL,
        KC_TRNS, KC_TRNS, KC_TRNS, LGUI_T(KC_BSPC), LSFT_T(KC_ENT), KC_DEL, KC_C, KC_P0, KC_PDOT, KC_TRNS, KC_TRNS, KC_TRNS),
*/
#define LN_LT5 KC_TRNS
#define LN_LT4 KC_NUM
#define LN_LT3 KC_PGDN
#define LN_LT2 KC_UP
#define LN_LT1 KC_PGUP
#define LN_LT0 KC_TAB
#define LN_RT0 KC_PSLS
#define LN_RT1 KC_P7
#define LN_RT2 KC_P8
#define LN_RT3 KC_P9
#define LN_RT4 KC_PMNS
#define LN_RT5 KC_TRNS

#define LN_LM5 KC_TRNS
#define LN_LM4 SK_WORDPRV
#define LN_LM3 KC_LEFT
#define LN_LM2 KC_DOWN
#define LN_LM1 KC_RGHT
#define LN_LM0 SK_WORDNXT
#define LN_RM0 KC_PAST
#define LN_RM1 RSFT_T(KC_P4)
#define LN_RM2 RGUI_T(KC_P5)
#define LN_RM3 RALT_T(KC_P6)
#define LN_RM4 RCTL_T(KC_PPLS)
#define LN_RM5 KC_TRNS

#define LN_LB5 KC_TRNS
#define LN_LB4 SK_UNDO
#define LN_LB3 SK_CUT
#define LN_LB2 SK_COPY
#define LN_LB1 SK_PSTE
#define LN_LB0 KC_SPC
#define LN_LBA KC_ESC
#define LN_LBB KC_TRNS
#define LN_RBB KC_TRNS
#define LN_RBA KC_ESC
#define LN_RB0 KC_PCMM
#define LN_RB1 KC_P1
#define LN_RB2 KC_P2
#define LN_RB3 KC_P3
#define LN_RB4 KC_PEQL
#define LN_RB5 KC_TRNS

#define LN_LH5 KC_TRNS
#define LN_LH4 KC_TRNS
#define LN_LH3 KC_TRNS
#define LN_LH2 LGUI_T(KC_BSPC)
#define LN_LH1 LSFT_T(KC_ENT)
#define LN_LH0 KC_DEL
#define LN_LHA KC_NO
#define LN_RHA KC_NO
#define LN_RH0 KC_C
#define LN_RH1 KC_P0
#define LN_RH2 KC_PDOT
#define LN_RH3 KC_TRNS
#define LN_RH4 KC_TRNS
#define LN_RH5 KC_TRNS

/*  L_NAV Layer (LV)
   ╭──────────────────────────────────────────╮                  ╭───────────────────────────────────────────────╮
__ │   QUIT     CLOZ    SCAP    SCLP    FAGN  │                  │  DOCBEG     HOME    UP      PGUP    PARAPRV   │ __
__ │   LCTL     LALT    LGUI    LSFT    FIND  |                  |  WORDPRV    LEFT    DOWN    RGHT    WORDNXT   │ __
__ │   UNDO     CUT     COPY    PSTE    PSTM  │ TAB  __  __  ESC │  DOCEND     END     DOWN    PGDN    PARANXT   │ __
   ╰──────────────────╮  __   S(MENU)   MENU  │ __           __  │  HISTPRV  HISTNXT    __    ╭──────────────────╯
      HISTPRV HISTNXT ╰───────────────────────╯                  ╰────────────────────────────╯ ZOOMRST ZOOMOUT
*/
/*
 L_NAV THE NAVIGATION (right hand) LAYER w/ edit & mods on left
    KC_TRNS, SK_QUIT, SK_CLOZ, SK_SCAP, SK_SCLP, SK_FAGN, SK_DOCBEG, KC_HOME, KC_UP, KC_PGUP, SK_PARAPRV, KC_NUM,
    KC_VOLU, KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, SK_FIND, SK_WORDPRV, KC_LEFT, KC_DOWN, KC_RGHT, SK_WORDNXT, KC_TRNS,
    KC_VOLD, SK_UNDO, SK_CUT, SK_COPY, SK_PSTE, SK_PSTM, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, SK_DOCEND, KC_END, KC_DOWN, KC_PGDN, SK_PARANXT, KC_TRNS,
    SK_ZOOMRST, KC_TRNS, S(KC_APP), KC_APP, KC_TRNS, SK_ZOOMOUT, SK_HISTPRV, SK_HISTNXT, SK_ZOOMIN, SK_ZOOMRST),
*/
#define LV_LT5 KC_TRNS
#define LV_LT4 SK_QUIT
#define LV_LT3 SK_CLOZ
#define LV_LT2 SK_SCAP
#define LV_LT1 SK_SCLP
#define LV_LT0 SK_FAGN
#define LV_RT0 SK_DOCBEG
#define LV_RT1 KC_HOME
#define LV_RT2 KC_UP
#define LV_RT3 KC_PGUP
#define LV_RT4 SK_PARAPRV
#define LV_RT5 KC_NUM

#define LV_LM5 KC_VOLU
#define LV_LM4 KC_LCTL
#define LV_LM3 KC_LALT
#define LV_LM2 KC_LGUI
#define LV_LM1 KC_LSFT
#define LV_LM0 SK_FIND
#define LV_RM0 SK_WORDPRV
#define LV_RM1 KC_LEFT
#define LV_RM2 KC_DOWN
#define LV_RM3 KC_RGHT
#define LV_RM4 SK_WORDNXT
#define LV_RM5 KC_TRNS

#define LV_LB5 KC_VOLD
#define LV_LB4 SK_UNDO
#define LV_LB3 SK_CUT
#define LV_LB2 SK_COPY
#define LV_LB1 SK_PSTE
#define LV_LB0 SK_PSTM
#define LV_LBA KC_TRNS
#define LV_LBB KC_TRNS
#define LV_RBB KC_TRNS
#define LV_RBA KC_TRNS
#define LV_RB0 SK_DOCEND
#define LV_RB1 KC_END
#define LV_RB2 KC_DOWN
#define LV_RB3 KC_PGDN
#define LV_RB4 SK_PARANXT
#define LV_RB5 KC_TRNS

#define LV_LH5 KC_TRNS
#define LV_LH4 SK_ZOOMRST
#define LV_LH3 KC_TRNS
#define LV_LH2 S(KC_APP)
#define LV_LH1 KC_APP
#define LV_LH0 KC_NO
#define LV_LHA KC_NO
#define LV_RHA KC_NO
#define LV_RH0 SK_ZOOMOUT
#define LV_RH1 SK_HISTPRV
#define LV_RH2 SK_HISTNXT
#define LV_RH3 SK_ZOOMIN
#define LV_RH4 SK_ZOOMRST
#define LV_RH5 KC_TRNS

/* L_CFG Keyboard Configuration (left) and Media Settings (right)
    __no__, QK_RBT, CG_SWAP, CG_NORM, EE_CLR, LCA(KC_DEL), SK_KILL, KC_NUM, KC_EJCT, __no__, SK_ZOOMRST, RGB_MOD,
    RGB_VAI, HD_AdaptKeyToggle, HD_L_QWERTY, HD_L_ALPHA, KC_VOLU, KC_BRIU, __no__, KC_MPRV, KC_MUTE, KC_MNXT, SK_ZOOMOUT, RGB_SAI,
    RGB_HUI, QK_BOOT, AG_SWAP, AG_NORM, KC_VOLD, KC_BRID, RGB_VAD, __no__, __no__, RGB_SAD, __no__, KC_MRWD, KC_MPLY, KC_MFFD, SK_ZOOMIN, RGB_HUD,
    __no__, __no__, __no__, TG(L_NUM), __no__, __no__, __no__, __no__, __no__, __no__)
*/
#define LC_LT5 KC_NO
#define LC_LT4 QK_RBT
#define LC_LT3 CG_SWAP
#define LC_LT2 CG_NORM
#define LC_LT1 EE_CLR
#define LC_LT0 SK_KILL
#define LC_RT0 LCA(KC_DEL)
#define LC_RT1 KC_NUM
#define LC_RT2 KC_EJCT
#define LC_RT3 KC_NO
#define LC_RT4 SK_ZOOMRST
#define LC_RT5 RGB_MOD
 
#define LC_LM5 RGB_VAI
#define LC_LM4 HD_AdaptKeyToggle
#define LC_LM3 HD_L_QWERTY
#define LC_LM2 HD_L_ALPHA
#define LC_LM1 KC_VOLU
#define LC_LM0 KC_BRIU
#define LC_RM0 KC_NO
#define LC_RM1 KC_MPRV
#define LC_RM2 KC_MUTE
#define LC_RM3 KC_MNXT
#define LC_RM4 SK_ZOOMOUT
#define LC_RM5 RGB_SAI
 
#define LC_LB5 RGB_HUI
#define LC_LB4 QK_BOOT
#define LC_LB3 AG_SWAP
#define LC_LB2 AG_NORM
#define LC_LB1 KC_VOLD
#define LC_LB0 KC_BRID
#define LC_LBA RGB_VAD
#define LC_LBB KC_NO
#define LC_RBB KC_NO
#define LC_RBA RGB_SAD
#define LC_RB0 KC_NO
#define LC_RB1 KC_MRWD
#define LC_RB2 KC_MPLY
#define LC_RB3 KC_MFFD
#define LC_RB4 SK_ZOOMIN
#define LC_RB5 RGB_HUD

#define LC_LH4 KC_NO
#define LC_LH3 KC_NO
#define LC_LH2 KC_NO
#define LC_LH1 TG(L_NUM)
#define LC_LH0 KC_NO
#define LC_LHA KC_NO
#define LC_RHA KC_NO
#define LC_RH0 KC_NO
#define LC_RH1 KC_NO
#define LC_RH2 KC_NO
#define LC_RH3 KC_NO
#define LC_RH4 KC_NO

