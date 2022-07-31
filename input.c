#include <stdlib.h>
#include <ncurses.h>

#include "global.h"   // Global variables
#include "help.h"
#include "myncurses.h"

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

