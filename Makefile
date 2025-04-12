build: copy
	qmk compile -kb zsa/voyager -km anttiharju
.PHONY: build

KEYMAP_DIST = ~/qmk_firmware/keyboards/zsa/voyager/keymaps/anttiharju

copy:
	mkdir -p ${KEYMAP_DIST}
	rm -rf ${KEYMAP_DIST}
	cp -r keymap ${KEYMAP_DIST}
.PHONY: copy

setup:
	brew install qmk/qmk/qmk
	qmk setup zsa/qmk_firmware -b firmware24 --yes
.PHONY: setup
