all: odio

odio: odio.c
	gcc global.c help.c tmpdebug.c menu.c myncurses.c odio.c -lncurses -o odio
