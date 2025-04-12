build: copy
	rm -rf ~/qmk_firmware/.build
	qmk compile -kb zsa/voyager -km anttiharju
	rm -rf build
	mkdir build
	find ~/qmk_firmware/.build -name "*.bin" -o -name "*.hex" | xargs -I{} cp {} build/
.PHONY: build

KEYMAP_DIST = ~/qmk_firmware/keyboards/zsa/voyager/keymaps/anttiharju

copy:
	mkdir -p ${KEYMAP_DIST}
	rm -rf ${KEYMAP_DIST}
	cp -r keymap ${KEYMAP_DIST}
.PHONY: copy

flash:
	@echo "Use keymapp to flash the .bin file"
.PHONY: flash

setup:
	brew install qmk/qmk/qmk
	qmk setup zsa/qmk_firmware -b firmware24 --yes
.PHONY: setup
