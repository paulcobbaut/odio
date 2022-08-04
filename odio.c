#include <stdlib.h>
#include <string.h>
#include <ncurses.h>

#include "global.h"    // Global variables
#include "help.h"      // F1-Help
#include "menu.h"      // The menu at the bottom of the screen
#include "input.h"     // handle user input
#include "myncurses.h" // The menu at the bottom of the screen

int main()
{
	// start program, read configuration, init ncurses
	start_and_init_this_program();

	// first find total screen size
	getmaxyx(stdscr, data.screen_height, data.screen_width);

	// display menu at the bottom
	display_bottom_menu(99);

	// handle keyboard input form the user
	handle_user_input();

	// close ncurses
	save_and_exit_this_program();
	return 0;
}
