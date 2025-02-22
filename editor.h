#pragma once
#include "buffer.h"
#ifndef EDITOR_H
#define EDITOR_H

#include "modes.h"

typedef struct{
	int rows;
	int cols;
	e_Modes mode;
	t_buffer* buf;
}s_Editor;

void init_editor(s_Editor *ed);
void draw_text_space(s_Editor *ed);
void draw_statusline(s_Editor *ed);
void refresh_editor(s_Editor *ed);

#endif
