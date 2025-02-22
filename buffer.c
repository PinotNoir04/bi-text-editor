#include <stddef.h>
#include <curses.h>
#include <string.h>
#include <stdlib.h>
#include "buffer.h"



t_buffer *buffer_init() {
	t_buffer *buf = malloc(sizeof(t_buffer));
	if (!buf) {exit(1);}

	buf->capacity = INITIAL_BUFFER_CAPACITY;
	buf->c_start = 0;
	buf->c_end = buf->capacity-1;

	buf->arr = (char *)malloc(buf->capacity*sizeof(char));
	if(!buf->arr) {
		free(buf->arr);
		free(buf);
		exit(1);
	}

	return buf;
}

void buffer_resize(t_buffer *buf) {
	buf->capacity *= 2;
	buf->arr = (char *)realloc(buf->arr, buf->capacity*sizeof(char));
	if (!buf->arr) {
		free(buf->arr);
		free(buf);
		exit(1);
	}
	buf->c_start++;
	buf->c_end = buf->capacity-1;
}

void insert_char(t_buffer *buf, char c) {
	if ((buf->c_end - buf->c_start) <= 1 ) {
		buffer_resize(buf);
	}
	buf->arr[buf->c_start] = c;
	buf->c_start++;
}

void delete_char(t_buffer *buf) {
	buf->c_start--;
}

void delete_buffer(t_buffer *buf) {
	free(buf->arr);
	free(buf);
}

void move_left(t_buffer *buf) {
	memmove(&buf->arr[buf->c_end-1], &buf->arr[buf->c_start-1], 1);
	buf->c_start--;
	buf->c_end--;
}

void move_right(t_buffer *buf) {
	memmove(&buf->arr[buf->c_start+1], &buf->arr[buf->c_end+1], 1);
	buf->c_start++;
	buf->c_end++;
}

