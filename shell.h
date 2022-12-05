#ifndef HEADER_FILE
#define HEADER_FILE
#define SENTENCE_LEN 511
#define PATH_MAX 512
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <pwd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <time.h>
#include <wait.h>
void printPrompt();
char *getUserName();
int numOfWords(const char sentence[]);
void parseString(char sentence[], char **parsedStr);
void freeArr(char **parsedStr);
void exeCommand(char **command);
void donePrint(int numOfCommands, int lengthOfCommands);
#endif