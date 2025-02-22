#include <stddef.h>
#include <curses.h>
#include <string.h>
#include <stdlib.h>
#include "buffer.h"



t_buffer *buffer_init() {
	t_buffer *buf = malloc(sizeof(t_buffer));
	if (!buf) {exit(1);}

	buf->capacity = 80;
	buf->gap_size = buf->capacity;

	buf->arr = (char *)malloc(buf->capacity*sizeof(char));
	if(!buf->arr) {
		free(buf->arr);
		free(buf);
		exit(1);
	}

	buf->c_start = buf->arr;
	buf->c_end = &buf->arr[buf->capacity-1];

	return buf;
	
}

void buffer_resize(t_buffer *buf) {
	buf->capacity *= 2;
	buf->gap_size = buf->capacity - buf->gap_size;
	buf->arr = (char *)realloc(buf->arr, buf->capacity*sizeof(char));
	if (!buf->arr) {
		free(buf->arr);
		free(buf);
		exit(1);
	}
	buf->c_end = &buf->arr[buf->capacity-1];
}

void insert_char(t_buffer *buf, char *text) {
	if (strlen(text) > buf->capacity) {
		buffer_resize(buf);
	}
	memcpy(buf->c_start, text, strlen(text));
	buf->c_start += strlen(text);
}

void delete_char(t_buffer *buf) {
	buf->c_start--;
}

void delete_buffer(t_buffer *buf) {
	free(buf->arr);
	free(buf);
}

void move_left(t_buffer *buf) {
	char *t = buf->c_start-1;
	char temp = *buf->c_end;
	*buf->c_end = *t;
	*t = temp;
	buf->c_start--;
	buf->c_end--;
}

void move_right(t_buffer *buf) {
	char *t = buf->c_end+1;
	char temp = *buf->c_start;
	*buf->c_start = *t;
	*t = temp;
	buf->c_start++;
	buf->c_end++;
}

