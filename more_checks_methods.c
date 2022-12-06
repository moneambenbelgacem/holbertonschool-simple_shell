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

/**
 * check_unset_env - check if command unsetenv
 * @str: command (string)
 * Return: (1) if succuss and (0) if fail
 */
int check_unset_env(char *str)
{
	char *cpy = _strdup(str), *token = NULL;

	if (_strcmp(_strtok(cpy, ' '), "unsetenv") == 0)
	{
		token = _strtok(NULL, ' ');
		if (token == NULL)
		{
			write(STDERR_FILENO, "Usage: unsetenv [VARIABLE]\n", 28);
			free(cpy);
			return (1);
		}
		if (unset_env(token) == -1)
		{
			write(STDERR_FILENO, "can't unset non-existent variable\n", 35);
			free(cpy);
			return (1);
		}
		free(cpy);
		return (1);
	}
	free(cpy);
	return (0);
}
