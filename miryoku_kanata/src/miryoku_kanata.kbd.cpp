// Copyright 2022 Manna Harbour
// https://github.com/manna-harbour/miryoku

#include "miryoku.h"

// Platform-specific configuration
// Uncomment the appropriate section for your platform

// Linux
(defcfg
  process-unmapped-keys yes
  danger-enable-cmd no
  sequence-timeout 2000
  sequence-input-mode visible-backspaced
  sequence-backtrack-modcancel no
  log-layer-changes no
  delegate-to-first-layer yes
  movemouse-inherit-accel-state yes
  movemouse-smooth-diagonals yes
  linux-dev /dev/input/by-path/platform-i8042-serio-0-event-kbd
  linux-continue-if-no-devs-found yes
)

// Windows
// (defcfg
//   process-unmapped-keys yes
//   danger-enable-cmd no
//   sequence-timeout 2000
//   log-layer-changes no
//   delegate-to-first-layer yes
//   movemouse-inherit-accel-state yes
//   movemouse-smooth-diagonals yes
//   windows-interception-mouse-hwid "70, 0, 60, 0"
//   windows-interception-keyboard-hwid "70, 0, 60, 0, 0"
// )

// macOS
// (defcfg
//   process-unmapped-keys yes
//   danger-enable-cmd no
//   sequence-timeout 2000
//   log-layer-changes no
//   delegate-to-first-layer yes
//   movemouse-inherit-accel-state yes
//   movemouse-smooth-diagonals yes
// )

