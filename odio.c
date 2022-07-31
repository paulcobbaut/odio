#include <ncurses.h>

// global variables for screen height and width
int screen_height; // character height of the screen (Y-axis)
int screen_width;  // character width of the screen (X-axis)

// Windows
WINDOW * debug_window;  // only for debugging
WINDOW * help_window;   // F1-Help

int start_ncurses()
{
	initscr();
	cbreak();
	noecho();
	start_color();
	keypad(stdscr, TRUE);  // enable keyboard mapping
}

int create_debug_window()
{
        // create debug window to display input
	int height = 4;
	int width = screen_width / 2;
	int starty = screen_height - 6;
	int startx = 3;
	debug_window = newwin(height, width, starty, startx);
	box(debug_window, 0, 0);
	mvwprintw(debug_window,0,1,"Debug");
	wrefresh(debug_window);
}

int create_bottom_menu()
{
	// show what the function keys do at the bottom of the screen
	init_pair(1, COLOR_YELLOW, COLOR_BLACK);
	attron(COLOR_PAIR(1));
	mvprintw(screen_height - 1, 0, "F1=Help  F3=Exit  F5=Radio  F6=Local  F7=Playlist  F9=Silence");
	attroff(COLOR_PAIR(1));
	refresh();
}


int save_and_exit_this_program()
{
	// todo... save playlist? save config?
	// end ncurses
	endwin();
	return 0;
}

int display_help_window()
{
        // create helpful window to explain the program a bit
	int height = screen_height / 1.5;
	int width = screen_width / 1.5;
	int starty = 2;
	int startx = 2;
	help_window = newwin(height, width, starty, startx);
	box(help_window, 0, 0);
	mvwprintw(help_window, 0, 1, "Help");
	mvwprintw(help_window, 1, 1, "F1 - Help    : Displays this screen.");
	mvwprintw(help_window, 2, 1, "F3 - Exit    : Exits the program and returns to the shell.");
	mvwprintw(help_window, 3, 1, "F5 - Radio   : Displays the screen to select radio stations.");
	mvwprintw(help_window, 4, 1, "F7 - Playlist: Displays the screen to manage a playlist.");
	mvwprintw(help_window, 5, 1, "F9 - Silence : Mutes all audio.");
	mvwprintw(help_window, 7, 1, "Odio, Copyright 2022: Paul Cobbaut, GNU GPLv3");
	mvwprintw(help_window, 8, 1, "Source available at https://github.com/paulcobbaut/odio");
	wrefresh(help_window);

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
