#include QMK_KEYBOARD_H
#include "print.h"

#define MOD_MASK_LCTL MOD_BIT(KC_LCTL)
#define MOD_MASK_RCTL MOD_BIT(KC_RCTL)
#define MOD_MASK_LSFT MOD_BIT(KC_LSFT)
#define MOD_MASK_RSFT MOD_BIT(KC_RSFT)
#define MOD_MASK_LALT MOD_BIT(KC_LALT)
#define MOD_MASK_RALT MOD_BIT(KC_RALT)

#define CS_LB LGUI(LSFT(KC_LBRC))
#define CS_RB LGUI(LSFT(KC_RBRC))
#define C_A LGUI(KC_A)

#define ENCODE XXXXXXX

enum my_keycodes {
    KC_LCS = SAFE_RANGE,
    KC_LCA,
    KC_RCS,
    KC_RCA,
    KC_LSA,
    KC_RSA,
};

enum layer { _QWERTY, _COLEMAK, _RAISE, _LOWER, _ADJUST };

// clang-format off

#define MODS    HSV_AZURE
#define MEDIA   HSV_YELLOW
#define FKEY    HSV_SPRINGGREEN
#define QWERTY  90, 85, 130
#define NUMERIC HSV_PURPLE
#define SYMBOL  HSV_MAGENTA
#define SYMBOL2 HSV_PINK
#define COLEMAK HSV_GOLD
#define CURSOR  HSV_TEAL
#define EDIT    HSV_YELLOW
#define APP     HSV_TURQUOISE
#define ADJUST  HSV_ORANGE
#define KEYCTL  HSV_CORAL
#define LOCK    HSV_CHARTREUSE
#define LOWER   HSV_BLUE
#define RAISE   HSV_RED
#define ENCODER HSV_WHITE
#define OFF     HSV_OFF


const rgblight_segment_t PROGMEM mods_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    { 1,  2, MODS   },
    {13,  1, MODS   },
    {25,  2, MODS   },
    {38,  2, MODS   },
    {45,  1, MODS   },
    {46,  1, LOWER  },
    {47,  1, RAISE  },
    {48,  1, MODS   },
    {55,  1, ENCODE },
    {56,  1, MODS   },
    {57,  1, LOWER  },
    {59,  1, MODS   },
    {62,  1, RAISE  },
    {63,  1, MODS   },
    {64,  1, ENCODE }
);
const rgblight_segment_t PROGMEM qwerty_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    { 2, 11, NUMERIC},
    {14, 11, QWERTY },
    {27, 11, QWERTY },
    {40,  5, QWERTY },
    {49,  6, QWERTY },
    {58,  1, QWERTY },
    {60,  2, QWERTY }
);
const rgblight_segment_t PROGMEM raise_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    { 1,  2, ADJUST },
    { 2, 11, FKEY   },
    {14,  3, CURSOR },
    {17,  1, MEDIA  },
    {18,  2, OFF    },
    {20,  2, EDIT   },
    {22,  3, OFF    },
    {27,  3, CURSOR },
    {30,  1, MEDIA  },
    {31,  1, LOCK   },
    {32,  1, OFF    },
    {33,  3, EDIT   },
    {36,  2, OFF    },
    {38,  1, MODS   },
    {40,  2, CURSOR },
    {42,  1, OFF    },
    {43,  2, MEDIA  },
    {49,  1, OFF    },
    {50,  3, EDIT   },
    {53,  2, OFF    }
);
const rgblight_segment_t PROGMEM lower_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    { 1, 13, OFF    },
    {13,  1, SYMBOL },
    {14, 10, NUMERIC},
    {24,  1, SYMBOL },
    {26,  1, SYMBOL2},
    {27, 10, SYMBOL },
    {37,  1, SYMBOL2},
    {39,  6, SYMBOL2},
    {49,  6, SYMBOL2}
);
const rgblight_segment_t PROGMEM adjust_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    { 1,  3, ADJUST },
    { 3,  3, OFF    },
    { 6,  1, ADJUST },
    { 7,  1, COLEMAK},
    { 8,  1, QWERTY },
    { 9, 18, OFF    },
    {27,  1, KEYCTL },
    {28, 11, OFF    },
    {39,  2, KEYCTL },
    {41, 14, OFF    },
    {55,  1, ENCODE },
    {56,  8, OFF    },
    {64,  1, ENCODE }
);
const rgblight_segment_t PROGMEM colemak_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    { 2, 11, NUMERIC},
    {14, 11, COLEMAK},
    {27, 11, COLEMAK},
    {40,  5, COLEMAK},
    {49,  6, COLEMAK}
);


