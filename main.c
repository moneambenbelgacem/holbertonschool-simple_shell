#include "shell.h"

/**
 * main - entry point
 * Return: integer
 */
int main(void)
{
	int status = 0, a, parsedStrLen;
	pid_t id;
	size_t size = 32;
	char buffer[1024], *sentence = buffer, **parsedStr;

	while (1)
	{

		if (getline(&sentence, &size, stdin) == -1)
		{
			if (feof(stdin))
				exit(EXIT_SUCCESS);
			else
			{

				sentence = NULL;
				perror("");
				exit(1);
			}
		}
		else
		{
			parsedStrLen = numOfWords(sentence);
			if (parsedStrLen > 0)
			{
				parsedStr = (char **)malloc((parsedStrLen + 1) * sizeof(char *));
				if (parsedStr == NULL)
				{
					fprintf(stderr, "malloc failed");
					return (1);
				}
				parsedStr[parsedStrLen] = NULL;
				parseString(sentence, parsedStr);
				id = fork();
				if (strcmp(parsedStr[0], "exit") == 0)
				{
					freeArr(parsedStr);
					return (0);
				}
				if (id == -1)
				{
					perror("");
					freeArr(parsedStr);
					exit(98);
				}
				else if (id == 0)
				{
					a = exeCommand(parsedStr);
					if (a == 127)
					{
						return (127);
					}
				}
				else
				{
					while (waitpid(-1, &status, 0) != id)
						;
					freeArr(parsedStr);
				}
			}
		}
	}

	return (0);
}
