#include <ncurses.h>
#include <stdlib.h>
#include <curses.h>
#include "editor.h"

int main() {

	initscr();
	curs_set(0);
	raw();
	noecho();
	keypad(stdscr, TRUE);
	s_Editor ed;
	init_editor(&ed);
	// nodelay(stdscr,TRUE);	
	while (1) {
		refresh_editor(&ed);
		int k = getch();
		switch (ed.mode) {
			case MODE_NORMAL: 
				if (k == 'i') {
					ed.mode = MODE_INSERT;
					curs_set(1);
				} else if (k == ':') {
					ed.mode = MODE_COMMAND;
				} else if (k == 'q') {
					exit(0);
				}
				break;
			case MODE_INSERT:
				if (k == 27) {
					ed.mode = MODE_NORMAL;
					curs_set(0);
				}
				break;
			case MODE_COMMAND:
				if (k == 27) {
					ed.mode = MODE_NORMAL;
				}
				break;
		}
	}
	endwin();
	
	return 0;
}