const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    mods_layer,
    qwerty_layer,
    colemak_layer,
    raise_layer,
    lower_layer,
    adjust_layer
);

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT(
                KC_ESC  , KC_1    , KC_2    , KC_3    , KC_4    , KC_5       ,                                                KC_6      , KC_7   , KC_8    , KC_9   , KC_0    , KC_MINS ,
                KC_TAB  , KC_Q    , KC_W    , KC_E    , KC_R    , KC_T       ,                                                KC_Y      , KC_U   , KC_I    , KC_O   , KC_P    , KC_BSLS,
      KC_LSFT , KC_LCTL , KC_A    , KC_S    , KC_D    , KC_F    , KC_G       ,                                                KC_H      , KC_J   , KC_K    , KC_L   , KC_SCLN , KC_QUOT , KC_RSFT ,
                KC_LALT , KC_Z    , KC_X    , KC_C    , KC_V    , KC_B       , KC_LSA , TO(_LOWER) , TO(_RAISE) , KC_RSA    , KC_N      , KC_M   , KC_COMM , KC_DOT , KC_SLSH , KC_LCBR,
                                              ENCODE  , KC_LCS  , MO(_LOWER) , KC_ENT , KC_LGUI    , KC_BSPC    , KC_SPC    , MO(_RAISE), KC_RCS , ENCODE
       ),
    [_COLEMAK] = LAYOUT(
                KC_ESC  , KC_1    , KC_2    , KC_3    , KC_4    , KC_5       ,                                                KC_6      , KC_7   , KC_8    , KC_9   , KC_0    , KC_MINS ,
                KC_TAB  , KC_Q    , KC_W    , KC_F    , KC_P    , KC_B       ,                                                KC_J      , KC_L   , KC_U    , KC_Y   , KC_SCLN , KC_BSLS ,
      KC_LSFT,  KC_LCTL , KC_A    , KC_R    , KC_S    , KC_T    , KC_G       ,                                                KC_M      , KC_N   , KC_E    , KC_I   , KC_O    , KC_QUOT , KC_RSFT ,
                KC_LALT , KC_Z    , KC_X    , KC_C    , KC_D    , KC_V       , KC_LSA , TO(_LOWER) , TO(_RAISE) , KC_RSA    , KC_K      , KC_H   , KC_COMM , KC_DOT , KC_SLSH , KC_LCBR,
                                              ENCODE  , KC_LCS  , MO(_LOWER) , KC_ENT , KC_LGUI    , KC_BSPC    , KC_SPC    , MO(_RAISE), KC_RCS , ENCODE
       ),
    [_RAISE] = LAYOUT(
                       TO(_ADJUST)   , KC_F1      , KC_F2        , KC_F3     , KC_F4     , KC_F5     ,                                             KC_F6   , KC_F7         , KC_F8     , KC_F9          , KC_F10        , KC_F11  ,
                       KC_ESC        , KC_HOME    , KC_UP        , KC_END    , KC_PGUP   , XXXXXXX   ,                                             XXXXXXX , KC_DEL        , KC_INS    , XXXXXXX        , XXXXXXX       , XXXXXXX ,
      OSM(MOD_LSFT) ,  OSM(MOD_LCTL) , KC_LEFT    , KC_DOWN      , KC_RIGHT  , KC_PGDN   , KC_CAPS   ,                                             XXXXXXX , LGUI(KC_C)    , LGUI(KC_V), LGUI(KC_X)     , XXXXXXX       , XXXXXXX , OSM(MOD_RSFT),
                       OSM(MOD_LALT) , LCTL(KC_A) , LCTL(KC_E)   , XXXXXXX   , CS_LB     , CS_RB     , _______ , _______ , TO(_QWERTY) , _______ , XXXXXXX , LCTL(KC_K)    , LGUI(KC_A), LCTL(KC_E)     , XXXXXXX       , XXXXXXX ,
                                                                    ENCODE   , _______   , _______   , _______ , _______ , _______     , _______ , _______ , _______       , ENCODE
       ),
    [_LOWER] = LAYOUT(
                XXXXXXX , XXXXXXX    , XXXXXXX      , XXXXXXX   , XXXXXXX   , XXXXXXX   ,                                             XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
                KC_GRV  , KC_1       , KC_2         , KC_3      , KC_4      , KC_5      ,                                             KC_6    , KC_7    , KC_8    , KC_9    , KC_0    , KC_MINS ,
      KC_LSFT,  KC_TILD , KC_EXLM    , KC_AT        , KC_HASH   , KC_DLR    , KC_PERC   ,                                             KC_CIRC , KC_AMPR , KC_ASTR , KC_LPRN , KC_RPRN , KC_UNDS ,  KC_RSFT ,
                KC_LCTL , KC_EQL     , KC_MINS      , KC_PLUS   , KC_LCBR   , KC_RCBR   , _______  , TO(_QWERTY), _______ , _______ , KC_LBRC , KC_RBRC , KC_SCLN , KC_COLN , KC_BSLS , KC_PIPE ,
                                                      ENCODE    , _______    , _______  , _______  , _______    , _______ , _______ , _______ , _______ , ENCODE
       ),
    [_ADJUST] = LAYOUT(
                QK_BOOT , DB_TOGG , XXXXXXX , XXXXXXX , XXXXXXX , EE_CLR  ,                                         TO(_COLEMAK), TO(_QWERTY), XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
                XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,                                         XXXXXXX     , XXXXXXX    , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
      XXXXXXX , XXXXXXX , RGB_VAI , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,                                         XXXXXXX     , XXXXXXX    , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , KC_RSFT ,
                RGB_TOG , RGB_VAD , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX     , XXXXXXX    , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
                                              XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX     , XXXXXXX    , XXXXXXX
       )
};
// clang-format on

