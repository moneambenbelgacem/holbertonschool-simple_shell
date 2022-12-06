#include "main.h"

/**
 * _strdup - copy string
 * @str: constant string
 * Return: string
 */
char *_strdup(const char *str)
{
	int i, n = 0;
	char *strcpy;

	if (str == NULL)
		return (NULL);

	while (str[n])
		n++;

	strcpy = malloc(n);
	if (strcpy == NULL)
		return (NULL);
	for (i = 0; str[i] != '\0'; i++)
		strcpy[i] = str[i];
	return (strcpy);
}

/**
 * _strcmp - string checking
 * @s1: string
 * @s2: string
 * Return: integer
 */
int _strcmp(const char *s1, const char *s2)
{
	int i, ss1 = 0, ss2 = 0, result = 0;

	for (i = 0; i > -1; i++)
	{
		if (s1[i] != s2[i])
		{
			ss1 = s1[i];
			ss2 = s2[i];
			break;
		}
		else
		{
			if (s1[i] == '\0' || s2[i] == '\0')
				break;
		}
	}
	result = ss1 - ss2;
	return (result);
}

int get_return_value(char *str)
{
	char *cpy = _strdup(str), *token;
	int exit_value;

	token = _strtok(cpy, ' ');
	token = _strtok(NULL, ' ');
	if (token == NULL)
	{
		free(cpy);
		return (0);
	}
	/* con... */
}
