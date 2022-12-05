#include "shell.h"
void exeCommand(char **command)
{
	if (strcmp(command[0], "cd") == 0)
	{
		printf("command not supported (YET)\n");
		freeArr(command);
		exit(0);
	}
	else if (execvp(command[0], command) != -1)
	{
		freeArr(command);
		exit(0);
	}
	else
	{
		perror("command not found");
		freeArr(command);
		exit(1);
	}
}
