#include "shell.h"

/**
 * parseString - function
 * @sentence: array of string
 * @parsedStr: array of string
 */
void parseString(char sentence[], char **parsedStr)
{
	char tmpWord[SENTENCE_LEN];
	int tmpIndex = 0, parsedIndex = 0;
	size_t i;

	for (i = 0; i < strlen(sentence); i++)
	{
		if (sentence[i] != ' ' && sentence[i] != '\n')
		{
			tmpWord[tmpIndex] = sentence[i];
			tmpIndex++;
		}

		else if ((sentence[i] == ' ' || sentence[i] == '\n') && tmpIndex > 0)
		{
			tmpWord[tmpIndex] = '\0';
			parsedStr[parsedIndex] = (char *)malloc((strlen(tmpWord)) + 1);
			if (parsedStr[parsedIndex] == NULL)
			{
				freeArr(parsedStr);
				fprintf(stderr, "malloc failed");
				exit(1);
			}
			strcpy(parsedStr[parsedIndex], tmpWord);

			parsedIndex++;
			tmpIndex = 0;
		}
	}
}
