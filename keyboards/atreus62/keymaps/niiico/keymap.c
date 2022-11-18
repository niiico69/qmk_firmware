#include "niiico.h"
#include "keymap_bepo.h"
#include "keymap_french.h"



#ifndef UNICODE_ENABLE
#    define UC(x) KC_NO
#endif

/*
 * The `LAYOUT_atreus62_base` macro is a template to allow the use of identical
 * modifiers for the default layouts (eg QWERTY, Colemak, Dvorak, etc), so
 * that there is no need to set them up for each layout, and modify all of
 * them if I want to change them.  This helps to keep consistency and ease
 * of use. K## is a placeholder to pass through the individual keycodes
 */

// clang-format off
#define LAYOUT_atreus62_base( \
    K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, \
    K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, \
    K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A,  \
    K31, K32, K33, K34, K35, K36, K37, K38, K39, K3A  \
  ) \
  LAYOUT_wrapper( \
      KC_ESC,          K01,     K02,     K03,   K04,     K05,                                                         K06,            K07,     K08,     K09,     K0A,     BP_EQL, \
      KC_TAB,          K11,     K12,     K13,   K14,     K15,                                                         K16,            K17,     K18,     K19,     K1A,     BP_Z,    \
      BP_W,            K21,     K22,     K23,   K24,     K25,                                                         K26,            K27,     K28,     K29,     K2A,     BP_M,    \
      LSFT_T(BP_EGRV), K31,     K32,     K33,   K34,     K35,                                                         K36,            K37,     K38,     K39,     K3A,     LSFT_T(BP_CCED), \
      LCTL_T(BP_DLR),  KC_LALT, KC_LGUI, KC_UP, KC_DOWN, LSFT_T(KC_BSPC), LT(_NUMBR,KC_DEL),       LT(_NAV,KC_ENT), RSFT_T(KC_SPC), KC_LEFT, KC_RGHT, KC_RGUI, KC_RALT, KC_NO \
  )

/* Re-pass though to allow  ates to b used */
#define LAYOUT_atreus62_base_wrapper(...)       LAYOUT_atreus62_base(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BEPO] = LAYOUT_atreus62_base_wrapper(
        __________________BEPO_L0__________________, __________________BEPO_R0__________________,
        __________________BEPO_L1__________________, __________________BEPO_R1__________________,
        __________________BEPO_L2__________________, __________________BEPO_R2__________________,
        __________________BEPO_L3__________________, __________________BEPO_R3__________________
    ),
    [_AZERTY_BEPO] = LAYOUT_wrapper(
        KC_ESC,         ______________AZERTY_BEPO_L0_______________,                                                   ______________AZERTY_BEPO_R0_______________, FR_EQL, \
        KC_TAB,         ______________AZERTY_BEPO_L1_______________,                                                   ______________AZERTY_BEPO_R1_______________, FR_Z,    \
        FR_W,           ______________AZERTY_BEPO_L2_______________,                                                   ______________AZERTY_BEPO_R2_______________, FR_M,    \
        LSFT_T(KC_E),   ______________AZERTY_BEPO_L3_______________,                                                   ______________AZERTY_BEPO_R3_______________, LSFT_T(FR_CCED), \
        LCTL_T(FR_DLR), KC_LALT, KC_LGUI, KC_UP, KC_DOWN, LSFT_T(KC_BSPC), LT(_NUMBR,KC_DEL),      LT(_NAV,KC_ENT), RSFT_T(KC_SPC), KC_LEFT, KC_RGHT, KC_RGUI, KC_RALT, KC_NO\
    ),
    [_AZERTY] = LAYOUT_wrapper(
        KC_ESC,          ________________AZERTY_L0__________________,                                                   ________________AZERTY_R0__________________, FR_RPRN, \
        KC_TAB,          ________________AZERTY_L1__________________,                                                   ________________AZERTY_R1__________________, FR_EQL,    \
        FR_ASTR,         ________________AZERTY_L2__________________,                                                   ________________AZERTY_R2__________________, FR_CIRC,    \
        LSFT_T(FR_LABK), ________________AZERTY_L3__________________,                                                   ________________AZERTY_R3__________________, LSFT_T(FR_DLR), \
        KC_LCTL,         KC_LALT, KC_LGUI, KC_UP, KC_DOWN, LSFT_T(KC_BSPC), LT(_NUMBR,KC_DEL),      LT(_NAV,KC_ENT), RSFT_T(KC_SPC), KC_LEFT, KC_RGHT, KC_RALT, KC_RGUI, FR_UGRV\
    ),
    [_NUMBR] = LAYOUT_wrapper(
        _______, _________________FUNC_ROW1_________________,                       _________________FUNC_ROW2_________________, KC_F11,
        _______, ___________________BLANK___________________,                       _________________NUMBR_R1__________________, KC_F12,
        KC_NO,   ___________________BLANK___________________,                       _________________NUMBR_R2__________________, BP_PLUS,
        KC_NO,   ___________________BLANK___________________,                       _________________NUMBR_R3__________________, BP_SLSH,
        _______, _______, _______, KC_PGUP, KC_PGDN, _______, _______,     _______, _______, LSFT(KC_0), KP_00, KC_HOME, KC_END, BP_EQL
    ),

    [_NAV] = LAYOUT_wrapper(
        _______, ___________________BLANK___________________,                       ___________________BLANK___________________, _______,
        _______, ___________________NAV_L1__________________,                       ___________________NAV_R1__________________, _______,
        RESET,   ___________________NAV_L2__________________,                       ___________________NAV_R2__________________, KC_NO,
        _______, ___________________NAV_L3__________________,                       ___________________NAV_R3__________________, KC_NO,
        _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______
    ),
    [_ADJUST] = LAYOUT_wrapper(
        _______, ___________________BLANK___________________,                       ___________________BLANK___________________, _______,
        _______, _________________ADJUST_L1_________________,                        _________________ADJUST_R1_________________, _______,
        RESET,   _________________ADJUST_L2_________________,                        _________________ADJUST_R2_________________, KC_NO,
        _______, _________________ADJUST_L3_________________,                        _________________ADJUST_R3_________________, KC_NO,
        _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______                       _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______
    )
};
// clang-format on

