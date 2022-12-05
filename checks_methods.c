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
