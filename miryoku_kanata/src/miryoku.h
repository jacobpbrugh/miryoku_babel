// Copyright 2022 Manna Harbour
// https://github.com/manna-harbour/miryoku

// Placeholder keys
#define U_NP XX  // not present
#define U_NA XX  // not available
#define U_NU XX  // available but unused

// Tapping term (milliseconds)
#define U_TAPPING_TERM 200

// Clipboard operations
#if defined (MIRYOKU_CLIPBOARD_FUN)
  #define U_RDO AG_REPT
  #define U_PST AG_PSTE
  #define U_CPY AG_COPY
  #define U_CUT AG_CUT
  #define U_UND AG_UNDO
#elif defined (MIRYOKU_CLIPBOARD_MAC)
  #define U_RDO S-M-z
  #define U_PST M-v
  #define U_CPY M-c
  #define U_CUT M-x
  #define U_UND M-z
#elif defined (MIRYOKU_CLIPBOARD_WIN)
  #define U_RDO C-y
  #define U_PST C-v
  #define U_CPY C-c
  #define U_CUT C-x
  #define U_UND C-z
#else
  #define U_RDO C-y
  #define U_PST C-v
  #define U_CPY C-c
  #define U_CUT C-x
  #define U_UND C-z
#endif

// Mod-tap: tap for key, hold for modifier
#define U_MT(TAP, HOLD) (tap-hold U_TAPPING_TERM U_TAPPING_TERM TAP HOLD)

// Layer-tap: tap for key, hold for layer
#define U_LT(TAP, HOLD) (tap-hold U_TAPPING_TERM U_TAPPING_TERM TAP (layer-while-held HOLD))

// Layer switching (via aliases defined in main config)
#define U_DF(LAYER) @lsw-##LAYER

// Button layer (not implemented in base config)
#define U_BUTTON button

// Layers
#define U_BASE base
#define U_EXTRA extra
#define U_TAP tap
#define U_NAV nav
#define U_MOUSE mouse
#define U_MEDIA media
#define U_NUM num
#define U_SYM sym
#define U_FUN fun

// Bootloader (platform specific - customize as needed)
#define U_BOOT (cmd-output-keys "echo 'Bootloader not configured'")

// Output selection (not applicable to Kanata)
#define U_OUT_TOG XX
#define U_EP_TOG XX

// RGB controls (hardware specific - customize as needed)
#define U_RGB_HUI XX
#define U_RGB_SAI XX
#define U_RGB_BRI XX
#define U_RGB_EFF XX
#define U_RGB_TOG XX

// Mouse buttons (emulated via sequences)
#define U_BTN1 (multi mlft)
#define U_BTN2 (multi mrgt)
#define U_BTN3 (multi mmid)

// Mouse movement (using movemouse action)
#define U_MS_U (movemouse-up 1 10)
#define U_MS_D (movemouse-down 1 10)
#define U_MS_L (movemouse-left 1 10)
#define U_MS_R (movemouse-right 1 10)

// Mouse wheel scrolling
#define U_WH_U (mwheel-up 50 120)
#define U_WH_D (mwheel-down 50 120)
#define U_WH_L (mwheel-left 50 120)
#define U_WH_R (mwheel-right 50 120)

// Caps word (using caps-word action)
#define U_CW (caps-word 2000)

// Alternative layer flipping
#if defined (MIRYOKU_LAYERS_FLIP)
  #define MIRYOKU_ALTERNATIVES_BASE_FLIP MIRYOKU_ALTERNATIVES_BASE
  #define MIRYOKU_ALTERNATIVES_TAP_FLIP MIRYOKU_ALTERNATIVES_TAP
  #define MIRYOKU_ALTERNATIVES_NAV_FLIP MIRYOKU_ALTERNATIVES_NAV
  #define MIRYOKU_ALTERNATIVES_MOUSE_FLIP MIRYOKU_ALTERNATIVES_MOUSE
  #define MIRYOKU_ALTERNATIVES_MEDIA_FLIP MIRYOKU_ALTERNATIVES_MEDIA
  #define MIRYOKU_ALTERNATIVES_NUM_FLIP MIRYOKU_ALTERNATIVES_NUM
  #define MIRYOKU_ALTERNATIVES_SYM_FLIP MIRYOKU_ALTERNATIVES_SYM
  #define MIRYOKU_ALTERNATIVES_FUN_FLIP MIRYOKU_ALTERNATIVES_FUN
#endif

// Keyboard layout mapping - 40 key ortho layout
// This macro maps the 40 keys to positions in deflayer definitions
#define MIRYOKU_MAPPING( \
K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, \
K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, \
K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, \
N30, N31, K32, K33, K34, K35, K36, K37, N38, N39 \
) \
K00  K01  K02  K03  K04  K05  K06  K07  K08  K09  \
K10  K11  K12  K13  K14  K15  K16  K17  K18  K19  \
K20  K21  K22  K23  K24  K25  K26  K27  K28  K29  \
          K32  K33  K34  K35  K36  K37

// Include custom configuration
#include "custom_config.h"

// Include layer definitions from Miryoku Babel
#include "miryoku_babel/miryoku_layer_alternatives.h"
#include "miryoku_babel/miryoku_layer_selection.h"
#include "miryoku_babel/miryoku_layer_list.h"
