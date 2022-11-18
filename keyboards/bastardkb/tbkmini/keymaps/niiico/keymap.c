#include "niiico.h"
#include "keymap_bepo.h"
#include "keymap_french.h"


// clang-format off
#if (!defined(LAYOUT) && defined(KEYMAP))
#    define LAYOUT KEYMAP
#endif

// clang-format off
#define KEYMAP_wrapper(...)                  LAYOUT_split_3x6_3(__VA_ARGS__)
#define LAYOUT_wrapper(...)                  LAYOUT_split_3x6_3(__VA_ARGS__)


#define LAYOUT_tbkmini_base(                                       \
    K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, \
    K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, \
    K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A  \
  ) \
  LAYOUT_wrapper( \
      KC_TAB,         K01,         K02,  K03,  K04,  K05,                                                              K06,   K07,   K08,   K09,   K0A,  BP_Z, \
      BP_W,           K11,         K12,  K13,  K14,  K15,                                                              K16,   K17,   K18,   K19,   K1A,  BP_M, \
      LSFT_T(BP_DLR), LALT_T(K21), K22,  K23,  K24,  K25,                                                              K26,   K27,   K28,   K29,   RALT_T(K2A), BP_CCED, \
                           LT(_NUMBR,KC_SPC), LSFT_T(KC_BSPC), LT(_SYMBL,KC_DEL),       LT(_SYMBL,KC_LGUI), RSFT_T(KC_SPC), LT(_NUMBR,KC_ENTER) \
  )

// clang-format on

/* Re-pass though to allow  ates to b used */
#define LAYOUT_tbkmini_base_wrapper(...)       LAYOUT_tbkmini_base(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BEPO] = LAYOUT_wrapper(
       KC_TAB,        __________________BEPO_L1__________________,            __________________BEPO_R1__________________,BP_Z,
       BP_W,          __________________BEPO_L2__________________,            __________________BEPO_R2__________________,BP_M,
       LSFT_T(BP_DLR),__________________BEPO_L3__________________,            __________________BEPO_R3__________________,BP_CCED,
            LT(_NAV,KC_ESC), LSFT_T(KC_BSPC), LT(_SYMBL,KC_DEL),            LT(_SYMBL,KC_LGUI), RSFT_T(KC_SPC), LT(_NUMBR,KC_ENTER)
    ),
    [_AZERTY_BEPO] = LAYOUT_wrapper(
        KC_TAB, ______________AZERTY_BEPO_L1_______________,                  ______________AZERTY_BEPO_R1_______________, FR_Z,
        FR_W,   ______________AZERTY_BEPO_L2_______________,                  ______________AZERTY_BEPO_R2_______________, FR_M,
        FR_DLR, ______________AZERTY_BEPO_L3_______________,                  ______________AZERTY_BEPO_R3_______________, FR_CCED,
            LT(_NAV,KC_ESC), LSFT_T(KC_BSPC), LT(_SYMBL,KC_DEL),            LT(_SYMBL,KC_LGUI), RSFT_T(KC_SPC), LT(_NUMBR,KC_ENTER)
    ),
    [_SYMBL] = LAYOUT_wrapper(
        _______, _________________SYMBL_L1__________________,                 _________________SYMBL_R1__________________, BP_EQL,
        KC_NO,   _________________SYMBL_L2__________________,                 _________________SYMBL_R2__________________, BP_DEG,
        _______, _________________SYMBL_L3__________________,                 _________________SYMBL_R3__________________, KC_NO,
                                   KC_PGUP, KC_PGDN, _______,                 _______, KC_HOME, KC_END
    ),
    [_NUMBR] = LAYOUT_wrapper(
        _______, _________________NUMBR_L1__________________,                 _________________NUMBR_R1__________________, BP_EQL,
        KC_NO,   _________________NUMBR_L2__________________,                 _________________NUMBR_R2__________________, BP_PLUS,
        _______, _________________NUMBR_L3__________________,                 _________________NUMBR_R3__________________, BP_SLSH,
                                     KC_F11, KC_F12, _______,                 _______, _______, _______
    ),
    [_ADJUST] = LAYOUT_wrapper(
        _______, _________________ADJUST_L1_________________,                 _________________ADJUST_R1_________________, _______,
        QK_BOOT, _________________ADJUST_L2_________________,                 _________________ADJUST_R2_________________, KC_NO,
        _______, _________________ADJUST_L3_________________,                 _________________ADJUST_R3_________________, KC_NO,
                                   _______, _______, _______,                 _______, _______, _______
    ),
    [_NAV] = LAYOUT_wrapper(
        _______, ___________________NAV_L1__________________,                 ___________________NAV_R1__________________, _______,
        _______, ___________________NAV_L2__________________,                 ___________________NAV_R2__________________, KC_NO,
        _______, ___________________NAV_L3__________________,                 ___________________NAV_R3__________________, KC_NO,
                                   _______, _______, _______,                 _______, _______, _______
    )
};


uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case RSFT_T(KC_SPC):
            return TAPPING_TERM + 300;
        default:
            return TAPPING_TERM;
    }
}


