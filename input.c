#include <stdlib.h>
#include <ncurses.h>

#include "global.h"
#include "help.h"
#include "menu.h"
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
			display_bottom_menu(1);
			break;
			case KEY_F(3):
			save_and_exit_this_program();
			display_bottom_menu(3);
			break;
			case KEY_F(5):
			mvwprintw(debug_window, 1, 1, "Playing Radio ... press q to quit     ");
			wrefresh(debug_window);
			display_bottom_menu(5);
			break;
			case KEY_F(6):
			mvwprintw(debug_window, 1, 1, "Playing mp3s ... press q to quit     ");
			wrefresh(debug_window);
			display_bottom_menu(6);
			break;
			case KEY_F(7):
			mvwprintw(debug_window, 1, 1, "Playing playlist ... press q to quit  ");
			wrefresh(debug_window);
			display_bottom_menu(7);
			break;
			case KEY_F(9):
			mvwprintw(debug_window, 1, 1, "Silence is golden ... press q to quit ");
			wrefresh(debug_window);
			display_bottom_menu(9);
			break;
			default:
			mvwprintw(debug_window, 1, 1, "You pressed what?   ");
			wrefresh(debug_window);
			break;
		}
		i = getch();
	}
}

