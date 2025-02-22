CFLAGS = -Wall -Wextra -pedantic -lcurses

CFILES = bi.c editor.c buffer.c
HFILES = editor.h buffer.h modes.h

bi: $(CFILES) $(HFILES)
	gcc $(CFILES) -o bi $(CFLAGS)
