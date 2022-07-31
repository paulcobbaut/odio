#include <stdlib.h>
#include <ncurses.h>

#include "global.h"   // Global variables

int start_ncurses()
{
	initscr();		// init ncurses
	cbreak();
	noecho();
	start_color();		// allow colored text
	keypad(stdscr, TRUE);	// enable keyboard mapping
	curs_set(0);		// hide the cursor
}

int save_and_exit_this_program()
{
	// todo... save playlist? save config?
	// end ncurses
	endwin();
	exit(0);
}

