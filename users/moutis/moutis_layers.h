//
//  moutis_layers.h
//  
//
//  Created by Alan on 9/23/23.
//

#ifndef moutis_layers_h
#define moutis_layers_h
#endif /* moutis_layers_h */


/*    KEY POSITION Names
    ╭─────────────────────╮                 ╭─────────────────────╮
LT5 │ LT4 LT3 LT2 LT1 LT0 │ LTA LTB RTB RTA │ RT0 RT1 RT2 RT3 RT4 │ RT5
LM5 │ LM4 LM3 LM2 LM1 LM0 │ LMA LMB RMB RMA │ RM0 RM1 RM2 RM3 RM4 │ RM5
LB5 │ LB4 LB3 LB2 LB1 LB0 │ LBA LBB RBB RBA │ RB0 RB1 RB2 RB3 RB4 │ RB5
    ╰───────╮ LH3 LH2 LH1 | LH0 LHA RHA RH0 | RH1 RH2 RH3 ╭───────╯
    LH5 LH4 ╰─────────────╯                 ╰─────────────╯ LH4 LH5
*/
/*  L_NUMPAD Layer (LN)
   ╭──────────────────────────────────────────╮ ╭──────────────────────────────────────────╮
__ │ KC_TAB   KC_HOME KC_UP   KC_END  KC_PGUP │ │ KC_PSLS KC_P7   KC_P8   KC_P9   KC_PMNS  │ __
__ │ A(TAB)   KC_LEFT KC_DOWN KC_RGHT KC_PGDN | | KC_PAST KC_P4   KC_P5   KC_P6   KC_PPLS  │ __
__ │ SK_UNDO  SK_CUT  SK_COPY SK_PSTE KC_SPC  │ │ KC_PCMM KC_P1   KC_P2   KC_P3   KC_PEQL  │ __
   ╰────────────────╮ MENU    BSP     KC_ENT  │ │ KC_P0   KC_PDOT TG(LN)  ╭────────────────╯
                    ╰─────────────────────────╯ ╰─────────────────────────╯
*/

/* L_NUMPAD Top row */
#define LN_LT4 KC_LNUM
#define LN_LT3 KC_HOME
#define LN_LT2 KC_UP
#define LN_LT1 KC_END
#define LN_LT0 KC_PGUP
#define LN_RT0 KC_PSLS
#define LN_RT1 KC_P7
#define LN_RT2 KC_P8
#define LN_RT3 KC_P9
#define LN_RT4 KC_PMNS
 
/* L_NUMPAD middle row */
#define LN_LM4 LALT_T(KC_TAB)
#define LN_LM3 KC_LEFT
#define LN_LM2 KC_DOWN
#define LN_LM1 KC_RGHT
#define LN_LM0 KC_PGDN
#define LN_RM0 KC_PAST
#define LN_RM1 KC_P4
#define LN_RM2 KC_P5
#define LN_RM3 KC_P6
#define LN_RM4 KC_PPLS

/* L_NUMPAD Bottom row */
#define LN_LB4 SK_UNDO
#define LN_LB3 SK_CUT
#define LN_LB2 SK_COPY
#define LN_LB1 SK_PSTE
#define LN_LB0 KC_SPC
#define LN_LBA KC_TRNS /* Left bottom inner key*/
#define LN_RBA KC_TRNS /* Right bottom inner key*/
#define LN_RB0 KC_PCMM
#define LN_RB1 KC_P1
#define LN_RB2 KC_P2
#define LN_RB3 KC_P3
#define LN_RB4 KC_PEQL

/* L_NUMPAD thumb row */
#define LN_RH5 ______
#define LN_RH4 ______
#define LN_LH3 KC_TRNS /* probably MENU? (KC_APP) */
#define LN_LH2 LGUI_T(KC_BSPC)
#define LN_LH1 LSFT_T(KC_ENT)
#define LN_LHA KC_TAB
#define LN_RHA KC_DEL
#define LN_RH1 KC_P0
#define LN_RH2 KC_PDOT
#define LN_RH3 TG(L_NUMPAD)
#define LN_RH4 ______
#define LN_RH5 ______

/*  L_NAV Layer (LV)
   ╭──────────────────────────────────────────╮               ╭───────────────────────────────────────────────╮
__ │ SK_QUIT  SK_CLOZ SK_SCAP SK_SCLP SK_FAGN │               │ SK_DOCBEG  KC_HOME KC_UP   KC_PGUP SK_PARAPRV │ __
__ │ KC_LCTL  KC_LALT KC_LGUI KC_LSFT SK_FIND |               | SK_WORDPRV KC_LEFT KC_DOWN KC_RGHT SK_WORDNXT │ __
__ │ SK_UNDO  SK_CUT  SK_COPY SK_PSTE SK_PSTM │ KC_ESC KC_TAB │ SK_DOCEND  KC_END  KC_DOWN KC_PGDN SK_PARANXT │ __
   ╰──────────────────╮ ______ ______  ______ │ ______ ______ │ ______     SK_HISTPRV SK_HISTNXT ╭────────────╯
SK_HISTPRV SK_HISTNXT ╰───────────────────────╯               ╰──────────────────────────────────╯  SK_ZOOMRST SK_ZOOMOUT
*/

/* L_NUMPAD Top row */
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
 
/* L_NUMPAD middle row */
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

/* L_NUMPAD Bottom row */
#define LV_LB4 SK_UNDO
#define LV_LB3 SK_CUT
#define LV_LB2 SK_COPY
#define LV_LB1 SK_PSTE
#define LV_LB0 SK_PSTM
#define LV_LBA KC_ESC /* Left bottom inner key*/
#define LV_RBA KC_TAB /* Right bottom inner key*/
#define LV_RB0 SK_DOCEND
#define LV_RB1 KC_END
#define LV_RB2 KC_DOWN
#define LV_RB3 KC_PGDN
#define LV_RB4 SK_PARANXT

/* L_NUMPAD thumb row */
#define LV_LH5 SK_HISTPRV
#define LV_LH4 SK_HISTNXT
#define LV_LH3 ______ /* probably MENU? (KC_APP) */
#define LV_LH2 ______
#define LV_LH1 ______
#define LV_LHA ______
#define LV_RHA ______
#define LV_RH1 SK_HISTPRV
#define LV_RH2 SK_HISTNXT
#define LV_RH3 SK_ZOOMRST
#define LV_RH4 SK_ZOOMOUT
#define LV_RH5 SK_ZOOMIN
