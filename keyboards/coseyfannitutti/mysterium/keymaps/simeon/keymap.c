#include QMK_KEYBOARD_H

enum custom_keycodes {
    CCMACRO = SAFE_RANGE,
    OEMACRO,
    KTMACRO,
    HSMACRO,
};

const char *const lines[] = {
    "Thanks from all the companies you have helped in the last 9 years:\n",
    "\n",
    "- Art Processors\n",
    "- Aussie Farmers Direct\n",
    "- Bared\n",
    "- CH2\n",
    "- Dimeo\n",
    "- Kraken Technologies\n",
    "- Loop11\n",
    "- MEERQAT\n",
    "- Middys\n",
    "- Mobile Embrace\n",
    "- Oxfam\n",
    "- WSP\n",
    "- Ynomia\n",
    "...\n"
    "\n",
    "And most of all Common Code, and all of us who have called her home.\n",
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CCMACRO:
            if (record->event.pressed) {
                SEND_STRING("Common Code");
            }
            break;
        case OEMACRO:
            if (record->event.pressed) {
                SEND_STRING("Octopus Energy");
            }
            break;
        case KTMACRO:
            if (record->event.pressed) {
                SEND_STRING("Kraken Technologies");
            }
            break;
        case HSMACRO:
            if (record->event.pressed) {
                for (size_t i = 0; i < sizeof(lines) / sizeof(lines[0]); i++) {
                    send_string(lines[i]);
                    SEND_STRING(SS_DELAY(300));
                }
            }
            break;
    };
    return true;
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_tkl_ansi(
      KC_ESC,          KC_F1,   KC_F2,   KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,   KC_F9,   KC_F10,   KC_F11,  KC_F12,   KC_PSCR,  KC_SCRL, KC_PAUS,
      KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,    KC_0,    KC_MINS,  KC_EQL,  KC_BSPC,  KC_INS,   KC_HOME, KC_PGUP,
      KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,    KC_P,    KC_LBRC,  KC_RBRC, KC_BSLS,  KC_DEL,   KC_END,  KC_PGDN,
      KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,    KC_SCLN, KC_QUOT,  KC_ENT,
      KC_LSFT,          KC_Z,    KC_X,    KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT,                     KC_UP,
      KC_LCTL, KC_LGUI, KC_LALT,                          KC_SPC,                 KC_RALT, KC_RGUI, MO(1),  KC_RCTL,            KC_LEFT, KC_DOWN, KC_RIGHT),

  [1] = LAYOUT_tkl_ansi(
      KC_SLEP,          KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, QK_BOOT,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,OEMACRO, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS,HSMACRO,KC_TRNS,KTMACRO,KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,
      KC_TRNS,          KC_TRNS, KC_TRNS, CCMACRO,KC_TRNS,KC_TRNS,KC_TRNS,KC_MUTE,KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,                     KC_VOLU,
      KC_TRNS, KC_TRNS, KC_TRNS,              KC_MEDIA_PLAY_PAUSE,                KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,            KC_MPRV, KC_VOLD, KC_MNXT)
};
// clang-format on
