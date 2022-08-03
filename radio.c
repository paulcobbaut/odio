#include <stdlib.h>
#include <ncurses.h>

#include "global.h" // Global variables
#include "radio.h"

int display_radio_window()
{
        // radio window
	int height = data.screen_height - 1;
	int width = data.screen_width;
	int starty = 0;
	int startx = 0;
	F5.window = newwin(height, width, starty, startx);
	werase(F5.window);
	box(F5.window, 0, 0);
	mvwprintw(F5.window, 0, 2, F5.name);
	mvwprintw(F5.window, 4, (width / 2) - 15, "Choose a radio stream to play");
	mvwprintw(F5.window, 5, (width / 2) - 15, "=============================");
	mvwprintw(F5.window, 8, 1, "Radio 1 Classics");
	mvwprintw(F5.window, 9, 1, "StuBru Untz");
	mvwprintw(F5.window, 10, 1, "Radio FG");
	wrefresh(F5.window);
}

