#include "shell.h"
/**
 * *_strcpy - copies the string pointed to by src to the buffer pointed to dest
 * @dest: char dest
 * @src: char src
 * Return: dest.
 */
char *_strcpy(char *dest, char *src)
{
	int i;
	char a;

	for (i = 0; src[i] != '\0'; i++)
	{
		a = src[i];
		dest[i] = a;
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * _strlen - returns the length of a string.
 * @s: pointer to String
 * Return: Nothing
 */
int _strlen(const char *s)
{
	int i = 0;

	while (*(s + i) != '\0')
	{
		i++;
	}

	return (i);
}
/**
 * _strcat - concatenates two strings.
 * @dest: string to destiny
 * @src: string to source
 * Return: Return a concatenate string
 */
char *_strcat(char *dest, char *src)
{
	char *output = NULL;
	unsigned int i = 0, j = 0, len1 = 0, len2 = 0;

	len1 = _strlen(dest);
	len2 = _strlen(src);

	output = _calloc(sizeof(char), (len1 + len2 + 1));
	if (output == NULL)
		return (NULL);

	i = 0;
	j = 0;

	if (dest)
	{
		while (i < len1)
		{
			output[i] = dest[i];
			i++;
		}
	}
	if (src)
	{
		while (i < (len1 + len2))
		{
			output[i] = src[j];
			i++;
			j++;
		}
	}
	output[i] = '\0';

	return (output);
}
