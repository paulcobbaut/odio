#include <stdlib.h>
#include <ncurses.h>

#include "global.h"   // Global variables

int create_bottom_menu()
{
	// show what the function keys do at the bottom of the screen
	init_pair(1, COLOR_YELLOW, COLOR_BLACK);
	attron(COLOR_PAIR(1));
	mvprintw(screen_height - 1, 0, "F1=Help  F3=Exit  F5=Radio  F6=Local  F7=Playlist  F9=Silence");
	attroff(COLOR_PAIR(1));
	refresh();
}

