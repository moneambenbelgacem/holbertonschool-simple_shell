#include "shell.h"






int main()
{

	char sentence[SENTENCE_LEN];
	char **parsedStr;
	int numOfCommands = 0, lengthOfCommands = 0, parsedStrLen;
	pid_t id;

	while (1)
	{
		printPrompt();
		if (fgets(sentence, SENTENCE_LEN, stdin) != NULL)
		{
			parsedStrLen = numOfWords(sentence);
			lengthOfCommands += (int)(strlen(sentence) - 1);
			numOfCommands++;
			if (parsedStrLen > 0)
			{
				parsedStr = (char **)malloc((parsedStrLen + 1) * sizeof(char *));
				if (parsedStr == NULL)
				{
					fprintf(stderr, "malloc failed");
					exit(1);
				}
				parsedStr[parsedStrLen] = NULL;
				parseString(sentence, parsedStr);
				if (strcmp(parsedStr[0], "done") == 0 && parsedStrLen == 1)
				{
					donePrint(numOfCommands, lengthOfCommands);
					freeArr(parsedStr);
					break;
				}
				id = fork();
				if (id < 0)
				{
					perror("ERR");
					freeArr(parsedStr);
					exit(1);
				}
				else if (id == 0)
				{
					exeCommand(parsedStr);
					freeArr(parsedStr);
				}
				else
				{
					wait(NULL);
					freeArr(parsedStr);
				}
			}
		}
	}
	return 0;
}