all: odio

odio: odio.c
	gcc odio.c -lncurses -o odio
