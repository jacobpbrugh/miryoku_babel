// Copyright 2022 Manna Harbour
// https://github.com/manna-harbour/miryoku
// generated -*- buffer-read-only: t -*-
// target: kanata

// This file should be replaced with the generated file from Miryoku Babel.
// To generate:
// 1. Run org-babel-tangle in miryoku_babel/readme.org with target="kanata"
// 2. Copy tangled/kanata/miryoku_layer_alternatives.h to this location

// Placeholder definitions - REPLACE WITH GENERATED FILE
#define MIRYOKU_ALTERNATIVES_BASE_COLEMAKDH \
q w f p b j l u y U_QUOT \
U_MT(a, lmet) U_MT(r, lalt) U_MT(s, lctl) U_MT(t, lsft) g m U_MT(n, lsft) U_MT(e, lctl) U_MT(i, lalt) U_MT(o, lmet) \
U_LT(z, button) U_MT(x, ralt) c d v k h U_COMM U_MT(DOT, ralt) U_LT(/, button) \
U_LT(escape, media) U_LT(spc, nav) U_LT(tab, mouse) U_LT(ret, sym) U_LT(bspc, num) U_LT(del, fun)

#define MIRYOKU_ALTERNATIVES_BASE MIRYOKU_ALTERNATIVES_BASE_COLEMAKDH

#define MIRYOKU_ALTERNATIVES_TAP_COLEMAKDH \
q, w, f, p, b, j, l, u, y, U_QUOT, \
a, r, s, t, g, m, n, e, i, o, \
z, x, c, d, v, k, h, U_COMM, ., /, \
escape, spc, tab, ret, bspc, del

#define MIRYOKU_ALTERNATIVES_TAP MIRYOKU_ALTERNATIVES_TAP_COLEMAKDH

#define MIRYOKU_ALTERNATIVES_NAV \
_, _, _, _, _, _, _, _, _, _, \
lmet, lalt, lctl, lsft, _, U_CPY, left, down, up, rght, \
_, ralt, _, _, _, _, home, pgdn, pgup, end, \
_, _, _, _, _, ret, bspc, del

#define MIRYOKU_ALTERNATIVES_MOUSE \
_, _, _, _, _, _, _, _, _, _, \
lmet, lalt, lctl, lsft, _, _, U_MS_L, U_MS_D, U_MS_U, U_MS_R, \
_, ralt, _, _, _, _, U_WH_L, U_WH_D, U_WH_U, U_WH_R, \
_, _, _, _, _, U_BTN2, U_BTN1, U_BTN3

#define MIRYOKU_ALTERNATIVES_MEDIA \
_, _, _, _, _, _, _, _, _, _, \
lmet, lalt, lctl, lsft, _, _, prev, vold, volu, next, \
_, ralt, _, _, _, _, _, _, _, _, \
_, _, _, _, _, mstp, play, mute

#define MIRYOKU_ALTERNATIVES_NUM \
[, 7, 8, 9, ], _, _, _, _, _, \
;, 4, 5, 6, =, _, lsft, lctl, lalt, lmet, \
`, 1, 2, 3, \\, _, ralt, _, _, _, \
., 0, -, _, _, _

#define MIRYOKU_ALTERNATIVES_SYM \
_, _, _, _, _, {, &, *, U_LPRN, }, \
_, lsft, lctl, lalt, lmet, +, $, %, ^, :, \
_, ralt, _, _, _, U_PIPE, !, @, #, ~, \
_, _, _, _, _, U_RPRN, \_

#define MIRYOKU_ALTERNATIVES_FUN \
f12, f7, f8, f9, _, _, _, _, _, _, \
f11, f4, f5, f6, _, _, lsft, lctl, lalt, lmet, \
f10, f1, f2, f3, _, _, ralt, _, _, _, \
_, spc, tab, _, _, _

#define MIRYOKU_ALTERNATIVES_BUTTON \
U_UND, U_CUT, U_CPY, U_PST, U_RDO, U_RDO, U_PST, U_CPY, U_CUT, U_UND, \
lmet, lalt, lctl, lsft, _, _, lsft, lctl, lalt, lmet, \
U_UND, U_CUT, U_CPY, U_PST, U_RDO, U_RDO, U_PST, U_CPY, U_CUT, U_UND, \
U_BTN3, U_BTN1, U_BTN2, U_BTN2, U_BTN1, U_BTN3
