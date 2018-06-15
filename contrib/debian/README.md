
Debian
====================
This directory contains files used to package tankd/tank-qt
for Debian-based Linux systems. If you compile tankd/tank-qt yourself, there are some useful files here.

## tank: URI support ##


tank-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install tank-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your tank-qt binary to `/usr/bin`
and the `../../share/pixmaps/tank128.png` to `/usr/share/pixmaps`

tank-qt.protocol (KDE)

