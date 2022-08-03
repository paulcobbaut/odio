#include <ncurses.h>
#include "global.h" 

// struct to contain all odio data
struct odiodata data = {.screen_width = 0, .screen_height = 0, .active_window = 0};

// init windows
struct odiowindow F1 = {1, "Help"};
struct odiowindow F5 = {5, "Radio"};
struct odiowindow F6 = {6, "Files"};
struct odiowindow F7 = {7, "List"};
struct odiowindow F8 = {8, "News"};

