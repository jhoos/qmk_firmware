/* Copyright 2021 Glorious, LLC <salman@pcgamingrace.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "keymap.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap _BLW: Windows Base Layer (Default Layer)
   */
[_BLW] = LAYOUT(
  KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_PSCR,  KC_DEL,   KC_INS,   KC_PGUP,  KC_PGDN,
  KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,  KC_NUM,   KC_PSLS,  KC_PAST,  KC_PMNS,
  KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,  KC_P7,    KC_P8,    KC_P9,    KC_PPLS,
  KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,   KC_P4,    KC_P5,    KC_P6,
  KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,  KC_UP,              KC_P1,    KC_P2,    KC_P3,    KC_PENT,
  KC_LCTL,  KC_LALT,  KC_LGUI,                      KC_SPC,                                 KC_RALT,  MO(_FLW), KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_P0,    KC_PDOT),

  /* Keymap _BLM: MacOS Base Layer (Default Layer)
   */
[_BLM] = LAYOUT(
  KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_PSCR,  KC_DEL,   KC_INS,   KC_PGUP,  KC_PGDN,
  KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,  TG(_NLM), KC_PSLS,  KC_PAST,  KC_PMNS,
  KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,  KC_HOME,  KC_UP,    KC_PGUP,  KC_PPLS,
  KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,   KC_LEFT,  _______,  KC_RGHT,
  KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,  KC_UP,              KC_END,   KC_DOWN,  KC_PGDN,  KC_PENT,
  KC_LCTL,  KC_LALT,  KC_LGUI,                      KC_SPC,                                 KC_RALT,  MO(_FLM), KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_INS,   KC_DEL),

  /* Keymap _NLM: NumLock Layer (Mac)
   */
[_NLM] = LAYOUT(
  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  TG(_NLM), KC_PSLS,  KC_PAST,  KC_PMNS,
  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_7,     KC_8,     KC_9,     KC_PPLS,
  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            KC_4,     KC_5,     KC_6,
  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            KC_1,     KC_2,     KC_3,     KC_PENT,
  _______,  _______,  _______,                      _______,                                _______,  _______,  _______,  _______,  _______,  _______,  KC_0,     KC_DOT),

  /* Keymap _FLW: Function Layer (Windows)
   */
[_FLW] = LAYOUT(
  QK_BOOT,  KC_MYCM,  KC_WHOM,  KC_CALC,  KC_MSEL,  KC_MPRV,  KC_MNXT,  KC_MPLY,  KC_MSTP,  KC_MUTE,  KC_VOLD,  KC_VOLU,  _______,   _______,  _______,  _______,  _______,  _______,
  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,
  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,
  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,             _______,  _______,  _______,
  _______,  RM_HUEU,  RM_HUED,  RM_SPDD,  RM_SPDU,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  RM_VALU,             _______,  _______,  _______,  _______,
  _______,  _______,  UC_WIN,                       _______,                                _______,  _______,  _______,  RM_PREV,   RM_VALD,  RM_NEXT,  _______,  _______),

  /* Keymap _FLM: Function Layer (MacOS)
   */
[_FLM] = LAYOUT(
  QK_BOOT,  KC_BRID,  KC_BRIU,  KC_MCTL,  KC_WSCH,  KC_ASST,  _______,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  _______,   _______,  _______,  _______,  _______,
  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,
  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,
  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,             _______,  _______,  _______,
  _______,  RM_HUEU,  RM_HUED,  RM_SPDD,  RM_SPDU,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  RM_VALU,             _______,  _______,  _______,  _______,
  _______,  _______,  UC_WIN,                       _______,                                _______,  _______,  _______,  RM_PREV,   RM_VALD,  RM_NEXT,  _______,  _______),

};

void keyboard_post_init_user(void) {
    rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_layers);
}

bool process_detected_host_os_user(os_variant_t detected_os) {
  switch (detected_os) {
    case OS_MACOS:
    case OS_IOS:
      rgb_matrix_sethsv_noeeprom(HSV_PURPLE);
      set_single_default_layer(_BLM);
      layer_on(_NLM);
      break;
    case OS_WINDOWS:
      rgb_matrix_sethsv_noeeprom(HSV_BLUE);
      set_single_default_layer(_BLW);
      break;
    case OS_LINUX:
    case OS_UNSURE:
      rgb_matrix_sethsv_noeeprom(HSV_YELLOW);
      break;
  }
  return true;
}

bool shutdown_user(bool jump_to_bootloader) {
  if (jump_to_bootloader) {
      // red for bootloader
      layer_clear();
      rgb_matrix_set_color_all(RGB_RED);
  } else {
      // off for soft reset
      rgb_matrix_set_color_all(RGB_OFF);
  }
  // force flushing -- otherwise will never happen
  rgb_matrix_update_pwm_buffers();
  return false;
}

bool rgb_matrix_indicators_user(void) {
  if (host_keyboard_led_state().caps_lock) {
    rgb_matrix_set_color(54, 0xFF, 0xFF, 0xFF);
  }
  if (host_keyboard_led_state().num_lock || layer_state_is(_NLM)) {
    rgb_matrix_set_color(32, 0xFF, 0xFF, 0xFF);
  }
  if (is_caps_word_on()) {
    rgb_matrix_set_color(70, 0xFF, 0xFF, 0xFF);
  }
  return false;
}
