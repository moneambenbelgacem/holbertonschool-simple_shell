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
void free_and_exit(char *buffer);
void free_env(char *var_name);
int chars_checks(char *str);
char *clearBuffer(char *str, int counter);
char *_strtok(char *str, char delim);
char *_strdup(const char *str);
int _strcmp(const char *s1, const char *s2);
char *_getenv(const char *name);
int check_dir(char *str);
int check_exit(char *str);

#endif