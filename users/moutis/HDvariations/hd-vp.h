
//
// The Hands Down Variation dependent files
//
#define HD_combo_header "HDvariations/vp/moutis_COMBO_hd.h"
#define HD_combo_code "HDvariations/vp/moutis_COMBO_hd.c"
#define HD_adaptive_code "HDvariations/vp/moutis_adaptivekeys_hd.c"
#define HD_process_record_code "HDvariations/vp/moutis_PROCESS_RECORD_hd.c"


//       Alpha Layer for a 34 key formfactor
// ╭─────────────────────╮ ╭─────────────────────╮
// │ LT4 LT3 LT2 LT1 LT0 │ │ RT0 RT1 RT2 RT3 RT4 │
// │ LM4 LM3 LM2 LM1 LM0 | | RT0 RM1 RM2 RM3 RM4 │
// │ LB4 LB3 LB2 LB1 LB0 │ │ RB0 RB1 RB2 RB3 RB4 │
// ╰───────────╮ LH2 LH1 │ │ RH1 RH2  ╭──────────╯
//             ╰─────────╯ ╰──────────╯
//              Hands Down Vibranium p
//     ╭─────────────────╮ ╭─────────────────╮
//     │  W  X  M  G  J  │ │ #$  .: /* "[ '] │
//     │  C  S  N  T  K  | | ,;   A  E  I  H │
//     │  P  F  L  D  V  │ │ -+   U  O  Y  B │
//     ╰───────╮  BSP R  │ │ SPC RET  ╭──────╯
//             ╰─────────╯ ╰──────────╯

// for now...
// This will morph to being entirel properly abstracted
// similar to Miryoku, (if HD is not somehow integrated with Miryoku someday.)

#define HD_LT4 KC_W
#define HD_LT3 KC_X
#define HD_LT2 KC_M
#define HD_LT1 KC_G
#define HD_LT0 KC_J
#define HD_RT0 KC_HASH
#define HD_RT1 KC_DOT
#define HD_RT2 KC_SLSH
#define HD_RT3 KC_DQUO
#define HD_RT4 KC_QUOT

#define HD_LM4 RCTL_T(KC_C)
#define HD_LM3 RALT_T(KC_S)
#define HD_LM2 RGUI_T(KC_N)
#define HD_LM1 RSFT_T(KC_T)
#define HD_LM0 LT(L_NUMPAD, KC_K)
#define HD_RM0 LT(L_FN_NUM, KC_COMM)
#define HD_RM1 RSFT_T(KC_A)
#define HD_RM2 RGUI_T(KC_E)
#define HD_RM3 RALT_T(KC_I)
#define HD_RM4 RCTL_T(KC_H)

#define HD_LB4 KC_P
#define HD_LB3 KC_F
#define HD_LB2 KC_L
#define HD_LB1 KC_D
#define HD_LB0 KC_V
#define HD_RB0 KC_MINS
#define HD_RB1 KC_U
#define HD_RB2 KC_O
#define HD_RB3 KC_Y
#define HD_RB4 KC_B

#define HD_LH2 LT(L_FN_NUM, KC_BSPC)
#define HD_LH1 LT(L_NAV, KC_R)
#define HD_RH1 LT(L_PUNCT,KC_SPC)
#define HD_RH2 LT(L_NAV,KC_ENT)


// TEXT ENTRY - off map standard alphas (also on Layer L_PUNCT @ J & G respectively)
#define HD_Z_combo HD_LM3, HD_LM1 // TYPE "z"
#define HD_Qu_combo HD_LT3, HD_LT1 // TYPE "q" (Qu & Linger deletes u)

//
// H digraph combos
// try to make these use the lead letter and a neighbor.
//
#define HD_Th_combo HD_LM2, HD_LM1 // TYPE "th"
#define HD_Ch_combo HD_LM3, HD_LM2 // TYPE "ch"
#define HD_Wh_combo HD_LT3, HD_LT2 // TYPE "wh"
#define HD_Sh_combo HD_LM4, HD_LM3 // TYPE "sh"
#define HD_Ph_combo HD_LB3, HD_LB1 // TYPE "ph"
#define HD_Gh_combo HD_LT2, HD_LT1 // TYPE "gh"
#define HD_Sch_combo HD_LM3, HD_LM4, HD_LM2 // TYPE "Sch"

