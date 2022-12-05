#include "shell.h"
char *getUserName()
{
	uid_t uid = geteuid();
	struct passwd *pw = getpwuid(uid);
	if (pw)
		return pw->pw_name;
	else
	{
		return NULL;
	}
}