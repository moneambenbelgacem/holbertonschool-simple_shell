#include "main.h"

/**
 * get_handler - Get message after ^C
 * @signo: integer
 */
void get_handler(__attribute__((unused)) int signo)
{
	write(STDOUT_FILENO, "\n", 4);
}

/**
 * kep_it_handler - Block trying sort from shell and check isatty
 */
void kep_it_handler(void)
{
	signal(SIGINT, get_handler);
	if ((isatty(STDOUT_FILENO) == 1))
		write(STDOUT_FILENO, "$ ", 3);
}

/**
 * str_concat - contacting two strings
 * @s1: first string
 * @s2: second string
 * Return: string
 */
char *str_concat(char *s1, char *s2)
{
	int i = 0, j = 0, n = 0;
	char *str;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	do {
		i++;
	} while (s1[i - 1]);
	do {
		j++;
	} while (s2[j - 1]);
	str = malloc(sizeof(char) * (i + j - 1));
	if (str == NULL)
		return (NULL);

	for (n = 0; n < i; n++)
		str[n] = s1[n];
	for (n = 0; n < j; n++)
		str[n + i - 1] = s2[n];
	return (str);
}

/**
 * _strlen - get length of string
 * @str: constant string
 * Return: integer
 */
int _strlen(const char *str)
{
	int i = 0;

	while (str[i])
		i++;

	return (i);
}