void keyboard_post_init_user(void) {
    rgblight_layers = my_rgb_layers;
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_180;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, true);
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(1, layer_state_cmp(state, _QWERTY));
    rgblight_set_layer_state(2, layer_state_cmp(state, _COLEMAK));
    rgblight_set_layer_state(3, layer_state_cmp(state, _RAISE));
    rgblight_set_layer_state(4, layer_state_cmp(state, _LOWER));
    rgblight_set_layer_state(5, layer_state_cmp(state, _ADJUST));
    return state;
}

static bool     timer_running;
static uint32_t osm_timer;
static uint8_t  osm_mods;
void            oneshot_mods_changed_user(uint8_t mods) {
    osm_mods = mods;
    if (mods == 0) {
        osm_timer     = 0;
        timer_running = false;
    } else if (!timer_running) {
        osm_timer     = timer_read();
        timer_running = true;
    }
}

#ifdef OLED_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
        case KC_LCS:
            if (record->event.pressed) {
                set_mods(MOD_MASK_LCTL | MOD_MASK_LSFT);
            } else {
                clear_mods();
            }
            return false;
        case KC_LCA:
            if (record->event.pressed) {
                set_mods(MOD_MASK_LCTL | MOD_MASK_LALT);
            } else {
                clear_mods();
            }
            return false;
        case KC_RCS:
            if (record->event.pressed) {
                set_mods(MOD_MASK_RCTL | MOD_MASK_RSFT);
            } else {
                clear_mods();
            }
            return false;
        case KC_RCA:
            if (record->event.pressed) {
                set_mods(MOD_MASK_RCTL | MOD_MASK_RALT);
            } else {
                clear_mods();
            }
            return false;
        case KC_LSA:
            if (record->event.pressed) {
                set_mods(MOD_MASK_LALT | MOD_MASK_LSFT);
            } else {
                clear_mods();
            }
            return false;
        case KC_RSA:
            if (record->event.pressed) {
                set_mods(MOD_MASK_RALT | MOD_MASK_RSFT);
            } else {
                clear_mods();
            }
            return false;
        default:
            return true;
    }
}

