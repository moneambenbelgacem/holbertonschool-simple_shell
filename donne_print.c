#include "shell.h"
void cd_home(void)
{
	char currentDir[2] = {"~"};
	
	
		getcwd(currentDir, sizeof(currentDir));
}