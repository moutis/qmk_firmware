#pragma once

#include "config_common.h"

// #define DEVICE_VER  0x0001
// #define VENDOR_ID   0x4A48 // JH
// #define PRODUCT_ID  0x6474 // dt

// #define MANUFACTURER    jasonhazel
// #define PRODUCT         dust

#define MATRIX_COLS   5
#define MATRIX_ROWS   8


#define DIODE_DIRECTION COL2ROW
#define MATRIX_ROW_PINS { GP3, GP4, GP2, GP1 }
#define MATRIX_COL_PINS { GP6, GP29, GP28, GP27, GP26 }

#define SOFT_SERIAL_PIN GP0
#define USE_SERIAL
#define SELECT_SOFT_SERIAL_SPEED 0

#define EE_HANDS

#define BOOTMAGIC_LITE_ROW    3
#define BOOTMAGIC_LITE_COLUMN 0
#define BOOTMAGIC_LITE_ROW_RIGHT    3
#define BOOTMAGIC_LITE_COLUMN_RIGHT 4