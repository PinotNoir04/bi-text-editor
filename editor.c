#include <ncurses.h>
#include <unistd.h>
#include <curses.h>
#include "editor.h"
#include "buffer.h"
#include "modes.h"

void init_editor(s_Editor *ed) {
	getmaxyx(stdscr, ed->rows, ed->cols);
	ed->mode = MODE_NORMAL;
	ed->buf = buffer_init();
}


void draw_text_space(s_Editor *ed) {
	for (int i=0;i<ed->rows-1;i++) {
		mvwprintw(stdscr, i, 0, "~");
	}
}

void draw_statusline(s_Editor *ed) {
	char *status_name;
	if (ed->mode == MODE_COMMAND) {
		status_name = "Command";
	} else if (ed->mode == MODE_INSERT) {
		status_name = "Insert";
	} else {
		status_name = "Normal";
	}
	attron(A_STANDOUT);
	mvwprintw(stdscr, ed->rows-1, 0, "%s", status_name);
	attroff(A_STANDOUT);
}

void refresh_editor(s_Editor *ed) {
	clear();
	draw_text_space(ed);
	draw_statusline(ed);
	refresh();
}
