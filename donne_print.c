#include "shell.h"
void donePrint(int numOfCommands, int lengthOfCommands)
{
	printf("Num of commands: %d\n", numOfCommands);
	printf("Total length of all commands: %d\n", lengthOfCommands);
	printf("Average length of all commands: %f\n", (double)(lengthOfCommands) / numOfCommands);
	printf("See you Next time !\n");
}