#include <stdlib.h>
#include <ncurses.h>

#include "global.h" // Global variables
#include "radio.h"

int display_radio_window()
{
        // radio window
	int height = screen_height - 1;
	int width = screen_width;
	int starty = 0;
	int startx = 0;
	radio_window = newwin(height, width, starty, startx);
	werase(radio_window);
	box(radio_window, 0, 0);
	mvwprintw(radio_window, 0, 2, "Radio");
	mvwprintw(radio_window, 4, (width / 2) - 15, "Choose a radio stream to play");
	mvwprintw(radio_window, 5, (width / 2) - 15, "=============================");
	mvwprintw(radio_window, 8, 1, "Radio 1 Classics");
	mvwprintw(radio_window, 9, 1, "StuBru Untz");
	mvwprintw(radio_window, 10, 1, "Radio FG");
	wrefresh(radio_window);
}

