#include "main.h"

/**
 * args - calculate all argument of functions
 * @str: string
 * Return: integer
 */
int args(char *str)
{
	int i = 0, counter = 0;

	if (str[0] != ' ')
		counter++;

	if (str[0] == ' ' && (str[1] != ' ' && str[1] != '\0'))
		counter++;

	while (str[i])
	{
		if (str[i] == ' ' && (str[i + 1] != ' ' && str[i + 1] != '\0'))
			counter++;
		i++;
	}
	return (counter);
}

/**
 * isDir - check if the path is directory
 * @path: constant string
 * Return: integer
 */
int isDir(const char *path)
{
	struct stat st = {0};

	stat(path, &st);
	return (S_ISREG(st.st_mode));
}

/**
 * its_executable - check if path is executable
 * @path: string
 * Return: integer
 */
int its_executable(char *path)
{
	if (isDir(path) == 0)
	{
		if (path[0] == '/')
			perror(path);
		else
			perror(path);
		return (1);
	}
	if (access(path, X_OK))
		return (2);
	else
		return (0);
}

/**
 * child_fork - forked a proccess
 * @child_pid: pid_t
 * @name: string
 * Return: integer
 */
int child_fork(pid_t child_pid, char *name)
{
	child_pid = fork();
	if (child_pid == -1)
	{
		perror(name);
		exit(EXIT_FAILURE);
	}
	return (child_pid);
}
