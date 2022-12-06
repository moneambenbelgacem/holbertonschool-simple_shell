#include "main.h"

/**
 * create_variable - create new variable to printed
 * @name: string
 * @value: string
 * Return: string
 */
char *create_variable(char *name, char *value)
{
	char *var = NULL, *aux = NULL;

	aux = str_concat(name, "=");
	if (aux == NULL)
		return (NULL);

	var = str_concat(aux, value);
	if (var == NULL)
		return (NULL);

	free(aux);
	return (var);
}

/**
 * _setenv - set env variables and overwrite
 * @name: name of variable
 * @value: value of variable
 * @overwrite: if need overwrite
 * Return: 0 if success or -1 if fail
 */
int _setenv(char *name, char *value, int overwrite)
{
	size_t len = 0, j = 0;
	int i = 0;

	while (name[j++] != '\0')
		len++;

	while (environ[i] != NULL)
	{
		if ((strncmp(environ[i], name, len) == 0) && overwrite != 0)
		{
			if (overwrite == 2)
				free(environ[i]);

			environ[i] = create_variable(name, value);
			if (environ[i] == NULL)
				return (-1);

			return (0);
		}
		i++;
	}
	environ[i] = create_variable(name, value);
	if (environ[i] == NULL)
		return (-1);
	environ[i + 1] = NULL;
	return (0);
}

/**
 * printEnv - print all variables from env
 */
void printEnv(void)
{
	int i = 0;

	while (environ[i])
	{
		write(1, environ[i], _strlen(environ[i]));
		write(1, "\n", 1);
		i++;
	}
}

/**
 * _getenv - get value of variable env
 * @name: constant string
 * Return: string
 */
char *_getenv(const char *name)
{
	char *token, *value, *cpy;
	size_t i = 0;

	if (name == NULL)
		exit(1);

	while (environ[i] != NULL)
	{
		cpy = _strdup(environ[i]);
		token = _strtok(cpy, '=');
		if (_strcmp(name, token) == 0)
		{
			token = _strtok(NULL, '=');
			value = malloc(sizeof(char) * _strlen(token) + 1);
			if (value == NULL)
			{
				free(cpy);
				return (NULL);
			}
			strcpy(value, token);
			free(cpy);
			break;
		}
		i++;
		free(cpy);
	}
	return (value);
}