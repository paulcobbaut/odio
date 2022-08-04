#ifndef GLOBAL_DOT_H
#define GLOBAL_DOT_H

// keep all data for odio in this struct
struct odiodata {
	int screen_height;
	int screen_width;
	int active_window;
	char configfilename[9];
};

extern struct odiodata data;

// init the F1,F5-F8 windows with this struct
struct odiowindow {
	int function_key;
	char name[8];
	WINDOW * window;
};

extern struct odiowindow F1;
extern struct odiowindow F5;
extern struct odiowindow F6;
extern struct odiowindow F7;
extern struct odiowindow F8;

#endif
