#include <ncurses.h>
#include <unistd.h>
#include <curses.h>
#include "screen.h"
#include "modes.h"

void set_bounds(s_Screen *scr) {
	getmaxyx(stdscr, scr->screen_rows, scr->screen_cols);
}


void draw_text_space(s_Screen *scr) {
	for (int i=0;i<scr->screen_rows-1;i++) {
		move(i,0);
		wprintw(stdscr,"~");
	}
}

void draw_statusline(s_Screen *scr, e_Modes mode) {
	char *status_name;
	attron(A_STANDOUT);
	if (mode == MODE_COMMAND) {
		status_name = "Command";
	} else if (mode == MODE_INSERT) {
		status_name = "Insert";
	} else {
		status_name = "Normal";
	}
	move(scr->screen_rows-1,0);
	wprintw(stdscr,"%s",status_name);
	attroff(A_STANDOUT);
}

void refresh_screen(s_Screen *scr, e_Modes mode) {
	clear();
	draw_text_space(scr);
	draw_statusline(scr, mode);
	refresh();
}
