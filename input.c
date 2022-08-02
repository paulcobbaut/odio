#include <stdlib.h>
#include <ncurses.h>

#include "global.h"
#include "help.h"
#include "news.h"
#include "menu.h"
#include "radio.h"
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
			display_radio_window();
			display_bottom_menu(5);
			break;
			case KEY_F(6):
			display_bottom_menu(6);
			break;
			case KEY_F(7):
			display_bottom_menu(7);
			break;
			case KEY_F(8):
			display_news_window();
			display_bottom_menu(8);
			break;
			case KEY_F(9):
			display_bottom_menu(9);
			break;
			default:
			break;
		}
		i = getch();
	}
}

