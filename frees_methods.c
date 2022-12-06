#include "main.h"

/**
 * free_env - free variable from env
 * @var_name: name of variable
 */
void free_env(char *var_name)
{
	size_t len = 0;
	int i = 0, j = 0;

	while (var_name[j++] != '\0')
		len++;

	while (environ[i] != NULL)
	{
		if (strncmp(environ[i], var_name, len) == 0)
			free(environ[i]);
		i++;
	}
}

/**
 * free_and_exit - free buffer and exit if ther is nothing
 * @buffer: string
 */
void free_and_exit(char *buffer)
{
	if (isatty(STDIN_FILENO) == 1)
		write(STDIN_FILENO, "\n", 1);
	free(buffer);
	free_env("OLDPWD");
	exit(0);
}
