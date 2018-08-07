
Debian
====================
This directory contains files used to package xgalaxyd/xgalaxy-qt
for Debian-based Linux systems. If you compile xgalaxyd/xgalaxy-qt yourself, there are some useful files here.

## xgalaxy: URI support ##


xgalaxy-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install xgalaxy-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your xgalaxy-qt binary to `/usr/bin`
and the `../../share/pixmaps/xgalaxy128.png` to `/usr/share/pixmaps`

xgalaxy-qt.protocol (KDE)

