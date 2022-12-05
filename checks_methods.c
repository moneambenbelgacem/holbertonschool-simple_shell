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
