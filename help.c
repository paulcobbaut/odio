#include <ncurses.h>
#include "global.h" 
#include "help.h" 

int display_help_window()
{
        // create helpful window to explain the program a bit
	int height = screen_height - 1;
	int width = screen_width;
	int starty = 0;
	int startx = 0;
	F1.window = newwin(height, width, starty, startx);
	werase(F1.window);
	box(F1.window, 0, 0);
	mvwprintw(F1.window, 0, 2, F1.name);
	mvwprintw(F1.window, 2, (width / 2) - 8, "Welcome to odio.");
	mvwprintw(F1.window, 3, (width / 2) - 8, "================");
	mvwprintw(F1.window,  6, 3, "F1 - Help    : Displays this screen.");
	mvwprintw(F1.window,  7, 3, "F3 - Exit    : Exits the program and returns to the shell.");
	mvwprintw(F1.window,  8, 3, "F5 - Radio   : Displays the screen to select radio stations.");
	mvwprintw(F1.window,  9, 3, "F6 - Local   : Displays the screen to play local audio files.");
	mvwprintw(F1.window, 10, 3, "F7 - List    : Displays the screen to manage a playlist.");
	mvwprintw(F1.window, 11, 3, "F8 - News    : Displays the screen to repeat a news bulletin.");
	mvwprintw(F1.window, 12, 3, "F9 - Silence : Mutes all audio.");
	mvwprintw(F1.window, 16, 3, "Odio, Copyright 2022: Paul Cobbaut, GNU GPLv3");
	mvwprintw(F1.window, 17, 3, "Source available at https://github.com/paulcobbaut/odio");
	wrefresh(F1.window);
}

