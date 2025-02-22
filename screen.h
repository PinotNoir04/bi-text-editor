#ifndef SCREEN_H
#define SCREEN_H

#include "modes.h"
typedef struct{
	int screen_rows;
	int screen_cols;
}s_Screen;

void set_bounds(s_Screen *scr);
void draw_text_space(s_Screen *scr);
void draw_statusline(s_Screen *scr, e_Modes mode);
void refresh_screen(s_Screen *scr, e_Modes mode);

#endif
