all: odio

odio: odio.c menu.c help.c tmpdebug.c myncurses.c input.c
	gcc global.c help.c tmpdebug.c menu.c myncurses.c input.c odio.c -lncurses -o odio
