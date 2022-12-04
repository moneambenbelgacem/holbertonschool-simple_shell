#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <stddef.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

extern char **environ;

void kep_it_handler(void);
char *str_concat(char *s1, char *s2);
int _setenv(char *name, char *value, int overwrite);
int _strlen(const char *str);

#endif