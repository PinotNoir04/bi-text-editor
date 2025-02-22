CFLAGS = -Wall -Wextra -pedantic -lcurses

bi: bi.c screen.c screen.h modes.h
	gcc bi.c screen.c -o bi $(CFLAGS)
