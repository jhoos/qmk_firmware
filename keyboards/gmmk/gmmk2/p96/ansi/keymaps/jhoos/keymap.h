#pragma once

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
enum custom_layers {
    _BLW,
    _BLM,
    _NLM,
    _FLW,
    _FLM,
};

enum tapdances {
    TDE_LALT,
};

#define TD_LALT TD(TDE_LALT)

extern hsv_t g_detected_os_color;

#define HSV_FROM_ANGLE_PCT(h, s, v) (hsv_t){((h) * 0xFF / 360), ((s) * 0xFF / 100), ((v) * 0xFF / 100)}

#define HSVT_DEFAULT (hsv_t){HSV_YELLOW}
#define HSVT_SFT HSV_FROM_ANGLE_PCT(36, 100, 100)
#define HSVT_CTL HSV_FROM_ANGLE_PCT(110, 99, 91)
#define HSVT_ALT (hsv_t){HSV_PURPLE}
#define HSVT_GUI g_detected_os_color
#define HSVT_ARW (hsv_t){HSV_BLUE}
#define HSVT_FUN (hsv_t){HSV_GREEN}
#define HSVT_MAC (HSV_FROM_ANGLE_PCT(6, 99, 100))
#define HSVT_WIN HSV_FROM_ANGLE_PCT(208, 87, 90)
