#include "main.h"

/**
 * chars_checks - checking characters in buffers
 * @str: string
 * Return: (0) if no error else (-1)
 */
int chars_checks(char *str)
{
	int i = 0, r = -1;

	if (str[0] == '#')
		return (-1);

	while (str[i])
	{
		if (str[i] != 32 && str[i] != 10 && str[i] != '\t' && str[i] != '#')
		{
			r = 0;
			if (str[0] == ' ' && str[1] != ' ')
				str = _strtok(str, ' ');
			break;
		}
		if (str[i] == '#')
			break;
		i++;
	}
	return (r);
}

/**
 * check_dir - check command for cd
 * @str: command (string)
 * Return: (1) or (0)
 */
int check_dir(char *str)
{
	char *cpy = _strdup(str), *dir = NULL, *PWD = NULL;
	int flag = 0, builtIn = 0;

	if (_strcmp(_strtok(cpy, ' '), "cd") == 0)
	{
		dir = _strtok(NULL, ' ');
		if (dir == NULL)
		{
			dir = _getenv("HOME");
			flag++;
		}
		PWD = _getenv("PWD");
		_setenv("OLDPWD", PWD, 1);
		_setenv("PWD", dir, 1);
		if (chdir(dir) != 0)
			perror(dir);
		builtIn++;
	}
	if (flag > 0)
		free(dir);
	free(cpy);
	free(PWD);
	return (builtIn);
}

/**
 * check_exit - check string is 'exit' found
 * @str: command (string)
 * Return: integer
 */
int check_exit(char *str)
{
	char *cpy = _strdup(str);

	if (_strcmp(_strtok(str, ' '), "exit") == 0)
	{
		free(cpy);
		return (1);
	}
	free(cpy);
	return (0);
}

/**
 * check_built_in - check for command
 * @str: command (string)
 * Return: integer
 */
int check_built_in(char *str)
{
	if (check_dir(str) == 1)
		return (2);
	if (check_exit(str) == 1)
		return (1);
	if (check_env(str) == 1)
		return (3);
	if (check_unset_env(str) == 1)
		return (4);
	if (check_set_env(str) == 1)
		return (5);
	if (check_help(str) == 1)
		return (6);
	return (0);
}
