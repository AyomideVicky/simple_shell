#include "shell.h"

/**
 * _getline - read line to buffer from stream
 * @stream: File Stream
 * Return: return number of byte read from file stream
 */

char *_getline(FILE *stream)
{
	char *lineptr = NULL;
	size_t n = 0;
	ssize_t nread;

	nread = getline(&lineptr, &n, stream);
	if (nread == EOF)
	{
		free (lineptr);
		exit (EXIT_SUCCESS);
	}

	return (lineptr);
}
