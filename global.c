#include <ncurses.h>
#include "global.h" 

// global variables for screen height and width
int screen_height; // character height of the screen (Y-axis)
int screen_width;  // character width of the screen (X-axis)

// Windows
WINDOW * debug_window;  // only for debugging
WINDOW * help_window;   // F1-Help
WINDOW * radio_window;  // F5-Radio

