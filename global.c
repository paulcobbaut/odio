#include <ncurses.h>
#include "global.h" 

// global variables for screen height and width
//int screen_height; // character height of the screen (Y-axis)
// int screen_width;  // character width of the screen (X-axis)

// struct to contain global variables
struct odiodata data = {.screen_width = 0, .screen_height = 0, .active_window = 1};

// init windows
struct odiowindow F1 = {1, "Help"};
struct odiowindow F5 = {5, "Radio"};
struct odiowindow F6 = {6, "Files"};
struct odiowindow F7 = {7, "List"};
struct odiowindow F8 = {8, "News"};

