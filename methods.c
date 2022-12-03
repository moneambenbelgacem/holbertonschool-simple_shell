#include "main.h"

/**
 * get_handler - Get message after ^C
 * @signo: integer
 */
void get_handler(__attribute__((unused)) int signo)
{
	write(STDOUT_FILENO, "\n$", 4);
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
	int i = 0, j = 0, x = 0;
	char *str;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	while (s1[i] != '\0')
		i++;
	while (s2[j] != '\0')
		j++;

	str = malloc(sizeof(char) + i + j);
	if (str == NULL)
		return (NULL);

	for (x = 0; x < i; x++)
		str[x] = s1[x];
	for (x = 0; x < j; x++)
		str[x + i - 1] = s2[x];

	return (str);
}
