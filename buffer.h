#pragma once
#ifndef BUFFER_H
#define BUFFER_H

#include <stddef.h>

typedef struct{
	size_t capacity;
	size_t gap_size;
	char *arr;
	char *c_start;
	char *c_end;
}t_buffer;

t_buffer *buffer_init();
void buffer_resize(t_buffer* buf);
void insert_char(t_buffer* buf, char *text);
void delete_char(t_buffer* buf);
void delete_buffer(t_buffer* buf);
void move_left(t_buffer* buf);
void move_right(t_buffer* buf);

#endif
