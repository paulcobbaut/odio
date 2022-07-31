#include <ncurses.h>
#include "global.h" 
#include "help.h" 

int display_help_window()
{
        // create helpful window to explain the program a bit
	int height = screen_height / 1.5;
	int width = screen_width / 1.5;
	int starty = screen_height / 8;
	int startx = screen_width / 8;
	help_window = newwin(height, width, starty, startx);
	box(help_window, 0, 0);
	mvwprintw(help_window, 0, 1, "Help");
	mvwprintw(help_window, 2, (width / 2) - 8, "Welcome to odio.");
	mvwprintw(help_window, 3, (width / 2) - 8, "================");
	mvwprintw(help_window, 6, 3, "F1 - Help    : Displays this screen.");
	mvwprintw(help_window, 7, 3, "F3 - Exit    : Exits the program and returns to the shell.");
	mvwprintw(help_window, 8, 3, "F5 - Radio   : Displays the screen to select radio stations.");
	mvwprintw(help_window, 9, 3, "F7 - Playlist: Displays the screen to manage a playlist.");
	mvwprintw(help_window, 10, 3, "F9 - Silence : Mutes all audio.");
	mvwprintw(help_window, 14, 3, "Odio, Copyright 2022: Paul Cobbaut, GNU GPLv3");
	mvwprintw(help_window, 15, 3, "Source available at https://github.com/paulcobbaut/odio");
	wrefresh(help_window);
}

