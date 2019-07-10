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
  BACKLIT,
  EXT_PLV
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define SHIFT OSM(MOD_LSFT)
#define NTAB LCTL(KC_TAB)
#define PTAB LSFT(NTAB)

#define NO_AA LALT(KC_A) //Å
#define NO_OSLH KC_QUOT  //Ä
#define NO_AE KC_SCLN  //Ö

#define ONESHOT_TIMEOUT  3000  /* Time (in ms) before the one shot key is released */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift| Shift|  Z   |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Ctrl | Alt  | CMD  |Lower | Bksp |Space |Raise | Play | Next | Vol- | Vol+ |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = LAYOUT_planck_grid(
    KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN,     KC_BSPC,
    KC_ESC,  KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,        KC_QUOT,
    SHIFT,  SHIFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,      KC_ENT ,
    KC_LCTL, KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_BSPC, KC_SPC,  RAISE,   KC_MPLY, KC_MFFD, KC__VOLDOWN, KC__VOLUP
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |      |  ,   |  1   |  2   |  3   |      |      |  -   |  =   |  \   |  ~   |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  0   |  4   |  5   |  6   |      |  `   | PTAB | NTAB |  [   |  ]   |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  .   |  7   |  8   |  9   |      |      |  (   |  )   |      |  /   |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      | Shift|      |      | Mute | bri- | bri+ |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
    _______, KC_COMM,   KC_1,   KC_2,   KC_3, _______, _______, KC_MINS,  KC_EQL, KC_BSLS, KC_TILD, _______,
    _______,    KC_0,   KC_4,   KC_5,   KC_6, _______,  KC_GRV,    PTAB,    NTAB, KC_LBRC, KC_RBRC, _______,
    _______,  KC_DOT,   KC_7,   KC_8,   KC_9, _______, _______, KC_LPRN, KC_RPRN, _______, KC_SLSH, _______,
    _______, _______,_______,_______,_______, _______,   SHIFT, _______, _______,KC__MUTE, KC_BRID, KC_BRIU
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |      |      |  F1  |  F2  |  F3  |      |      |  å   |  ä   |  ö   |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |  F4  |  F5  |  F6  |      | left | down |  up  | right|   :  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |  F7  |  F8  |  F9  |      |      |      |      |Pg Up |Pg Dn |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
    _______, _______,  KC_F1,  KC_F2,  KC_F3, _______,  _______,   NO_AA, NO_OSLH,   NO_AE, _______, _______,
    _______, _______,  KC_F4,  KC_F5,  KC_F6, _______,  KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, KC_COLN, _______,
    _______, _______,  KC_F7,  KC_F8,  KC_F9, _______,  _______, _______, _______, KC_PGUP, KC_PGDN, _______,
    _______, _______,_______,_______,_______, _______,  _______, _______, _______, _______, _______, _______
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |EEPROM| Reset|      |      |GUI_on|      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      | left | down | up   |right |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    EEPROM_RESET, RESET,DEBUG,  _______, MAGIC_UNNO_GUI	, _______, _______, _______, _______, _______, _______, KC_DEL ,
    _______, _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, MUV_DE,   MUV_IN,  _______, _______, _______, _______, TERM_ON, TERM_OFF,_______, _______, _______,
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
    case BACKLIT:
      if (record->event.pressed) {
        register_code(KC_RSFT);
      } else {
        unregister_code(KC_RSFT);
      }
      return false;
      break;
  }
  return true;
}

void oneshot_mods_changed_user(uint8_t mods) {
  if (mods & MOD_MASK_SHIFT) {
    println("Oneshot mods SHIFT");
  }
  if (mods & MOD_MASK_CTRL) {
    println("Oneshot mods CTRL");
  }
  if (mods & MOD_MASK_ALT) {
    println("Oneshot mods ALT");
  }
  if (mods & MOD_MASK_GUI) {
    println("Oneshot mods GUI");
  }
  if (!mods) {
    println("Oneshot mods off");
  }
}

void matrix_scan_user(void) {
}
