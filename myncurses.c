#include <stdlib.h>
#include <ncurses.h>

#include "global.h"   // Global variables

int start_ncurses()
{
	// read configuration
	FILE *configfile;
	configfile = fopen(data.configfilename, "r");
	fscanf(configfile,"%d",&data.active_window);
	fclose(configfile);

	// init ncurses
	initscr();		// init ncurses
	cbreak();
	noecho();
	start_color();		// allow colored text
	keypad(stdscr, TRUE);	// enable keyboard mapping
	curs_set(0);		// hide the cursor
}

int save_and_exit_this_program()
{
	// write configuration
	FILE *configfile;
	configfile = fopen(data.configfilename, "w");
	if(configfile == NULL) { printf("error"); };
	fprintf(configfile,"%d",data.active_window);
	fclose(configfile);

	// end ncurses
	endwin();
	exit(0);
}

