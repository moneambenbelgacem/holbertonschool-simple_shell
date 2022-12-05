#include "shell.h"
void printPrompt()
{
	char *userName = getUserName();
	char currentDir[PATH_MAX];

	getcwd(currentDir, sizeof(currentDir));
	printf("%s@%s>", userName, currentDir);
}