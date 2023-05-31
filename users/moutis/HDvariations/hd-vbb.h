
//           Base (alpha) Layer  (Hands Down Vibranium C)
//Building for a 36 key on a 42 key board (outside column is unused)
//       ╭─────────────────╮ ╭─────────────────╮
//       │  X  W  M  G  J  │ │ #$  .: /* "[ '] │
//       │  S  C  N  T  K  | | ,;   A  E  I  H │
//       │  B  P  L  D  V  │ │ -+   U  O  Y  F │
//       ╰───────╮  BSP R  │ │ SPC RET  ╭──────╯
//               ╰─────────╯ ╰──────────╯
//           Base (alpha) Layer  (Hands Down Vibranium B)
//Building for a 36 key on a 42 key board (outside column is unused)
//       ╭─────────────────╮ ╭─────────────────╮
//       │  X  W  M  G  J  │ │ #$  .: /* "[ '] │
//       │  S  C  N  T  K  | | ,;   A  E  I  H │
//       │  F  P  L  D  V  │ │ -+   U  O  Y  B │
//       ╰───────╮  BSP R  │ │ SPC RET  ╭──────╯
//               ╰─────────╯ ╰──────────╯
//           Base (alpha) Layer  (Hands Down Vibranium A)
//Building for a 36 key on a 42 key board (outside column is unused)
//       ╭─────────────────╮ ╭─────────────────╮
//       │  W  X  M  G  J  │ │ #$  .: /* "[ '] │
//       │  C  S  N  T  K  | | ,;   A  E  I  H │
//       │  P  F  L  D  V  │ │ -+   U  O  Y  B │
//       ╰───────╮  BSP R  │ │ SPC RET  ╭──────╯
//               ╰─────────╯ ╰──────────╯

// for now...
// This will morph to being properly abstracted
// similar to Miryoku, (if HD is not somehow integrated with Miryoku someday.)

//           Base (alpha) Layer  (Hands Down Vibranium C)
//Building for a 36 key on a 42 key board (outside column is unused)
//       ╭─────────────────╮ ╭─────────────────╮
//       │  X  W  M  G  J  │ │ #$  .: /* "[ '] │
//       │  S  C  N  T  K  | | ,;   A  E  I  H │
//       │  B  P  L  D  V  │ │ -+   U  O  Y  F │
//       ╰───────╮  BSP R  │ │ SPC RET  ╭──────╯
//               ╰─────────╯ ╰──────────╯
//           Base (alpha) Layer  (Hands Down Vibranium B)
//Building for a 36 key on a 42 key board (outside column is unused)
//       ╭─────────────────╮ ╭─────────────────╮
//       │  X  W  M  G  J  │ │ #$  .: /* "[ '] │
//       │  S  C  N  T  K  | | ,;   A  E  I  H │
//       │  F  P  L  D  V  │ │ -+   U  O  Y  B │
//       ╰───────╮  BSP R  │ │ SPC RET  ╭──────╯
//               ╰─────────╯ ╰──────────╯
//           Base (alpha) Layer  (Hands Down Vibranium A)
//Building for a 36 key on a 42 key board (outside column is unused)
//       ╭─────────────────╮ ╭─────────────────╮
//       │  W  X  M  G  J  │ │ #$  .: /* "[ '] │
//       │  C  S  N  T  K  | | ,;   A  E  I  H │
//       │  P  F  L  D  V  │ │ -+   U  O  Y  B │
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
#define LM0 LT(L_NUMPAD, KC_K)
#define RM0 LT(L_FN_NUM,KC_COMM)
#define RM1 RSFT_T(KC_A)
#define RM2 RGUI_T(KC_E)
#define RM3 RALT_T(KC_I)
#define RM4 RCTL_T(KC_H)

#define LB4 KC_F
#define LB3 KC_P
#define LB2 KC_L
#define LB1 KC_D
#define LB0 KC_V
#define RB0 KC_MINS
#define RB1 KC_U
#define RB2 KC_O
#define RB3 KC_Y
#define RB4 KC_B

#define LH2 LT(L_FN_NUM, KC_BSPC)
#define LH1 LT(L_NAV, KC_R)
#define RH1 LT(L_PUNCT,KC_SPC)
#define RH2 LT(L_NAV,KC_ENT)
