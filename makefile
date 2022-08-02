all: odio

odio: odio.c radio.c menu.c help.c myncurses.c input.c news.c
	gcc global.c radio.c help.c menu.c myncurses.c input.c news.c odio.c -lncurses -o odio
