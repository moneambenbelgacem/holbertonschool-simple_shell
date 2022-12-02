#include <stdio.h>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("%d\n", argc);
		return (0);
	}

	printf("%s: 1: %s: not found\n", argv[0], argv[1]);
	return (1);
}
