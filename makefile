all: odio

odio: global.c odio.c radio.c list.c files.c menu.c help.c myncurses.c input.c news.c
	gcc global.c radio.c help.c list.c files.c menu.c myncurses.c news.c input.c odio.c -lncurses -o odio
