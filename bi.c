#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include "modes.h"
#include "screen.h"

int main() {

	initscr();
	curs_set(0);
	raw();
	noecho();
	keypad(stdscr, TRUE);
	s_Screen scr;
	set_bounds(&scr);
	// nodelay(stdscr,TRUE);	
	e_Modes mode = MODE_NORMAL;
	while (1) {
		refresh_screen(&scr, mode);
		int k = getch();
		switch (mode) {
			case MODE_NORMAL: 
				if (k == 'i') {
					mode = MODE_INSERT;
					curs_set(1);
				} else if (k == ':') {
					mode = MODE_COMMAND;
				} else if (k == 'q') {
					exit(0);
				}
				break;
			case MODE_INSERT:
				if (k == 27) {
					mode = MODE_NORMAL;
					curs_set(0);
				}
				break;
			case MODE_COMMAND:
				if (k == 27) {
					mode = MODE_NORMAL;
				}
				break;
		}
	}
	endwin();
	
	return 0;
}
