#include "main.h"

/**
 * main - Entry place
 * Return: integer
 */
int main(void)
{
	size_t i = 0;
	int counter = 0, built_in = 0, exit_value = 0, child_pid = 0, status = 0;
	char *buffer = NULL, *dup = NULL, **argv = NULL;

	while (1)
	{
		kep_it_handler();
		counter = getline(&buffer, &i, stdin);
		if (counter == -1)
			free_and_exit(buffer);
		if (chars_checks(buffer) == -1)
			continue;
		buffer = clearBuffer(buffer, counter);
		built_in = check_built_in(buffer);
		if (built_in == 1)
		{
			exit_value = get_return_value(buffer);
			if (exit_value >= 0)
				break;
			continue;
		}
		dup = _strdup(buffer);
		argv = tokenize(dup, built_in);
		if (built_in == 0 && its_executable(argv[0]) == 0)
			child_pid = child_fork(child_pid, argv[0]);
		else
			child_pid = -1;
		if (child_pid == 0 && execve(argv[0], argv, environ) == -1)
		{
			perror(argv[0]);
			break;
		}
		if (child_pid != 0)
			wait_and_free(status, argv, dup);
	}
	if (built_in != 1)
		free_array_dup(argv, dup);
	return (exit_value);
}
