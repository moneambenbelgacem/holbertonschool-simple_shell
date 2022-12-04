#include "main.h"

/**
 * main - Entry place
 * Return: integer
 */
int main(void)
{
	size_t i = 0;
	int counter = 0;
	char *buffer = NULL;

	while (1)
	{
		kep_it_handler();
		counter = getline(&buffer, &i, stdin);
		if (counter == 1)
			free_and_exit(buffer);
	}
}
