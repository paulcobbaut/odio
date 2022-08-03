#ifndef GLOBAL_DOT_H
#define GLOBAL_DOT_H

//extern int screen_height; // character height of the screen (Y-axis)
//extern int screen_width;  // character width of the screen (X-axis)

struct odiodata {
	int screen_height;
	int screen_width;
	int active_window;
};

extern struct odiodata data;

struct odiowindow {
	int function_key;
	char name[8];
	WINDOW * window;
};

// init windows
extern struct odiowindow F1;
extern struct odiowindow F5;
extern struct odiowindow F6;
extern struct odiowindow F7;
extern struct odiowindow F8;

#endif
