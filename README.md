# Captive — Max Skills Droid Name Generator

In [*Captive*](https://en.wikipedia.org/wiki/Captive_(video_game)), the 1990 CRPG developed by Antony Crowther and published by Mindscape, a droid's name determines its initial Dexterity, Vitality and Wisdom stats. This tool generates names where all three start at their maximum value of 15. It also lets you type any name to check what stats it would produce.

**[Open the app](https://maxskills.lumphammer.net/)** — single HTML file, no build step, no dependencies.

## How it works

A port of [MaxSkills.exe](https://captive.atari.org/Miscellaneous/Tools/Tools.php) by Pierre "Lyverbe" Fournier (2008), reimplemented in vanilla JS from the original C++ source (included in `attic/`). The game hashes the name's bytes through a fixed integer formula to derive three 0–255 values; the generator loops until it finds a name where all three land on 15.

## License

Original algorithm © 2008 Pierre Fournier, GPLv2. See `license.txt`.
