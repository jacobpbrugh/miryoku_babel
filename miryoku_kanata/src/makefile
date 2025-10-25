# Copyright 2022 Manna Harbour
# https://github.com/manna-harbour/miryoku

source := $(wildcard *.kbd.cpp)
targets := $(patsubst %.kbd.cpp, build/%.kbd, $(source))

all: $(targets)

build/%.kbd: %.kbd.cpp FORCE
	@mkdir -p build
	cpp -P -traditional-cpp -nostdinc -I. $(OPT_DEFS) $< | \
	sed -e "s%U_QUOT%'%g" \
	    -e "s%U_DQUO%\"%g" \
	    -e "s%U_COMM%,%g" \
	    -e "s%U_LPRN%(%g" \
	    -e "s%U_RPRN%)%g" \
	    -e "s%U_PIPE%|%g" \
	    -e "s%U_LF%\n%g" \
	    -e "s%U_TAB%	%g" \
	    -e "s%\bDOT\b%.%g" \
	> $@

test: all
	kanata -d build/miryoku_kanata.kbd

clean:
	rm -rf build

FORCE:

-include custom_rules.mk

.PHONY: all test clean FORCE
