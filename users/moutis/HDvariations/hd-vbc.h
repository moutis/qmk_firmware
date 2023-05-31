
//           Base (alpha) Layer  (Hands Down Vibranium C)
//Building for a 36 key on a 42 key board (outside column is unused)
//       ╭─────────────────╮ ╭─────────────────╮
//       │  X  W  M  G  J  │ │ #$  .: /* "[ '] │
//       │  S  C  N  T  K  | | ,;   A  E  I  H │
//       │  V  P  L  D  B  │ │ -+   U  O  Y  F │
//       ╰───────╮  BSP R  │ │ SPC RET  ╭──────╯
//               ╰─────────╯ ╰──────────╯

// for now...
// This will morph to being properly abstracted
// similar to Miryoku, (if HD is not somehow integrated with Miryoku someday.)

#define LT4 KC_X
#define LT3 KC_W
#define LT2 KC_M
#define LT1 KC_G
#define LT0 KC_J
#define RT0 KC_HASH
#define RT1 KC_DOT
#define RT2 KC_SLSH
#define RT3 KC_DQUO
#define RT4 KC_QUOT

#define LM4 RCTL_T(KC_S)
#define LM3 RALT_T(KC_C)
#define LM2 RGUI_T(KC_N)
#define LM1 RSFT_T(KC_T)
#define LM0 LT(L_NUMPAD, KC_B)
#define RM0 LT(L_FN_NUM, KC_COMM)
#define RM1 RSFT_T(KC_A)
#define RM2 RGUI_T(KC_E)
#define RM3 RALT_T(KC_I)
#define RM4 RCTL_T(KC_H)

#define LB4 KC_V
#define LB3 KC_P
#define LB2 KC_L
#define LB1 KC_D
#define LB0 KC_K
#define RB0 KC_MINS
#define RB1 KC_U
#define RB2 KC_O
#define RB3 KC_Y
#define RB4 KC_F

#define LH2 LT(L_FN_NUM, KC_BSPC)
#define LH1 LT(L_NAV, KC_R)
#define RH1 LT(L_PUNCT,KC_SPC)
#define RH2 LT(L_NAV,KC_ENT)


// TEXT ENTRY - off map standard alphas (also on Layer L_PUNCT @ J & G respectively)
#define Z_combo LM3, LM1 // TYPE "z"
#define Qu_combo LT3, LT1 // TYPE "q" (Qu & Linger deletes u)

//
// H digraph combos
// try to make these use the lead letter and a neighbor.
//
#define Th_combo LM2, LM1 // TYPE "th"
#define Ch_combo LM3, LM2 // TYPE "ch"
#define Wh_combo LT3, LT2 // TYPE "wh"
#define Sh_combo LM4, LM3 // TYPE "sh"
#define Ph_combo LB3, LB1 // TYPE "ph"
#define Gh_combo LT2, LT1 // TYPE "gh"
#define Sch_combo LM3, LM4, LM2 // TYPE "Sch"

