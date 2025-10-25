# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Overview

Miryoku Babel generates layer data source files for Miryoku keyboard layout implementations from a single source. The repository uses Emacs Org-mode with Babel to maintain keyboard layers in org tables and tangle them into source files for multiple keyboard firmware platforms (QMK, ZMK, KMonad, KMK, SVG).

## Core Architecture

### Source of Truth
- `readme.org` is the single source of truth containing:
  - Layer definitions in org tables (Base, Nav, Mouse, Media, Num, Sym, Fun, Button)
  - Alternative layout definitions (AZERTY, QWERTY, Dvorak, Colemak, etc.)
  - Python scripts embedded in org-mode code blocks
  - Keycode translation tables mapping between firmware formats

### Tangling Process
The tangling process converts org tables into firmware-specific header files:
1. Python scripts read layer tables from org tables
2. Scripts apply keycode translations for each target (qmk/zmk/kmonad/kmk/svg)
3. Output files are generated in `tangled/{target}/` directories

### Layer Table Structure
- Base layer is split into three tables: tap alphas, tap thumbs, and hold modifiers
- Other layers are defined as single-hand tables (left or right)
- `U_NP` indicates "not present" for non-thumb positions
- `U_NA` indicates "not available"

## Building/Tangling

### Within Emacs
```elisp
;; Add to emacs init file:
(require 'ob-python)
(setq org-confirm-babel-evaluate nil)
(setq python-indent-guess-indent-offset-verbose nil)

;; Then run:
C-c C-v t  ; org-babel-tangle
```

### Command Line (Outside Emacs)
```bash
# Install Org mode
git clone --depth 1 --single-branch --branch main https://git.savannah.gnu.org/git/emacs/org-mode.git
cd org-mode
make autoloads
cd ..

# Tangle
emacs --batch -Q -L org-mode/lisp -f package-initialize \
  -eval "(require 'ob-python)" \
  -eval "(setq org-confirm-babel-evaluate nil)" \
  -eval "(setq python-indent-guess-indent-offset-verbose nil)" \
  ./readme.org -f org-babel-tangle
```

### GitHub Actions
Use the Build workflow in the Actions tab to tangle remotely and download artifacts.

## File Structure

### Generated Files (Do Not Edit)
All files in `tangled/` are generated and marked read-only:
- `tangled/{qmk,zmk,kmonad,kmk,svg}/miryoku_layer_alternatives.h` - All alternative layouts
- `tangled/{qmk,zmk,kmonad,kmk,svg}/miryoku_layer_selection.h` - Layer selection logic
- `tangled/{qmk,zmk,kmonad,kmk,svg}/miryoku_layer_list.h` - Layer enumeration

### Custom Configuration
- `custom_config.h` - User-specific layer customizations using C preprocessor defines
  - Can override individual layers with `#define MIRYOKU_LAYER_*`
  - Platform-specific settings (e.g., `MIRYOKU_KMONAD_OS_MAC`)

## Keycode Translation

Each firmware platform uses different keycode formats:
- **QMK**: `KC_` prefix (e.g., `KC_A`, `LGUI_T(KC_Q)`)
- **ZMK**: `&kp` prefix for keys, `U_MT` for mod-tap (e.g., `&kp A`, `U_MT(LGUI, Q)`)
- **KMonad**: Lowercase, no prefix (e.g., `a`, `U_MT(q, met)`)
- **SVG**: Long-form names in quotes (e.g., `"A"`, `"Left Gui"`)
- **KMK**: `KC.` prefix (e.g., `KC.A`)

Translation tables in `readme.org` map source keycodes to target formats.

## Editing Layers

### Modify Layer Tables in readme.org
1. Find the appropriate layer table (e.g., `#+NAME: nav-r`)
2. Edit table cells using org-mode table editing commands
3. Basic keycodes entered without prefix
4. Special symbols: `-` is `MINS`, `.` is `DOT`, `|` is `PIPE`, `"` is `DQUO`
5. Run tangle to regenerate output files

### Alternative Layouts
Define under "Alternative Layouts" section with format:
- Alphas: Full keyboard alpha layouts
- Nav/Mouse/Media: Alternative navigation schemes (vi-style, inverted-T)
- Layers: Flip variations (swap left/right hand positions)

## Testing

Verify tangled output matches committed files:
```bash
# Remove tangled files
rm -r tangled

# Retangle
# (use emacs command from above)

# Check diff
git status -s
git diff --exit-code
```

The test workflow runs this validation on push.
