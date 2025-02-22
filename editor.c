#include <unistd.h>
#include <curses.h>
#include "editor.h"
#include "buffer.h"
#include "modes.h"

void init_editor(s_Editor *ed) {
	getmaxyx(stdscr, ed->rows, ed->cols);
	ed->mode = MODE_NORMAL;
	ed->buf_arr = buffer_init();
}


void draw_text_space(s_Editor *ed) {
	int row=0, pos=0;
	for (size_t i=0; i<ed->buf_arr->c_start; i++) {
		mvaddch(row, pos, ed->buf_arr->arr[i]);
		pos++;
	}
	for (size_t i=ed->buf_arr->c_end; i<ed->buf_arr->capacity; i++) {
		mvaddch(row, pos, ed->buf_arr->arr[i]);
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
