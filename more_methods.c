#include "main.h"

/**
 * remove_tab - change tab by space in string
 * @str: string
 * Return: string
 */
char *remove_tab(char *str)
{
	int i = 0, tab = 0;

	while (str[i])
	{
		if (str[i] == '\t')
			tab++;
		i++;
	}
	i = 0;
	if (tab > 0)
		while (str[i])
		{
			if (str[i] == '\t')
				str[i] = ' ';
			i++;
		}
	return (str);
}

/**
 * comments - check for hashtag and remove it
 * @str: string
 * Return: string
 */
char *comments(char *str)
{
	int i = 0, hashtag = 0, flag = 0;

	while (str[i])
	{
		if (str[i] == ' ' && str[i + 1] == '#')
		{
			hashtag++;
			break;
		}
		i++;
	}
	if (hashtag == 0)
		return (str);
	i = 0;
	while (str[i])
	{
		if (flag == 1)
		{
			str[i] = ' ';
			i++;
			continue;
		}
		if (str[i] == ' ' && str[i + 1] == '#')
		{
			flag++;
			i++;
			continue;
		}
		i++;
	}
	return (str);
}

/**
 * clearBuffer - clean string from # and tab ...
 * @str: string
 * @counter: length of string (integer)
 * Return: string
 */
char *clearBuffer(char *str, int counter)
{
	str[counter - 1] = '\0';
	str = remove_tab(str);
	str = comments(str);
	return (str);
}

/**
 * _strtok - strtok a string
 * @str: string
 * @delim: character to cut by
 * Return: string
 */
char *_strtok(char *str, char delim)
{
	static char *tok1, *tok2;
	unsigned int i;

	if (str != NULL)
		tok2 = str;
	tok1 = tok2;
	if (tok1 == NULL)
		return (NULL);
	for (i = 0; tok1[i] != '\0'; i++)
	{
		if (tok1[i] != delim)
			break;
	}
	if (tok2[i] == '\0')
	{
		tok2 = NULL;
		return (NULL);
	}
	tok1 = tok2 + i;
	tok2 = tok1;
	for (i = 0; tok2[i] != '\0'; i++)
	{
		if (tok2[i] == delim)
			break;
	}
	if (tok2[i] == '\0')
		tok2 = NULL;
	else
	{
		tok2[i] = '\0';
		tok2 += i + 1;
		if (tok2[0] == '\0')
			tok2 = NULL;
	}
	return (tok1);
}
