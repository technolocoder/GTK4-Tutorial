Test-Window : Test-Window/main.c
	gcc Test-Window/main.c -o Test-Window/main `pkg-config --cflags gtk4` `pkg-config --libs gtk4`

Test-Button : Test-Button/main.c
	gcc Test-Button/main.c -o Test-Button/main `pkg-config --cflags gtk4` `pkg-config --libs gtk4`

Test-Grid : Test-Grid/main.c
	gcc Test-Grid/main.c -o Test-Grid/main `pkg-config --cflags gtk4` `pkg-config --libs gtk4`

Test-Text : Test-Text/main.c
	gcc Test-Text/main.c -o Test-Text/main `pkg-config --cflags gtk4` `pkg-config --libs gtk4`

Test-Multipanel : Test-Multipanel/main.c
	gcc Test-Multipanel/main.c -o Test-Multipanel/main `pkg-config --cflags gtk4` `pkg-config --libs gtk4`
