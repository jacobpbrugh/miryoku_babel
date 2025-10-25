# Miryoku Kanata

[Miryoku](https://github.com/manna-harbour/miryoku/) is an ergonomic, minimal, orthogonal, and universal keyboard layout.

This is the Miryoku implementation for [Kanata](https://github.com/jtroo/kanata).

## Building

### Requirements

- cpp (C preprocessor)
- sed
- make

### Build Steps

```bash
cd src
make
```

The generated `miryoku_kanata.kbd` file will be created in `src/build/`.

### Customization

Build options can be specified on the make command line:

```bash
make MIRYOKU_ALPHAS=QWERTY MIRYOKU_NAV=VI
```

See the [Miryoku](https://github.com/manna-harbour/miryoku/) documentation for available options.

For platform-specific configuration, edit `src/miryoku_kanata.kbd.cpp` and uncomment the appropriate `defcfg` section.

### Layer Files

The layer definition files in `src/miryoku_babel/` are generated from [Miryoku Babel](https://github.com/manna-harbour/miryoku_babel).

To use custom layers:
1. Generate layer files using Miryoku Babel with target `kanata`
2. Copy the generated files from `tangled/kanata/` to `src/miryoku_babel/`:
   - `miryoku_layer_alternatives.h`
   - `miryoku_layer_list.h`
   - `miryoku_layer_selection.h`
3. Rebuild with `make`

## Running

```bash
# Linux
sudo kanata -c src/build/miryoku_kanata.kbd

# Windows (as Administrator)
kanata.exe -c src/build/miryoku_kanata.kbd

# macOS
sudo kanata -c src/build/miryoku_kanata.kbd
```

## License

Copyright 2022 Manna Harbour
https://github.com/manna-harbour/miryoku
