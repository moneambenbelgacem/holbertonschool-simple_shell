#include "shell.h"

/**
 * cd_home - function
 */
void cd_home(void)
{
	char currentDir[2] = {"~"};

	getcwd(currentDir, sizeof(currentDir));
}
