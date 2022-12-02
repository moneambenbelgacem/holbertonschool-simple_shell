#include "main.h"

/**
 * get_handler - Get message after ^C
 */
void get_handler(void)
{
	write(STDOUT_FILENO, "\n$", 4);
}

/**
 * kep_it_handler - Block trying sort from shell and check isatty
 */
void kep_it_handler(void)
{
	signal(SIGINT, get_handler);
	if ((isatty(STDOUT_FILENO) == 1))
		write(STDOUT_FILENO, "$ ", 3);
}
