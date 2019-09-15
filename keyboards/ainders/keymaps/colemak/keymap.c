/* ainders */

#include QMK_KEYBOARD_H
#include "muse.h"

extern keymap_config_t keymap_config;

void matrix_init_user() {
  set_unicode_input_mode(UC_OSX);
};

enum planck_layers {
  _COLEMAK,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum ainders_keycodes {
  ACOLN = SAFE_RANGE
};

#define KC_LOWER  _LOWER //LT(_LOWER, KC_TAB)
#define KC_RAISE  _RAISE //LT(_RAISE, KC_ENTER)
#define KC_CMD    CMD_T(KC_MFFD)
#define KC_ALT    ALT_T(KC_MUTE)

#define KC_ATAB   LT(_RAISE, KC_TAB)
#define KC_AENT   LT(_LOWER, KC_ENTER)
 
#define KC_NTAB   LCTL(KC_TAB)  // switch tabs easily
#define KC_PTAB   LSFT(KC_NTAB)

#define KC_SCRNSH LSFT(LCMD(KC_3))// screenshot on a mac
#define KC_ESCTRL CTL_T(KC_ESC)  // tab when tapped, ctrl when held
#define KC_CAC    LCAG_T(KC_NO)  // ctrl+alt+cmd when held
#define KC_MSFT   OSM(MOD_LSFT)  // sticky shift

#define ONESHOT_TAP_TOGGLE 2 // double tap to toggle

// #define KC_A_CIRC  /* XP(UC(0xE5),*/ UC(0xC5)
// #define KC_A_UMLAUT/* XP(UC(0xE4),*/ UC(0xC4)
// #define KC_O_UMLAUT/* XP(UC(0xF6),*/ UC(0xF6)
#define KC_ACOLN ACOLN

static bool shift_held = false;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_COLEMAK] = LAYOUT_kc(
// |-----+-----+-----+-----+-----+-----|     |-----+-----+-----+-----+-----+-----|
    ATAB ,  Q  ,  W  ,  F  ,  P  ,  B  ,        J  ,  L  ,  U  ,  Y  ,  X  , BSPC,
// |-----+-----+-----+-----+-----+-----|     |-----+-----+-----+-----+-----+-----|
   ESCTRL,  A  ,  R  ,  S  ,  T  ,  G  ,        M  ,  N  ,  E  ,  I  ,  O  , QUOT,
// |-----+-----+-----+-----+-----+-----|     |-----+-----+-----+-----+-----+-----|
     CAC , MSFT,  Z  ,  C  ,  D  ,  V  ,        K  ,  H  , COMM, DOT , SLSH, AENT,
// |-----+-----+-----+-----+-----+-----|     |-----+-----+-----+-----+-----+-----|
                   ,,,     ,LOWER, CMD ,       SPC ,RAISE, ALT ,,,
//                   |-----+-----+-----|     |-----+-----+-----|
),

[_LOWER] = LAYOUT_kc(
// |-----+-----+-----+-----+-----+-----|     |-----+-----+-----+-----+-----+-----|
         , COMM,  1  ,  2  ,  3  , MINS,           , MINS, EQL , BSLS, TILD, DEL ,
// |-----+-----+-----+-----+-----+-----|     |-----+-----+-----+-----+-----+-----|
         ,  0  ,  4  ,  5  ,  6  , PLUS,           , LPRN, RPRN, LBRC, RBRC,     ,
// |-----+-----+-----+-----+-----+-----|     |-----+-----+-----+-----+-----+-----|
         , DOT ,  7  ,  8  ,  9  , ASTR,           , PTAB, NTAB, GRV ,     ,     ,
// |-----+-----+-----+-----+-----+-----|     |-----+-----+-----+-----+-----+-----|
                   ,,,     ,     ,     ,       LSFT,     ,     ,,,
//                   |-----+-----+-----|     |-----+-----+-----|
),

[_RAISE] = LAYOUT_kc(
// |-----+-----+-----+-----+-----+-----|     |-----+-----+-----+-----+-----+-----|
         , VOLU,  F1 ,  F2 ,  F2 ,     ,          ,A_UMLAUT,O_UMLAUT,,     , DEL ,
// |-----+-----+-----+-----+-----+-----|     |-----+-----+-----+-----+-----+-----|
         , VOLD, MRWD, MPLY, MFFD,     ,       LEFT, DOWN,  UP , RGHT,ACOLN,     ,
// |-----+-----+-----+-----+-----+-----|     |-----+-----+-----+-----+-----+-----|
         , MUTE,  F7 ,  F8 ,  F9 ,     ,           ,     ,     ,     ,     ,     ,
// |-----+-----+-----+-----+-----+-----|     |-----+-----+-----+-----+-----+-----|
                   ,,,     ,     , DEL ,           ,     ,     ,,,
//                   |-----+-----+-----|     |-----+-----+-----|
),

[_ADJUST] = LAYOUT_kc(
// |-----+-----+-----+-----+-----+-----|     |-----+-----+-----+-----+-----+-----|
         ,     ,     ,     ,SCRNSH,    ,           , PGDN, PGUP,     ,     ,     ,
// |-----+-----+-----+-----+-----+-----|     |-----+-----+-----+-----+-----+-----|
         ,     ,     ,     ,     ,     ,           ,     ,     ,     ,     ,     ,
// |-----+-----+-----+-----+-----+-----|     |-----+-----+-----+-----+-----+-----|
         ,     ,     ,     ,     ,     ,           ,     ,     ,     ,     ,     ,
// |-----+-----+-----+-----+-----+-----|     |-----+-----+-----+-----+-----+-----|
                   ,,,     ,     ,     ,           ,     ,     ,,,
//                   |-----+-----+-----|     |-----+-----+-----|
)

};

uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case KC_MSFT:
      shift_held = record->event.pressed;
      return true;
      break;     
//    case ACOLN:
//      if (record->event.pressed && shift_held) {
//        unregister_code(KC_MSFT);
//        register_code(KC_COLN);
//      } else {
//        register_code(KC_SCLN);
//      }
//      return false;
//      break;
    case ACOLN: {  //colon, but semicolon when shifted
      if (record->event.pressed) {
        if (!shift_held) {
          register_code(KC_LSFT);
          register_code(KC_SCLN);
      	} else {
          unregister_code(KC_LSFT);
      	  register_code(KC_SCLN);
      	}
      } else { // Release the key
        unregister_code(KC_LSFT);
      	unregister_code(KC_SCLN);
      }
      return false;
      break;
    }
  }
  return true;
}

void matrix_scan_user(void) {
}
