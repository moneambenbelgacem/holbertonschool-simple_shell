#include "shell.h"
int exeCommand(char **command)
{
	
	if (strcmp(command[0], "cd") == 0)
	{
		if (command[1] == NULL)
		{
			fprintf(stderr,"expect argument");
			freeArr(command);
			
		}
		else
		{
			if (chdir(command[1]) != 0)
			{
				printf("hsh : cd");
				freeArr(command);
			

			}
		}
	

			
		
	}
	else if (execvp(command[0], command) != -1)
	{
		freeArr(command);
		return(100);
	}
	else
	{
		perror("command not found");
		freeArr(command);
		return(100);
	}
	return(100);
}
