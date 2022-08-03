#include <ncurses.h>
#include "global.h" 
#include "files.h" 

int display_files_window()
{
	int height = data.screen_height - 1;
	int width = data.screen_width;
	int starty = 0;
	int startx = 0;
	F6.window = newwin(height, width, starty, startx);
	werase(F6.window);
	box(F6.window, 0, 0);
	mvwprintw(F6.window, 0, 2, F6.name);
	mvwprintw(F6.window, 2, (width / 2) - 8, "Choose a .flac or a .mp3 file...");
	mvwprintw(F6.window, 17, 3, "One day this may play those .flac or .mp3 files...");
	wrefresh(F6.window);
}

