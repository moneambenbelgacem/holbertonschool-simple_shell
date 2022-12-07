#include "main.h"

/**
 * help_case - help for command
 * @name: name of commands
 */
void help_case(char *name)
{
	if (_strcmp(name, "cd") == 0)
	{
		write(1, "cd [dir]\nChange the shell working directory.\n", 46);
	}
	else if (_strcmp(name, "exit") == 0)
	{
		write(1, "exit [n]\nExits the shell with a status of N.\n", 46);
	}
	else if (_strcmp(name, "setenv") == 0)
	{
		write(1, "setenv [var] [value]\nSet environment variables.\n", 49);
	}
	else if (_strcmp(name, "unsetenv") == 0)
	{
		write(1, "unsetenv [var]\nUnset environment variables.\n", 45);
	}
	else if (_strcmp(name, "help") == 0)
	{
		write(1, "help [BUILTIN]\nDisplays information for Buitlt-Ins.\n", 53);
	}
	else if (_strcmp(name, "env") == 0)
	{
		write(1, "env\nPrint all environment variables.\n", 38);
	}
	else
	{
		write(1, "Wrong Built-In, use help to list all Built-Ins\n", 48);
	}
}
