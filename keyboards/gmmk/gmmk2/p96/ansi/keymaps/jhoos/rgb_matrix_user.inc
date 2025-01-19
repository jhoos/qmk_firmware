RGB_MATRIX_EFFECT(layers)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

#    include QMK_KEYBOARD_H
#    include "keymap.h"

#define REACTIVE_BY_HUE

static hsv_t reactive_math(hsv_t hsv, uint16_t offset) {
#    ifdef REACTIVE_BY_HUE
    // change color 1/4 way around color wheel
    hsv.h += scale8(255 - offset, 64);
#    else
    // change to white and back
    // NOTE this doesn't show up well on light colors like yellow
    hsv.v += lerp8by8(255, hsv.v, offset);
    hsv.s += scale8(offset, hsv.s);
#    endif
    return hsv;
}

static bool layers(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);
    const uint16_t max_tick          = 65535 / qadd8(rgb_matrix_config.speed, 1);
    const rgb_t    config_rgb        = rgb_matrix_hsv_to_rgb(rgb_matrix_config.hsv);
    const hsv_t    default_key_color = {HSV_YELLOW};

    // Set underglow LEDS to default (as determined by OS detection)
    for (uint8_t i = led_min; i < led_max; ++i) {
        if (HAS_ANY_FLAGS(g_led_config.flags[i], LED_FLAG_UNDERGLOW)) {
            rgb_matrix_set_color(i, config_rgb.r, config_rgb.g, config_rgb.b);
        }
    }

    // Set key colors based on active key map layer
    for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
        for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
            const uint8_t i = g_led_config.matrix_co[row][col];

            if (i >= led_min && i < led_max && i != NO_LED) {
                const keypos_t keypos = {col, row};
                hsv_t          color  = default_key_color;

                const uint8_t  keylayer = layer_switch_get_layer(keypos);
                const uint16_t keycode  = keymap_key_to_keycode(keylayer, keypos);
                switch (keycode) {
                    case KC_NO ... KC_TRANSPARENT:
                        color = (hsv_t){HSV_OFF};
                        break;
                    case KC_LSFT:
                    case KC_RSFT:
                    case TG(_NLM):
                    case KC_CAPS_LOCK:
                    case KC_NUM_LOCK:
                        color = HSVT_SFT;
                        break;
                    case KC_LCTL:
                    case KC_RCTL:
                    case TD_LALT:
                        color = HSVT_CTL;
                        break;
                    case KC_LALT:
                    case KC_RALT:
                        color = HSVT_ALT;
                        break;
                    case KC_LGUI:
                    case MO(_FLW):
                    case MO(_FLM):
                        color = HSVT_GUI;
                        break;
                    case KC_DEL:
                        color = default_key_color;
                        break;
                    case KC_HOME ... KC_PAGE_UP:
                    case KC_END ... KC_UP:
                        color = HSVT_ARW;
                        break;
                    case KC_ESC:
                    case KC_F1 ... KC_PRINT_SCREEN:
                    case KC_INS:
                        color = HSVT_FUN;
                        break;
                    case KC_P1 ... KC_PDOT:
                        if (!host_keyboard_led_state().num_lock) {
                            color = HSVT_ARW;
                        }
                        break;
                    case CONSUMER_KEYCODE_RANGE:
                        color = g_detected_os_color;
                        break;
                    case QK_BOOT:
                        color = (hsv_t){HSV_RED};
                        break;
                    case KC_A ... KC_Z:
                    case KC_MINUS:
                        if ((host_keyboard_led_state().caps_lock && keycode != KC_MINUS) || is_caps_word_on()) {
                            color = HSVT_SFT;
                        }
                        break;
                    case DF(_BLW):
                        color = HSVT_WIN;
                        break;
                    case DF(_BLM):
                        color = HSVT_MAC;
                        break;
                    default:
                        color = default_key_color;
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

                uint16_t offset = 255;
                switch (keycode) {
                    case MODIFIER_KEYCODE_RANGE:
                    case MO(_FLW):
                    case MO(_FLM):
                    case TD(_NLM):
                        // don't animate these keys
                        break;
                    default: {
                        offset = scale16by8(tick, qadd8(rgb_matrix_config.speed, 1));
                        break;
                    }
                }
                rgb_t rgb = rgb_matrix_hsv_to_rgb(reactive_math(color, offset));
                rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
            }
        }
    }

    return rgb_matrix_check_finished_leds(led_max);
}

#endif
