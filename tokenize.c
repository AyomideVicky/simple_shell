#include "shell.h"

/**
 * tokenize - Split string based on Delimiter
 * @str: string to be tokenized
 * Return: Pointer to str
 */

char **tokenizer(char *str)
{
	const unsigned int BUFFER = 1024;
	char **tokens; //Double Pointer for Strings after tokenization
	char *token;
	unsigned int i;

	tokens = malloc(sizeof(char) * BUFFER);
	if (tokens == NULL)
	{
		errors(3);
		exit(EXIT_FAILURE);
	}

	token = strtok(str, "\n\t\r ");

	i = 0;
	while (token != NULL)
	{
		tokens[i] = token;
		token = strtok(NULL, "\n\t\r ");
		i++;
	}

	tokens[i] = NULL;

	return (tokens);
}
