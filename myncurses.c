#include <stdlib.h>
#include <ncurses.h>

#include "global.h"   // Global variables

int start_ncurses()
{
	initscr();
	cbreak();
	noecho();
	start_color();
	keypad(stdscr, TRUE);  // enable keyboard mapping
}

int save_and_exit_this_program()
{
	// todo... save playlist? save config?
	// end ncurses
	endwin();
	exit(0);
}

