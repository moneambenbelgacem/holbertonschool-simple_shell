#include "shell.h"

/**
 * freeArr - function
 * @parsedStr: array of string
 */
void freeArr(char **parsedStr)
{
	int i = 0;

	while (parsedStr[i])
		free(parsedStr[i++]);
	free(parsedStr);
}
