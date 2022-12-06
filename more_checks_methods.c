#include "main.h"

/**
 * check_env - check if command is env and print it
 * @str: command (string)
 * Return: (1) or (0)
 */
int check_env(char *str)
{
	char *cpy = _strdup(str);

	if (_strcmp(_strtok(cpy, ' '), "env") == 0)
	{
		free(cpy);
		printEnv();
		return (1);
	}
	free(cpy);
	return (0);
}
