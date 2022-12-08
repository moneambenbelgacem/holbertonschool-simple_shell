#include "shell.h"

/**
 * getUserName - function
 * Return: string
 */
char *getUserName()
{
	uid_t uid = geteuid();
	struct passwd *pw = getpwuid(uid);

	if (pw)
		return (pw->pw_name);

	return (NULL);
}
