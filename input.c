#include <stdlib.h>
#include <ncurses.h>

#include "global.h"
#include "help.h"
#include "radio.h"
#include "files.h"
#include "list.h"
#include "news.h"
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
				data.active_window = 0;
				display_help_window();
				display_bottom_menu();
				break;
			case KEY_F(3):
				data.active_window = 1;
				save_and_exit_this_program();
				display_bottom_menu();
				break;
			case KEY_F(5):
				data.active_window = 2;
				display_radio_window();
				display_bottom_menu();
				break;
			case KEY_F(6):
				data.active_window = 3;
				display_files_window();
				display_bottom_menu();
				break;
			case KEY_F(7):
				data.active_window = 4;
				display_list_window();
				display_bottom_menu();
				break;
			case KEY_F(8):
				data.active_window = 5;
				display_news_window();
				display_bottom_menu();
				break;
			case KEY_F(9):
				data.active_window = 6;
				display_bottom_menu();
				break;
			default:
			break;
		}
		i = getch();
	}
}

