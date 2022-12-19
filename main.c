#include "shell.h"

/**
 * main - Entry Point
 *
 * Return - always 0
 */


int main(int argc __attribute__((unused)), char *argv[] __attribute__((unused)))
{
	char *lineptr = NULL;
	size_t n = 0;
	ssize_t nread;

	while (1)
	{
		printf("$ ");
		nread = getline(&lineptr, &n, stdin);
		if (nread != -1)
		{
			printf("%s", lineptr);
		}
		else
			exit (1);

	}
}
