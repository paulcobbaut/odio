#include <ncurses.h>
#include "global.h" 
#include "list.h" 

int display_list_window()
{
	int height = data.screen_height - 1;
	int width = data.screen_width;
	int starty = 0;
	int startx = 0;
	F7.window = newwin(height, width, starty, startx);
	werase(F7.window);
	box(F7.window, 0, 0);
	mvwprintw(F7.window, 0, 2, F7.name);
	mvwprintw(F7.window, 2, (width / 2) - 8, "Playlist");
	mvwprintw(F7.window, 8, 3, "07h00-09h00 Radio: Radio 1 Classics ");
	mvwprintw(F7.window, 9, 3, "09h00-10h30 Files: Rock");
	mvwprintw(F7.window, 10, 3, "10h30-'end' Radio 1 news, latest");
	mvwprintw(F7.window, 11, 3, "'end'-12h00 Files: Rock");
	mvwprintw(F7.window, 12, 3, "12h00-17h00 Radio: Klara");
	mvwprintw(F7.window, 13, 3, "17h00-19h00 Radio: Radio 1");
	mvwprintw(F7.window, 14, 3, "19h00-23h00 Files: New Wave and Electronic");
	wrefresh(F7.window);
}

