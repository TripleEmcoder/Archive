#include "windows.h"
#include <stdarg.h>
#include <ncurses.h>

WINDOW* create_window(int x, int y, int width, int height)
{
	WINDOW *main = newwin(height, width, y, x);
	box(main, 0, 0);
	wrefresh(main);
	
	WINDOW *local = newwin(height-2, width-2, y+1, x+1);
	local->_parent = main;
	scrollok(local, TRUE);
	immedok(local, TRUE);
	leaveok(local, 1);

	return local;
}

void destroy_window(WINDOW* local)
{
	delwin(local->_parent);
	delwin(local);
}

WINDOW* input;
WINDOW* output;
WINDOW* debug_output;

void create_windows()
{
	int width, height;

	initscr();
	getmaxyx(stdscr, height, width);
	input = create_window(0, height-5, width, 5);
	output = create_window(0, 0, width, height-15);
	debug_output = create_window(0, height-15, width, 10);
}

void destroy_windows()
{
	destroy_window(input);
	destroy_window(output);
	destroy_window(debug_output);
	endwin();
}

void read_input(char* line)
{
	wgetstr(input, line);
}

void write_output(const char* format, ...)
{
	va_list args;
	va_start(args, format);
	vwprintw(output, format, args);
	va_end(args);
}

void write_debug_output(const char* format, ...)
{
	va_list args;
	va_start(args, format);
	vwprintw(debug_output, format, args);
	va_end(args);
}
