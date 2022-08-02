#include <ncurses.h>
#include "global.h" 

// global variables for screen height and width
int screen_height; // character height of the screen (Y-axis)
int screen_width;  // character width of the screen (X-axis)

// Windows
//WINDOW * help_window;   // F1-Help
//WINDOW * news_window;   // F8-News
//WINDOW * radio_window;  // F5-Radio


// init windows
struct odiowindow F1 = {1, "Help"};
struct odiowindow F5 = {5, "Radio"};
struct odiowindow F1 = {1, "Local"};
struct odiowindow F1 = {1, "List"};
struct odiowindow F8 = {8, "News"};

