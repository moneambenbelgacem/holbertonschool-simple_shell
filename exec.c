#include "shell.h"
int exeCommand(char **command)
{
	
	if (strcmp(command[0], "cd") == 0)
	{
		if (command[1] == NULL)
		{
			fprintf(stderr,"expect argument");
			freeArr(command);
			return (0);
			
		}
		else
		{
			if (chdir(command[1]) != 0)
			{
				printf("hsh : cd");
				freeArr(command);
				return (0);
			

			}
		}
	

			
		
	}
	else if (execvp(command[0], command) != -1)
	{
		freeArr(command);
		return(1);
	}
	else
	{
		perror("command not found");
		freeArr(command);
		return(1);
	}
	return(1);
}
