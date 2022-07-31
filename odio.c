#include <stdlib.h>
#include <ncurses.h>

#include "global.h"   // Global variables
#include "help.h"     // F1-Help
#include "tmpdebug.h" // Temporary window for debugging
#include "menu.h"     // The menu at the bottom of the screen
#include "input.h"     // handle user input
#include "myncurses.h"  // The menu at the bottom of the screen


int main()
{
	// start ncurses
	start_ncurses();

	// first find total screen size
	getmaxyx(stdscr, screen_height, screen_width);

	// display menu at the bottom
	display_bottom_menu(99);

	// display debug window to test keystrokes
	create_debug_window();

	// handle keyboard input form the user
	handle_user_input();

	// close ncurses
	endwin();
	return 0;
}
