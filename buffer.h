#pragma once
#ifndef BUFFER_H
#define BUFFER_H

#include <stddef.h>

#define INITIAL_BUFFER_CAPACITY 100

typedef struct{
	size_t capacity;
	size_t c_start;
	size_t c_end;
	char *arr;
}t_buffer;

t_buffer *buffer_init();
void buffer_resize(t_buffer* buf);
void insert_char(t_buffer* buf, char text);
void delete_char(t_buffer* buf);
void delete_buffer(t_buffer* buf);
void move_left(t_buffer* buf);
void move_right(t_buffer* buf);

#endif
