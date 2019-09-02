/* ainders */

#include QMK_KEYBOARD_H
#include "muse.h"

extern keymap_config_t keymap_config;

enum planck_layers {
  _COLEMAK,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum planck_keycodes {
  COLEMAK = SAFE_RANGE,
  KC_A_CIRC,   //å
  KC_A_UMLAUT, //ä
  KC_O_UMLAUT  //ö
};

#define KC_LOWER  LT(_LOWER, KC_TAB)
#define KC_RAISE  LT(_RAISE, KC_ENTER)
#define KC_CMD    CMD_T(KC_MUTE)
#define KC_ALT    ALT_T(KC_MFFD)

#define KC_NTAB   LCTL(KC_TAB)  // switch tabs easily
#define KC_PTAB   LSFT(KC_NTAB)

#define KC_SCRNSH LSFT(LCMD(KC_3))// screenshot on a mac
#define KC_ESCTRL CTL_T(KC_ESC)  // tab when tapped, ctrl when held
#define KC_SUPER  LCAG_T(KC_NO)  // ctrl+alt+cmd when held
#define KC_MSFT   OSM(MOD_LSFT)  // sticky shift

#define ONESHOT_TAP_TOGGLE 2 // double tap to toggle
#define KC_EMOJI UC(0x45B)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// [_COLEMAK] = LAYOUT_kc(
//          ,  Q  ,  W  ,  F  ,  P  ,  G  ,        J  ,  L  ,  U  ,  Y  , SCLN,     ,
//    ESCTRL,  A  ,  R  ,  S  ,  T  ,  D  ,        H  ,  N  ,  E  ,  I  ,  O  , QUOT,
//     SUPER, MSFT,  Z  ,  X  ,  C  ,  V  ,        B  ,  K  ,  M  , COMM, DOT ,     ,
//                    ,,, LCMD,LOWER, BSPC,       SPC ,RAISE, LALT,,,
// ),
//
// [_COLEMAKDH] = LAYOUT_kc(
//      TAB ,  Q  ,  W  ,  F  ,  P  ,  B  ,        J  ,  L  ,  U  ,  Y  , SCLN, BSPC,
//    ESCTRL,  A  ,  R  ,  S  ,  T  ,  G  ,        M  ,  N  ,  E  ,  I  ,  O  , QUOT,
//     SUPER,  Z  ,  X  ,  C  ,  D  ,  V  ,        K  ,  H  , COMM, DOT , SLSH, LALT,
//                    ,,, LCMD,LOWER, MSFT,       SPC ,RAISE,     ,,,
// ),

[_COLEMAK] = LAYOUT_kc(
// |-----+-----+-----+-----+-----+-----|     |-----+-----+-----+-----+-----+-----|
    EMOJI,  X  ,  W  ,  F  ,  P  ,  Q  ,        J  ,  L  ,  U  ,  Y  ,  B  , SCLN,
// |-----+-----+-----+-----+-----+-----|     |-----+-----+-----+-----+-----+-----|
   ESCTRL,  A  ,  R  ,  S  ,  T  ,  G  ,        M  ,  N  ,  E  ,  I  ,  O  , QUOT,
// |-----+-----+-----+-----+-----+-----|     |-----+-----+-----+-----+-----+-----|
    SUPER, MSFT,  Z  ,  C  ,  D  ,  V  ,        K  ,  H  , COMM, DOT , SLSH, SCLN,
// |-----+-----+-----+-----+-----+-----|     |-----+-----+-----+-----+-----+-----|
                   ,,, CMD ,LOWER, BSPC,       SPC ,RAISE, ALT ,,,
//                   |-----+-----+-----|     |-----+-----+-----|
),

[_LOWER] = LAYOUT_kc(
// |-----+-----+-----+-----+-----+-----|     |-----+-----+-----+-----+-----+-----|
         , COMM,  1  ,  2  ,  3  , MINS,           , MINS, EQL , BSLS, TILD,     ,
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
         , VOLU,  F1 ,  F2 ,SCRNSH,    ,         ,A_CIRC,A_UMLAUT,O_UMLAUT,,     ,
// |-----+-----+-----+-----+-----+-----|     |-----+-----+-----+-----+-----+-----|
         , VOLD, MRWD, MPLY, MFFD,     ,       LEFT, DOWN,  UP , RGHT, COLN,     ,
// |-----+-----+-----+-----+-----+-----|     |-----+-----+-----+-----+-----+-----|
         , MUTE,  F7 ,  F8 ,  F9 ,     ,           , PGDN, PGUP,     ,     ,     ,
// |-----+-----+-----+-----+-----+-----|     |-----+-----+-----+-----+-----+-----|
                   ,,,     ,     , DEL ,           ,     ,     ,,,
//                   |-----+-----+-----|     |-----+-----+-----|
),

[_ADJUST] = LAYOUT_kc(
// |-----+-----+-----+-----+-----+-----|     |-----+-----+-----+-----+-----+-----|
         ,     ,     ,     ,     ,     ,           ,     ,     ,     ,     ,     ,
// |-----+-----+-----+-----+-----+-----|     |-----+-----+-----+-----+-----+-----|
         ,     ,     ,     ,     ,     ,           ,     ,     ,     ,     ,     ,
// |-----+-----+-----+-----+-----+-----|     |-----+-----+-----+-----+-----+-----|
         ,     ,     ,     ,     ,     ,           ,     ,     ,     ,     ,     ,
// |-----+-----+-----+-----+-----+-----|     |-----+-----+-----+-----+-----+-----|
//                   |-----+-----+-----|     |-----+-----+-----|
                   ,,,     ,     ,     ,           ,     ,     ,,,
//                   |-----+-----+-----|     |-----+-----+-----|
)

};

uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case KC_A_CIRC:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT("a"));
      }
      return false;
      break;
    case KC_A_UMLAUT:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT("u")"a");
      }
      return false;
      break;
    case KC_O_UMLAUT:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT("u")"o");
      }
      return false;
      break;
  }
  return true;
}

void matrix_scan_user(void) {
}
