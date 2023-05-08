#pragma once

/* USB Device descriptor parameter */
//#define VENDOR_ID       0x0000 //TODO: Get a vendor ID
//#define PRODUCT_ID      0x0000 //TODO: Get a product ID
//#define DEVICE_VER      0x0001
//#define MANUFACTURER    BarbellBoards
//#define PRODUCT         Rollow

/* key matrix size */
// Rows are doubled-up
#define MATRIX_ROWS  8
#define MATRIX_COLS  6
#define MATRIX_ROW_PINS \
    { D4, C6, D7, E6 }

// wiring of each half
#define MATRIX_COL_PINS \
    { F4, F5, F6, F7, B1, B3 }
#define DIODE_DIRECTION COL2ROW

#define TAPPING_TERM 200
#define DEBOUNCE 5

/* encoder support */
#define ENCODERS_PAD_A { B4 }
#define ENCODERS_PAD_B { B5 }
#define ENCODERS_PAD_A_RIGHT { B2 }
#define ENCODERS_PAD_B_RIGHT { B6 }
#define ENCODER_RESOLUTION 2

#define TAP_CODE_DELAY 10

/* communication between sides */
#define USE_SERIAL
#define SERIAL_USE_MULTI_TRANSACTION
#define SOFT_SERIAL_PIN D2
