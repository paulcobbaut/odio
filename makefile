all: odio

odio: odio.c
	gcc global.c help.c tmpdebug.c menu.c odio.c -lncurses -o odio
