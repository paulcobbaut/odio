#include <stdlib.h>
#include <string.h>
#include <ncurses.h>
#include <mpv/client.h>

#include "global.h"    // Global variables
#include "help.h"      // F1-Help
#include "menu.h"      // The menu at the bottom of the screen
#include "input.h"     // handle user input
#include "myncurses.h" // start/stop program
#include "mympv.h"     // mpv for playing audio

int main()
{
	// start program, read configuration, init ncurses
	start_and_init_this_program();

	// first find total screen size
	getmaxyx(stdscr, data.screen_height, data.screen_width);

	// display menu at the bottom
	//display_bottom_menu(99);

	// init mpv handle
	data.ctx = mpv_create();
	if (!data.ctx) { printf("Error MPV create\n"); return 1; }
	check_error(mpv_set_option_string(data.ctx, "vid", "no"));
	check_error(mpv_set_option_string(data.ctx, "volume", "55"));
	check_error(mpv_set_option_string(data.ctx, "start", "00:40"));
	check_error(mpv_set_option_string(data.ctx, "input-terminal", "no"));
	check_error(mpv_initialize(data.ctx));
	const char *cmd[] = {"loadfile", "/home/pi/abba.mp3", NULL};
	check_error(mpv_command(data.ctx, cmd));
	while (1) {
		mpv_event *event = mpv_wait_event(data.ctx, 10);
		printf("event: %s\n", mpv_event_name(event->event_id));
		if (event->event_id == MPV_EVENT_SHUTDOWN)
			break;
	}

	// handle keyboard input from the user
	handle_user_input();

	// close ncurses
	save_and_exit_this_program();
	return 0;
}
