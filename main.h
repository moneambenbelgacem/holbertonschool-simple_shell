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

/**
 * struct list_s - lista
 * @str: str
 * @next: next
 */
typedef struct list_s
{
	char *str;
	struct list_s *next;
} list_t;

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
int check_built_in(char *str);
int get_return_value(char *str);
int _isdigit(char *str);
int check_env(char *str);
void printEnv(void);
int unset_env(char *name);
int check_unset_env(char *str);
int check_set_env(char *str);
void help_case(char *name);
int check_help(char *str);
int args(char *str);
char *path(char *filename);
int isDir(const char *path);
char **tokenize(char *str, int builtIn);
int its_executable(char *path);
int child_fork(pid_t child_pid, char *name);
void free_array_dup(char **array, char *dup);
void wait_and_free(int status, char **argv, char *dup);

#endif
