#include "main.h"

/**
 * tokenize - get args of function
 * @str: string
 * @builtIn: integer
 * Return: array of string
 */
char **tokenize(char *str, int builtIn)
{
	int size = 0, i = 0;
	char **array = NULL, *token = NULL, *test = NULL;
	struct stat st = {0};

	size = args(str);
	array = malloc(sizeof(char *) * (size + 1));
	if (array == NULL)
		return (NULL);
	token = _strtok(str, ' ');
	while (token != NULL)
	{
		array[i] = _strdup(token);
		token = _strtok(NULL, ' ');
		i++;
	}
	if (builtIn == 0 && array[0][0] != '/')
	{
		test = path(array[0]);
		if (test != NULL)
		{
			free(array[0]);
			array[0] = _strdup(test);
		}
		else
		{
			if ((stat(array[0], &st) == 0) || (isDir(array[0]) == 0))
				;
			else
				perror(array[0]);
		}
		free(test);
	}
	array[i] = NULL;
	return (array);
}
