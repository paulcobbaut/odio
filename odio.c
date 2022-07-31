#include <stdlib.h>
#include <ncurses.h>

#include "global.h"   // Global variables
#include "help.h"     // F1-Help
#include "tmpdebug.h" // Temporary window for debugging
#include "menu.h"     // The menu at the bottom of the screen

int start_ncurses()
{
	initscr();
	cbreak();
	noecho();
	start_color();
	keypad(stdscr, TRUE);  // enable keyboard mapping
}

int save_and_exit_this_program()
{
	// todo... save playlist? save config?
	// end ncurses
	endwin();
	exit(0);
}

int handle_user_input()
{
	int i = getch();
        while(i != 'q')
	{
		switch(i)
		{
			case KEY_F(1):
			display_help_window();
			break;
			case KEY_F(3):
			save_and_exit_this_program();
			break;
			case KEY_F(5):
			mvwprintw(debug_window, 1, 1, "Playing Radio ... press q to quit     ");
			wrefresh(debug_window);
			break;
			case KEY_F(6):
			mvwprintw(debug_window, 1, 1, "Playing mp3s ... press q to quit     ");
			wrefresh(debug_window);
			break;
			case KEY_F(7):
			mvwprintw(debug_window, 1, 1, "Playing playlist ... press q to quit  ");
			wrefresh(debug_window);
			break;
			case KEY_F(12):
			mvwprintw(debug_window, 1, 1, "Silence is golden ... press q to quit ");
			wrefresh(debug_window);
			break;
			case 'f':
			mvwprintw(debug_window, 1, 1, "You pressed f   ");
			wrefresh(debug_window);
			break;
		}
		i = getch();
	}
}

int main()
{
	// start ncurses
	start_ncurses();

	// first find total screen size
	getmaxyx(stdscr, screen_height, screen_width);

	// display menu at the bottom
	create_bottom_menu();

	// display debug window to test keystrokes
	create_debug_window();

	// handle keyboard input form the user
	handle_user_input();

	// close ncurses
	endwin();
	return 0;
}
