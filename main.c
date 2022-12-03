#include "main.h"

/**
 * main - Entry place
 * Return: integer
 */
int main(void)
{
	_setenv("OLDPWD", " ", 1);
	while (1)
	{
		kep_it_handler();
	}
}
