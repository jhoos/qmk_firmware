RGB_MATRIX_EFFECT(layers)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

#include QMK_KEYBOARD_H
#include "keymap.h"

static bool layers(effect_params_t* params) {
  RGB_MATRIX_USE_LIMITS(led_min, led_max);
  const uint8_t layer = get_highest_layer(layer_state);

  const uint16_t max_tick = 65535 / qadd8(rgb_matrix_config.speed, 1);

  const rgb_t config_rgb = rgb_matrix_hsv_to_rgb(rgb_matrix_config.hsv);
  const hsv_t default_key_color = {HSV_YELLOW};

  for (uint8_t i = led_min; i < led_max; ++i) {
    if (HAS_ANY_FLAGS(g_led_config.flags[i], LED_FLAG_UNDERGLOW)) {
      rgb_matrix_set_color(i, config_rgb.r, config_rgb.g, config_rgb.b);
    }
  }

  for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
    for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
      const uint8_t i = g_led_config.matrix_co[row][col];

      if (i >= led_min && i < led_max && i != NO_LED) {
        hsv_t color = rgb_matrix_config.hsv;

        const uint16_t keycode = keymap_key_to_keycode(layer, (keypos_t){col, row});
        switch (layer) {
          case _BL:
            switch (keycode) {
              case MODIFIER_KEYCODE_RANGE:
              case KC_PSCR:
                color = (hsv_t){HSV_CYAN};
                break;
              case KC_LEFT:
              case KC_RIGHT:
              case KC_DOWN:
              case KC_UP:
              case KC_DEL:
              case KC_INS:
              case KC_PGUP:
              case KC_PGDN:
                  color = (hsv_t){HSV_BLUE};
                  break;
              case KC_F1 ... KC_F12:
                  color = (hsv_t){HSV_ORANGE};
                  break;
              case KC_P1 ... KC_P9:
              case KC_PDOT:
                color = host_keyboard_led_state().num_lock ? default_key_color : (hsv_t){HSV_BLUE};
                break;
              case KC_P0:
                color = host_keyboard_led_state().num_lock ? default_key_color : (hsv_t){HSV_OFF};
                break;
              case MO(_FL):
              case KC_CAPS_LOCK:
              case KC_NUM_LOCK:
                color = (hsv_t){HSV_GREEN};
                break;
              case KC_A ... KC_Z:
              case KC_MINUS:
                if (host_keyboard_led_state().caps_lock && keycode != KC_MINUS) {
                  color = (hsv_t){HSV_GOLDENROD};
                }
                else if (is_caps_word_on()) {
                  color = (hsv_t){HSV_GOLDENROD};
                }
                else {
                  color = default_key_color;
                }
                break;
              default:
                color = default_key_color;
                break;
            }
            break;
          case _FL:
            if (keycode > KC_TRNS) {
              color = (hsv_t){HSV_GREEN};
            }
            else {
              color = (hsv_t){HSV_OFF};
            }
            break;
        }

        // Animate key hits like SOLID_REACT does
        uint16_t tick = max_tick;
        // Reverse search to find most recent key hit
        for (int8_t j = g_last_hit_tracker.count - 1; j >= 0; j--) {
            if (g_last_hit_tracker.index[j] == i && g_last_hit_tracker.tick[j] < tick) {
                tick = g_last_hit_tracker.tick[j];
                break;
            }
        }

        uint16_t offset = scale16by8(tick, qadd8(rgb_matrix_config.speed, 1));
        rgb_t    rgb    = rgb_matrix_hsv_to_rgb(SOLID_REACTIVE_math(color, offset));
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
      }
    }
  }

  return rgb_matrix_check_finished_leds(led_max);
}

#endif
