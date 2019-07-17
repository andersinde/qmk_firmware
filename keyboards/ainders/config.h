
#ifndef CONFIG_H
#define CONFIG_H

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID 0xFEED
#define PRODUCT_ID 0x6060
#define DEVICE_VER 0x0001
#define MANUFACTURER    ainders
#define PRODUCT         plink
#define DESCRIPTION     ainders

/* key matrix size */
#define MATRIX_ROWS 4
#define MATRIX_COLS 12

/* Planck PCB default pin-out */
// #define MATRIX_ROW_PINS { C6, D7, C7, D6 }
// #define MATRIX_COL_PINS { D0, F7, D1, B6, D3, B5, D2, B4, F6, B7, B3, F5 }
// #define UNUSED_PINS { B0, B1, B2, F0, F1, F4, D4, D5, E6 }

/* ainders plink Keyboard Matrix Assignments */
#define MATRIX_ROW_PINS { D1, D7, B3, B2 }
#define MATRIX_COL_PINS { F4, F5, F6, F7, B1, B6, B5, B4, E6, C6, D4, D0 }
#define UNUSED_PINS

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCING_DELAY 5



/*
 * Magic Key Options
 *
 * Magic keys are hotkey commands that allow control over firmware functions of
 * the keyboard. They are best used in combination with the HID Listen program,
 * found here: https://www.pjrc.com/teensy/hid_listen.html
 *
 * The options below allow the magic key functionality to be changed. This is
 * useful if your keyboard/keypad is missing keys and you want magic key support.
 *
 */

/* key combination for magic key command */
/*
#define IS_COMMAND() ( \
    keyboard_report->mods == (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT)) \
)
*/

#endif
