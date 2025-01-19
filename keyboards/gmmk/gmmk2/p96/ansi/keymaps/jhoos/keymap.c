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

tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Ctrl, twice for Alt
    [TDE_LALT] = ACTION_TAP_DANCE_DOUBLE(KC_LCTL, KC_LALT),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap _BLW: Windows Base Layer (Default Layer)
   */
[_BLW] = LAYOUT(
  KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_PSCR,  KC_DEL,   KC_INS,   KC_PGUP,  KC_PGDN,
  KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,  KC_NUM,   KC_PSLS,  KC_PAST,  KC_PMNS,
  KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,  KC_P7,    KC_P8,    KC_P9,    KC_PPLS,
  KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,   KC_P4,    KC_P5,    KC_P6,
  KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,  KC_UP,              KC_P1,    KC_P2,    KC_P3,    KC_PENT,
  KC_LCTL,  KC_LGUI,  TD_LALT,                      KC_SPC,                                 KC_RALT,  MO(_FLW), KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_P0,    KC_PDOT),

  /* Keymap _BLM: MacOS Base Layer (Default Layer)
   */
[_BLM] = LAYOUT(
  KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_PSCR,  KC_DEL,   KC_INS,   KC_PGUP,  KC_PGDN,
  KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,  TG(_NLM), KC_PSLS,  KC_PAST,  KC_PMNS,
  KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,  KC_HOME,  KC_UP,    KC_PGUP,  KC_PPLS,
  KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,   KC_LEFT,  KC_NO,    KC_RGHT,
  KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,  KC_UP,              KC_END,   KC_DOWN,  KC_PGDN,  KC_PENT,
  KC_LCTL,  KC_LALT,  KC_LGUI,                      KC_SPC,                                 KC_LGUI,  MO(_FLM), KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_INS,   KC_DEL),

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
  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,             _______,  _______,  _______,  _______,
  _______,  DF(_BLM), _______,                     _______,                                _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______),

  /* Keymap _FLM: Function Layer (MacOS)
   */
[_FLM] = LAYOUT(
  QK_BOOT,  KC_BRID,  KC_BRIU,  KC_MCTL,  KC_WSCH,  KC_ASST,  _______,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,   _______,  _______,  _______,  _______,  _______,
  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,
  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,
  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,             _______,  _______,  _______,
  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,             _______,  _______,  _______,  _______,
  _______,  _______,  DF(_BLW),                     _______,                                _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______),

};

void keyboard_post_init_user(void) {
    rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_layers);
}

hsv_t g_detected_os_color = {HSV_OFF};

bool process_detected_host_os_user(os_variant_t detected_os) {
    switch (detected_os) {
        case OS_MACOS:
        case OS_IOS:
            set_single_default_layer(_BLM);
            break;
        case OS_WINDOWS:
            set_single_default_layer(_BLW);
            break;
        default:
            set_single_default_layer(_BLW);
            break;
    }
    return true;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    if (layer_state_cmp(state, _BLW)) {
        g_detected_os_color = HSVT_WIN;
        layer_off(_NLM);
    }
    else if (layer_state_cmp(state, _BLM)) {
        g_detected_os_color = HSVT_MAC;
        layer_on(_NLM);
    }
    else {
        g_detected_os_color = (hsv_t){HSV_OFF};
    }
    rgb_matrix_sethsv_noeeprom(g_detected_os_color.h, g_detected_os_color.s, g_detected_os_color.v);
    return state;
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
    if (get_mods() & MOD_MASK_SHIFT) {
        rgb_matrix_set_color(70, 0xFF, 0xFF, 0xFF);
        rgb_matrix_set_color(81, 0xFF, 0xFF, 0xFF);
    }
    if (get_mods() & MOD_MASK_CTRL) {
        rgb_matrix_set_color(87, 0xFF, 0xFF, 0xFF);
        rgb_matrix_set_color(93, 0xFF, 0xFF, 0xFF);
    }
    if (get_mods() & MOD_MASK_ALT) {
        if (IS_LAYER_ON(_BLW)) {
            // rgb_matrix_set_color(89, 0xFF, 0xFF, 0xFF);
            rgb_matrix_set_color(91, 0xFF, 0xFF, 0xFF);
        }
        else {
            rgb_matrix_set_color(88, 0xFF, 0xFF, 0xFF);
        }
    }
    if (get_mods() & MOD_MASK_GUI) {
        if (IS_LAYER_ON(_BLW)) {
            rgb_matrix_set_color(88, 0xFF, 0xFF, 0xFF);
        }
        else {
            rgb_matrix_set_color(89, 0xFF, 0xFF, 0xFF);
            rgb_matrix_set_color(91, 0xFF, 0xFF, 0xFF);
        }
    }
    return false;
}
