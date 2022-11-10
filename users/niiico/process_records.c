#include "niiico.h"


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case KP_00:
      if (record->event.pressed) {
        tap_code16(LSFT(KC_0));
        tap_code16(LSFT(KC_0));
//        tap_code16(KC_SPC);
//        tap_code16(RALT(KC_SPC));
      } else {
      }
      break;
  }
  return true;

}

