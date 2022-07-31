#include <stdlib.h>
#include <ncurses.h>

#include "global.h"   // Global variables

int create_bottom_menu()
{
	// show what the function keys do at the bottom of the screen
	// create normal and highlighted (active) view
	init_pair(1, COLOR_YELLOW, COLOR_BLACK);
	init_pair(2, COLOR_BLACK, COLOR_YELLOW);
	int pair;

	int active_window = 3;	

	// array of all function keys
        char * fkeys[6] = {"F1=Help","F3=Exit","F5=Radio","F6=Local","F7=List","F9=Silence"}; 

	for (int i = 0; i < 6; i++)
	{
		if (i == active_window)
			pair = 2;
		else
			pair = 1; 
	attron(COLOR_PAIR(pair));
	mvprintw(screen_height - 1, i * 12, fkeys[i]);
	attroff(COLOR_PAIR(pair));
	}


	refresh();
}



