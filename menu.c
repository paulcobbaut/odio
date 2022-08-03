#include <stdlib.h>
#include <ncurses.h>

#include "global.h"   // Global variables

int display_bottom_menu()
{
	// show what the function keys do at the bottom of the screen
	// create normal and highlighted (active) view
	init_pair(1, COLOR_YELLOW, COLOR_BLACK);
	init_pair(2, COLOR_BLACK, COLOR_YELLOW);
	int pair;

	// array of all function keys
        char * fkeys[7] = {"F1=Help","F3=Exit","F5=Radio","F6=Files","F7=List","F8=News","F9=Silence"}; 

	// loop through array
	for (int i = 0; i < 7; i++)
	{
		if (i == data.active_window)
			pair = 2;
		else
			pair = 1; 
		attron(COLOR_PAIR(pair));
		mvprintw(data.screen_height - 1, i * 12, fkeys[i]);
		attroff(COLOR_PAIR(pair));
	}
	refresh();
}



