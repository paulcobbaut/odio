#include <stdlib.h>
#include <ncurses.h>

#include "global.h"   // Global variables

int display_bottom_menu(int function_key)
{
	// show what the function keys do at the bottom of the screen
	// create normal and highlighted (active) view
	init_pair(1, COLOR_YELLOW, COLOR_BLACK);
	init_pair(2, COLOR_BLACK, COLOR_YELLOW);
	int pair;

	int active_window;

	// map the function_key pressed to the fkeys index
	switch(function_key)
	{
		case 1:			// F1=Help
		active_window = 0;
		break;
		case 3:			// F3=Exit
		active_window = 1;
		break;
		case 5:			// F5=Radio
		active_window = 2;
		break;
		case 6:			// F5=Local
		active_window = 3;
		break;
		case 7:			// F7=List
		active_window = 4;
		break;
		case 8:			// F7=List
		active_window = 5;
		break;
		case 9:			// F9=Silence
		active_window = 6;
		break;
		default:		// nothing chosen at start of program
		active_window = 99;
		break;
	}
	// array of all function keys
        char * fkeys[7] = {"F1=Help","F3=Exit","F5=Radio","F6=Local","F7=List","F8=News","F9=Silence"}; 

	// loop through array
	for (int i = 0; i < 7; i++)
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



