#include <ncurses.h>
#include "global.h" 
#include "news.h" 

int display_news_window()
{
	int height = data.screen_height - 1;
	int width = data.screen_width;
	int starty = 0;
	int startx = 0;
	F8.window = newwin(height, width, starty, startx);
	werase(F8.window);
	box(F8.window, 0, 0);
	mvwprintw(F8.window, 0, 2, F8.name);
	mvwprintw(F8.window, 2, (width / 2) - 8, "NNNNEEEEWWWWSSSSS");
	mvwprintw(F8.window, 17, 3, "One day this may (re)play the Radio 1 news bulletin.");
	wrefresh(F8.window);
}