// Source layer - physical keyboard layout
// This is a standard ANSI layout, customize for your keyboard
#if defined (MIRYOKU_MAPPING_KINESIS_ADVANTAGE)
  (defsrc
    =     1     2     3     4     5     6     7     8     9     0     -
    tab   q     w     e     r     t     y     u     i     o     p     \
    caps  a     s     d     f     g     h     j     k     l     ;     '
    lsft  z     x     c     v     b     n     m     ,     .     /     rsft
                      `     lctl  home  end   bspc
                            del   pgup  pgdn  ret
                                  lmet  rmet
  )
#elif defined (MIRYOKU_MAPPING_LITE)
  (defsrc
    q     w     e     r     t     y     u     i     o     p
    a     s     d     f     g     h     j     k     l     ;
    z     x     c     v     b     n     m     ,     .     /
                      esc   spc   tab   ret   bspc  del
  )
#else
  // Standard 60% keyboard layout
  (defsrc
    grv   1     2     3     4     5     6     7     8     9     0     -     =     bspc
    tab   q     w     e     r     t     y     u     i     o     p     [     ]     \
    caps  a     s     d     f     g     h     j     k     l     ;     '     ret
    lsft  z     x     c     v     b     n     m     ,     .     /     rsft
    lctl  lmet  lalt              spc               ralt  rmet  rctl
  )
#endif

// Aliases for layer switching
(defalias
  lsw-base (layer-switch U_BASE)
  lsw-extra (layer-switch U_EXTRA)
  lsw-tap (layer-switch U_TAP)
  lsw-button (layer-switch U_BUTTON)
)

// Base layer
#if defined (MIRYOKU_ALPHAS_AZERTY)
  #if defined (MIRYOKU_LAYERS_FLIP)
    #define MIRYOKU_LAYERMAPPING_BASE MIRYOKU_ALTERNATIVES_BASE_AZERTY_FLIP
  #else
    #define MIRYOKU_LAYERMAPPING_BASE MIRYOKU_ALTERNATIVES_BASE_AZERTY
  #endif
#elif defined (MIRYOKU_ALPHAS_BEAKL15)
  #if defined (MIRYOKU_LAYERS_FLIP)
    #define MIRYOKU_LAYERMAPPING_BASE MIRYOKU_ALTERNATIVES_BASE_BEAKL15_FLIP
  #else
    #define MIRYOKU_LAYERMAPPING_BASE MIRYOKU_ALTERNATIVES_BASE_BEAKL15
  #endif
#elif defined (MIRYOKU_ALPHAS_COLEMAK)
  #if defined (MIRYOKU_LAYERS_FLIP)
    #define MIRYOKU_LAYERMAPPING_BASE MIRYOKU_ALTERNATIVES_BASE_COLEMAK_FLIP
  #else
    #define MIRYOKU_LAYERMAPPING_BASE MIRYOKU_ALTERNATIVES_BASE_COLEMAK
  #endif
#elif defined (MIRYOKU_ALPHAS_COLEMAKDH)
  #if defined (MIRYOKU_LAYERS_FLIP)
    #define MIRYOKU_LAYERMAPPING_BASE MIRYOKU_ALTERNATIVES_BASE_COLEMAKDH_FLIP
  #else
    #define MIRYOKU_LAYERMAPPING_BASE MIRYOKU_ALTERNATIVES_BASE_COLEMAKDH
  #endif
#elif defined (MIRYOKU_ALPHAS_COLEMAKDHK)
  #if defined (MIRYOKU_LAYERS_FLIP)
    #define MIRYOKU_LAYERMAPPING_BASE MIRYOKU_ALTERNATIVES_BASE_COLEMAKDHK_FLIP
  #else
    #define MIRYOKU_LAYERMAPPING_BASE MIRYOKU_ALTERNATIVES_BASE_COLEMAKDHK
  #endif
#elif defined (MIRYOKU_ALPHAS_DVORAK)
  #if defined (MIRYOKU_LAYERS_FLIP)
    #define MIRYOKU_LAYERMAPPING_BASE MIRYOKU_ALTERNATIVES_BASE_DVORAK_FLIP
  #else
    #define MIRYOKU_LAYERMAPPING_BASE MIRYOKU_ALTERNATIVES_BASE_DVORAK
  #endif
#elif defined (MIRYOKU_ALPHAS_HALMAK)
  #if defined (MIRYOKU_LAYERS_FLIP)
    #define MIRYOKU_LAYERMAPPING_BASE MIRYOKU_ALTERNATIVES_BASE_HALMAK_FLIP
  #else
    #define MIRYOKU_LAYERMAPPING_BASE MIRYOKU_ALTERNATIVES_BASE_HALMAK
  #endif
#elif defined (MIRYOKU_ALPHAS_WORKMAN)
  #if defined (MIRYOKU_LAYERS_FLIP)
    #define MIRYOKU_LAYERMAPPING_BASE MIRYOKU_ALTERNATIVES_BASE_WORKMAN_FLIP
  #else
    #define MIRYOKU_LAYERMAPPING_BASE MIRYOKU_ALTERNATIVES_BASE_WORKMAN
  #endif
#elif defined (MIRYOKU_ALPHAS_QWERTY)
  #if defined (MIRYOKU_LAYERS_FLIP)
    #define MIRYOKU_LAYERMAPPING_BASE MIRYOKU_ALTERNATIVES_BASE_QWERTY_FLIP
  #else
    #define MIRYOKU_LAYERMAPPING_BASE MIRYOKU_ALTERNATIVES_BASE_QWERTY
  #endif
#elif defined (MIRYOKU_ALPHAS_QWERTZ)
  #if defined (MIRYOKU_LAYERS_FLIP)
    #define MIRYOKU_LAYERMAPPING_BASE MIRYOKU_ALTERNATIVES_BASE_QWERTZ_FLIP
  #else
    #define MIRYOKU_LAYERMAPPING_BASE MIRYOKU_ALTERNATIVES_BASE_QWERTZ
  #endif
#else
  #if defined (MIRYOKU_LAYERS_FLIP)
    #define MIRYOKU_LAYERMAPPING_BASE MIRYOKU_ALTERNATIVES_BASE_COLEMAKDH_FLIP
  #else
    #define MIRYOKU_LAYERMAPPING_BASE MIRYOKU_ALTERNATIVES_BASE_COLEMAKDH
  #endif
#endif

// Extra layer
#define MIRYOKU_LAYERMAPPING_EXTRA MIRYOKU_ALTERNATIVES_BASE

// Tap layer
#if defined (MIRYOKU_ALPHAS_AZERTY)
  #if defined (MIRYOKU_LAYERS_FLIP)
    #define MIRYOKU_LAYERMAPPING_TAP MIRYOKU_ALTERNATIVES_TAP_AZERTY_FLIP
  #else
    #define MIRYOKU_LAYERMAPPING_TAP MIRYOKU_ALTERNATIVES_TAP_AZERTY
  #endif
#elif defined (MIRYOKU_ALPHAS_BEAKL15)
  #if defined (MIRYOKU_LAYERS_FLIP)
    #define MIRYOKU_LAYERMAPPING_TAP MIRYOKU_ALTERNATIVES_TAP_BEAKL15_FLIP
  #else
    #define MIRYOKU_LAYERMAPPING_TAP MIRYOKU_ALTERNATIVES_TAP_BEAKL15
  #endif
#elif defined (MIRYOKU_ALPHAS_COLEMAK)
  #if defined (MIRYOKU_LAYERS_FLIP)
    #define MIRYOKU_LAYERMAPPING_TAP MIRYOKU_ALTERNATIVES_TAP_COLEMAK_FLIP
  #else
    #define MIRYOKU_LAYERMAPPING_TAP MIRYOKU_ALTERNATIVES_TAP_COLEMAK
  #endif
#elif defined (MIRYOKU_ALPHAS_COLEMAKDH)
  #if defined (MIRYOKU_LAYERS_FLIP)
    #define MIRYOKU_LAYERMAPPING_TAP MIRYOKU_ALTERNATIVES_TAP_COLEMAKDH_FLIP
  #else
    #define MIRYOKU_LAYERMAPPING_TAP MIRYOKU_ALTERNATIVES_TAP_COLEMAKDH
  #endif
#elif defined (MIRYOKU_ALPHAS_COLEMAKDHK)
  #if defined (MIRYOKU_LAYERS_FLIP)
    #define MIRYOKU_LAYERMAPPING_TAP MIRYOKU_ALTERNATIVES_TAP_COLEMAKDHK_FLIP
  #else
    #define MIRYOKU_LAYERMAPPING_TAP MIRYOKU_ALTERNATIVES_TAP_COLEMAKDHK
  #endif
#elif defined (MIRYOKU_ALPHAS_DVORAK)
  #if defined (MIRYOKU_LAYERS_FLIP)
    #define MIRYOKU_LAYERMAPPING_TAP MIRYOKU_ALTERNATIVES_TAP_DVORAK_FLIP
  #else
    #define MIRYOKU_LAYERMAPPING_TAP MIRYOKU_ALTERNATIVES_TAP_DVORAK
  #endif
#elif defined (MIRYOKU_ALPHAS_HALMAK)
  #if defined (MIRYOKU_LAYERS_FLIP)
    #define MIRYOKU_LAYERMAPPING_TAP MIRYOKU_ALTERNATIVES_TAP_HALMAK_FLIP
  #else
    #define MIRYOKU_LAYERMAPPING_TAP MIRYOKU_ALTERNATIVES_TAP_HALMAK
  #endif
#elif defined (MIRYOKU_ALPHAS_WORKMAN)
  #if defined (MIRYOKU_LAYERS_FLIP)
    #define MIRYOKU_LAYERMAPPING_TAP MIRYOKU_ALTERNATIVES_TAP_WORKMAN_FLIP
  #else
    #define MIRYOKU_LAYERMAPPING_TAP MIRYOKU_ALTERNATIVES_TAP_WORKMAN
  #endif
#elif defined (MIRYOKU_ALPHAS_QWERTY)
  #if defined (MIRYOKU_LAYERS_FLIP)
    #define MIRYOKU_LAYERMAPPING_TAP MIRYOKU_ALTERNATIVES_TAP_QWERTY_FLIP
  #else
    #define MIRYOKU_LAYERMAPPING_TAP MIRYOKU_ALTERNATIVES_TAP_QWERTY
  #endif
#elif defined (MIRYOKU_ALPHAS_QWERTZ)
  #if defined (MIRYOKU_LAYERS_FLIP)
    #define MIRYOKU_LAYERMAPPING_TAP MIRYOKU_ALTERNATIVES_TAP_QWERTZ_FLIP
  #else
    #define MIRYOKU_LAYERMAPPING_TAP MIRYOKU_ALTERNATIVES_TAP_QWERTZ
  #endif
#else
  #if defined (MIRYOKU_LAYERS_FLIP)
    #define MIRYOKU_LAYERMAPPING_TAP MIRYOKU_ALTERNATIVES_TAP_COLEMAKDH_FLIP
  #else
    #define MIRYOKU_LAYERMAPPING_TAP MIRYOKU_ALTERNATIVES_TAP_COLEMAKDH
  #endif
#endif

// Nav layer
#if defined (MIRYOKU_NAV_INVERTEDT)
  #if defined (MIRYOKU_LAYERS_FLIP)
    #define MIRYOKU_LAYERMAPPING_NAV MIRYOKU_ALTERNATIVES_NAV_INVERTEDT_FLIP
  #else
    #define MIRYOKU_LAYERMAPPING_NAV MIRYOKU_ALTERNATIVES_NAV_INVERTEDT
  #endif
#elif defined (MIRYOKU_NAV_VI)
  #define MIRYOKU_LAYERMAPPING_NAV MIRYOKU_ALTERNATIVES_NAV_VI
#else
  #if defined (MIRYOKU_LAYERS_FLIP)
    #define MIRYOKU_LAYERMAPPING_NAV MIRYOKU_ALTERNATIVES_NAV_FLIP
  #else
    #define MIRYOKU_LAYERMAPPING_NAV MIRYOKU_ALTERNATIVES_NAV
  #endif
#endif

// Mouse layer
#if defined (MIRYOKU_MOUSE_INVERTEDT)
  #if defined (MIRYOKU_LAYERS_FLIP)
    #define MIRYOKU_LAYERMAPPING_MOUSE MIRYOKU_ALTERNATIVES_MOUSE_INVERTEDT_FLIP
  #else
    #define MIRYOKU_LAYERMAPPING_MOUSE MIRYOKU_ALTERNATIVES_MOUSE_INVERTEDT
  #endif
#elif defined (MIRYOKU_MOUSE_VI)
  #define MIRYOKU_LAYERMAPPING_MOUSE MIRYOKU_ALTERNATIVES_MOUSE_VI
#else
  #if defined (MIRYOKU_LAYERS_FLIP)
    #define MIRYOKU_LAYERMAPPING_MOUSE MIRYOKU_ALTERNATIVES_MOUSE_FLIP
  #else
    #define MIRYOKU_LAYERMAPPING_MOUSE MIRYOKU_ALTERNATIVES_MOUSE
  #endif
#endif

// Media layer
#if defined (MIRYOKU_MEDIA_INVERTEDT)
  #if defined (MIRYOKU_LAYERS_FLIP)
    #define MIRYOKU_LAYERMAPPING_MEDIA MIRYOKU_ALTERNATIVES_MEDIA_INVERTEDT_FLIP
  #else
    #define MIRYOKU_LAYERMAPPING_MEDIA MIRYOKU_ALTERNATIVES_MEDIA_INVERTEDT
  #endif
#elif defined (MIRYOKU_MEDIA_VI)
  #define MIRYOKU_LAYERMAPPING_MEDIA MIRYOKU_ALTERNATIVES_MEDIA_VI
#else
  #if defined (MIRYOKU_LAYERS_FLIP)
    #define MIRYOKU_LAYERMAPPING_MEDIA MIRYOKU_ALTERNATIVES_MEDIA_FLIP
  #else
    #define MIRYOKU_LAYERMAPPING_MEDIA MIRYOKU_ALTERNATIVES_MEDIA
  #endif
#endif

// Num layer
#if defined (MIRYOKU_LAYERS_FLIP)
  #define MIRYOKU_LAYERMAPPING_NUM MIRYOKU_ALTERNATIVES_NUM_FLIP
#else
  #define MIRYOKU_LAYERMAPPING_NUM MIRYOKU_ALTERNATIVES_NUM
#endif

// Sym layer
#if defined (MIRYOKU_LAYERS_FLIP)
  #define MIRYOKU_LAYERMAPPING_SYM MIRYOKU_ALTERNATIVES_SYM_FLIP
#else
  #define MIRYOKU_LAYERMAPPING_SYM MIRYOKU_ALTERNATIVES_SYM
#endif

// Fun layer
#if defined (MIRYOKU_LAYERS_FLIP)
  #define MIRYOKU_LAYERMAPPING_FUN MIRYOKU_ALTERNATIVES_FUN_FLIP
#else
  #define MIRYOKU_LAYERMAPPING_FUN MIRYOKU_ALTERNATIVES_FUN
#endif

// Button layer
#define MIRYOKU_LAYERMAPPING_BUTTON MIRYOKU_ALTERNATIVES_BUTTON

// Generate layer definitions after all mappings are defined
#define MIRYOKU_X(LAYER, STRING) \
(deflayer U_##LAYER \
MIRYOKU_LAYERMAPPING_##LAYER \
)

MIRYOKU_LAYER_LIST
#undef MIRYOKU_X
