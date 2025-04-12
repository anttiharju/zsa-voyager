# Antti's ZSA Voyager keyboard layout

Most of the code in this repository is imported from https://configure.zsa.io/voyager/layouts/jvM3o/latest/0. The UI configurator, Oryx, is excellent for iterating but is somewhat limited in terms of advanced features. I needed one to improve switching between the three layers I have: 0, 1, and 2.

## Previously

1. I hold layer switch key on layer 0 to get to layer 1
2. I hold another layer switch key on layer 1 to get to layer 2
3. I release the layer switch key from step 1, yet I remain on layer 2.

## Now

Releasing the layer switch key from step 1 returns me to layer 2. This has been a constant footgun and the new setup feels more intuitive to me.

The custom logic is in commit [`410e0a4`](https://github.com/anttiharju/zsa-voyager/commit/410e0a40dedc74d50f1cb79c3833ae781257591e)

## Simplified build guide on macOS

Once:

```sh
make setup
```

After code changes:

```sh
make
```

and to flash use [Keymapp](https://www.zsa.io/flash). I tried `qmk flash` but my keyboard appeared to get stuck, which is a bit spooky and Keymapp gives me a nice progress bar.

I don't expect to do a lot of customisation to the firmware in this repository, I just needed the above-explained improved layer switching. It also feels like there's now less delay with the layer light switching, but I could be imagining it.

My layout is the result of iterating since summer 2021. A split keyboard improves my ergonomics, specifically with wrists and shoulders, allowing me to live a healthier and happier life despite spending most of time working at my keyboard. I've previously owned a ZSA Moonlander keyboard.

## Setup

- ZSA Voyager (black, no legend)
- Tripod kit, with ~20€ SmallRig vertical mount setup
- Sunset Tacticle Choc Switches because they feel very similar to MX Browns (unlike choc browns, which gave me temporary finger joint pain)
- and Choc Keycap spacers to reduce the excessive clicking originating from what is in my view a design fault in Voyager's keycaps.

Despite the not-so-out-of-the-box setup, I am extremely happy with Voyager as a keyboard. It's portable, responsive with my configuration, low-profile, and rigid, unlike the thumb clusters in Moonlander. It also looks professional without gamery features, like big red buttons.

## Building your layout from source

Congratulations on taking the next step, and making use of your keyboard's open-source nature! There's so much you can do with QMK. 

Here's how to get started compiling your own firmware:
1. Choose whether to build your layout against ZSA's QMK fork or mainline QMK. Using ZSA's fork means your firmware will compile easily, but it is slower to update and does not pull all the new features of mainline QMK. Mainline is the bleeding edge, but you will probably need to debug some compiler errors when setting up your layout for the first time.
2. Use the documentation at [docs.qmk.fm](https://docs.qmk.fm/) to set up your environment for building your firmware.
	- If you would like to compile against ZSA's fork,  make sure to manually set the path when going through the setup: [https://github.com/zsa/qmk_firmware/](https://github.com/zsa/qmk_firmware/) (ZSA's QMK fork). Otherwise, the setup process will default to mainline QMK (qmk/qmk_firmware).
		- ZSA's QMK fork will default to the current firmware revision, but it is possible to compile against other revisions by specifying the relevant branch. You can see what firmware revision a layout was compiled against in Oryx by looking at the badge at the top right, e.g. "firmware v24.0", "firmware v23.0" etc.
        3. Create a folder with a simple name and no spaces for your layout inside the qmk_firmware/keyboards/zsa/voyager/keymaps/ folder.
	- Optionally, you can instead use an external userspace: https://docs.qmk.fm/newbs_external_userspace
4. Copy the contents of the \*\_source folder (in the .zip you downloaded from Oryx) into this folder.
5. Make sure you've set up your environment for compiling per the [QMK docs](https://docs.qmk.fm/#/newbs_getting_started?id=set-up-your-environment).
6. From your shell, make sure your working directory is qmk_firmware, then enter the command `qmk compile`. If you haven't set up a default keyboard and layout through the QMK docs, you'll need to specify these manually: `qmk compile -kb <your-keyboard> -km <your-layout-folder-name>`. 
7. To flash, enter the command `qmk flash`, then put your board into bootloader mode with the reset button. 

Good luck on your journey! If you would like to maintain your Oryx layout with custom QMK functionality, check out this [community-made tool to add custom QMK features to your Oryx layout](https://blog.zsa.io/oryx-custom-qmk-features/). And remember, if you get stuck, you can always get back to your [original layout](https://configure.zsa.io/voyager/layouts/jvM3o/5WBx56/0) from Oryx.
