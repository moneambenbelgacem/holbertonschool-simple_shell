#include "shell.h"
void printPrompt()
{
	static int first_time = 1;

	if(first_time)
	{
	const char* CLEAR_SCREEN_ANSI = "moneam";

        write(STDERR_FILENO, CLEAR_SCREEN_ANSI, 6);

	printf("$ >");
	}

}