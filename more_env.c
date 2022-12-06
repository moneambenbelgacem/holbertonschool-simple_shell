#include "main.h"

/**
 * unset_env - remove env variable
 * @name: name of variable (string)
 * Return: (0) if succuss and (-1) if fail
 */
int unset_env(char *name)
{
	size_t len = 0;
	int i = 0, flag = 0;

	len = _strlen(name);
	while (environ[i] != NULL)
	{
		if (strncmp(environ[i], name, len) == 0)
		{
			while (environ[i] != NULL)
			{
				environ[i] = environ[i + 1];
				i++;
			}
			flag++;
			break;
		}
		i++;
	}
	if (flag > 0)
		return (0);
	return (-1);
}
