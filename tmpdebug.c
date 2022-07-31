#include <stdlib.h>
#include <ncurses.h>

#include "global.h" // Global variables
#include "tmpdebug.h"

int create_debug_window()
{
        // create debug window to display input
	int height = 4;
	int width = screen_width / 2;
	int starty = screen_height - 6;
	int startx = 3;
	debug_window = newwin(height, width, starty, startx);
	box(debug_window, 0, 0);
	mvwprintw(debug_window,0,2,"Debug");
	wrefresh(debug_window);
}

