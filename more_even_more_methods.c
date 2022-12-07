#include "main.h"

/**
 * args - calculate all argument of functions
 * @str: string
 * Return: integer
 */
int args(char *str)
{
	int i = 0, counter = 0;

	if (str[0] != ' ')
		counter++;

	if (str[0] == ' ' && (str[1] != ' ' && str[1] != '\0'))
		counter++;

	while (str[i])
	{
		if (str[i] == ' ' && (str[i + 1] != ' ' && str[i + 1] != '\0'))
			counter++;
		i++;
	}
	return (counter);
}

/**
 * isDir - check if the path is directory
 * @path: constant string
 * Return: integer
 */
int isDir(const char *path)
{
	struct stat st = {0};

	stat(path, &st);
	return (S_ISREG(st.st_mode));
}
