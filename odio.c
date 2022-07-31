#include <ncurses.h>

// global variables for screen height and width
int screen_height; // character height of the screen (Y-axis)
int screen_width;  // character width of the screen (X-axis)

// Windows
WINDOW * debug_window;



int start_ncurses()
{
	initscr();
	cbreak();
	noecho();
	start_color();
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
	// create tabs 
	init_pair(1, COLOR_YELLOW, COLOR_BLACK);
	attron(COLOR_PAIR(1));
	mvprintw(screen_height - 1, 0, "F1=Help  F3=Exit  F5=Radio  F6=Local  F7=Playlist  F12=Silence");
	attroff(COLOR_PAIR(1));
	// show
	refresh();
}

int main()
{
	// start ncurses
	start_ncurses();

	// first find total screen size
	getmaxyx(stdscr, screen_height, screen_width);

	// display menu at the bottom
	create_bottom_menu();
	create_debug_window();


	/* capture input
	int i = getch();
	if (i == 'f')
	{
		mvwprintw(debug_window, 1, 1, "You pressed f");
		wrefresh(debug_window);
	}*/
 
	int i = getch();
        while(i != 'q')
	{
		switch(i)
		{
			case 'd':
			mvwprintw(debug_window, 1, 1, "You pressed ddd");
			wrefresh(debug_window);
			break;
			case 'e':
			mvwprintw(debug_window, 1, 1, "You pressed ee");
			wrefresh(debug_window);
			break;
			case 'f':
			mvwprintw(debug_window, 1, 1, "You pressed f");
			wrefresh(debug_window);
			break;
		}
		i = getch();
	}


	// wait for key and close ncurses
	getch();
	endwin();
	return 0;
}
