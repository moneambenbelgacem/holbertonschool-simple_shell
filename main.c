#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

void read_command(char cmd[], char *par[])
{
	char line[1024];
	int count = 0, i = 0, j = 0;
	char *array[100], *pch;

	// read one line
	for (;;)
	{
		int c = fgetc(stdin);
		line[count++] = (char)c;
		if (c == '\n')
			break;
	}
	if (count == 1)
		return;
	pch = strtok(line, " \n");
	// parse the line
	while (pch != NULL)
	{
		array[i++] = strdup(pch);
		pch = strtok(NULL, " \n");
	}
	// first word is the command
	strcpy(cmd, array[0]);

	// other the parametr
	for (j = 0; j < i; j++)
		par[j] = array[j];
	par[i] = NULL; // NULL terminate the parametre list
}

void disp_on_screen()
{
	static int first_time = 1;
	if (first_time)
	{
		// clear screen for the first time
		const char *CLEAR_SCREEN_ANSI = "\e[1;1H\e[2J";
		write(STDOUT_FILENO, CLEAR_SCREEN_ANSI, 11);
		first_time = 0;
	}
	printf("#"); // display_prompt
}


int main()
{
	char cmd[100], command[100], *param[20];
	// env variable
	char *envp[] = {(char *)"PATH=/bin", 0};
	while (1)
	{
		disp_on_screen();			  // display prompt on screen
		read_command(command, param); // read input from terminal
		if (fork() != 0)			  // pparent
			wait(NULL);
		else
		{
			strcpy(cmd, "/bin/");
			strcat(cmd, command);
			execve(cmd, param, envp); // execute command
		}
		if (strcmp(command, "exit") == 0)
			break;
	}
}