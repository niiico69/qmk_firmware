#pragma once

// this makes it possible to do rolling combos (zx) with keys that
// convert to other keys on hold (z becomes ctrl when you hold it,
// and when this option isn't enabled, z rapidly followed by x
// actually sends Ctrl-x. That's bad.)
#define IGNORE_MOD_TAP_INTERRUPT
#undef PERMISSIVE_HOLD
//#define PERMISSIVE_HOLD
//#define TAPPING_FORCE_HOLD
#define TAPPING_FORCE_HOLD_PER_KEY
//#define RETRO_TAPPING

#define TAPPING_TERM 300
#define TAPPING_TERM_PER_KEY