bool oled_task_user(void) {
    static uint32_t last_tick;
    static uint8_t  frame;
    uint8_t         mod_state;
    uint32_t        elapsed;

    oled_write_P(PSTR("\x10\x9d"), false);
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("qwerty\n"), false);
            break;
        case _COLEMAK:
            oled_write_P(PSTR("colemak\n"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("raise\n"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("lower\n"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("keybd\n"), false);
            break;
    }

    mod_state = get_mods() | osm_mods;

    oled_write_P(PSTR("# "), false);

    if (mod_state & MOD_MASK_LSFT) {
        oled_write_P(PSTR("\x18"), false);
    } else {
        oled_write_P(PSTR(" "), false);
    }

    if (mod_state & MOD_MASK_LCTL) {
        oled_write_P(PSTR("\x1E"), false);
    } else {
        oled_write_P(PSTR(" "), false);
    }

    if (mod_state & MOD_MASK_LALT) {
        oled_write_P(PSTR("\x1C"), false);
    } else {
        oled_write_P(PSTR(" "), false);
    }

    if (mod_state & MOD_MASK_GUI) {
        oled_write_P(PSTR("  \x04"), false);
    } else {
        oled_write_P(PSTR("    "), false);
    }

    if (mod_state & MOD_MASK_RALT) {
        oled_write_P(PSTR("\x1C"), false);
    } else {
        oled_write_P(PSTR(" "), false);
    }

    if (mod_state & MOD_MASK_RCTL) {
        oled_write_P(PSTR("\x1E"), false);
    } else {
        oled_write_P(PSTR(" "), false);
    }

    if (mod_state & MOD_MASK_RSFT) {
        oled_write_P(PSTR("\x18"), false);
    } else {
        oled_write_P(PSTR(" "), false);
    }

    oled_write("\r\n", false);
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.caps_lock ? PSTR("cap ") : PSTR("    "), false);
    oled_write_P(led_state.num_lock ? PSTR("num ") : PSTR("    "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("scr ") : PSTR("    "), false);

    oled_write("\r\n", false);
    if ((elapsed = timer_elapsed(osm_timer)) > ONESHOT_TIMEOUT) {
        oled_write("      ", false);
        last_tick = 0;
        osm_timer = 0;
    } else if (osm_mods != 0) {
        if (elapsed - last_tick > 85 || last_tick == 0) {
            last_tick    = elapsed;
            char* second = "----";
            sprintf(second, "%4li", elapsed);
            oled_write(second, false);
            switch (frame) {
                case 0:
                    oled_write_P(PSTR(" \x18"), false);
                    frame = 1;
                    break;
                case 1:
                    oled_write_P(PSTR(" \x1A"), false);
                    frame = 2;
                    break;
                case 2:
                    oled_write_P(PSTR(" \x19"), false);
                    frame = 3;
                    break;
                case 3:
                    oled_write_P(PSTR(" \x1B"), false);
                    frame = 0;
                    break;
            }
        }
    }

    return false;
}

#endif
