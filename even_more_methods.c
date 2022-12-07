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

/**
 * _isdigit - check if string is digit
 * @str: string
 * Return: (0) is string is digit
 */
int _isdigit(char *str)
{
	int i = 0, flag = 0;

	while (str[i] != '\0')
	{
		if (str[i] >= 48 && str[i] <= 57)
		{
			i++;
			continue;
		}
		else
		{
			flag++;
			break;
		}
	}
	return (flag);
}

/**
 * get_return_value - set number exit by it
 * @str: command (string)
 * Return: integer
 */
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
	if (_isdigit(token) == 0)
		exit_value = atoi(token);
	else
	{
		free(cpy);
		write(STDERR_FILENO, "exit: Illegal number\n", 22);
		return (-1);
	}
	free(cpy);
	if (exit_value < 0)
	{
		write(STDERR_FILENO, "exit: Illegal number\n", 22);
		exit_value = -1;
	}

	return (exit_value);
}
