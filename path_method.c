#include "main.h"

/**
 * path - check if file exist
 * @filename: file name
 * Return: route of file or null
 */
char *path(char *filename)
{
	char *PATH = _getenv("PATH");
	char *cpy = _strdup(PATH);
	char *concatenated = NULL;
	char *token = NULL, *absolute = NULL;
	struct stat st;

	token = _strtok(cpy, ' ');
	concatenated = str_concat("/", filename);
	while (token != NULL)
	{
		if (stat(absolute, &st) == 0)
		{
			free(PATH);
			free(cpy);
			free(concatenated);
			return (absolute);
		}
		token = _strtok(NULL, ':');
		free(absolute);
	}
	free(PATH);
	free(concatenated);
	free(cpy);
	return (NULL);
}
