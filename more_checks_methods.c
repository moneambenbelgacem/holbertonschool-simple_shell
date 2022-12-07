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

/**
 * check_set_env - check if command setenv
 * @str: command (string)
 * Return: integer
 */
int check_set_env(char *str)
{
	char *cpy = _strdup(str), *name = NULL, *value = NULL;

	if (strcmp(_strtok(cpy, ' '), "setenv") == 0)
	{
		name = _strtok(NULL, ' ');
		value = _strtok(NULL, ' ');
		if (name == NULL || value == NULL)
		{
			write(STDERR_FILENO, "Usage: setenv [VARIABLE] [VALUE]\n", 34);
			free(cpy);
			return (1);
		}
		_setenv(name, value, 1);
		free(cpy);
		return (1);
	}
	free(cpy);
	return (0);
}

/**
 * check_help - check if command is 'help'
 * @str: command (string)
 * Return: integer
 */
int check_help(char *str)
{
	char *cpy = _strdup(str), *name = NULL;

	if (_strcmp(_strtok(cpy, ' '), "help") == 0)
	{
		name = _strtok(NULL, ' ');
		if (name == NULL)
		{
			write(1, "Usage: help [BUILTIN]\nList of Built-Ins\n", 41);
			write(1, "cd\nexit\nsetenv\nunsetenv\nenv\nhelp\n", 34);
			free(cpy);
			return (1);
		}
		else
			while (name != NULL)
			{
				help_case(name);
				name = _strtok(NULL, ' ');
			}
		free(cpy);
		return (1);
	}
	free(cpy);
	return (0);
}
