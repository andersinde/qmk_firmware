/*
 * ainders pink planck
 */

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
  A_CIRC, //å
  A_UMLAUT, //ä
  O_UMLAUT //ö
};

#define LOWER LT(_LOWER, KC_TAB)
#define RAISE LT(_RAISE, KC_ENTER)
#define MODSHFT OSM(MOD_LSFT)
#define NTAB LCTL(KC_TAB)
#define PTAB LSFT(NTAB)
#define INV_COLORS LCTL(LALT(LCMD(KC_SPC)))

#define ESCTRL CTL_T(KC_ESC) // tab when tapped, ctrl when held
#define CMDBS  CMD_T(KC_BSPC) // backspace when tapped, command when held
#define ALTSPC LALT(KC_SPC) // space when tapped, alt when held

#define ONESHOT_TAP_TOGGLE 3

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Enter|
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |EscCtl|   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  '   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Caps | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      | CMD  |Lower | BSPC |Space |Raise | Alt  | Play| Vol- | Vol+  |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = LAYOUT_planck_grid(
    KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,   KC_G,  KC_J,   KC_L,    KC_U,  KC_Y,    KC_SCLN,     KC_ENTER,
    ESCTRL,  KC_A,    KC_R,    KC_S,    KC_T,   KC_D,  KC_H,   KC_N,    KC_E,  KC_I,    KC_O,        KC_QUOT,
    KC_CAPS, MODSHFT, KC_Z,    KC_X,    KC_C,   KC_V,  KC_B,   KC_K,    KC_M,  KC_COMM, KC_DOT,      KC_SLSH,
    _______, _______, _______, KC_LCMD, LOWER,  CMDBS, ALTSPC, RAISE, KC_LALT,  KC_MPLY, KC__VOLDOWN, KC__VOLUP
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |      |  ,   |  1   |  2   |  3   |      |      |  -   |  =   |  \   |  ~   |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  0   |  4   |  5   |  6   |      |  `   | PTAB | NTAB |  [   |  ]   |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  .   |  7   |  8   |  9   |      |      |  (   |  )   |  `   |  /   |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      | Shift|      |      | Mute | bri- | bri+ |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
    _______, KC_COMM,   KC_1,   KC_2,   KC_3, _______, _______, KC_MINS,  KC_EQL, KC_BSLS, KC_TILD, _______,
    _______,    KC_0,   KC_4,   KC_5,   KC_6, _______, _______,    PTAB,    NTAB, KC_LBRC, KC_RBRC, _______,
    _______,  KC_DOT,   KC_7,   KC_8,   KC_9, _______, _______, KC_LPRN, KC_RPRN, KC_GRV, KC_SLSH, _______,
    _______, _______,_______,_______,_______, _______, KC_LSFT, _______, _______,KC__MUTE, KC_BRID, KC_BRIU
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |      |      |  F1  |  F2  |  F3  |      |      |  å   |  ä   |  ö   |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |  F4  |  F5  |  F6  |      | left | down |  up  | right|   :  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |  F7  |  F8  |  F9  |      |      |Pg Dn |Pg Up |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
    _______, _______,  KC_F1,  KC_F2,  KC_F3, _______,  _______, A_CIRC, A_UMLAUT, O_UMLAUT,_______, _______,
    _______, _______,  KC_F4,  KC_F5,  KC_F6, _______,  KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, KC_COLN, KC_ENTER,
    _______, _______,  KC_F7,  KC_F8,  KC_F9, _______,  _______, KC_PGDN, KC_PGUP, _______, _______, _______,
    _______, _______,_______,_______,_______,  KC_DEL,  _______, _______, _______, _______, _______, _______
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |EEPROM| Reset|      |      |GUI_on|      |      |invcol|      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    EEPROM_RESET, RESET,DEBUG,  _______, MAGIC_UNNO_GUI	, _______, _______, INV_COLORS, _______, _______, _______,       ,
    _______, _______, KC_MRWD,  KC_MPLY, KC_MFFD, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______,  _______, _______, _______, _______, TERM_ON, TERM_OFF,_______, _______, _______,
    _______, _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______
)

};

uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case COLEMAK:
      if (record->event.pressed) {
        print("switched to colemak\n");
        set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
      break;
    case A_CIRC:
      if (record->event.pressed) {
          SEND_STRING(SS_LALT("a"));
      }
      return false;
      break;
    case A_UMLAUT:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT("u")"a");
      }
      return false;
      break;
    case O_UMLAUT:
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
