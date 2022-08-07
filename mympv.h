#ifndef MYMPV_DOT_H
#define MYMPV_DOT_H

#include <stdlib.h>

static inline void check_error(int status)
{
	if (status < 0) {
		printf("mpv API error: %s\n", mpv_error_string(status));
		printf("Error: %s\n", status);
		printf("Exiting...\n");
		exit(1);
	}
}

#endif
